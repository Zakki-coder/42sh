/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:59:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/09/12 08:39:00 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** includes
*/
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

# define MAX_BUFF_SIZE 4096
# define BUFF_SIZE 2048
# define FD_SIZE 4096

/*
** structs
*/
typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** mandatory
*/
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *dst, const char *src, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isspecial(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/*
** additional
*/
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnew(size_t size);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
int		ft_atoi(const char *str);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** linked lists
*/
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
** extra
*/
void	ft_exit_no_mem(int status);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_lstaddback(t_list **alst, t_list *new);
void	*ft_calloc(size_t count, size_t size);
int		ft_lstsize(t_list *begin_list);
t_list	*ft_lstlast(t_list *begin_list);
void	*ft_realloc(void *ptr, size_t size);
char	*ft_itoa_base(int value, int base);
char	*ft_ftoa(double nbr, size_t precision);
char	*ft_lftoa(long double nbr, size_t precision);
char	*ft_ltoa_base(long int value, int base);
char	*ft_lltoa_base(long long int value, int base);
char	*ft_ulltoa_base(unsigned long long value, int base);
char	*strjoin_head(char *str, char *tail);
char	*strjoin_tail(char *head, char *str);
char	*ft_strsep(char **stringp, const char *delim);
int		get_next_line(const int fd, char **line);
char	*ft_strsep(char **stringp, const char *delim);
void	ft_del(void *content, size_t content_size);
char	*ft_strndup(char *str, size_t n);
size_t	ft_arrlen(char **array);
char	*ft_skip_space(char *str);
void	ft_arrclean(char **array);
int		ft_freeda(void ***a, size_t row);
char	*ft_strupdate(char *s1, const char *s2);
char	*ft_strjoin_three(char *s1, char *s2, char *s3);
int		ft_isdigit_loop(char *str);
int		ft_intlen(long nbr);
long	ft_atol(const char *nbr);

#endif
