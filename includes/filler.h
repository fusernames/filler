/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 05:58:11 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 08:12:06 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_filler{
	int		x;
	int		y;
	char	player;
	char	player2;
	char	**map;
	char	**piece;
	int		res[2];
}				t_filler;

t_filler		*ft_parser_launch(void);
int				ft_parser_map(t_filler *data);
int				ft_parser_piece(t_filler *data);

int				ft_resolve(t_filler *data);
int				ft_score(t_filler *data);
int				ft_can_place(t_filler *data, int y, int x);
int				ft_place_piece(t_filler *data, int y, int x);
int				ft_remove_piece(t_filler *data);

#endif
