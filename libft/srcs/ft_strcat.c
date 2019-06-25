/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 14:49:53 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:29:37 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		i_src;

	i = 0;
	i_src = 0;
	while (dest[i])
		i++;
	while (src[i_src])
		dest[i++] = src[i_src++];
	dest[i] = '\0';
	return (dest);
}
