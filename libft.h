/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:55:53 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 13:28:01 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

typedef enum e_bool {FALSE, TRUE}	t_bool;
typedef unsigned char	t_byte;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}				t_list;

typedef enum e_mlx_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_mlx_event;

typedef struct s_color {
	unsigned char	alpha;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_line {
	t_point	start;
	t_point	end;
}	t_line;

typedef struct s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	width;
	unsigned int	height;
}	t_data;

typedef struct s_mlxd {
	void	*mlx;
	void	*window;
}	t_mlxd;

int		get_color(t_color color);
t_color	make_color(int color);
t_color	mix_colors(t_color from, t_color to, double amount);
t_color	add_shade(t_color color, double amount);
t_color	get_opposite(t_color color);
void	reset(size_t *m, size_t *n, long long int *startpos);
int		ft_pow(int nb, int power);
int		ft_printf(const char *str, ...);
int		count_valid_flags(const char *str);
char	*ft_strchr(const char *s, int c);
void	putstrip(const char *str, char ignore_percent, size_t *count);
void	put_charc(char c, size_t *count);
void	put_pointerc(void *pointer, size_t *count);
void	put_nbrc(int num, size_t *count);
void	put_unbrc(unsigned int num, size_t *count);
void	put_hex(unsigned int num, unsigned char isLower, size_t *count);
void	put_longhex(unsigned long num, size_t *count);
void	switcher(char c, va_list *list, size_t *chars);
void	iterator(const char *str, va_list *list, size_t *count);
void	ft_bzero(void *s, size_t n);
char	ft_toupper(char c);
char	ft_tolower(char c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, t_byte c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, t_byte c, size_t n);
t_bool	ft_isprint(char c);
t_bool	ft_isascii(char c);
t_bool	ft_isalpha(char c);
t_bool	ft_isalnum(char c);
t_bool	ft_isdigit(char c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
