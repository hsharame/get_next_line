/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:36:26 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/24 16:36:28 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_conserve(char *saved);
char	*ft_read(int fd, char *saved, char *buf);
t_list	*find_fd(t_list **head, int fd);
void	ft_clean(t_list **head, t_list *current);

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_newline(const char *s, int new);
char	*ft_getline(char *saved);

#endif
