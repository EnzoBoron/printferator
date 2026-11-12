# include "test.h"

int number_of_test = 0;
int number_passed_test = 0;

int test_str_int(char *instruction, char *got, int expected)
{
	char	buf[16];

	number_of_test++;
	snprintf(buf, sizeof(buf), "%d", expected);
	if (got && !strcmp(got, buf))
	{
		number_passed_test++;
		return (1);
	}
	printf(RED"\n\t\tKO"RESET"\t"BLUE"%s:"RESET" got: >%s< but expected: >%s<\n",
		instruction, got ? got : "(null)", buf);
	return (0);
}

int test_int(char *instruction, int expected, int got)
{
	number_of_test++;
	if (expected == got)
	{
		number_passed_test++;
		return (1);
	}
	printf(RED"\n\t\tKO"RESET"\t"BLUE"%s:"RESET" got: >%d< but expected: >%d<\n",
		instruction, got, expected);
	return (0);
}

int test_string(char *expected, char *got)
{
	number_of_test++;
	if (expected && got && !strcmp(expected, got))
	{
		number_passed_test++;
		return (1);
	}
	printf(RED"\n\t\tKO"RESET"\tgot: >%s< but expected: >%s<\n",
		got ? got : "(null)", expected ? expected : "(null)");
	return (0);
}

void display_score(int score, int total)
{
	if (score == total)
	{
		fprintf(stderr, GREEN"OK"RESET);
		fprintf(stderr, GREEN"\t%d/%d\n\n"RESET, score, total);
	}
	else
		fprintf(stderr, RED"\n\tKO\t%d/%d\n\n"RESET, score, total);
}

static int	g_saved_fd;
static int	g_pipe[2];
#define CAP_SIZE 4096

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

static void output_close()
{
	int score = 0;

    fprintf(stderr, "output close:\t");

	close (1);
    int a = ft_printf("Begin of %s %d %c %x %x\n", "tests", 42, 115, 10, 10);
    int b = printf("Begin of %s %d %c %x %x\n", "tests", 42, 115, 10, 10);
    score += test_int("printf(\"Begin of %s %d %c %x %x\n\", \"tests\", 42, 115, 10, 10)", a, b);
	display_score(score, 1);
}

int main(int ac, char **av)
{
	if (atoi(av[1]) == 0)
		basic();
	else if (atoi(av[1]) == 1)
		bonus();
	else if (atoi(av[1]) == 2)
	{
		basic();
		bonus();
	} else {
		printf("Usage: [dossier] [number]\n");
		printf("[number]:\n");
		printf("	0: Basic tests\n");
		printf("	1: Bonus tests\n");
		printf("	2: basic and bonus tests\n\n");
	}
	output_close();
	display_score(number_passed_test, number_of_test);
	return (0);
}
