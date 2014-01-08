/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_is_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 23:18:28 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/08 23:18:28 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		is_up(char *buf)
{
	return (buf[0] == 27 && buf[1] == 91 && buf[2] == 65);
}

int		is_down(char *buf)
{
	return (buf[0] == 27 && buf[1] == 91 && buf[2] == 66);
}

int		is_left(char *buf)
{
	return (buf[0] == 27 && buf[1] == 91 && buf[2] == 68);
}

int		is_right(char *buf)
{
	return (buf[0] == 27 && buf[1] == 91 && buf[2] == 67);
}

int		is_space(char *buf)
{
	return (buf[0] == 32);
}

int		is_enter(char *buf)
{
	return (buf[0] == 10);
}

int		is_del(char *buf)
{
	return (buf[0] == 127);
}

int		is_delete(char *buf)
{
	return (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126);
}

int		is_quit(char *buf)
{
	return (buf[0] == 3);
}

int		is_background(char *buf)
{
	return (buf[0] == 26);
}
