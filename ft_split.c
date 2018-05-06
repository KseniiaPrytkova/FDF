/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:33:33 by kprytkov          #+#    #+#             */
/*   Updated: 2018/04/28 19:33:34 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char			*i_will_malloc(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int			i_will_count_ws(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str && *str != ' ' && *str != '\t' && *str != '\n')
		{
			count++;
			while (*str && *str != ' ' && *str != '\t' && *str != '\n')
				str++;
		}
	}
	return (count);
}

char				**ft_split(char *str)
{
	char	**str_array;
	int		how_much_words;
	int		counter;

	how_much_words = i_will_count_ws(str);
	if (!(str_array = (char **)malloc(sizeof(char*) * (how_much_words + 1))))
		return (NULL);
	counter = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str && *str != ' ' && *str != '\t' && *str != '\n')
		{
			str_array[counter] = i_will_malloc(str);
			counter++;
			while (*str && *str != ' ' && *str != '\t' && *str != '\n')
				str++;
		}
	}
	str_array[counter] = NULL;
	return (str_array);
}
