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
	int		fd;
	char	*line;

	*line = 'a';
	while (*line ==	'a')
	{
		*line = 'b';
		fd = open("test", O_RDWR|O_APPEND|O_CREAT, 0666);
		while (line)
		{
			get_next_line(0, &line);
			write(fd, line, ft_strlen(line));
		}
		close(fd);
		write(1, "8 2\n", 4);
	}
	return (0);
}
