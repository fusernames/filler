/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 08:06:29 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 08:07:29 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_can_place(t_filler *d, int y, int x)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	nb = 0;
	while (d->piece[i])
	{
		j = 0;
		while (d->piece[i][j])
		{
			if (d->piece[i][j] == '*')
			{
				if (i + y < 0 || i + y >= d->y || j + x < 0 || j + x >= d->x)
					return (0);
				else if (d->map[i + y][j + x] == d->player2)
					return (0);
				else if (d->map[i + y][j + x] == d->player)
					nb++;
			}
			j++;
		}
		i++;
	}
	return (nb == 1 ? 1 : 0);
}
