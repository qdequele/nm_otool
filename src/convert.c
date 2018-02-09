/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:31:08 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/08 14:15:35 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int	convert_endian_32(u_int32_t nb)
{
	return (
		(nb & 0x000000FF) << 24 |
		(nb & 0x0000FF00) << 8 |
		(nb & 0x00FF0000) >> 8 |
		(nb & 0xFF000000) >> 24
	);
}

int	convert_endian_64(u_int64_t nb)
{
	return (
		(nb & 0x00000000000000FF) << 56 |
		(nb & 0x000000000000FF00) << 40 |
		(nb & 0x0000000000FF0000) << 24 |
		(nb & 0x00000000FF000000) << 8 |
		(nb & 0x000000FF00000000) >> 8 |
		(nb & 0x0000FF0000000000) >> 24 |
		(nb & 0x00FF000000000000) >> 40 |
		(nb & 0xFF00000000000000) >> 56
	);
}