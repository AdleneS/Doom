/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:56:17 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:29:44 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*alloc;

	if (!(alloc = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	ft_strcpy(alloc, src);
	return (alloc);
}
