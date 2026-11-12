#include "test.h"

static void basic_string()
{
    int score = 0;
    char *str;
    int l;
	int a;

    printf("Simple string:\t");

    capture_start();
    a = ft_printf("qwertyuiopasdfghjklzxcvbnm");
    str = capture_end(&l);
	score += test_int(26, a);
    score += test_string("qwertyuiopasdfghjklzxcvbnm", str);
    free(str);

    capture_start();
    a = ft_printf("testtesttesttesttest");
    str = capture_end(&l);
	score += test_int(20, a);
    score += test_string("testtesttesttesttest", str);
    free(str);

    capture_start();
    a = ft_printf(" ");
    str = capture_end(&l);
	score += test_int(1, a);
    score += test_string(" ", str);
    free(str);

    capture_start();
    a = ft_printf("~45678lkj;\t'[]\v=/*+--_=|][\n");
    str = capture_end(&l);
	score += test_int(27, a);
    score += test_string("~45678lkj;\t'[]\v=/*+--_=|][\n", str);
    free(str);

    display_score(score, 8);
}

static void basic_percentage_s()
{
    int score = 0;
    char *str;
    int l, a;

    printf("Flag %%s:\t");

    capture_start();
    a = ft_printf("  %s  ", "qwertyuiopasdfghjklzxcvbnm");
    str = capture_end(&l);
	score += test_int(30, a);
    score += test_string("  qwertyuiopasdfghjklzxcvbnm  ", str);
    free(str);

    capture_start();
    a = ft_printf("\n%s\n", "testtesttesttesttest");
    str = capture_end(&l);
	score += test_int(22, a);
    score += test_string("\ntesttesttesttesttest\n", str);
    free(str);

    capture_start();
    a = ft_printf("\n\t\v0%s0\v\t\n", " ");
    str = capture_end(&l);
	score += test_int(9, a);
    score += test_string("\n\t\v0 0\v\t\n", str);
    free(str);

    capture_start();
    a = ft_printf("%s", "~45678lkj;'[]=/*+--_=|][");
    str = capture_end(&l);
	score += test_int(24, a);
    score += test_string("~45678lkj;'[]=/*+--_=|][", str);
    free(str);

    capture_start();
    a = ft_printf("%s %s %s %s\n", "hello", "my", "friend", NULL);
    str = capture_end(&l);
	score += test_int(23, a);
    score += test_string("hello my friend (null)\n", str);
    free(str);

    display_score(score, 10);
}

static void basic_percentage_d()
{
    int score = 0;
    char *str;
    int l, a;

    printf("Flag %%d:\t");

    capture_start();
    a = ft_printf("%d", 42);
    str = capture_end(&l);
	score += test_int(2, a);
    score += test_str_int(str, 42);
    free(str);

    capture_start();
    a = ft_printf("%d", -42);
    str = capture_end(&l);
	score += test_int(3, a);
    score += test_str_int(str, -42);
    free(str);

    capture_start();
    a = ft_printf("%d", __INT_MAX__);
    str = capture_end(&l);
	score += test_int(10, a);
    score += test_str_int(str, __INT_MAX__);
    free(str);

    capture_start();
    ft_printf("%d", INT_MIN);
    str = capture_end(&l);
    score += test_str_int(str, INT_MIN);
    free(str);

    display_score(score, 7);
}

static void basic_percentage_c()
{
    int score = 0;
    char *str;
    int l, a;

    printf("Flag %%c:\t");

    capture_start();
    a = ft_printf("%c", 'a');
    str = capture_end(&l);
	score += test_int(1, a);
    score += test_string(str, "a");
    free(str);

    capture_start();
    a = ft_printf("%c", 'z');
    str = capture_end(&l);
	score += test_int(1, a);
    score += test_string(str, "z");
    free(str);

    capture_start();
    a = ft_printf("%c", 0);
    str = capture_end(&l);
	score += test_int(1, a);
    score += test_str_int(str, 0);
    free(str);

    capture_start();
    a = ft_printf("%c%c%c%c", 0, 51, 126, 81);
    str = capture_end(&l);
	score += test_int(4, a);
    score += test_str_int(str, 0);
    free(str);

    display_score(score, 8);
}

static void basic_percentage_p()
{
    int score = 0;
    char *str;
    char *rep;
    int l, p1, *p2 = NULL, *p3 = &l;
	int a, b;

    printf("Flag %%p:\t");

    capture_start();
    a = ft_printf("%p", &p1);
    str = capture_end(&l);
    capture_start();
    b = printf("%p", &p1);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%p", p2);
    str = capture_end(&l);
    capture_start();
    b = printf("%p", p2);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%p", p3);
    str = capture_end(&l);
    capture_start();
    b = printf("%p", p3);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%p", NULL);
    str = capture_end(&l);
    capture_start();
    b = printf("%p", NULL);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%p%p%p", &p1, p2, p3);
    str = capture_end(&l);
    capture_start();
    b = printf("%p%p%p", &p1, p2, p3);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 10);
}

static void basic_percentage_i()
{
    int score = 0;
    char *str;
    int l, a;

    printf("Flag %%i:\t");

    capture_start();
    a = ft_printf("%i", 42);
    str = capture_end(&l);
	score += test_int(2, a);
    score += test_str_int(str, 42);
    free(str);

    capture_start();
    a = ft_printf("%i", -42);
    str = capture_end(&l);
	score += test_int(3, a);
    score += test_str_int(str, -42);
    free(str);

    capture_start();
    ft_printf("%i", __INT_MAX__);
    str = capture_end(&l);
    score += test_str_int(str, __INT_MAX__);
    free(str);

    capture_start();
    ft_printf("%i", INT_MIN);
    str = capture_end(&l);
    score += test_str_int(str, INT_MIN);
    free(str);

    display_score(score, 6);
}

static void basic_percentage_u()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;

    printf("Flag %%u:\t");

    capture_start();
    a = ft_printf("%u", 123);
    str = capture_end(&l);
    capture_start();
    b = printf("%u", 123);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%u", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%u", -42);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%u", __INT_MAX__);
    str = capture_end(&l);
    capture_start();
    b = printf("%u", __INT_MAX__);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%u", INT_MIN);
    str = capture_end(&l);
    capture_start();
    b = printf("%u", INT_MIN);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%u%u%u", 125, 77885, __INT_MAX__);
    str = capture_end(&l);
    capture_start();
    b = printf("%u%u%u", 125, 77885, __INT_MAX__);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 10);
}

static void basic_percentage_x()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;

    printf("Flag %%x:\t");

    capture_start();
    a = ft_printf("%x", 123);
    str = capture_end(&l);
    capture_start();
    b = printf("%x", 123);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%x", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%x", -42);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%x", INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%x", INT_MAX);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%x", 77885);
    str = capture_end(&l);
    capture_start();
    b = printf("%x", 77885);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%x%x%x", 125, 77885, INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%x%x%x", 125, 77885, INT_MAX);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 10);
}

static void basic_percentage_X()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;

    printf("Flag %%X:\t");

    capture_start();
    a = ft_printf("%X", 123);
    str = capture_end(&l);
    capture_start();
    b = printf("%X", 123);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%X", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%X", -42);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%X", INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%X", INT_MAX);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%X", 77885);
    str = capture_end(&l);
    capture_start();
    b = printf("%X", 77885);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%X%X%X", 125, 77885, INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%X%X%X", 125, 77885, INT_MAX);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 10);
}

static void basic_percentage()
{
    int score = 0;
    char *str;
    int l, a;

    printf("Flag %%:\t\t");

    capture_start();
    a = ft_printf("qwertyuiopasd%%fghjklzxcvbnm");
    str = capture_end(&l);
	score += test_int(27, a);
    score += test_string("qwertyuiopasd%fghjklzxcvbnm", str);
    free(str);

    capture_start();
    a = ft_printf("%%testtestte%%sttesttest%%");
    str = capture_end(&l);
	score += test_int(23, a);
    score += test_string("%testtestte%sttesttest%", str);
    free(str);

    capture_start();
    a = ft_printf("%%");
    str = capture_end(&l);
	score += test_int(1, a);
    score += test_string("%", str);
    free(str);

    capture_start();
    a = ft_printf("%%~4567%%8lkj;'[]%%=/*+%%--_=|]%%[%%%%%%");
    str = capture_end(&l);
	score += test_int(32, a);
    score += test_string("%~4567%8lkj;'[]%=/*+%--_=|]%[%%%", str);
    free(str);

    display_score(score, 8);
}

static void all_combine()
{
    int score = 0;
    char *str;
    char *rep;
    int l, p = 12, *p1 = &p;
	int a, b;

    printf("All combine:\t");

    capture_start();
    a = ft_printf("%X q%s s%u cdsc%dfsd%i\n%cfwef \t%psefs%%d\n", 123, "qwe", 1555, 7788, 42, 'a', p1);
    str = capture_end(&l);
    capture_start();
    b = printf("%X q%s s%u cdsc%dfsd%i\n%cfwef \t%psefs%%d\n", 123, "qwe", 1555, 7788, 42, 'a', p1);
    rep = capture_end(&l);
	score += test_int(b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 2);
}


void basic()
{
    basic_string();
    basic_percentage();
    basic_percentage_s();
    basic_percentage_d();
    basic_percentage_c();
    basic_percentage_p();
    basic_percentage_i();
    basic_percentage_u();
    basic_percentage_x();
    basic_percentage_X();
	all_combine();
}