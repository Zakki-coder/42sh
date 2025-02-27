/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_end_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:26:23 by jniemine          #+#    #+#             */
/*   Updated: 2023/01/26 09:56:21 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void	ft_reset_tmp_env(t_shell *sh)
{
	int		i;
	char	*key;
	char	**env;

	i = -1;
	if (sh->tmp_env_key)
	{
		while (sh->tmp_env_key[++i])
		{
			key = ft_strchr(sh->tmp_env_key[i], '=');
			if (key)
			{
				key = ft_strsub(sh->tmp_env_key[i], 0, key - \
					sh->tmp_env_key[i]);
				env = ft_env_get(sh, key);
				ft_strdel(env);
				*env = ft_strdup(sh->tmp_env_key[i]);
				ft_strdel(&key);
			}
			else
				ft_env_remove(sh, sh->tmp_env_key[i]);
			ft_strdel(&sh->tmp_env_key[i]);
		}
		ft_memdel((void **)&sh->tmp_env_key);
	}
}

/**
 * It resets the tokens and sets the return value to 0
 *
 * @param sh the session struct
 */
void	shell_end_cycle(t_shell *sh)
{
	free_node(sh->head);
	free_tokens(&sh->tokens);
	reset_fd(sh->terminal);
	ft_reset_tmp_env(sh);
}
