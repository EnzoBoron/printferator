#ifndef _TEST_H_
# define _TEST_H_

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
#include <setjmp.h>

# define GREEN "\033[32m"
# define RED   "\033[31m"
# define BLUE  "\033[38;5;117m"
# define RESET "\033[0m"

int     test_buf(char *expected, int le, char *got, int lg, const char *call);
void	capture_start(void);
char	*capture_end(int *len);
void    basic();
void	bonus();
void    display_score(int score, int total);
int		test_int(char *instruction, int a, int b);
int		ft_printf(const char *format, ...);
void	report_crash(const char *call);

extern sigjmp_buf				g_jmp;
extern volatile sig_atomic_t	g_in_test;

#define T(...) do { \
	volatile int _a = -1; \
	int _b, _la, _lb; \
	char *_s, *_r; \
	capture_start(); \
	g_in_test = 1; \
	if (sigsetjmp(g_jmp, 1) == 0) \
		_a = ft_printf(__VA_ARGS__); \
	else \
		report_crash(#__VA_ARGS__); \
	g_in_test = 0; \
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
