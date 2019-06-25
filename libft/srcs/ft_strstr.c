/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 10:46:55 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:23:41 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strstr(char const *haystack, const char *needle)
{
	int i;
	int j;
	int count;

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
				if (j == count - 1)
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
