/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:43:50 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 20:20:47 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}
