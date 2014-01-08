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
#include "../libft/includes/libft.h"

void ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(-1);
}

int		main(int ac, char const *av[])
{
	char			*name;
	char			bp[1024];
	char			t[4096];
	char			*area;
	char			*ab;
	char			*af;
	struct termios	term;

	name = getenv("TERM");
	if (tgetent(bp, name) < 1)
		ft_error("bad tgetent");
	if (tcgetattr(0, &term) != 0)
		ft_error("bad tcgetattr");
	term.c_lflag &= ECHO;
	term.c_lflag &= ICANON;
	if (tcsetattr(0, 0, &term) != 0)
		ft_error("bad tcsetattr");
	/*while ()
	{

	}*/

	area = t;
	af = tgetstr("AF", &area);
	ab = tgetstr("AB", &area);
	printf("-%s\n-%s\n-%s\n", bp, af, ab);
	
	(void)ac;
	(void)av;
	return (0);
}
