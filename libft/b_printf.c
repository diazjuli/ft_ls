/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 20:08:50 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/13 20:59:42 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**calls set_converter if there are any precision characters before the convertor
**set conversion type in ob
**set print function by calling function dispatcher then print conversion
*/

void	conversion(t_bprintf *ob)
{
	void	(*printfn)(t_bprintf*);

	set_converter(ob);
	ob->type_to_print = ob->format[ob->index];
	printfn = set_print_fn(ob);
	if (printfn != NULL)
		printfn(ob);
	else
		ob->index--;
}

/*
**print out characters in string until a % if found, if % is found
**reset structure ob and call conversion function
*/

int		print_conv(t_bprintf *ob)
{
	while (ob->format[ob->index] != '\0')
	{
		if (ob->format[ob->index] == '%')
		{
			ob->index++;
			reset_struct(ob);
			conversion(ob);
		}
		else
		{
			write(1, &(ob->format[ob->index]), 1);
			ob->count++;
		}
		if (ob->format[ob->index] != '\0')
			ob->index++;
	}
	return (ob->count);
}

/*
**create and initialize va_list and structure ob, then call print
*/

int		b_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_bprintf	ob;

	va_start(ap, format);
	init_struct(&ob, format, &ap);
	print_conv(&ob);
	va_end(ap);
	return (ob.count);
}
