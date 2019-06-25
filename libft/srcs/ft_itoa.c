/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:02:43 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 16:32:17 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa(long long int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_intlen(n);
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	if (n < 0)
		n *= -1;
	str[i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}
