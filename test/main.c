#include "test.h"

int	number_of_test = 0;
int	number_passed_test = 0;

static void	print_escaped(const char *s, int len)
{
	for (int i = 0; i < len; i++)
	{
		unsigned char c = s[i];

		if (c == '\n')
			printf("\\n");
		else if (c == '\t')
			printf("\\t");
		else if (c < 32 || c > 126)
			printf("\\x%02x", c);
		else
			putchar(c);
	}
}

static int	g_return_ko = 0;

sigjmp_buf						g_jmp;
volatile sig_atomic_t			g_in_test = 0;
static volatile sig_atomic_t	g_signal = 0;
static int						g_crashed = 0;

static void	print_segfault(int sig)
{
	if (!g_in_test)
	{
		signal(sig, SIG_DFL);
		raise(sig);
		return ;
	}
	g_signal = sig;
	siglongjmp(g_jmp, 1);
}

void	report_crash(const char *call)
{
	const char	*name;

	if (g_signal == SIGBUS)
		name = "Bus error";
	else if (g_signal == SIGABRT)
		name = "Abort";
	else
		name = "Segmentation fault";
	g_crashed = 1;
	fprintf(stderr, RED"\n\t\tKO"RESET"\t"BLUE"%s:"RESET" ft_printf(%s)\n",
		name, call);
}

int	test_int(char *instruction, int expected, int got)
{
	number_of_test++;
	if (g_crashed)
		return (0);
	g_return_ko = (expected != got);
	if (expected == got)
	{
		number_passed_test++;
		return (1);
	}
	printf(RED"\n\t\tKO"RESET"\t"BLUE"%s:"RESET" got: >%d< but expected: >%d<\n",
		instruction, got, expected);
	return (0);
}

int	test_buf(char *expected, int le, char *got, int lg, const char *call)
{
	int	return_ko;

	number_of_test++;
	if (g_crashed)
	{
		g_crashed = 0;
		return (0);
	}
	return_ko = g_return_ko;
	g_return_ko = 0;
	if (le == lg && !memcmp(expected, got, le))
	{
		number_passed_test++;
		return (1);
	}
	if (return_ko)
		printf("\t\t\tft_printf(%s)\n\t\t\tgot:      >", call);
	else
		printf(RED"\n\t\tKO"RESET"\tft_printf(%s)\n\t\t\tgot:      >", call);
	print_escaped(got, lg);
	printf("< (%d)\n\t\t\texpected: >", lg);
	print_escaped(expected, le);
	printf("< (%d)\n", le);
	return (0);
}

void	display_score(int score, int total)
{
	if (score == total)
		fprintf(stderr, GREEN"OK\t%d/%d\n\n"RESET, score, total);
	else
		fprintf(stderr, RED"\n\tKO\t%d/%d\n\n"RESET, score, total);
}

#define CAP_SIZE 4096

static int	g_saved_fd;
static int	g_pipe[2];

void	capture_start(void)
{
	fflush(stdout);
	pipe(g_pipe);
	g_saved_fd = dup(STDOUT_FILENO);
	dup2(g_pipe[1], STDOUT_FILENO);
	close(g_pipe[1]);
}

char	*capture_end(int *len)
{
	char	*out;
	int		total;
	int		r;

	fflush(stdout);
	dup2(g_saved_fd, STDOUT_FILENO);
	close(g_saved_fd);
	out = calloc(CAP_SIZE + 1, 1);
	total = 0;
	while (out && total < CAP_SIZE
		&& (r = read(g_pipe[0], out + total, CAP_SIZE - total)) > 0)
		total += r;
	close(g_pipe[0]);
	if (len)
		*len = total;
	return (out);
}

static void	output_close(void)
{
	int				score = 0;
	volatile int	a = -1;
	int				b;

	fprintf(stderr, "Output close:\t");
	close(STDOUT_FILENO);
	g_in_test = 1;
	if (sigsetjmp(g_jmp, 1) == 0)
		a = ft_printf("Begin of %s %d %c %x %x\n", "tests", 42, 115, 10, 10);
	else
		report_crash("\"Begin of %s %d %c %x %x\\n\", \"tests\", 42, 115, 10, 10");
	g_in_test = 0;
	b = printf("Begin of %s %d %c %x %x\n", "tests", 42, 115, 10, 10);
	score += test_int("ft_printf(\"Begin of %s %d %c %x %x\\n\", "
		"\"tests\", 42, 115, 10, 10)", b, a);
	g_crashed = 0;
	display_score(score, 1);
}

static void	output_close_bonus(void)
{
	int				score = 0;
	volatile int	a = -1;
	int				b;

	fprintf(stderr, "Output close bonus:\t");
	close(STDOUT_FILENO);
	g_in_test = 1;
	if (sigsetjmp(g_jmp, 1) == 0)
		a = ft_printf("Begin of %.3s %010d %c %#x %#x\n", "tests", 42, 115, 10, 10);
	else
		report_crash("\"Begin of %.3s %010d %c %#x %#x\\n\", \"tests\", 42, 115, 10, 10");
	g_in_test = 0;
	b = printf("Begin of %.3s %010d %c %#x %#x\n", "tests", 42, 115, 10, 10);
	score += test_int("ft_printf(\"Begin of %.3s %010d %c %#x %#x\\n\", "
		"\"tests\", 42, 115, 10, 10)", b, a);
	g_crashed = 0;
	display_score(score, 1);
}

int	main(int ac, char **av)
{
	int	mode;

	signal(SIGSEGV, print_segfault);
	signal(SIGBUS, print_segfault);
	signal(SIGABRT, print_segfault);
	(void)ac;
	mode = atoi(av[1]);
	if (mode == 0)
		basic();
	else if (mode == 1)
	{
		bonus();
		output_close_bonus();
	}
	else if (mode == 2)
	{
		basic();
		bonus();
		output_close_bonus();
	}
	output_close();
	display_score(number_passed_test, number_of_test);
	return (0);
}
