/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:50:53 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/09 15:31:49 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	read_file(char *filename)
{
	int			fd;
	char		*ptr;
	struct stat	buff;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, &buff) < 0)
	{
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	if ((ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	g_env->filename = filename;
	g_env->ptr = ptr;
}
