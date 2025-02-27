/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:30:04 by mbarutel          #+#    #+#             */
/*   Updated: 2023/01/27 14:56:11 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void	main_loop(t_shell *sh)
{
	int	status;

	status = 1;
	sh->term->clipboard.buff = NULL;
	while (status)
	{
		// ft_init_signals();
		set_signal_keyboard();
		sh->orig_termios = ft_raw_enable();
		if (ft_keyboard(sh->term) == 1)
		{
			ft_history_write_to_file(sh->term);
			status = 0;
		}
		ft_raw_disable(sh->orig_termios);
		if (*(sh->term->inp))
		{
			sh->line = ft_lexer(sh->term);
			sh->tokens = chop_line(sh->line, sh->tokens, 1);
			sh->head = build_tree(&sh->tokens);
			if (sh->head && ((t_semicolon *)sh->head)->left)
				exec_tree(sh->head, &sh->env, sh->terminal, sh);
			shell_end_cycle(sh);
		}
	}
}

int	main(void)
{
	t_shell		sh[1];

	ft_getent();
	banner_print();
	ft_session_init(sh);
	ft_history_get(sh->term);
	main_loop(sh);
	hash_free(sh->ht);
	ft_strdel(&sh->terminal);
	return (0);
}
