/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:52:41 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/14 10:02:15 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*get_buf(t_file file, char *dir)
{
	char			*path;
	char			*temp;

	temp = ft_strjoin(dir, "/");
	path = ft_strjoin(temp, file.path);
	free(temp);
	return (path);
}

void	print_file(long modifiers, t_file file, char *dir)
{
	char			*path;
	char *restrict	buf;

	buf = (char *)malloc(10000);
	path = get_buf(file, dir);
	readlink(path, buf, 9999);
	if (file.path[0] != '.' || modifiers & A)
	{
		if (modifiers & L)
		{
			b_printf("%s %d ", file.access, file.num_links);
			b_printf("%s ", getpwuid(file.user_id)->pw_name);
			b_printf("%s ", getgrgid(file.group_id)->gr_name);
			print_max(ctime(&file.mod_time) + 4, 12, file.size);
			b_printf(" %s", file.path);
			if (file.access[0] == 'l')
				b_printf(" -> %s\n", buf);
			else
				ft_putstr("\n");
		}
		else
			b_printf("%s\n", file.path);
	}
	free(path);
	free(buf);
}

void	print(long modifiers, t_node *list, t_file dir, DIR *thisdir)
{
	t_node *temp;

	list = sort_list(modifiers, list, 0);
	if (modifiers & L)
		b_printf("total %d\n", dir.dirblocks);
	temp = list;
	while (list)
	{
		print_file(modifiers, list->file, dir.path);
		free(list->file.access);
		free(list->file.path);
		list = list->next;
	}
	free_list(temp);
	closedir(thisdir);
}

int		print_dir(long modifiers, t_file file, t_node *dir_list)
{
	DIR				*thisdir;
	struct dirent	*curr_file;
	struct stat		buf;
	char			*path;
	t_node			*list;

	if ((thisdir = opendir(file.path)) == NULL)
		return (-1);
	list = NULL;
	file.dirblocks = 0;
	while ((curr_file = readdir(thisdir)) != NULL)
	{
		path = ft_strcat(ft_strcat(ft_strnew(400), file.path), "/");
		path = ft_strcat(path, curr_file->d_name);
		if (lstat(path, &buf) == -1)
			return (-1);
		dir_list = add_to_list(ft_strdup(curr_file->d_name), buf, dir_list);
		if (if_add_recursive(curr_file->d_name, buf.st_mode, modifiers))
			list = add_tail(ft_strdup(path), buf, list);
		if (dir_list->file.path[0] != '.' || modifiers & A)
			file.dirblocks += dir_list->file.dirblocks;
		free(path);
	}
	print(modifiers, dir_list, file, thisdir);
	return (print_recursive(modifiers, list));
}

void	print_list(long modifiers, t_node *list, int count)
{
	t_node *temp;
	t_node *dir_list;

	temp = list;
	dir_list = NULL;
	while (list)
	{
		if (list->file.access[0] == 'd')
		{
			if (count < 0)
				b_printf("\n%s:\n", list->file.path);
			else if (count > 1)
				b_printf("%s:\n", list->file.path);
			if (list->file.access[1] == 'r')
				print_dir(modifiers, list->file, dir_list);
			else
				permission_denied(list->file.path);
		}
		else
			print_file(modifiers, list->file, ".");
		count = -1;
		free(list->file.access);
		list = list->next;
	}
	free_list(temp);
}
