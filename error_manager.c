/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:07:24 by kprytkov          #+#    #+#             */
/*   Updated: 2018/04/18 19:07:25 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int 			is_number(char *str)
{
	int			i;
	char		ch;
	char 		*hex_box;

	int j = 0;

	i = 0;
	ch = 0;
	while (str[i] != '\0')
	{
		ch = *str;
		if (ch == ' ' || ch == '\t' || ch == '\n')
			str++;
		else if ((ch >= '0' && ch <= '9') || ch == '-')
			str++;
		else if (ch == ',' && (*(str + 1) == '0'))
		{
			printf("IT'S HEX!\n");
			while (*str && *str != ' ' && *str != '\t' && *str != '\n')
				str++;
		}

		else
		{
			ft_putstr("usage: INVALID_MAP[i understand numbers only!]\n");
			return (0);
		}
	}
	return (1);
}

int				i_will_count_lines(t_env *e)
{
	size_t		len_absolute;
	size_t		len_relative;
	int			first_time;
	char		*line;

	len_absolute = 0;
	len_relative = 0;
	first_time = 0;
	while (get_next_line(e->fd, &line))
	{
		if (is_number(line) == 0)
			return (0);
		if (first_time == 0)
		{
			len_absolute = ft_wordcount(line, ' ');
			first_time = 1;
		}
		else
		{
			len_relative = ft_wordcount(line, ' ');
			if (len_relative != len_absolute)
			{
				ft_putstr("usage: INVALID_MAP[different number of characters in lines!]\n");
				return (0);
			}
			else
				e->p_nb = len_absolute;
		}
		free(line);
		e->l_nb++;
	}
	close(e->fd);
	return (1);
}
