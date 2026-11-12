# include "test.h"

int number_of_test = 0;
int number_passed_test = 0;

int test_str_int(char *a, int b)
{
	number_of_test++;
	if (atoi(a) == b)
	{
		number_passed_test++;
		return (1);
	}
	else
	{
		printf(RED"\n\t\tKO"RESET"\tgot: >%d< but expected: >%s<\n", b, a);
		return (0);
	}
}

int test_int(int a, int b)
{
	number_of_test++;
	if (a == b)
	{
		number_passed_test++;
		return (1);
	}
	else
	{
		fprintf(stderr, RED"\n\t\tKO"RESET"\tgot: >%d< but expected: >%d<\n", b, a);
		return (0);
	}
}

int test_string(char *a, char *b)
{
	number_of_test++;
	if (!ft_memcmp(a, b, ft_strlen(a)))
	{
		number_passed_test++;
		return (1);
	}
	else
	{
		printf(RED"\n\t\tKO"RESET"\tgot: >%s< but expected: >%s<\n", b, a);
		return (0);
	}
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
    int a = ft_printf("Begin of %s %.10d %c %#x %#x\n", "tests", 42, 115, 10, 10);
    int b = printf("Begin of %s %.10d %c %#x %#x\n", "tests", 42, 115, 10, 10);
    score += test_int(a, b);
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
