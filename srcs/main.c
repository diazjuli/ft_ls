/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:43:24 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/14 17:36:15 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	free_list(t_node *list)
{
	t_node *temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

void	ft_ls(long modifiers, int count, char **args)
{
	struct stat buf;
	t_node		*list;
	int			i;

	i = -1;
	list = NULL;
	lstat(".", &buf);
	if (count == 0)
		list = add_to_list(".", buf, list);
	while (++i < count)
	{
		if (lstat(args[i], &buf) == -1)
		{
			ft_putstr("ls: ");
			ft_putstr(args[i]);
			ft_putstr(": No such file or directory\n");
		}
		else
			list = add_to_list(args[i], buf, list);
	}
	list = sort_list(modifiers, list, count);
	print_list(modifiers, list, count);
}

int		main(int argc, char **argv)
{
	long	modifiers;
	int		i;
	int		j;

	i = 0;
	modifiers = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][++j] != '\0')
		{
			modifiers = get_flags(argv[i][j], modifiers);
			if (ft_strchr("arltRufgd", argv[i][j]) == NULL)
			{
				ft_putstr("ls: illegal option -- ");
				ft_putchar(argv[i][j]);
				ft_putstr("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrst");
				ft_putstr("uwx1] [file ...]\n");
				exit(0);
			}
		}
	}
	ft_ls(modifiers, argc - i, argv + i);
}
