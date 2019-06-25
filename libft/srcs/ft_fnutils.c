/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fnutils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 12:35:32 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 12:36:09 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_file_isspecial(char *name)
{
	if (ft_strlen(name) == 1 && name[0] == '.')
		return (1);
	if (ft_strlen(name) == 2 && name[0] == '.' && name[1] == '.')
		return (1);
	return (0);
}

int		ft_file_ishidden(char *name)
{
	if (name[0] == '.' || ft_file_isspecial(name))
		return (1);
	return (0);
}
