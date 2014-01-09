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
#include "ft_select.h"

void	eb_print(t_data *d)
{
	t_lst	*tmp;
	int		cpt;

	if (*(d->list) == NULL)
	{
		ft_putstr("la liste est vide. Appuyer sur ENTER pour quitter.\n");
		return ;
	}
	cpt = 0;
	tmp = *(d->list);
	while (tmp != *(d->list) || cpt++ == 0)
	{
		if (d->cursor == tmp)
			tputs(tgetstr("us", NULL), 1, eb_putchar);
		if (tmp->select)
			tputs(tgetstr("mr", NULL), 1, eb_putchar);
		ft_putendl(tmp->str);
		tputs(tgetstr("me", NULL), 1, eb_putchar);
		tmp = tmp->next;
	}
}

void	eb_print_checked(t_data *d)
{
	t_lst	*tmp;
	int		cpt;
	int		i;

	cpt = 0;
	i = 0;
	tmp = *(d->list);
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
