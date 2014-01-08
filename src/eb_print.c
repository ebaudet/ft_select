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

#include "ft_select.h"

void	eb_print(t_data *d)
{
	t_lst	*tmp;
	int		cpt;

	cpt = 0;
	tmp = *(d->list);
	while (tmp != *(d->list) || cpt++ == 0)
	{
		ft_putendl(tmp->str);
		tmp = tmp->next;
	}
}
