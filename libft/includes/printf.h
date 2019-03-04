/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 10:42:02 by jdiaz             #+#    #+#             */
/*   Updated: 2018/09/15 17:44:58 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_bprintf
{
	const char	*format;
	int			count;
	int			index;
	char		type_to_print;
	va_list		*ap;
}					t_bprintf;

typedef	void		(*t_func)(t_bprintf *ob);

typedef struct		s_fns
{
	char	convertor;
	t_func	fn;

}					t_fns;

char				get_hexa(unsigned int num);
int					b_printf(const char *restrict format, ...);
char				*nbase_uitoa(unsigned int num, unsigned int base);
char				*nbase_ultoa(unsigned long num, unsigned long base);
void				set_converter(t_bprintf *ob);
int					is_allowed_char(char a);
t_func				set_print_fn(t_bprintf *ob);
int					is_converter(char a);
void				reset_struct(t_bprintf *ob);
void				init_struct(t_bprintf *ob, const char *format, va_list *ap);
void				print_str(t_bprintf *ob);
void				print_char(t_bprintf *ob);
void				print_pointer(t_bprintf *ob);
void				print_int(t_bprintf *ob);
void				print_unsigned_int(t_bprintf *ob);
void				print_octal(t_bprintf *ob);
void				print_hexa(t_bprintf *ob);

#endif
