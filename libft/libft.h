/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:16:48 by smunio            #+#    #+#             */
/*   Updated: 2023/05/03 12:28:27 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 _______ _______ _______ 
|\     /|\     /|\     /|
| +---+ | +---+ | +---+ |
| |   | | |   | | |   | |
| |L  | | |I  | | |B  | |
| +---+ | +---+ | +---+ |
|/_____\|/_____\|/_____\|
                        
*/

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*previous;
	int				content;
	int				rank;
}					t_stack;

/*
*		------
		LIBFT
*		------
*/

int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int tofind);
void	*ft_memset(void *p, int value, size_t count);
void	*ft_memcpy( void *destination, const void *source, size_t size);
int		ft_memcmp( const void *pointer1, const void *pointer2, size_t size );
void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size );
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	ft_bzero(void *s, unsigned int n);
int		ft_atoi(const char *str);
void	*ft_memmove(void *dst, void *src, size_t len);
char	*ft_strdup(char *src);
char	*ft_strrchr(char *s, int tofind);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_isprint(int c);
size_t	ft_strlcat( char *destination, const char *source, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

/*
*
	| BONUS | LIBFT |
*
*/

t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack	**lst, t_stack	*new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(int));
void	ft_lstclear(t_stack **lst, void (*del)(int));
void	ft_lstiter(t_stack *lst, void (*f)(int));
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(int), void (*del)(int));
void	ft_lstdellast(t_stack *lst);

/*
*		-------
		PRINTF
*		-------
*/

int		ft_putchar(char c);
int		ft_putnbr_hex(long long nb, char *hex);
int		ft_putadr_hex(unsigned long nb, int taille);
int		ft_putstr(char *s);
int		ft_putnbr(long long nb, int taille);
size_t	ft_strlen(const char *str);
int		ft_printf(const char	*s, ...);
int		ft_putchar2(char c);
int		size_number(long long nb, int u);
int		size_number_base10(long long nb, int u, int taille);
int		size_ptr(unsigned long nb, int u);

/*
*		-------------
		GET_NEXT_LINE
*		-------------
*/

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 3
// # endif

// char	*get_next_line(int fd);
// char	*ft_strjoin_gnl(char *s1, char *s2, int *read_size, int i);
// char	*ft_line(char *buffer, char *line, int *read_size);
// char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *len_buff);
// int		ft_strlen_gnl(char *s);
// int		len_backslash_n(char *s, int *read_size, int choice);
// int		ft_fill_save(char **save, int *read_size);
char	*free_item(char **s);
// char	*double_free(char *s1, char **s2);
// char	*gnl_v2(char **save, char **line, int *read_size, int *i);

#endif