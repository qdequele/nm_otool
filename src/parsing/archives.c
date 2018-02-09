/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archives.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:54:31 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/09 16:03:02 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_archives(void *ptr)
{
	struct ar_hdr	*header;
	int				o_size;
	char			*o_name;

	if (DEBUG) ft_putendl("search_archives");
	header = (struct ar_hdr *)(void*)(ptr + SARMAG);
	while ((header = (struct ar_hdr *)((void*)header + sizeof(struct ar_hdr)
			+ ft_atoi(header->ar_size))) && ((char *)header)[0])
	{
		o_size = ft_atoi(ft_strsub(header->ar_name, 3, 5));
		o_name = ft_strsub((char *)((void *)header + sizeof(struct ar_hdr)),
			0, o_size);
		g_env->current_group = ft_strjoin(g_env->filename, ft_strjoin("(",
			ft_strjoin(o_name, "):\n")));
		match_header((void *)header + sizeof(struct ar_hdr) + o_size);
	}
}
