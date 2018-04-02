#include "filler.h"

static int	ft_radius(t_filler *data, int y, int x, char c)
{
	int score;
	int border;
	char **map;

	map = data->map;
	score = 0;
	border = (y + 1 >= data->y) + (x + 1 >= data->y)
		+ (x + 1 >= data->y && y + 1 >= data->y);
	border += (y - 1 < 0) + (x - 1 < 0) + (x - 1 < 0 && y - 1 < 0);
	if (c == 'M')
		return (border);
	if (y + 1 < data->y && map[y + 1][x] == c)
		score++;
	if (x + 1 < data->x && map[y][x + 1] == c)
		score++;
	if (x + 1 < data->x && y + 1 > data->y && map[y + 1][x + 1] == c)
		score++;
	if (y - 1 >= 0 && map[y - 1][x] == c)
		score++;
	if (x - 1 >= 0 && map[y][x - 1] == c)
		score++;
	if (x - 1 >= 0 && y - 1 >= 0 && map[y - 1][x - 1] == c)
		score++;
	return (score);
}

static int	ft_calculator(t_filler *data, int y, int x)
{
	int		score;

	score = 0;
	score += ft_radius(data, y, x, data->player2) * 20;
	score += ft_radius(data, y, x, data->player) * 4;
	score += ft_radius(data, y, x, '.') * 4;
	score += ft_radius(data, y, x, 'M') * 4;
			
	return (score);
}

int			ft_score(t_filler *data)
{
	int		score;
	int		y;
	int		x;

	score = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '*')
				score += ft_calculator(data, y, x);
			x++;
		}
		y++;		
	}
	return (score);
}
