/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:16:19 by kprytkov          #+#    #+#             */
/*   Updated: 2018/04/18 18:16:20 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "get_next_line.h"

int		get_next_line(const int fd, char **line);
int		i_will_count_lines(int fd, int nb_of_lines);


#endif