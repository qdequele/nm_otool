/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:19:58 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/22 17:45:50 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int main(int ac, char **av)
{
	int i;

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
		if (ft_match_str(av[i], ".a", ft_strlen(av[1]), 2) == 1)
		{
			ft_putstr("Archive : ");
			ft_putendl(av[i]);
		}
		else
		{
			ft_putstr(av[i]);
			ft_putendl(":");
		}
		read_file(av[i]);
		match_header(g_env->ptr);
	}
	return (0);
}
