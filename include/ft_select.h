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

# include "../libft/includes/libft.h"

typedef struct		s_lst
{
	char			*str;
	int				select;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct		s_data
{
	char			bp[1024];
	char			read_char[5];
	t_lst			**list;
	t_lst			*cursor;
	int				row;
	int				col;
	int				len;
	int				nb_elt;
	int				nb_col;
	int				pos_x;
	int				pos_y;
	int				merge;
	int				center;
	int				i;
}					t_data;

/*
** eb_list.c
*/
t_lst	*eb_new_elt(char *str);
void	eb_add_list_last(t_lst **list, t_lst *new);
void	eb_add_list_first(t_lst **list, t_lst *new);
int		eb_del_elt(t_lst **list, t_lst *elt, t_data *d);
t_lst	**get_lst(char **av, t_data *d);

/*
** eb_tools.c
*/
int		eb_putchar(int c);

/*
** eb_print.c
*/
void	eb_print(t_data *d);
int		eb_position(t_data *d, t_lst *tmp);
void	eb_print_checked(t_data *d);
void	ft_error(char *msg);

/*
** eb_is_key.c
*/
int		is_up(char *buf);
int		is_down(char *buf);
int		is_left(char *buf);
int		is_right(char *buf);
int		is_space(char *buf);
int		is_enter(char *buf);
int		is_del(char *buf);
int		is_delete(char *buf);
int		is_quit(char *buf);
int		is_background(char *buf);
int		is_esc(char *buf);
int		is_ctrc(char *buf);
int		is_ctrz(char *buf);

/*
** eb_signal.c
*/
void	eb_print_sig(int s);
void	eb_getsig(void);

/*
** eb_test.c
*/
void	print_list(t_lst **list);
void	eb_test();

#endif
