/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:20:54 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:45:46 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	len;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (len--)
		f(&s[len]);
}
