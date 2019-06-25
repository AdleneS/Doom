/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:24:24 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:17:59 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t count;

	i = 0;
	count = 0;
	while (needle[count] != '\0')
		count++;
	if (needle && count > 0)
	{
		while (haystack[i] != '\0')
		{
			j = 0;
			while (needle[j] == haystack[i + j])
			{
				if (j == count - 1 && (i + j < len))
					return ((char *)haystack + i);
				j++;
			}
			i++;
		}
	}
	else
		return ((char *)haystack);
	return (0);
}
