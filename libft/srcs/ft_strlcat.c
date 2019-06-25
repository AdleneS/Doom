/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:41:51 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:19:33 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		dst_len;
	size_t		src_len;

	j = 0;
	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i < (size - 1))
		dst[i++] = src[j++];
	if (size >= dst_len)
		dst[i] = '\0';
	if (dst_len > size)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
