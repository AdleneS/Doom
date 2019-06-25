/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 15:37:53 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:47:55 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, int nb)
{
	int		i;
	int		i_src;

	i = 0;
	i_src = 0;
	while (dest[i])
		i++;
	while (i_src < nb && src[i_src] != '\0')
		dest[i++] = src[i_src++];
	dest[i] = '\0';
	return (dest);
}
