/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:45:25 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 16:04:16 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*alloc;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	alloc = (char *)malloc(sizeof(char) * len + 1);
	if (!alloc)
		return (NULL);
	while (i < len)
	{
		alloc[i] = f(i, s[i]);
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}
