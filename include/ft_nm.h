/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:29 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 14:34:42 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

// [file1] - [file2]
// |
// [32] - [64] - [ppc]
// |
// [0000000100000000 T __mh_execute_header] - [0000000100000000 T __mh_execute_header]

# include <libft.h>
# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>

/*
**	ARCHI
*/

typedef struct	s_sym {
	char		*addr;
	char		*type;
	char		*name;
}				t_sym;

t_list			*create_sym(char *addr, char *type, char *name);
char			*symbol_type(uint8_t type);
void			symbol_description(t_list *node);
/*
**	ARCHI
*/

typedef struct	s_archi {
	char		*type;
	void		*ptr;
	int			nb_sym;
	t_list		*sym_list;
}				t_archi;

t_list			*create_archi(char *type, void *ptr);
void			find_arch(t_list *node);
void			archi_description(t_list *node);

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
}				t_env;

t_env			*g_env;

void			create_env();
void			env_description();
/*
**	LOAD COMMAND
*/

void			search_lc_64(t_archi *archi);
void			search_nlist_64(void *lc, t_archi *archi);
void			search_lc_32(t_archi *archi);
void			search_nlist_32(void *lc, t_archi *archi);

#endif
