/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:42:48 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/13 20:51:36 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_int(t_bprintf *ob)
{
	char	*result;

	result = ft_itoa(va_arg(*(ob->ap), int));
	ft_putstr(result);
	ob->count += ft_strlen(result);
	free(result);
}

void	print_hexa(t_bprintf *ob)
{
	char			*result;
	unsigned int	base;

	if (ob->type_to_print == 'x')
		base = 16;
	else if (ob->type_to_print == 'u')
		base = 10;
	else
		base = 8;
	result = nbase_uitoa(va_arg(*(ob->ap), unsigned int), base);
	ob->count += ft_strlen(result);
	ft_putstr(result);
	free(result);
}
