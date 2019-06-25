/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 19:08:15 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 19:24:38 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_errmalloc(void)
{
	ft_error("memory allocation has failed. Exiting.");
}

void	ft_errusage(char *name, char *str)
{
	ft_putstr(name);
	ft_putstr(": ");
	ft_error(str);
}

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}
