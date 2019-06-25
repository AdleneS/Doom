/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsize.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:36:00 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:46:25 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstsize(t_list *list)
{
	int count;

	count = 0;
	if (!list)
		return (-1);
	while (list != '\0')
	{
		count++;
		list = list->next;
	}
	return (count);
}
