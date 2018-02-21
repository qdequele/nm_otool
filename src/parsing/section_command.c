/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:55:36 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/15 17:40:01 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	show_section_32(void *lc, void *ptr)
{
	struct segment_command	*seg;
	struct section			*sec;
	int						i;

	seg = (struct segment_command *)lc;
	sec = (struct section *)((void *)seg + sizeof(struct segment_command));
	i = 0;
	while (i < (int)seg->nsects)
	{
		if (ft_strcmp(sec->sectname, SECT_TEXT) == 0)
		{
			show_sec_name(sec->segname, sec->sectname);
			show_sec_line((int)sec->size, sec->addr, ptr + sec->offset, 16);
		}
		sec = (struct section *)((void *)sec + sizeof(struct section));
		i++;
	}
}

void	show_section_64(void *lc, void *ptr)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	int							i;

	seg = (struct segment_command_64 *)lc;
	sec = (struct section_64 *)((void *)seg + sizeof(struct segment_command_64));
	i = 0;
	while (i < (int)seg->nsects)
	{
		if (ft_strcmp(sec->sectname, SECT_TEXT) == 0)
		{
			show_sec_name(sec->segname, sec->sectname);
			show_sec_line((int)sec->size, sec->addr, ptr + sec->offset, 16);
		}
		sec = (struct section_64 *)((void *)sec + sizeof(struct section_64));
		i++;
	}
}

void	search_section_32(void *lc)
{
	struct segment_command	*seg;
	struct section			*sec;
	int						i;

	seg = (struct segment_command *)lc;
	sec = (struct section *)((void *)seg + sizeof(struct segment_command));
	i = 0;
	while (i < (int)seg->nsects)
	{
		ft_lstaddend(&(g_env->current_group->sec_list),
			create_section(sec->segname, sec->sectname, ft_strnew(0)));
		sec = (struct section *)((void *)sec + sizeof(struct section));
		i++;
	}
}

void	search_section_64(void *lc)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	int							i;

	seg = (struct segment_command_64 *)lc;
	sec = (struct section_64 *)((void *)seg + sizeof(struct segment_command_64));
	i = 0;
	while (i < (int)seg->nsects)
	{
		ft_lstaddend(&(g_env->current_group->sec_list),
			create_section(sec->segname, sec->sectname, ft_strnew(0)));
		sec = (struct section_64 *)((void *)sec + sizeof(struct section_64));
		i++;
	}
}
