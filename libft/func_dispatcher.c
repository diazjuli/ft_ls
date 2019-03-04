/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 20:38:43 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/13 20:52:30 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_func	set_print_fn(t_bprintf *ob)
{
	int				i;
	static	t_fns	fns[9] = {
		{ .convertor = 's', .fn = print_str },
		{ .convertor = 'c', .fn = print_char },
		{ .convertor = 'p', .fn = print_pointer },
		{ .convertor = 'd', .fn = print_int },
		{ .convertor = 'i', .fn = print_int },
		{ .convertor = 'u', .fn = print_hexa },
		{ .convertor = 'x', .fn = print_hexa },
		{ .convertor = 'o', .fn = print_hexa },
		{ .convertor = '%', .fn = print_char }};

	i = -1;
	while (++i < 9)
		if (ob->type_to_print == fns[i].convertor)
			return (fns[i].fn);
	return (NULL);
}
