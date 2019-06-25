/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 12:01:36 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:53:22 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	if (!n)
		return (0);
	i = 0;
	j = 1;
	while ((j != n) && (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'))
	{
		j++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
