/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:55:36 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/09 15:13:49 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_section_32(void *lc)
{
	struct segment_command	*seg;
	struct section			*sec;
	int						i;
	int						j;
	char					*content;

	if (DEBUG) ft_putendl("search_section_32");
	seg = (struct segment_command *)lc;
	sec = (struct section *)((void *)seg + sizeof(struct segment_command));
	i = 0;
	while (i < (int)seg->nsects)
	{
		j = 0;
		content = ft_strnew(0);
		// while (j < (int)sec->size)
		// {
		// 	if ((j % 8) == 0)
		// 	{
		// 		if (j != 0)
		// 			content = ft_strfjoin(content, "\n");
		// 		content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_ultohex(sec->addr + j), 8, '0')), "\t");
		// 	}
		// 	content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_uitohex(((char *)(archi->ptr + sec->offset))[j]), 2, '0')), " ");
		// 	j++;
		// }
		content = ft_strfjoin(content, "\n");
		ft_lstaddend(&(g_env->sec_list), create_section(sec->segname, sec->sectname, content));
		sec = (struct section *)((void *)sec + sizeof(struct section));
		i++;
	}
}

void	search_section_64(void *lc)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	int							i;
	int							j;
	char						*content;

	if (DEBUG) ft_putendl("search_section_64");
	seg = (struct segment_command_64 *)lc;
	sec = (struct section_64 *)((void *)seg + sizeof(struct segment_command_64));
	i = 0;
	while (i < (int)seg->nsects)
	{
		j = 0;
		content = ft_strnew(0);
		// while (j < (int)sec->size)
		// {
		// 	if ((j % 16) == 0)
		// 	{
		// 		if (j != 0)
		// 			content = ft_strfjoin(content, "\n");
		// 		content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_ultohex(sec->addr + j), 16, '0')), "\t");
		// 	}
		// 	content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_uitohex(((char *)(archi->ptr + sec->offset))[j]), 2, '0')), " ");
		// 	j++;
		// }
		content = ft_strfjoin(content, "\n");
		ft_lstaddend(&(g_env->sec_list), create_section(sec->segname, sec->sectname, content));
		sec = (struct section_64 *)((void *)sec + sizeof(struct section_64));
		i++;
	}
}
