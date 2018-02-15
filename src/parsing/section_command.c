/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:55:36 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/15 15:08:19 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	show_section_32(void *lc, void *ptr)
{
	struct segment_command	*seg;
	struct section			*sec;
	int						i;
	int						j;
	char					*content;

	if (DEBUG) ft_putendl("show_section_32");
	seg = (struct segment_command *)lc;
	sec = (struct section *)((void *)seg + sizeof(struct segment_command));
	i = 0;
	while (i < (int)seg->nsects)
	{
		j = 0;
		content = ft_strnew(0);
		show_sec_name(sec->segname, sec->sectname);
		while (j < (int)sec->size)
		{
			if ((j % 8) == 0)
			{
				if (j != 0)
					content = ft_strfjoin(content, "\n");
				content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(
								ft_ultohex(sec->addr + j), 8, '0')), "\t");
			}
			content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_uitohex(((char *)(ptr + sec->offset))[j]), 2, '0')), " ");
			j++;
		}
		ft_putendl(content);
		sec = (struct section *)((void *)sec + sizeof(struct section));
		i++;
	}
}

void	show_section_64(void *lc, void *ptr)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	int							i;
	int							j;
	char						*content;

	if (DEBUG) ft_putendl("show_section_64");
	seg = (struct segment_command_64 *)lc;
	sec = (struct section_64 *)((void *)seg + sizeof(struct segment_command_64));
	i = 0;
	while (i < (int)seg->nsects)
	{
		j = 0;
		content = ft_strnew(0);
		show_sec_name(sec->segname, sec->sectname);
		while (j < (int)sec->size)
		{
			if ((j % 16) == 0)
			{
				if (j != 0)
					content = ft_strfjoin(content, "\n");
				content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_ultohex(sec->addr + j), 16, '0')), "\t");
			}
			content = ft_strfjoin(
				ft_strfjoin(content,
					ft_padding_right(
						ft_uitohex(((char *)(ptr + sec->offset))[j]), 2, '0')
					), " ");
			j++;
		}
		ft_putendl(content);
		sec = (struct section_64 *)((void *)sec + sizeof(struct section_64));
		i++;
	}
}

void	search_section_32(void *lc)
{
	struct segment_command	*seg;
	struct section			*sec;
	int						i;
	char					*content;

	if (DEBUG) ft_putendl("search_section_32");
	seg = (struct segment_command *)lc;
	sec = (struct section *)((void *)seg + sizeof(struct segment_command));
	i = 0;
	while (i < (int)seg->nsects)
	{
		content = ft_strnew(0);
		ft_lstaddend(&(g_env->current_group->sec_list), create_section(sec->segname, sec->sectname, content));
		sec = (struct section *)((void *)sec + sizeof(struct section));
		i++;
	}
}

void	search_section_64(void *lc)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	int							i;
	char						*content;

	if (DEBUG) ft_putendl("search_section_64");
	seg = (struct segment_command_64 *)lc;
	sec = (struct section_64 *)((void *)seg + sizeof(struct segment_command_64));
	i = 0;
	while (i < (int)seg->nsects)
	{
		content = ft_strnew(0);
		ft_lstaddend(&(g_env->current_group->sec_list), create_section(sec->segname, sec->sectname, content));
		sec = (struct section_64 *)((void *)sec + sizeof(struct section_64));
		i++;
	}
}
