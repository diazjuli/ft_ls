/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:37:00 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/14 10:00:29 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# define A 1
# define T 2
# define L 4
# define R 8
# define R2 16
# define U 32
# define F 64
# define G 128
# define D 256

typedef	struct			s_file
{
	char			*path;
	char			*access;
	mode_t			mode;
	int				num_links;
	uid_t			user_id;
	gid_t			group_id;
	time_t			mod_time;
	struct timespec	time_spec;
	int				size;
	int				dirblocks;
}						t_file;

typedef	struct			s_node
{
	struct s_node	*next;
	t_file			file;
}						t_node;

t_node					*add_to_list(char *path, struct stat buf, t_node *list);
t_node					*sort_list(long modifiers, t_node *list, int mode);
void					print_list(long modifiers, t_node *list, int count);
void					free_list(t_node *list);
t_node					*get_stat(char *name, t_file file, t_node *list);
t_node					*add_tail(char *path, struct stat buf, t_node *list);
char					*get_access(mode_t mode);
long					get_flags(char flag, long modifiers);
void					free_list(t_node *list);
int						if_add_recursive(char *name, mode_t mode,
		long modifiers);
int						print_recursive(long modifiers, t_node *list);
int						print_dir(long modifiers, t_file file,
		t_node *dir_list);
void					print_file(long modifiers, t_file file, char *dir);
void					permission_denied(char *path);
void					print_max(char *print, int length, int num);
int						p_w(int num);

#endif
