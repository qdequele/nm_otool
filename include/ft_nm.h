/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:29 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/28 20:52:50 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <mach-o/dyld.h>
# include <mach-o/stab.h>
# include <mach/machine.h>
# include <ar.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>

# define DEBUG 0

# define OPT_N 0b00000001
# define OPT_O 0b00000010
# define OPT_P 0b00000100
# define OPT_R 0b00001000
# define OPT_U 0b00010000
# define OPT_U_MAJ 0b00100000
# define OPT_J 0b01000000

/*
**	SYMBOLES
*/

typedef struct	s_sym {
	char		*addr;
	char		*type;
	char		*name;
}				t_sym;

t_list			*create_sym(char *addr, char *type, char *name);
void			symbol_description(t_list *node);

/*
**	SECTION
*/

typedef struct	s_section {
	char		*seg_name;
	char		*sec_name;
	char		*content;
}				t_section;

t_list			*create_section(char *seg_name, char *sec_name, char *content);
void			show_sec_name(char *segname, char *sectname);
void			show_sec_line_32(int sec_size, uint64_t addr, void *offset);
void			show_sec_line_64(int sec_size, uint64_t addr, void *offset);

/*
**	GROUP
*/

typedef struct	s_group {
	char		*name;
	t_list		*sym_list;
	t_list		*sec_list;
}				t_group;

void			create_group(char *name);
void			group_description(t_list *node);

/*
**	ENV
*/

typedef struct	s_env {
	int			options;
	int			otool;
	void		*ptr;
	int			filesize;
	char		*filename;
	int			nb_fat;
	t_group		*current_group;
	t_list		*group_list;
}				t_env;

t_env			*g_env;

void			create_env();
void			create_env_otool(void);
void			env_description(char *name);
int				parse_options_nm(char **entry);
void			read_file(char *filename);
void			check_integrity(int ptr);

/*
**	HEADER
*/

void			match_header(void *ptr);

void			search_lc_32(void *ptr);
void			search_lc_64(void *ptr);
void			search_nlist_32(void *lc, void *ptr);
void			search_nlist_64(void *lc, void *ptr);
void			search_section_32(void *lc);
void			search_section_64(void *lc);
void			search_archives(void *ptr);
void			search_fat_32(void *ptr);
void			search_fat_64(void *ptr);

void			show_section_32(void *lc, void *ptr);
void			show_section_64(void *lc, void *ptr);

char			*symbol_type(uint8_t type, uint8_t sect);

/*
**	UTILS
*/

int				sort_alphabetically(t_list *node);
int				sort_numerically(t_list *node);
int				sort_reverse(t_list **node);
int				equatable(t_list *f, t_list *b);
int				convert_endian_32(u_int32_t nb);
int				convert_endian_64(u_int64_t nb);

#endif
