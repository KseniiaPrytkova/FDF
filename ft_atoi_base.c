/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:03:58 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/04 18:03:59 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	i_will_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * i_will_power(nb, power - 1));
}

static int	is_correct_input(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else if (c >= 'A' && c <= 'Z')
		return (3);
	else
		return (0);
}

static int	i_will_convert(char c, int base)
{
	int		result;
	int		is_correct;

	result = 0;
	is_correct = 0;
	is_correct = is_correct_input(c);
	if (is_correct == 1)
		result = c - 48;
	else if (is_correct == 2)
		result = c - 97 + 10;
	else if (is_correct == 3)
		result = c - 65 + 10;
	else
		result = -1;
	if (result < base && result != -1)
		return (result);
	else
		return (-1);
}

static int	length_number(char *str)
{
	int		counter;

	counter = 0;
	while (str[counter])
	{
		if (is_correct_input(str[counter]) == 0)
			break ;
		counter++;
	}
	return (counter);
}

int			ft_atoi_base(char *nb, int base)
{
	int		result;
	int		length;
	int		i;

	i = 0;
	result = 0;
	if (base == 10)
		return (ft_atoi(nb));
	while ((nb[i] == ' ') || (nb[i] == '\n') || (nb[i] == '\t'))
		i++;
	length = length_number(nb) - 1;
	while (*nb && length >= 0 && i_will_convert(*nb, base) != -1)
	{
		result += i_will_convert(*nb, base) * i_will_power(base, length);
		nb++;
		length--;
	}
	return (result);
}
