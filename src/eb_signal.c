/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eb_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:03:51 by ebaudet           #+#    #+#             */
/*   Updated: 2014/01/09 20:03:51 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <curses.h>
#include <term.h>
#include "ft_select.h"

void	eb_print_sig(int s)
{
	if (s == SIGHUP)
		ft_putendl("SIGHUP");
	if (s == SIGINT)
		ft_putendl("SIGINT");
	if (s == SIGQUIT)
		ft_putendl("SIGQUIT");
	if (s == SIGILL)
		ft_putendl("SIGILL");
	if (s == SIGTRAP)
		ft_putendl("SIGTRAP");
	if (s == SIGABRT)
		ft_putendl("SIGABRT");
	if (s == SIGEMT)
		ft_putendl("SIGEMT");
	if (s == SIGFPE)
		ft_putendl("SIGFPE");
	if (s == SIGKILL)
		ft_putendl("SIGKILL");
	if (s == SIGBUS)
		ft_putendl("SIGBUS");
	if (s == SIGSEGV)
		ft_putendl("SIGSEGV");
	if (s == SIGSYS)
		ft_putendl("SIGSYS");
	if (s == SIGPIPE)
		ft_putendl("SIGPIPE");
	if (s == SIGALRM)
		ft_putendl("SIGALRM");
	if (s == SIGTERM)
	{
		ft_putendl("SIGTERM");
		/* KILL PROCESS */
	}
	if (s == SIGURG)
		ft_putendl("SIGURG");
	if (s == SIGSTOP)
		ft_putendl("SIGSTOP");
	if (s == SIGTSTP)
		ft_putendl("SIGTSTP");
	if (s == SIGCONT)
		ft_putendl("SIGCONT");
	if (s == SIGCHLD)
		ft_putendl("SIGCHLD");
	if (s == SIGTTIN)
		ft_putendl("SIGTTIN");
	if (s == SIGTTOU)
		ft_putendl("SIGTTOU");
	if (s == SIGIO)
		ft_putendl("SIGIO");
	if (s == SIGXCPU)
		ft_putendl("SIGXCPU");
	if (s == SIGXFSZ)
		ft_putendl("SIGXFSZ");
	if (s == SIGVTALRM)
		ft_putendl("SIGVTALRM");
	if (s == SIGPROF)
		ft_putendl("SIGPROF");
	if (s == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1, eb_putchar);
		/*TODO : signal width*/
	}
	if (s == SIGINFO)
		ft_putendl("SIGINFO");
	if (s == SIGUSR1)
		ft_putendl("SIGUSR1");
	if (s == SIGUSR2)
		ft_putendl("SIGUSR2");
}

void	eb_getsig(void)
{
	signal(SIGHUP, eb_print_sig);
	signal(SIGINT, eb_print_sig);
	signal(SIGQUIT, eb_print_sig);
	signal(SIGILL, eb_print_sig);
	signal(SIGTRAP, eb_print_sig);
	signal(SIGABRT, eb_print_sig);
	signal(SIGEMT, eb_print_sig);
	signal(SIGFPE, eb_print_sig);
	signal(SIGKILL, eb_print_sig);
	signal(SIGBUS, eb_print_sig);
	signal(SIGSEGV, eb_print_sig);
	signal(SIGSYS, eb_print_sig);
	signal(SIGPIPE, eb_print_sig);
	signal(SIGALRM, eb_print_sig);
	signal(SIGTERM, eb_print_sig);
	signal(SIGURG, eb_print_sig);
	signal(SIGSTOP, eb_print_sig);
	signal(SIGTSTP, eb_print_sig);
	signal(SIGCONT, eb_print_sig);
	signal(SIGCHLD, eb_print_sig);
	signal(SIGTTIN, eb_print_sig);
	signal(SIGTTOU, eb_print_sig);
	signal(SIGIO, eb_print_sig);
	signal(SIGXCPU, eb_print_sig);
	signal(SIGXFSZ, eb_print_sig);
	signal(SIGVTALRM, eb_print_sig);
	signal(SIGPROF, eb_print_sig);
	signal(SIGWINCH, eb_print_sig);
	signal(SIGINFO, eb_print_sig);
	signal(SIGUSR1, eb_print_sig);
	signal(SIGUSR2, eb_print_sig);
}
