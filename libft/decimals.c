/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:37:28 by jdiaz             #+#    #+#             */
/*   Updated: 2018/11/13 21:02:22 by jdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	get_hexa(unsigned int num)
{
	if (num < 10)
		return (num + '0');
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else
		return ('f');
}

int		ft_uilength(unsigned int n, unsigned int base)
{
	int length;

	length = 1;
	while (n / base != 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

int		ft_lulength(unsigned long n, unsigned long base)
{
	int length;

	length = 1;
	while (n / base != 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

char	*nbase_ultoa(unsigned long num, unsigned long base)
{
	char	*result;
	int		length;

	length = ft_lulength(num, base);
	result = (char *)malloc(sizeof(char) * length + 1);
	if (!result)
		return (NULL);
	result[length--] = '\0';
	while (num / base != 0)
	{
		result[length--] = get_hexa(num % base);
		num = num / base;
	}
	result[0] = get_hexa(num % base);
	return (result);
}
