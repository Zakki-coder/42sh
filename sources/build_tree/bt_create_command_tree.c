/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_create_command_tree.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:49:58 by jniemine          #+#    #+#             */
/*   Updated: 2023/01/26 09:55:22 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_treenode	*create_command_tree(t_token *tokens, int i_tok, int semicol)
{
	int			pipe;
	t_treenode	*head;

	if (is_semicolon_or_ampersand(tokens[i_tok].token))
		return (NULL);
	pipe = foreseer_of_tokens(tokens, PIPE, i_tok, semicol);
	if (pipe >= 0)
		head = create_pipe_node(tokens, pipe);
	else
		head = parse_right_cmd(tokens, i_tok);
	return (head);
}
