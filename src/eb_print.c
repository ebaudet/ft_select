/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:18:19 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/08 21:18:19 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"

void	eb_print(t_data *d)
{
	t_lst	*tmp;
	int		cpt;

	d->i = -1;
	cpt = 0;
	tmp = *(d->list);
	while (tmp != *(d->list) || cpt++ == 0)
	{
		++d->i;
		if (eb_position(d, tmp) == -1)
		{
			ft_putstr("Redimensionner la fenetre.\n");
			return ;
		}
		if (d->cursor == tmp)
			tputs(tgetstr("us", NULL), 1, eb_putchar);
		if (tmp->select)
			tputs(tgetstr("mr", NULL), 1, eb_putchar);
		
		ft_putstr(tmp->str);
		tputs(tgetstr("me", NULL), 1, eb_putchar);
		tmp = tmp->next;
	}
}

int		eb_position(t_data *d, t_lst *tmp)
{
	int		column_width;

	d->nb_col = d->nb_elt / d->row;
	d->nb_col += (d->nb_elt % d->row == 0) ? 0 : 1;
	d->merge = ((d->col / d->nb_col) - d->len) / 2;
	if (d->merge <= 0)
		return (-1);
	d->center = (d->len - ft_strlen(tmp->str)) / 2;
	d->center = 0;
	column_width = 2 * d->merge + d->len;
	d->pos_x = d->center + column_width * (d->i / d->row) + d->merge;
	d->pos_y = d->i % d->row;
	tputs(tgoto(tgetstr("cm", NULL), d->pos_x, d->pos_y), 1, eb_putchar);
	return (0);
}

void	eb_print_checked(t_data *d)
{
	t_lst	*tmp;
	int		cpt;
	int		i;

	cpt = 0;
	i = 0;
	tmp = *(d->list);
	tputs(tgetstr("cl", NULL), 1, eb_putchar);
	while (tmp != *(d->list) || cpt++ == 0)
	{
		if (tmp->select == 1)
		{
			if (i != 0)
				ft_putchar(' ');
			ft_putstr(tmp->str);
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(-1);
}
