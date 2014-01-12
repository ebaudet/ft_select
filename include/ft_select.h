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

# define FD_STD_OUT 1
# define FD_STD_ERR 2

# define NOT_ARROW 0
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

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
t_lst			*eb_new_elt(char *str);
void			eb_add_list_last(t_lst **list, t_lst *new);
void			eb_add_list_first(t_lst **list, t_lst *new);
int				eb_del_elt(t_lst **list, t_lst *elt, t_data *d);
t_lst			**get_lst(char **av, t_data *d);

/*
** eb_tools.c
*/
int				eb_putchar(int c);
int				eb_putchar_output(int c);
void			eb_clear_screen(t_data *d);
void			*eb_get_data(void);
void			eb_get_winsize(t_data *d);

/*
** eb_print.c
*/
void			eb_print(t_data *d);
int				eb_position(t_data *d, t_lst *tmp);
void			eb_print_checked(t_data *d);
void			ft_error(char *msg);
void			eb_putstr_term(char *str);

/*
** eb_is_key.c
*/
int				is_space(char *buf);
int				is_enter(char *buf);
int				is_del(char *buf);
int				is_delete(char *buf);
int				is_esc(char *buf);

/*
** eb_is_key_arrow.c
*/
int				is_arrow(char *buf);

/*
** eb_signal.c
*/
void			eb_sig_resize(void);
void			eb_sig_clear(void);
void			eb_sig_fg(void);
void			eb_sig_action(int s);
void			eb_getsig(void);

/*
** eb_term.c
*/
struct termios	*eb_get_init_conf(void);
void			eb_init(void);
void			eb_close(void);

#endif
