/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 21:38:47 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/02 21:38:47 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "../libft/includes/libft.h"

typedef struct	s_lst
{
	char			*str;
	int				select;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

typedef struct	s_data
{
	char			bp[1024];
	char			read_char[4];
	t_lst			**list;
}				t_data;

/*
** eb_list.c
*/
t_lst	*eb_new_elt(char *str);
void	eb_add_list_last(t_lst **list, t_lst *new);
void	eb_add_list_first(t_lst **list, t_lst *new);
int		eb_del_elt(t_lst *elt);
t_lst	**get_lst(char **av);

/*
** eb_tools.c
*/
int		eb_putchar(int c);

/*
** eb_print.c
*/
void	eb_print(t_data *d);

/*
** eb_test.c
*/
void	print_list(t_lst **list);
void	eb_test();

#endif
