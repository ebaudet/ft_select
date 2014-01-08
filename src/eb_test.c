/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 19:01:41 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/08 19:01:41 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_select.h"

void	print_list(t_lst **list)
{
	t_lst	*tmp;
	int		i;

	i = -1;
	tmp = *list;
	while (tmp != *list || ++i == 0)
	{
		printf("[%d, %s, %d]->", tmp->nb, tmp->str, tmp->select);
		tmp = tmp->next;
	}
	if (i == 0)
		printf("pas d'elements dans la liste\n");
	printf("\n---------------\n");
}

void	eb_test()
{
	t_lst			*list;
	t_lst			*tmp;

	tmp = eb_new_elt("str1");
	list = tmp;
	tmp = eb_new_elt("str2");
	eb_add_list_last(&list, tmp);
	print_list(&list);
	tmp = eb_new_elt("str3");
	eb_add_list_last(&list, tmp);
	print_list(&list);
	tmp = eb_new_elt("str4");
	eb_add_list_last(&list, tmp);
	print_list(&list);
	tmp = eb_new_elt("str5");
	eb_add_list_first(&list, tmp);
	print_list(&list);
	tmp = eb_new_elt("str6");
	eb_add_list_first(&list, tmp);
	print_list(&list);
	tmp = eb_new_elt("str7");
	eb_add_list_last(&list, tmp);
	print_list(&list);
}
