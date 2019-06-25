/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:43:26 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:00:18 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstat(t_list *list, size_t nbr)
{
	size_t	i;
	t_list	*res;

	res = list;
	i = 1;
	while (res)
	{
		if (i == nbr)
			return (res);
		res = res->next;
		i++;
	}
	return (NULL);
}
