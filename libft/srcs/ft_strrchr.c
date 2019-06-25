/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:48:33 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:15:25 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int lastpos;

	lastpos = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			lastpos = i;
		i++;
	}
	if (lastpos >= 0)
		return ((char *)s + lastpos);
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}
