/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 21:38:44 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/10 21:37:28 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "ft_select.h"

int		eb_supprime_element(t_data *d)
{
	if (d->cursor->next == *(d->list))
	{
		d->cursor = (d->cursor)->prev;
		if (eb_del_elt(d->list, (d->cursor)->next, d) == 0)
			return (-1);
	}
	else
	{
		d->cursor = (d->cursor)->next;
		if (eb_del_elt(d->list, (d->cursor)->prev, d) == 0)
			return (-1);
	}
	return (0);
	/*d->cursor = (d->cursor == *(d->list)->prev) ? (d->cursor)->prev : (d->cursor)->next;
	eb_del_elt(d->list, (d->cursor)->prev);*/
}

int		eb_wait_for_it(t_data *d)
{
	while (!is_enter(d->read_char) && !is_esc(d->read_char))
	{
		if (is_down(d->read_char))
			d->cursor = (d->cursor)->next;
		if (is_up(d->read_char))
			d->cursor = (d->cursor)->prev;
		if (is_space(d->read_char))
		{
			(d->cursor)->select = ((d->cursor)->select == 0) ? 1 : 0;
			d->cursor = (d->cursor)->next;
		}
		if (is_delete(d->read_char) || is_del(d->read_char))
		{
			if (eb_supprime_element(d) == -1)
				return (0);
		}
		tputs(tgetstr("cl", NULL), 1, eb_putchar);
		eb_print(d);
		/*printf("[%d %d %d %d %d]\n", d->read_char[0], d->read_char[1],
				d->read_char[2], d->read_char[3], d->read_char[4]);*/
		ft_bzero(d->read_char, 5);
		read(0, d->read_char, 5);
	}
	if (is_enter(d->read_char))
		return (1);
	return (0);
}

int		main(int ac, char const *av[])
{
	t_data					d;
	/*static struct termios	old;*/
	struct termios			term;

	if (ac < 2)
		ft_error("usage: ft_select choix1 etc.");
	d.list = get_lst((char **)++av, &d);
	d.cursor = *(d.list);
	if (tgetent(d.bp, getenv("TERM")) < 1)
		ft_error("bad tgetent");
	if (tcgetattr(0, &term) != 0)
		ft_error("bad tcgetattr");
	term.c_lflag &= ECHO;
	term.c_lflag &= ICANON;
	if (tcsetattr(0, 0, &term) != 0)
		ft_error("bad tcsetattr");
	d.row = tgetnum("li");
	d.col = tgetnum("co");
	tputs(tgetstr("vi", NULL), 1, eb_putchar);
	tputs(tgetstr("cl", NULL), 1, eb_putchar);
	/*eb_getsig();*/
	if (eb_wait_for_it(&d) == 1)
		eb_print_checked(&d);
	tputs(tgetstr("ve", NULL), 1, eb_putchar);
	tputs(tgetstr("me", NULL), 1, eb_putchar);
	return (0);
}
