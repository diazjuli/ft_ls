/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:18:13 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/13 17:24:22 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#includes <ft_ls.h>

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
