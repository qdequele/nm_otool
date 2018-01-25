/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:50:53 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 13:28:44 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

t_list	*create_file(char *name, char *path, void *ptr)
{
	t_file		*file;
	t_list		*lst;

	if ((file = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	file->name = name;
	file->path = path;
	file->ptr = ptr;
	file->nb_archi = 0;
	file->archi_list = NULL;
	lst->content = (void *)file;
	lst->content_size = sizeof(file);
	lst->next = NULL;
	return (lst);
}

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
	ft_lstaddend(&(g_env->file_list), create_file(filename, filename, ptr));
	g_env->nb_files += 1;
}
