/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putfloat.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 13:55:51 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 14:57:10 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putfloat(float x, int p)
{
	int d;

	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	d = x;
	ft_putnbr(d);
	if (p > 0)
		ft_putchar('.');
	while (p--)
	{
		x = (x - d) * 10;
		d = x;
		ft_putnbr(d);
	}
}
