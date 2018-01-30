/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:38:24 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/30 16:48:18 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"


int		main(int ac, char ** av)
{
	int		i;
	create_env();
	i = parse_options(av) - 1;
	if (g_env == NULL)
	{
		perror("malloc g_env");
		exit(EXIT_FAILURE);
	}
	while (++i < ac)
		read_file(av[i]);
	ft_lstiter(g_env->file_list, find_arch);
	env_description();
	return (0);
}
