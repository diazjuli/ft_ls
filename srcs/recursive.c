/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:28:52 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/14 09:05:34 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		if_add_recursive(char *name, mode_t mode, long modifiers)
{
	if (S_ISDIR(mode) && (modifiers & R2) && !ft_strequ(name, ".") &&
			!ft_strequ(name, "..") && (name[0] != '.' || (modifiers & A)))
		return (1);
	return (0);
}

int		print_recursive(long modifiers, t_node *list)
{
	t_node *temp;
	t_node *dir_list;

	temp = list;
	dir_list = NULL;
	list = sort_list(modifiers, list, 0);
	while (list)
	{
		if (list->file.access[0] == 'd')
		{
			b_printf("\n%s:\n", list->file.path);
			if (list->file.access[1] == 'r')
				print_dir(modifiers, list->file, dir_list);
			else
				permission_denied(list->file.path);
		}
		else
			print_file(modifiers, list->file, ".");
		free(list->file.access);
		free(list->file.path);
		list = list->next;
	}
	free_list(temp);
	return (1);
}
