/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:52:58 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 14:33:40 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	if (!(join = (char *)malloc((sizeof(char) * (s1_len + s2_len)) + 1)))
		return (NULL);
	while (i < s1_len && (size_t)-1 != i++)
		join[i - 1] = s1[i - 1];
	while (i < (s1_len + s2_len))
	{
		join[i] = s2[j];
		j++;
		i++;
	}
	join[i] = '\0';
	return (join);
}
