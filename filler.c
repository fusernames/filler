/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:00:01 by alcaroff          #+#    #+#             */
/*   Updated: 2018/02/19 13:19:07 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*data;
	int			ret;

	data = ft_parser_launch();
	while (1)
	{
		ft_parser_map(data);
		ft_parser_piece(data);
		data->res[0] = 0;
		data->res[1] = 0;
		ret = ft_resolve(data);
		ft_putstr(ft_itoa(data->res[0]));
		ft_putchar(' ');
		ft_putstr(ft_itoa(data->res[1]));
		ft_putchar('\n');
		ft_tabfree(data->map);
		ft_tabfree(data->piece);
		if (ret == -1)
			break;
	}
	free(data);
	return (0);
}
