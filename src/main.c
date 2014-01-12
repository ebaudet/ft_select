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
#include <unistd.h>
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
}

int		eb_wait_for_it(t_data *d)
{
	while (!is_enter(d->read_char) && !is_esc(d->read_char))
	{
		if (is_arrow(d->read_char) == DOWN)
			d->cursor = (d->cursor)->next;
		if (is_arrow(d->read_char) == UP)
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
		eb_clear_screen(d);
		eb_print(d);
		ft_bzero(d->read_char, 4);
		read(0, d->read_char, 4);
	}
	if (is_enter(d->read_char))
		return (1);
	return (0);
}

int		main(int ac, char const *av[])
{
	t_data				*d;
	struct termios		*old;

	eb_getsig();
	d = eb_get_data();
	old = eb_get_init_conf();
	if (ac < 2)
		ft_error("usage: ft_select choix1 etc.");
	d->list = get_lst((char **)++av, d);
	d->cursor = *(d->list);
	if (tgetent(d->bp, getenv("TERM")) < 1)
		ft_error("bad tgetent");
	eb_init();
	d->row = tgetnum("li");
	d->col = tgetnum("co");
	tputs(tgetstr("cl", NULL), 1, eb_putchar);
	tputs(tgetstr("dl", NULL), 1, eb_putchar);
	if (eb_wait_for_it(d) == 1)
		eb_print_checked(d);
	else
		eb_clear_screen(d);
	eb_close();
	return (0);
}
