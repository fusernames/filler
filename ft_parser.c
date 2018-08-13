/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 08:05:16 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 08:09:07 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*ft_parser_launch(void)
{
	char		*line;
	t_filler	*data;
	char		**tab;

	data = malloc(sizeof(t_filler));
	get_next_line(0, &line);
	if (line[10] == '1')
	{
		data->player = 'O';
		data->player2 = 'X';
	}
	else
	{
		data->player = 'X';
		data->player2 = 'O';
	}
	get_next_line(0, &line);
	tab = ft_splitwhitespace(&line[7]);
	data->y = ft_atoi(tab[0]);
	data->x = ft_atoi(tab[1]);
	ft_tabfree(tab);
	return (data);
}

int			ft_parser_map(t_filler *data)
{
	char	*line;
	int		i;

	data->map = malloc(sizeof(char *) * data->y + 1);
	data->map[data->y] = NULL;
	i = 0;
	while (i < data->y)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
			data->map[i++] = ft_strdup(&line[4]);
	}
	return (0);
}

int			ft_parser_piece(t_filler *data)
{
	char	*line;
	char	**tab;
	int		i;
	int		y;
	int		x;

	get_next_line(0, &line);
	tab = ft_splitwhitespace(&line[6]);
	y = ft_atoi(tab[0]);
	x = ft_atoi(tab[1]);
	data->piece = malloc(sizeof(char *) * y + 1);
	data->piece[y] = NULL;
	i = 0;
	while (i < y)
	{
		get_next_line(0, &line);
		data->piece[i++] = ft_strdup(line);
	}
	ft_tabfree(tab);
	return (0);
}
