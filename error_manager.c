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

#include "./includes/fdf.h"

int		is_it_hex(char *str)
{
	unsigned char	ch;
	int				i;

	i = 0;
	if (*str == '0' && *(str + 1) == 'x')
	{
		str = str + 2;
		while (*str)
		{
			ch = (unsigned char)*str;
			if (ft_isalnum((int)ch) != 1)
				return (0);
			str++;
		}
		return (1);
	}
	else
		return (0);
}

static void			i_will_echo(int nb)
{
	if (nb == 1)
		ft_putstr("usage: INVALID_MAP[diff nb of characters in lines!]\n");
	else if (nb == 2)
		ft_putstr("usage: INVALID_MAP[give me numbers only(hex && dec)]\n");
}

static int			is_number(char *str)
{
	int				i;
	char			ch;

	i = 0;
	ch = 0;
	while (str[i] != '\0')
	{
		ch = *str;
		if (ch == ' ' || ch == '\t' || ch == '\n')
			str++;
		else if ((ch >= '0' && ch <= '9') || ch == '-')
			str++;
		else if (ch == ',' && (*(str + 1) == '0')
			&& (*(str + 2) == 'x' || *(str + 2) == 'X'))
		{
			while (*str && *str != ' ' && *str != '\t' && *str != '\n')
				str++;
		}
		else
		{
			i_will_echo(2);
			return (0);
		}
	}
	return (1);
}

static int			helper_for_counter(int abs, int rel, char *line, t_env *e)
{
	rel = ft_wordcount(line, ' ');
	if (rel != abs)
	{
		i_will_echo(1);
		return (0);
	}
	else
		e->p_nb = abs;
	return (1);
}

int					i_will_count_lines(t_env *e)
{
	size_t			len_absolute;
	size_t			len_relative;
	int				first_time;
	char			*line;

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
		else if (!(helper_for_counter(len_absolute, len_relative, line, e)))
			return (0);
		free(line);
		e->l_nb++;
	}
	close(e->fd);
	return (1);
}
