/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 21:38:44 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/05 21:31:47 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "ft_select.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(-1);
}

void	eb_wait_for_it(t_data *d, struct termios *term)
{
	while (!is_enter(d->read_char))
	{
		read(0, d->read_char, 5);
		eb_print(d);
		printf("[%d %d %d %d %d]\n", d->read_char[0], d->read_char[1], d->read_char[2], d->read_char[3], d->read_char[4]);
	}
	(void)term;
}

int		main(int ac, char const *av[])
{
	t_data					d;
	/*static struct termios	old;*/
	struct termios			term;

	if (ac < 2)
		ft_error("usage: ft_select choix1 etc.");
	d.list = get_lst((char **)++av);
	d.cursor = *(d.list);
	if (tgetent(d.bp, getenv("TERM")) < 1)
		ft_error("bad tgetent");
	if (tcgetattr(0, &term) != 0)
		ft_error("bad tcgetattr");
	term.c_lflag &= ECHO;
	term.c_lflag &= ICANON;
	if (tcsetattr(0, 0, &term) != 0)
		ft_error("bad tcsetattr");
	tputs(tgetstr("vi", NULL), 1, eb_putchar);
	eb_wait_for_it(&d, &term);

	tputs(tgetstr("ve", NULL), 1, eb_putchar);
	(void)ac;
	(void)av;
	return (0);
}
