/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamelialaksi <kamelialaksi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:18:37 by klaksi            #+#    #+#             */
/*   Updated: 2022/11/13 22:04:02 by kamelialaks      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// *************************** ft_is ********************************

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// *************************** ft_mem ********************************

void 	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void 	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void	*dst, const void	*src, size_t	len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void 	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// *************************** ft_put ********************************

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void 	ft_putendl_fd(char *s, int fd);
void 	ft_putnbr_fd(int n, int fd);

// *************************** ft_str ********************************

int 	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char 	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// *************************** ft_to ********************************

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);

// *************************** ft_sub ********************************

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);


// *************************** BONUS *********************************

// *************************** ft_lst ********************************

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list 	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void 	ft_lstclear(t_list **lst, void (*del)(void*));
void 	ft_lstiter(t_list *lst, void (*f)(void *));

#endif