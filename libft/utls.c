/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:35:15 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/13 20:52:06 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_converter(char a)
{
	if (ft_strchr("diouxspc", a) != NULL)
		return (1);
	else if (a == '%')
		return (2);
	else
		return (0);
}

int		is_allowed_char(char a)
{
	if (a == '\0')
		return (0);
	if (ft_strchr("", a) != NULL)
		return (1);
	else if (ft_isdigit(a) == 1)
		return (1);
	else if (is_converter(a) != 0)
		return (1);
	else
		return (0);
}

void	set_converter(t_bprintf *ob)
{
	char a;

	a = ob->format[ob->index];
	while (is_allowed_char(a) == 1 && is_converter(a) == 0)
	{
		ob->index++;
		a = ob->format[ob->index];
	}
}

void	reset_struct(t_bprintf *ob)
{
	ob->type_to_print = '\0';
}

void	init_struct(t_bprintf *ob, const char *format, va_list *ap)
{
	ob->format = format;
	ob->count = 0;
	ob->index = 0;
	ob->ap = ap;
	reset_struct(ob);
}
