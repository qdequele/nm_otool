/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:07:52 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/09 15:33:39 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void		create_env()
{
	t_env	*env;

	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
	{
		g_env = NULL;
		return ;
	}
	env->options = 0;
	env->ptr= NULL;
	env->filename = NULL;
	env->current_group = NULL;
	env->sym_list = NULL;
	env->sec_list = NULL;
	g_env = env;
}

int			parse_options_nm(char **entry)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (entry[++i] != NULL && entry[i][0] == '-')
		while (entry[i][++j] != '\0')
			if (entry[i][j] == 'n')
				g_env->options = g_env->options | OPT_N;
			else if (entry[i][j] == 'o')
				g_env->options = g_env->options | OPT_O;
			else if (entry[i][j] == 'p')
				g_env->options = g_env->options | OPT_P;
			else if (entry[i][j] == 'r')
				g_env->options = g_env->options | OPT_R;
			else if (entry[i][j] == 'u')
				g_env->options = g_env->options | OPT_U;
			else if (entry[i][j] == 'U')
				g_env->options = g_env->options | OPT_U_MAJ;
			else if (entry[i][j] == 'j')
				g_env->options = g_env->options | OPT_J;
			else
				return (i);
	return (i);
}

void		env_description()
{
	if (g_env->sym_list == NULL)
		return;

	if ((g_env->options & OPT_P) == OPT_P)
		return ft_lstiter(g_env->sym_list, symbol_description);
	else if ((g_env->options & OPT_N) == OPT_N)
		ft_lst_bubble_sort(g_env->sym_list, sort_numerically);
	else
		ft_lst_bubble_sort(g_env->sym_list, sort_alphabetically);
	if ((g_env->options & OPT_R) == OPT_R)
		sort_reverse(&(g_env->sym_list));
	ft_lstiter(g_env->sym_list, symbol_description);
}