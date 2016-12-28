/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:06:33 by maxpetit          #+#    #+#             */
/*   Updated: 2016/12/28 14:55:06 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <grp.h>
# include <time.h>
# include <pwd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"
# define SIZE 100
# define SEC_SEX_MONTH 15552000
# define ERROR_DIR ": No such file or directory\n"
# define CMP_CURRENT ft_strcmp(name, ".")
# define CMP_PREVIOUS ft_strcmp(name, "..")
# define HIDE_FILE (name[0] ==  '.')
# define NO_HIDE_FILE (name[0] !=  '.')

# define A ft_find_char(arg, 'a')
# define R ft_find_char(data.arg, 'R')
# define R_MIN ft_find_char(arg, 'r')
# define L ft_find_char(data.arg, 'l')
# define T ft_find_char(arg, 't')
# define IS_DIR S_ISDIR(((t_entity *)lst->content)->stat.st_mode)
# define TMP_PATH ((t_entity *)tmp->content)->path
# define TMP_TYPE ((t_entity *)tmp->content)->type
# define LST_PATH ((t_entity *)lst->content)->path
# define LST_TYPE ((t_entity *)lst->content)->type

# define LST_TYPE ((t_entity *)lst->content)->type
# define LST_PERM ((t_entity *)lst->content)->stat.st_mode
# define LST_NLINK ft_itoa((int)((t_entity *)lst->content)->stat.st_nlink)
# define LST_SIZE_NLINK ((t_entity *)lst->content)->buf_size.nblink
# define LST_UID ((t_entity *)lst->content)->stat.st_uid
# define LST_SIZE_UID ((t_entity *)lst->content)->buf_size.uid
# define LST_GID ((t_entity *)lst->content)->stat.st_gid
# define LST_SIZE_GID ((t_entity *)lst->content)->buf_size.gid
# define LST_SIZE ft_itoa((int)((t_entity *)lst->content)->stat.st_size)
# define LST_SIZE_SIZE ((t_entity *)lst->content)->buf_size.size
# define LST_TIME (((t_entity *)lst->content)->stat.st_mtime)

# define USER_NAME passwd->pw_name
# define GROUP_NAME group->gr_name
# define PATH ft_check_path(*argv)

# define SIZE_NLINK ft_strlen(LST_NLINK)
# define SIZE_SIZE ft_strlen(LST_SIZE)
# define LST_RDEV ft_itoa((int)((t_entity *)lst->content)->stat.st_rdev)
# define SIZE_RDEV ft_strlen(rdev)
# define SIZE_USER ft_strlen(USER_NAME)
# define SIZE_GROUP ft_strlen(GROUP_NAME)

# define TURTLE_PATH ((t_entity *)turtle->content)->path
# define RABBIT_NXT_PATH ((t_entity *)rabbit->next->content)->path
# define RABBIT_PATH ((t_entity *)rabbit->content)->path
# define TURTLE_NANOT ((t_entity *)turtle->content)->stat.st_mtimespec.tv_nsec
# define RABBIT_NANOT ((t_entity *)rabbit->content)->stat.st_mtimespec.tv_nsec
# define TURTLE_TIME ((t_entity *)turtle->content)->stat.st_mtime
# define RABBIT_TIME ((t_entity *)rabbit->content)->stat.st_mtime
# define CMP_PATH (ft_strcmp(TURTLE_PATH, RABBIT_PATH) > 0)
# define CMP_TIME ((TURTLE_TIME - RABBIT_TIME) < 0)
# define CMP_NANOTIME ((TURTLE_NANOT - RABBIT_NANOT) < 0)
# define EGUAL_TIME ((TURTLE_TIME - RABBIT_TIME) == 0)
# define EGUAL_NANOTIME ((TURTLE_NANOT - RABBIT_NANOT) == 0)
# define CMP_PATH_NXT (ft_strcmp(TURTLE_PATH, RABBIT_NXT_PATH) > 0)

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;
typedef struct tm		t_tm;
typedef struct		s_display
{
	int				nblink;
	int				uid;
	int				gid;
	int				dev;
	int				size;
}					t_display;
typedef struct		s_entity
{
	char			*path;
	char			type;
	t_stat			stat;
	t_display		buf_size;
}					t_entity;
typedef struct		s_filedata
{
	char			*arg;
	char			*original_path;
	char			*fst_path;
	int				type_arg;
	int				file_exist;
	int				dir;
}					t_filedata;
typedef struct		s_manage_arg
{
	int				i;
	int				j;
	char			*path;
	char			**f_file;
	char			**f_dir;
	int				ret;
}					t_manage_arg;
/*
**sort_list.c
*/
void				ft_sort(t_list **entity);
void				ft_find_min(t_list **entity);
int					ft_cmp_time(t_list *turtle, t_list *rabbit);
void				ft_sort_time(t_list **entity);
void				ft_find_min_time(t_list **entity);
/*
**print.c
*/
void				ft_print_total(int total);
void				ft_print_list(t_list **list, char *path, t_filedata data);
void				ft_loop_count(t_list *lst, int *spe_file,
					char *path, t_filedata data);
void				ft_loop_print(t_list **lst, int spe_file,
					char *path, t_filedata data);
void				ft_print_name(char const *path, t_filedata data);
/*
**print_option.c
*/
void				ft_print_size(t_list *lst, int spe_file, char *arg);
void				ft_print_mode(t_list *list);
void				ft_putmajmin(t_stat stat);
void				ft_print_stat(t_list *list, int spe_file, char *arg);
void				ft_display_link(char *path);
/*
**padding.c
*/
char				*ft_padding(char orientation, char *str,
					size_t size, char elem);
void				ft_pad_free(char orientation, char *str,
					size_t size, char elem);
void				ft_print_nlink(t_list *lst);
/*
**manage_size.c
*/
void				ft_return_size(t_list *list, int option, char *path);
void				ft_return_sizeint(t_list *list, int option, char *path);
void				ft_initialize_int(size_t *nblink, size_t *dev,
					size_t *size);
void				ft_initialize(size_t *uid, size_t *gid);
/*
**main.c
*/
void				ft_free_struct(t_manage_arg *x);
int					ft_fill_arg(char *param, char *arg);
int					ft_check_path(char *str);
void				ft_loop_arg(t_list *tab_file, t_list *tab_dir,
					char **argv, char *arg);
/*
**check.c
*/
int					ft_check_isdir(char *path);
int					ft_check_in_current_file(t_list **lst, char *path);
/*
**ls.c
*/
void				ft_sort_by_option(t_list **entity, char *agr);
int					ft_manage_dir(t_list **lst, char *path, t_filedata data);
int					ft_ls(t_list *entity, char *path, t_filedata data);
void				ft_begin_ls(t_list *lst, char *arg, int dir, char **tab);
/*
**list.c
*/
char				ft_define_type(unsigned long mode);
int					ft_check_dir(t_list *lst, char *arg);
void				ft_del_elem(t_list **lst);
void				ft_del_elem_fstlst(t_list **lst);
/*
**create_list.c
*/
t_entity			*ft_create_elem(char *path, char *f_name, int dir);
int					ft_create_lst(t_list **lst, char *path, char *name,
					int dir);
/*
**function.c
*/
void				ft_putstr_without(const char *s);
int					ft_find_char(char *arg, char c);
void				ft_putstr_str(char *str1, char *str2,
					char *str3, char *str4);
/*
**function_cut_add.c
*/
char				*ft_put_endpath(char *path, char *f_name);
char				*ft_take_end(char *path);
void				ft_more_six_month(char *str_time, char **str_new,
					int len, int i);
char				*ft_cut_time(char *time, long int sec);

#endif
