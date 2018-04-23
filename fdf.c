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
	int			nb_of_lines;
	int 		fd;

	nb_of_lines = 0;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		nb_of_lines = i_will_count_lines(fd, nb_of_lines);
		printf("THERE R %d LINES IN MAP:\n", nb_of_lines);

		if(nb_of_lines != 0)
			printf("GOOD MAP!\n");
		

	}
	return (0);
}