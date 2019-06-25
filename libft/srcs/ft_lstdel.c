/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:53:20 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 15:17:52 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	lst = *alst;
	while (lst)
	{
		del(lst->content, lst->content_size);
		free(lst);
		lst = lst->next;
	}
	*alst = NULL;
}
