/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:36:16 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/24 16:36:19 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_clean(t_list **head, t_list *current)
{
	t_list	*temp;

	if (*head == NULL || current == NULL)
		return ;
	if (current == *head)
		*head = (*head)->next;
	else
	{
		temp = *head;
		while (temp != NULL && temp->next != current)
			temp = temp->next;
		if (temp != NULL)
			temp->next = current->next;
	}
	free(current->content);
	free(current);
}

char	*ft_read(int fd, char *saved, char *buf)
{
	char	*temp;
	ssize_t	octets;

	octets = 1;
	while (!ft_strlen_newline(saved, 1))
	{
		octets = read(fd, buf, BUFFER_SIZE);
		if (octets <= 0)
		{
			free(buf);
			if (octets < 0 || saved == NULL || saved[0] == '\0')
			{
				free(saved);
				return (NULL);
			}
			return (saved);
		}
		buf[octets] = '\0';
		temp = ft_strjoin(saved, buf);
		free(saved);
		saved = temp;
	}
	free(buf);
	return (saved);
}

char	*ft_conserve(char *saved)
{
	int		i;
	int		length;
	char	*stock;

	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	if (saved[i] == '\n')
		i++;
	length = ft_strlen_newline(saved, 0) - i;
	stock = ft_substr(saved, i, length);
	if (!stock)
		return (NULL);
	free(saved);
	return (stock);
}

t_list	*find_fd(t_list **head, int fd)
{
	t_list	*current;
	t_list	*new;

	current = *head;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->content[0] = '\0';
	new->next = *head;
	*head = new;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*current;
	char			*line;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	current = find_fd(&head, fd);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || !current)
		return (NULL);
	current->content = ft_read(fd, current->content, buf);
	if (current->content != NULL && current->content[0] != '\0')
	{
		line = ft_getline(current->content);
		current->content = ft_conserve(current->content);
	}
	else
		ft_clean(&head, current);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd, fd1;
	char	*line;

	fd = open("empty.txt", O_RDONLY);
	fd1 = open("1char.txt", O_RDONLY);
	if (fd == -1 || fd1 == -1)
		return (1);
	line = get_next_line(fd);
	printf("fd : %s", line);
	free(line);
	line = get_next_line(1000);
	printf("fd1 : %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("fd : %s", line);
	free(line);
		line = get_next_line(fd);
	printf("fd : %s", line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("fd : %s", line);
		free(line);

		line = get_next_line(fd1);
		if (line == NULL)
			break;
		printf("fd1 : %s", line);
		free(line);
	}
	close(fd);
	close(fd1);
}*/
