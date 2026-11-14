#include "test.h"

int	number_of_test = 0;
int	number_passed_test = 0;

void	print_escaped(const char *s, int len)
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

static char	escape_char(char c)
{
	if (c == '\n')
		return ('n');
	if (c == '\t')
		return ('t');
	if (c == '\v')
		return ('v');
	if (c == '\r')
		return ('r');
	if (c == '\f')
		return ('f');
	return (0);
}

static char	*escape(const char *str)
{
	char	*res;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
		j += 1 + (escape_char(str[i++]) != 0);
	res = malloc(j + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (escape_char(str[i]))
		{
			res[j++] = '\\';
			res[j++] = escape_char(str[i]);
		}
		else
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

static int	g_return_ko = 0;

int	test_int(char *instruction, int expected, int got)
{
	number_of_test++;
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

int	test_string(char *expected, char *got)
{
	char	*e;
	char	*g;

	number_of_test++;
	if (expected && got && !strcmp(expected, got))
	{
		number_passed_test++;
		return (1);
	}
	e = escape(expected);
	g = escape(got);
	printf(RED"\n\t\t"RESET"\tgot: >%s< but expected: >%s<\n",
		g ? g : "(null)", e ? e : "(null)");
	free(e);
	free(g);
	return (0);
}

int	test_str_int(char *instruction, char *got, int expected)
{
	char	buf[16];
	char	*g;

	number_of_test++;
	snprintf(buf, sizeof(buf), "%d", expected);
	if (got && !strcmp(got, buf))
	{
		number_passed_test++;
		return (1);
	}
	g = escape(got);
	printf(RED"\n\t\t"RESET"\t"BLUE"%s:"RESET" got: >%s< but expected: >%s<\n",
		instruction, g ? g : "(null)", buf);
	free(g);
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
	int	score = 0;
	int	a, b;

	fprintf(stderr, "Output close:\t");
	close(STDOUT_FILENO);
	a = ft_printf("Begin of %s %d %c %x %x\n", "tests", 42, 115, 10, 10);
	b = printf("Begin of %s %d %c %x %x\n", "tests", 42, 115, 10, 10);
	score += test_int("ft_printf(\"Begin of %s %d %c %x %x\\n\", "
		"\"tests\", 42, 115, 10, 10)", b, a);
	display_score(score, 1);
}

static void	output_close_bonus(void)
{
	int	score = 0;
	int	a, b;

	fprintf(stderr, "Output close bonus:\t");
	close(STDOUT_FILENO);
	a = ft_printf("Begin of %.3s %010d %c %#x %#x\n", "tests", 42, 115, 10, 10);
	b = printf("Begin of %.3s %010d %c %#x %#x\n", "tests", 42, 115, 10, 10);
	score += test_int("ft_printf(\"Begin of %.3s %010d %c %#x %#x\\n\", "
		"\"tests\", 42, 115, 10, 10)", b, a);
	display_score(score, 1);
}

int	main(int ac, char **av)
{
	int	mode;

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
