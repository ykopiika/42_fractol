/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:40:39 by ykopiika          #+#    #+#             */
/*   Updated: 2019/01/11 16:40:50 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_chr(const char *s, int c)
{
	char	r;
	char	*str;
	int		i;

	str = (char*)s;
	r = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == r)
			return (&(str[i]));
		i++;
	}
	if (r == '\0')
		return (&(str[i]));
	return (NULL);
}

static t_lfd	*get_new_lst(const int fd)
{
	t_lfd	*new_lst;

	if (!(new_lst = (t_lfd*)malloc(sizeof(t_lfd))))
		return (NULL);
	ft_bzero(new_lst->s, BUFF_SIZE + 1);
	new_lst->str = NULL;
	new_lst->new_nl = NULL;
	new_lst->fd = fd;
	new_lst->rd = 0;
	new_lst->next = NULL;
	return (new_lst);
}

static t_lfd	*get_lst(t_lfd *lst, const int fd)
{
	t_lfd	*plst;

	if (!lst)
	{
		if (!(lst = (t_lfd *)malloc(sizeof(t_lfd))))
			return (NULL);
		ft_bzero(lst->s, BUFF_SIZE + 1);
		lst->str = NULL;
		lst->new_nl = NULL;
		lst->fd = fd;
		lst->rd = 0;
		lst->next = NULL;
		return (lst);
	}
	plst = lst;
	while (plst->next)
	{
		if ((plst->next)->fd == fd)
			return (plst->next);
		plst = plst->next;
	}
	plst->next = get_new_lst(fd);
	return (plst->next);
}

static void		write_line(t_lfd *lst, char **line, int fd)
{
	char	*tmp;

	while (ft_chr(lst->str, '\n') == NULL &&
		(lst->rd = read(fd, lst->s, BUFF_SIZE)) > 0)
	{
		lst->s[lst->rd] = '\0';
		tmp = lst->str;
		lst->str = ft_strjoin(tmp, &lst->s[0]);
		free(tmp);
	}
	if ((lst->new_nl = ft_chr(lst->str, '\n')) == NULL)
		lst->new_nl = ft_chr(lst->str, '\0');
	*line = ft_strsub(lst->str, 0, (lst->new_nl - lst->str));
	if (lst->new_nl && *lst->new_nl == '\n')
		ft_memmove((void*)&lst->str[0], (lst->new_nl + 1),
				ft_strlen(lst->new_nl) + 1);
	else
		ft_strdel(&lst->str);
}

int				get_next_line(const int fd, char **line)
{
	static t_lfd	*beg_lst;
	t_lfd			*lst;

	if (fd < 0 || fd > 4864 || (read(fd, NULL, 0) < 0) ||
			BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	if (!beg_lst)
	{
		beg_lst = get_lst(beg_lst, fd);
		if (beg_lst == NULL)
			return (-1);
	}
	lst = get_lst(beg_lst, fd);
	if (lst == NULL)
		return (-1);
	write_line(lst, line, fd);
	if (lst->rd == 0 && (!lst->new_nl || *lst->new_nl == 0) && *line == NULL)
		return (0);
	return (1);
}
