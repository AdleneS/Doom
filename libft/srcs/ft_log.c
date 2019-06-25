/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_log.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 17:50:36 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 17:59:36 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_log(char *file, char *str)
{
	int		fd;

	fd = open(file, O_WRONLY | O_APPEND | O_CREAT);
	ft_putstr_fd(str, fd);
	close(fd);
}
