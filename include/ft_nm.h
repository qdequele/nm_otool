/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:29 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/07 15:03:18 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <libft.h>
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

# define OPT_N 0b00000001 // -n : Sort numerically rather than alphabetically.
# define OPT_O 0b00000010 // -o : Prepend file or archive element name to each output line, rather than only once.
# define OPT_P 0b00000100 // -p : don't sort
# define OPT_R 0b00001000 // -r : sort in reverse
# define OPT_U 0b00010000 // -u : show only undefined symbols
# define OPT_U_MAJ 0b00100000 // -U : don't show undefined symbols
# define OPT_J 0b01000000 // -j : Just display the symbol names (no value or type).

# define ENDIAN(X) (( X >> 24 ) | (( X << 8) & 0x00ff0000 ) | (( X >> 8) & 0x0000ff00) | ( X << 24))

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
void			section_description(t_list *node);

/*
**	ARCHITECTURES
*/

typedef struct	s_architecture {
	char		*type;
	void		*ptr;
	int			nb_sym;
	t_list		*sym_list;
	int			nb_sec;
	t_list		*sec_list;
}				t_architecture;

t_list			*create_architecture(char *type, void *ptr);
void			architecture_description(t_list *node);

/*
**	FILE
*/

typedef struct	s_file {
	char		*name;
	char		*path;
	void		*ptr;
	int			nb_archi;
	t_list		*archi_list;
}				t_file;

t_list			*create_file(char *name, char *path, void *ptr);
void			read_file(char *filename);
void			file_description(t_list *node);

/*
**	ENV
*/

typedef struct	s_env {
	int			nb_files;
	t_list		*file_list;
	int			options;
}				t_env;

t_env			*g_env;

void			create_env();
void			env_description();
int				parse_options_nm(char **entry);
void			print_options();

/*
**	HEADER
*/

void			find_architecture(t_list *node);
void			match_header(t_list *node);
/*
**	LOAD COMMAND
*/

void			search_lc_32(t_architecture *archi);
void			search_lc_64(t_architecture *archi);

/*
**	NLIST
*/

void			search_nlist_32(void *lc, t_architecture *archi);
void			search_nlist_64(void *lc, t_architecture *archi);

/*
**	SECTION COMMAND
*/

void			search_section_32(void *lc, t_architecture *archi);
void			search_section_64(void *lc, t_architecture *archi);

/*
**	ARCHIVES
*/

t_list			*search_archives(t_file *file);

/*
**	FAT
*/

t_list			*search_fat_32(t_file *file);
t_list			*search_fat_cigam_32(t_file *file);
t_list			*search_fat_64(t_file *file);
t_list			*search_fat_cigam_64(t_file *file);

/*
**	SYMBOLES TYPES
*/

char			*symbol_type_64(uint8_t type, uint8_t sect, t_architecture *archi);
char			*symbol_type_32(uint8_t type, uint8_t sect, t_architecture *archi);

/*
**	SORT
*/

int				sort_alphabetically(t_list *node);
int				sort_numerically(t_list *node);
int				sort_reverse(t_list **node);

#endif
