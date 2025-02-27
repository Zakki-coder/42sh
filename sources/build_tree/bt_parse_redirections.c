/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_parse_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:14:15 by jniemine          #+#    #+#             */
/*   Updated: 2023/01/26 09:55:22 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_treenode	*parse_redirections(t_token *tokens, int i_tok, int cmd)
{
	t_treenode	*redir;
	t_treenode	*redir_start;

	redir = NULL;
	if (!tokens[i_tok].value)
		return (NULL);
	while (!redir && tokens[i_tok].token && tokens[i_tok].token != PIPE
		&& !is_semicolon_or_ampersand(tokens[i_tok].token))
	{
		if (choose_redir_type(tokens, &redir, i_tok++, cmd))
			return (NULL);
	}
	redir_start = redir;
	while (tokens[i_tok].token && tokens[i_tok].token != PIPE
		&& !is_semicolon_or_ampersand(tokens[i_tok].token))
	{
		if (choose_redir_type(tokens, &redir, i_tok, cmd))
			return (NULL);
		++i_tok;
	}
	if (redir_start)
		return (redir_start);
	return (init_cmd_node(tokens[cmd].value));
}
