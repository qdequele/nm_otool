/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:38:24 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/08 14:36:44 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>


int		main(int ac, char ** av)
{
	int		i;


	i = parse_options_nm(av) - 1;
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
		//show_env();
		//delete_env();
	}
	return (0);
}
