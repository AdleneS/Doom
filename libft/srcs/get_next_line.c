/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slopez <slopez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 12:08:11 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 16:42:54 by slopez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static t_gnl	*find_file(t_gnl **list, int fd)
{
	t_gnl		*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	tmp->save = ft_strnew(BUFF_SIZE);
	tmp->fd = fd;
	tmp->next = NULL;
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static void		ft_del_after_occ(char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			s[i] = 0;
}

static int		process_file(char *s, char **line)
{
	char	*tmp_dup_s;
	char	*tmp_line;

	if (ft_strrchr(s, '\n'))
	{
		tmp_dup_s = ft_strdup(s);
		s = ft_strcpy(s, ft_strchr(s, '\n') + 1);
		ft_del_after_occ(tmp_dup_s, 10);
		tmp_line = *line;
		*line = ft_strjoin(tmp_line, tmp_dup_s);
		free(tmp_dup_s);
		free(tmp_line);
		return (1);
	}
	else
	{
		tmp_line = *line;
		*line = ft_strjoin(tmp_line, s);
		free(tmp_line);
		ft_bzero(s, BUFF_SIZE);
		return (0);
	}
}

int				get_next_line(const int fd, char **line)
{
	int				rd;
	static t_gnl	*lst;
	t_gnl			*file;

	file = find_file(&lst, fd);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!file->save)
		file->save = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (*file->save)
		if (process_file(file->save, line))
			return (1);
	ft_bzero(file->save, BUFF_SIZE);
	while ((rd = read(fd, file->save, BUFF_SIZE)))
	{
		if (rd < 0)
			return (-1);
		if (process_file(file->save, line))
			return (1);
	}
	return (**line ? 1 : 0);
}
