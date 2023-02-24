/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:06:50 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/24 23:04:31 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isprint(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_pow(int num, int power);
int			binary_to_decimal(char *byte);
size_t		ft_intlen(int n);
size_t		ft_strlen(const char *s);
size_t		ft_intstrlen(char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_calloc(size_t count, size_t size);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*	ft_printf	*/

typedef struct s_strct
{
	va_list	ptr;
	int		count;
}	t_strct;

void		ft_putstr_(t_strct **list, char *string);
void		ft_putptr_(t_strct **list, unsigned long p);
void		ft_putnbr_(t_strct **list, int nbr, unsigned int u);
void		ft_puthex_(t_strct **list, unsigned int x, char specifier);
void		ft_putchar_(t_strct **list, char c);
char		*ft_itoau(unsigned int n);
int			ft_printf(const char *format, ...);

/*	get_next_line	*/

char		*get_next_line(int fd);
char		*ft_stringsrch(char *s, int c);
size_t		ft_getlen(const char *s);
char		*push_to_stash(char *stash, char *buff);
void		copy(char *dst, char *src, size_t len);

#endif