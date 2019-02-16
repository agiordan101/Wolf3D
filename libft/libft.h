/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:31:57 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 17:05:34 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE	5

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *src, int c, size_t n);
void				*ft_bzero(void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(char *str);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule, const char *aiguille);
char				*ft_strnstr(const char *meule, const char *aiguille,
					size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_addline(char **tab, char *line, size_t length);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddback(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_nbrlen(long nbr);
void				*ft_memrcpy(void *dest, const void *src, size_t n);
size_t				ft_lstlen(t_list *first);
t_list				*ft_newlist(size_t svize);
void				ft_sorttab(int *tab, size_t length, int (*f)(int a, int b));
void				ft_swapint(int *a, int *b);
void				ft_swapchar(char *a, char *b);
int					*ft_addint(int *tab, int nbr, size_t length);
int					**ft_addinttab(int **tab, int *line, size_t length);
int					ft_sqrt(int nb);
int					get_next_line(const int fd, char **line);
void				ft_strfill(void *s, int c, size_t n);
void				ft_filltabint(int **tab, size_t len, int nbr);
int					ft_atoi_base(const char *str, int base);
void				ft_printtab(char **tab);
void				ft_printtabl(char **tab);
int					ft_tablen(char **tab);
char				**ft_tabnew(size_t nline, size_t lline);
void				ft_tabdel(char ***tab);
char				**ft_tabcpy(char **dest, char **src);
char				**ft_tabdup(char **tab);
void				ft_tabintdel(int **tab);
void				ft_tabint2del(int ***tab, size_t len);
double				ft_abs(double x);
int					ft_isspace(int c);
char				*ft_strreplace(char *str, char *target, char *replace);
int					ft_filereplace(char *file, char *target, char *replace);
int					ft_stristr(char *str, char *tofind);
void				ft_putinttab(int *tab, size_t len);
int					ft_countnumbers(char *str);
int					*ft_catinttab(int *tab1, size_t l1, int *tab2, size_t l2);

#endif
