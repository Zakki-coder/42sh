/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:41:05 by mrantil           #+#    #+#             */
/*   Updated: 2023/01/27 18:05:03 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int	check_if_valid_input(t_fc *fc, char ***cmd)
{
	if ((*cmd && !(*cmd)[1 + fc->e]) \
		|| (*cmd && (*cmd)[1 + fc->e] \
		&& (*cmd)[1 + fc->e][0] == '-' \
		&& ft_isdigit((*cmd)[1 + fc->e][1])) \
		|| (*cmd && (*cmd)[1 + fc->e] && ft_isdigit((*cmd)[1 + fc->e][0])) \
		|| (*cmd && fc->e))
	{
		return (1);
	}
	return (0);
}

static int	inner_loop(char ***cmd, int i, int j)
{
	while ((*cmd)[i][++j])
	{
		if (j == 0 && (*cmd)[i][0] == '-')
			continue ;
		else if (!ft_isdigit((*cmd)[i][j]))
		{
			if (j == 0 || (j == 1 && (*cmd)[i][0] == '-'))
			{
				ft_putendl_fd("42sh: fc: no command found", 2);
				return (1);
			}
			else
			{
				(*cmd)[i][j] = '\0';
				break ;
			}
		}
	}
	return (0);
}

static int	check_for_errors(char ***cmd)
{
	int		i;
	int		j;

	i = 0;
	while ((*cmd)[++i] && i < 3)
	{
		j = -1;
		if (inner_loop(cmd, i, j))
			return (1);
	}
	return (0);
}

int	ft_fc(t_shell *sh, char ***cmd)
{
	t_fc	fc;
	int		ret;

	fc.e = 0;
	ret = 0;
	if ((*cmd)[1] && ft_strnequ((*cmd)[1], "-e", 2))
		fc.e = 2;
	if (check_if_valid_input(&fc, cmd))
	{
		if (check_for_errors(cmd))
			return (0);
		if (fc_error_check_for_no_flag_or_e_flag(sh, &fc, cmd))
			ret = fc_no_flag_or_e_flag(sh, &fc, cmd);
	}
	else
		ret = fc_check_flags(sh, cmd);
	return (ret);
}
