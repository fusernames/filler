/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 06:00:01 by alcaroff          #+#    #+#             */
/*   Updated: 2018/02/14 07:10:19 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("test", O_RDWR|O_APPEND|O_CREAT, 0666);
	while ((get_next_line(1, &line)) > 0)
	{
		write(fd, line, ft_strlen(line));
	}
	return (0);
}
