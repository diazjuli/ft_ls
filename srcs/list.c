/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:57:05 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/14 09:02:40 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*get_access(mode_t mode)
{
	char	*access;

	access = (char *)malloc(11);
	access[0] = S_ISDIR(mode) == 1 ? 'd' : '-';
	access[0] = S_ISLNK(mode) == 1 ? 'l' : access[0];
	access[1] = S_IRUSR & mode ? 'r' : '-';
	access[2] = S_IWUSR & mode ? 'w' : '-';
	access[3] = S_IXUSR & mode ? 'x' : '-';
	access[3] = S_ISUID & mode ? 'S' : access[3];
	access[4] = S_IRGRP & mode ? 'r' : '-';
	access[5] = S_IWGRP & mode ? 'w' : '-';
	access[6] = S_IXGRP & mode ? 'x' : '-';
	access[6] = S_ISGID & mode ? 'S' : access[6];
	access[7] = S_IROTH & mode ? 'r' : '-';
	access[8] = S_IWOTH & mode ? 'w' : '-';
	access[9] = S_IXOTH & mode ? 'x' : '-';
	access[9] = S_ISVTX & mode ? 'T' : access[9];
	access[10] = '\0';
	return (access);
}

t_node	*add_to_list(char *path, struct stat buf, t_node *list)
{
	t_node	*to_add;
	t_file	new;

	to_add = (t_node *)malloc(sizeof(t_node));
	new.path = path;
	new.mode = buf.st_mode;
	new.num_links = (int)buf.st_nlink;
	new.user_id = buf.st_uid;
	new.group_id = buf.st_gid;
	new.mod_time = buf.st_mtime;
	new.time_spec = buf.st_mtimespec;
	new.size = (int)buf.st_size;
	new.dirblocks = (int)buf.st_blocks;
	new.access = get_access(buf.st_mode);
	to_add->file = new;
	to_add->next = list;
	return (to_add);
}

int		file_cmp(long modifiers, t_file a, t_file b, int mode)
{
	int result;

	if (mode != 0 && S_ISDIR(a.mode) != S_ISDIR(b.mode))
		result = S_ISDIR(a.mode) ? 1 : -1;
	else
	{
		result = ft_strcmp(a.path, b.path);
		if (modifiers & T)
		{
			if (a.time_spec.tv_sec - b.time_spec.tv_sec != 0)
				result = b.time_spec.tv_sec - a.time_spec.tv_sec;
			else
				result = b.time_spec.tv_nsec - a.time_spec.tv_nsec;
		}
		if (modifiers & R)
			result = -result;
	}
	return (result);
}

t_node	*sort_list(long modifiers, t_node *list, int mode)
{
	t_node	*cpy;
	t_file	tmp;

	cpy = list;
	while (cpy && cpy->next)
	{
		if (file_cmp(modifiers, cpy->file, cpy->next->file, mode) > 0)
		{
			tmp = cpy->next->file;
			cpy->next->file = cpy->file;
			cpy->file = tmp;
			cpy = list;
		}
		else
			cpy = cpy->next;
	}
	return (list);
}
