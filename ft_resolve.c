/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 08:01:24 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 09:03:04 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_resolve_2(t_filler *data, int y, int *score)
{
	int		x;

	x = -(ft_linelen(data->piece[0]));
	while (x < data->x + (int)ft_linelen(data->piece[0]))
	{
		if (ft_can_place(data, y, x))
		{
			ft_place_piece(data, y, x);
			if (ft_score(data) > *score)
			{
				*score = ft_score(data);
				data->res[0] = y;
				data->res[1] = x;
			}
			ft_remove_piece(data);
		}
		x++;
	}
}

int			ft_resolve(t_filler *data)
{
	int		y;
	int		score;

	score = -1;
	y = -(ft_tablen(data->piece));
	while (y < data->y + (int)ft_tablen(data->piece))
	{
		ft_resolve_2(data, y, &score);
		y++;
	}
	return (score);
}
