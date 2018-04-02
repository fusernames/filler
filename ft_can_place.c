#include "filler.h"

int			ft_can_place(t_filler *data, int y, int x)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	nb = 0;
	while(data->piece[i])
	{
		j = 0;
		while(data->piece[i][j])
		{
			if (data->piece[i][j] == '*')
			{
				if (i + y < 0 || i + y >= data->y || j + x < 0
					|| j + x >= data->x)
					return (0);
				else if (data->map[i + y][j + x] == data->player2)
					return (0);
				else if (data->map[i + y][j + x] == data->player)
					nb++;
			}
			j++;
		}
		i++;
	}
	return (nb == 1 ? 1 : 0);
}
