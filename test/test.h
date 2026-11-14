#ifndef _TEST_H_
# define _TEST_H_

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define GREEN "\033[32m"
# define RED   "\033[31m"
# define BLUE  "\033[38;5;117m"
# define RESET "\033[0m"

int     test_buf(char *expected, int le, char *got, int lg, const char *call);
int		test_str_int(char *instruction, char *a, int b);
int     test_string(char *a, char *b);
void	capture_start(void);
char	*capture_end(int *len);
void    basic();
void	bonus();
void    display_score(int score, int total);
int		test_int(char *instruction, int a, int b);
int		ft_printf(const char *format, ...);
void	print_escaped(const char *s, int len);

#define T(...) do { \
	int _a, _b, _la, _lb; \
	char *_s, *_r; \
	capture_start(); \
	_a = ft_printf(__VA_ARGS__); \
	_s = capture_end(&_la); \
	capture_start(); \
	_b = printf(__VA_ARGS__); \
	_r = capture_end(&_lb); \
	score += test_int(_b, _a); \
	score += test_buf(_r, _lb, _s, _la, #__VA_ARGS__); \
	free(_s); \
	free(_r); \
	total += 2; \
} while (0)

#endif
