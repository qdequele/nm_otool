/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:51:36 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/06 10:51:52 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

char	*symbol_type_64(uint8_t type, uint8_t sect, t_architecture *archi)
{
	char		*ret;
	t_section	*sec;

	if ((type & N_TYPE) == N_UNDF)
		ret = "U";
	else if ((type & N_TYPE) == N_ABS)
		ret = "A";
	else if ((type & N_TYPE) == N_SECT)
	{
		sec = (t_section *)(ft_lstget_at(archi->sec_list, (int)sect - 1)->content);
		if (ft_strcmp(sec->sec_name, SECT_TEXT) == 0)
			ret = "T";
		else if (ft_strcmp(sec->sec_name, SECT_DATA) == 0)
			ret = "D";
		else if (ft_strcmp(sec->sec_name, SECT_BSS) == 0)
			ret = "B";
		else
			ret = "S";
	}
	else if ((type & N_TYPE) == N_PBUD)
		ret = "P";
	else if ((type & N_TYPE) == N_INDR)
		ret = "I";
	else
		ret = "X";

	if ((type & N_EXT) == 0 && ft_strcmp(ret, "X") != 0)
		ret += 32;
	return (ret);
}

char	*symbol_type_32(uint8_t type, uint8_t sect, t_architecture *archi)
{
	char		*ret;
	t_section	*sec;

	if ((type & N_TYPE) == N_UNDF)
		ret = "U";
	else if ((type & N_TYPE) == N_ABS)
		ret = "A";
	else if ((type & N_TYPE) == N_SECT)
	{
		sec = (t_section *)(ft_lstget_at(archi->sec_list, (int)sect - 1)->content);
		if (ft_strcmp(sec->sec_name, SECT_TEXT) == 0)
			ret = "T";
		else if (ft_strcmp(sec->sec_name, SECT_DATA) == 0)
			ret = "D";
		else if (ft_strcmp(sec->sec_name, SECT_COMMON) == 0)
			ret = "B";
		else
			ret = "S";
	}
	else if ((type & N_TYPE) == N_PBUD)
		ret = "P";
	else if ((type & N_TYPE) == N_INDR)
		ret = "I";
	else
		ret = "X";

	if ((type & N_EXT) == 0 && ft_strcmp(ret, "X") != 0)
		ret += 32;
	return (ret);
}
