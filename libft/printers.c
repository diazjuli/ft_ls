/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:49:39 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/13 20:51:48 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_str(t_bprintf *ob)
{
	char	*to_print;

	to_print = va_arg(*(ob->ap), char *);
	if (to_print == NULL)
	{
		ft_putstr("(null)");
		ob->count += 6;
	}
	else
	{
		ft_putstr(to_print);
		ob->count += ft_strlen(to_print);
	}
}

void	print_char(t_bprintf *ob)
{
	if (ob->type_to_print == '%')
	{
		write(1, "%", 1);
	}
	else
	{
		ft_putchar(va_arg(*(ob->ap), int));
	}
	ob->count++;
}

void	print_pointer(t_bprintf *ob)
{
	unsigned long long	p;
	char				*result;

	p = (unsigned long long)va_arg(*(ob->ap), void *);
	result = nbase_ultoa(p, 16);
	ob->count += ft_strlen(result) + 2;
	ft_putstr("0x");
	ft_putstr(result);
	free(result);
}
