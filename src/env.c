/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:07:52 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 13:11:07 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

void		create_env()
{
	t_env	*env;

	if ((env = (t_env *)malloc(sizeof(t_env))) == NULL)
	{
		g_env = NULL;
		return ;
	}
	env->nb_files = 0;
	env->file_list = NULL;
	g_env = env;
}
