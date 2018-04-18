/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:16:09 by kprytkov          #+#    #+#             */
/*   Updated: 2018/04/18 18:16:10 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int		fd;
		int		ret;
		char	*line;
		int		counter;
		int		len_absolute;
		int		len_relative;

		int		first_time;

		fd = open(arg[1], O_RDONLY);
		ret = 0;
		counter = 0;
		first_time = 0;
		len_absolute = 0;
		while (ret = get_next_line(fd, &line))
		{
			counter++;
			if (first_time == 0)
			{
				len_absolute = ft_strlen(line);
				first_time = 1;
			}
			if (ft_strlen(line) != len_absolute)
			{
				ft_putstr("usage: invalid_map\n");
				return (0);
			}

		}
		printf("%i\n", counter );
		close(fd);

	}
	return (0);
}