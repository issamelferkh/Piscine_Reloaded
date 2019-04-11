/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:02:07 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/03/26 23:10:03 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int			ft_check_error(int ac)
{
	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	if (ac > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		i;
	int		fd;
	char	buf[BUF_SIZE];

	if (ft_check_error(ac))
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		while (read(fd, buf, BUF_SIZE) > 0)
		{
			write(1, buf, BUF_SIZE);
			i = -1;
			while (++i < BUF_SIZE)
				buf[i] = '\0';
		}
		close(fd);
	}
	return (0);
}
