/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:38:24 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 14:02:32 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"


int		main(int ac, char ** av)
{
	int		i;
	create_env();
	if (g_env == NULL)
	{
		perror("malloc g_env");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (++i < ac)
		read_file(av[i]);
	ft_lstiter(g_env->file_list, find_arch);
	env_description();
	return (0);
}
