/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:07:52 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/28 20:52:27 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void		create_env(void)
{
	t_env	*env;

	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
	{
		g_env = NULL;
		return ;
	}
	env->options = 0;
	env->otool = 0;
	env->nb_fat = 0;
	env->ptr = NULL;
	env->filename = NULL;
	env->current_group = NULL;
	env->group_list = NULL;
	g_env = env;
}

void		create_env_otool(void)
{
	create_env();
	g_env->otool = 1;
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

void		env_description(char *name)
{
	if (g_env->group_list == NULL)
		return ;
	if (g_env->nb_fat == 1)
	{
		ft_putstr(g_env->filename);
		ft_putendl(":");
	}
	else if (name != NULL)
	{
		ft_putstr("\n");
		ft_putstr(name);
		ft_putendl(":");
	}
	ft_lstiter(g_env->group_list, group_description);
}
