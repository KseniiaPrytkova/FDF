#include "fdf.h"

static t_point *map_maker(char **after_split, int y, t_env *e)
{
	int		i;
	t_point *map_line;

	i = 0;
	map_line = (t_point*)malloc(sizeof(t_point) * e->p_nb);
	while (i < e->p_nb)
	{
		map_line[i].x = i;
		map_line[i].y = y;
		map_line[i].z = ft_atoi(after_split[i]);
		map_line[i].x_before = i;
		map_line[i].y_before = y;
		map_line[i].z_before = map_line[i].z;
		i++;
	}
	return (map_line);
}

void i_will_read(t_env *e)
{
	char	*line;
	char **after_split;
	int counter;
	char ch;


	counter = 0;
	if (!(e->map = (t_point **)malloc(sizeof(t_point *) * e->l_nb + 1)))
		return ;
	while (counter < e->l_nb)
	{

		get_next_line(e->fd, &line);
		after_split = ft_split(line);
		e->map[counter] = map_maker(after_split, counter, e);
		counter++;
	}
	e->map[e->l_nb] = NULL;
}