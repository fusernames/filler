#include "filler.h"

int		ft_resolve(t_filler *data)
{	
	int		y;
	int		x;
	int		score;

	score = -1;
	y = 1 - ft_tablen(data->piece);
	while (y < data->y + (int)ft_tablen(data->piece))
	{
		y++;
		x = 1 - ft_linelen(data->piece[0]);
		while (x < data->x + (int)ft_linelen(data->piece[0]))
		{
			if (ft_can_place(data, y, x))
			{
				ft_place_piece(data, y, x);
				if (ft_score(data) > score)
				{	
					score = ft_score(data);
					data->res[0] = y;
					data->res[1] = x;
				}
				ft_remove_piece(data);
			}
			x++;
		}
	}
	return (score);
}
