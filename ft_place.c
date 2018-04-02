#include "filler.h"

int		ft_remove_piece(t_filler *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '*')
				data->map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_place_piece(t_filler *data, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (data->piece[i])
	{
		j = 0;
		while (data->piece[i][j])
		{
			if (data->piece[i][j] == '*' && data->map[y + i][x + j] == '.')
			data->map[y + i][x + j] = '*';
			j++;
		}
		i++;
	}
	return (0);
}
