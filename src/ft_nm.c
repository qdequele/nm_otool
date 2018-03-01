/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:38:24 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/28 20:51:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		create_env();
		if (g_env == NULL)
		{
			perror("malloc g_env");
			exit(EXIT_FAILURE);
		}
		read_file(av[i]);
		match_header(g_env->ptr);
		if (ac > 2)
			env_description(av[i]);
		else
			env_description(NULL);
	}
	return (0);
}
