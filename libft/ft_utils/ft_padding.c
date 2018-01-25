/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:47:09 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 11:16:58 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_padding_left(char *before, int pad, char c)
{
	char	*after;
	int		b_len;
	int		i;

	b_len = ft_strlen(before);
	if ((after = (char *)malloc(sizeof(char)* (pad + 1))) == NULL)
		return NULL;
	after[pad] = '\0';
	i = 0;
	while (i < b_len && i < pad)
	{
		after[i] = before[i];
		i++;
	}
	while (i < pad)
	{
		after[i] = c;
		i++;
	}
	return (after);
}

char	*ft_padding_right(char *before, int pad, char c)
{
	char	*after;
	int		b_len;

	b_len = ft_strlen(before);
	if ((after = (char *)malloc(sizeof(char)* (pad + 1))) == NULL)
		return NULL;
	after[pad] = '\0';
	while (b_len > 0 && pad > 0)
	{
		after[pad - 1] = before[b_len - 1];
		b_len--;
		pad--;
	}
	while (pad > 0)
	{
		after[pad - 1] = c;
		pad--;
	}
	return (after);
}
