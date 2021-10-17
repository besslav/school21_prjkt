/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:40:39 by pskip             #+#    #+#             */
/*   Updated: 2021/10/16 16:46:58 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int litera);
int		ft_isdigit(int litera);
int		ft_isalnum(int litera);
int		ft_isascii(int litera);
int		ft_isprint(int litera);
size_t	ft_strlen(const char *string);
char	*ft_memset(char *str, int upd, size_t n);
char	*ft_bzero(char *str, size_t n);
void	*ft_memcpy(void *strto, const void *strfr, size_t n);
size_t	ft_strlcpy(char *strto, const char *strfr, size_t n);
size_t	ft_strlcat(char *strto, char *strfr, size_t n);
int		ft_toupper(int litera);
int		ft_tolower(int litera);
char	*ft_strchr(char *str, int findit);
char	*ft_strrchr(char *str, char findit);
char	*ft_memchr(void *str, int ascii_code, size_t end);
int		ft_memcmp(const void *first, const void *second, size_t end);
int		ft_strncmp(const char *first, const char *second, size_t end);
void	*ft_memmove(void *strto, const void *strfr, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);

char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif