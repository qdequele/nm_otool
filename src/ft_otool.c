/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:19:58 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/15 14:55:21 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		main(int ac, char ** av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		create_env();
		g_env->otool = 1;
		if (g_env == NULL)
		{
			perror("malloc g_env");
			exit(EXIT_FAILURE);
		}
		ft_putstr(av[i]);
		ft_putstr(":\n");
		read_file(av[i]);
		match_header(g_env->ptr);
	}
	return (0);
}
