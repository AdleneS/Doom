/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:31:57 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 13:00:22 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_contain_space(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*new_str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (ft_contain_space(s[len - 1]))
		len--;
	while (ft_contain_space(s[i]))
	{
		i++;
		len--;
	}
	if (len <= 0)
		len = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s = s + i;
	i = 0;
	while (i < len)
		new_str[i++] = *s++;
	new_str[i] = '\0';
	return (new_str);
}
