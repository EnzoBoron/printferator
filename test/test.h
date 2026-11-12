#ifndef _TEST_H_
# define _TEST_H_

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
// # include "../ft_printf/includes/ft_printf.h"

# define GREEN "\033[32m"
# define RED   "\033[31m"
# define RESET "\033[0m"

int     test_str_int(char *a, int b);
int     test_string(char *a, char *b);
char    *get_str(void);
void	capture_start(void);
char	*capture_end(int *len);
void    basic();
void	bonus();
void    display_score(int score, int total);
int		test_int(int a, int b);
int		ft_printf(const char *format, ...);

#endif /* _TEST_H_ */