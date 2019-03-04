/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:16:17 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/14 10:02:17 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_max(char *print, int length, int num)
{
	int i;

	i = 0;
	p_w(num);
	while (print[i] && i < length)
	{
		ft_putchar(print[i]);
		i++;
	}
}

int		p_w(int num)
{
	int temp;
	int length;

	length = 0;
	temp = num;
	while (num)
	{
		num = num / 10;
		length++;
	}
	while (length < 5)
	{
		ft_putchar(' ');
		length++;
	}
	ft_putnbr(temp);
	ft_putchar(' ');
	return (temp);
}

void	permission_denied(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": Permission denied\n");
}

t_node	*add_tail(char *path, struct stat buf, t_node *list)
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

long	get_flags(char flag, long modifiers)
{
	modifiers = flag == 'a' ? modifiers | A : modifiers;
	modifiers = flag == 't' ? modifiers | T : modifiers;
	modifiers = flag == 'l' ? modifiers | L : modifiers;
	modifiers = flag == 'r' ? modifiers | R : modifiers;
	modifiers = flag == 'R' ? modifiers | R2 : modifiers;
	modifiers = flag == 'u' ? modifiers | U : modifiers;
	modifiers = flag == 'f' ? modifiers | F : modifiers;
	modifiers = flag == 'g' ? modifiers | G : modifiers;
	modifiers = flag == 'd' ? modifiers | D : modifiers;
	return (modifiers);
}
