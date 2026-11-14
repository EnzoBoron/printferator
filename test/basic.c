#include "test.h"

#define test_int(expected, got) (test_int)("valeur de retour", expected, got)

static void basic_string()
{
    int score = 0, total = 0;

    printf("Simple string:\t");

    T("qwertyuiopasdfghjklzxcvbnm");
    T("testtesttesttesttest");
    T(" ");
    T("~45678lkj;\t'[]\v=/*+--_=|][\n");
    T("");
    T("\n");
    T("\n\n\t\t\v\f\r");
    T("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
      "eiusmod tempor incididunt ut labore et dolore magna aliqua.");

    display_score(score, total);
}

static void basic_percentage()
{
    int score = 0, total = 0;

    printf("Flag %%:\t\t");

    T("qwertyuiopasd%%fghjklzxcvbnm");
    T("%%testtestte%%sttesttest%%");
    T("%%");
    T("%%%%");
    T("100%%");
    T("%%~4567%%8lkj;'[]%%=/*+%%--_=|]%%[%%%%%%");

    display_score(score, total);
}

static void basic_percentage_s()
{
    int score = 0, total = 0;

    printf("Flag %%s:\t");

    T("  %s  ", "qwertyuiopasdfghjklzxcvbnm");
    T("\n%s\n", "testtesttesttesttest");
    T("\n\t\v0%s0\v\t\n", " ");
    T("%s", "~45678lkj;'[]=/*+--_=|][");
    T("%s", "");
    T("[%s]", "");
    T("%s%s", "", "");
    T("%s%s%s", "a", "b", "c");
    T("%s", "%d %s %%");
    T("%s", (char *)NULL);
    T("%s %s %s %s\n", "hello", "my", "friend", (char *)NULL);
    T("%s", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
            "eiusmod tempor incididunt ut labore et dolore magna aliqua.");

    display_score(score, total);
}

static void basic_percentage_c()
{
    int score = 0, total = 0;

    printf("Flag %%c:\t");

    T("%c", 'a');
    T("%c", 'z');
    T("%c", ' ');
    T("%c", '%');
    T("%c", '\n');
    T("%c", 0);
    T("%c", 127);
    T("[%c]", 0);
    T("%c%c%c", 'a', '\t', 'b');
    T("%c%c%c%c", 0, 51, 126, 81);
    T("%c %c %c", '1', '2', '3');

    display_score(score, total);
}

static void basic_percentage_d()
{
    int score = 0, total = 0;

    printf("Flag %%d:\t");

    T("%d", 0);
    T("%d", 1);
    T("%d", -1);
    T("%d", 9);
    T("%d", 10);
    T("%d", -10);
    T("%d", 42);
    T("%d", -42);
    T("%d", 100);
    T("%d", 123456789);
    T("%d", INT_MAX);
    T("%d", INT_MIN);
    T("%d", INT_MAX - 1);
    T("%d", INT_MIN + 1);
    T("%d%d", 1, 2);
    T("%d %d %d %d", 0, -1, INT_MAX, INT_MIN);
    T("[%d]", -0);

    display_score(score, total);
}

static void basic_percentage_i()
{
    int score = 0, total = 0;

    printf("Flag %%i:\t");

    T("%i", 0);
    T("%i", 1);
    T("%i", -1);
    T("%i", 42);
    T("%i", -42);
    T("%i", 100);
    T("%i", INT_MAX);
    T("%i", INT_MIN);
    T("%i%i", 1, 2);
    T("%i %i %i %i", 0, -1, INT_MAX, INT_MIN);

    display_score(score, total);
}

static void basic_percentage_u()
{
    int score = 0, total = 0;

    printf("Flag %%u:\t");

    T("%u", 0u);
    T("%u", 1u);
    T("%u", 123u);
    T("%u", (unsigned int)-1);
    T("%u", (unsigned int)-42);
    T("%u", (unsigned int)INT_MAX);
    T("%u", (unsigned int)INT_MIN);
    T("%u", UINT_MAX);
    T("%u", UINT_MAX - 1);
    T("%u%u%u", 125u, 77885u, (unsigned int)INT_MAX);
    T("%u %u", 0u, UINT_MAX);

    display_score(score, total);
}

static void basic_percentage_x()
{
    int score = 0, total = 0;

    printf("Flag %%x:\t");

    T("%x", 0u);
    T("%x", 1u);
    T("%x", 9u);
    T("%x", 10u);
    T("%x", 15u);
    T("%x", 16u);
    T("%x", 255u);
    T("%x", 256u);
    T("%x", 123u);
    T("%x", 77885u);
    T("%x", 0xdeadbeefu);
    T("%x", (unsigned int)-42);
    T("%x", (unsigned int)INT_MAX);
    T("%x", (unsigned int)INT_MIN);
    T("%x", UINT_MAX);
    T("%x%x%x", 125u, 77885u, (unsigned int)INT_MAX);

    display_score(score, total);
}

static void basic_percentage_X()
{
    int score = 0, total = 0;

    printf("Flag %%X:\t");

    T("%X", 0u);
    T("%X", 1u);
    T("%X", 10u);
    T("%X", 15u);
    T("%X", 16u);
    T("%X", 255u);
    T("%X", 123u);
    T("%X", 77885u);
    T("%X", 0xdeadbeefu);
    T("%X", (unsigned int)-42);
    T("%X", (unsigned int)INT_MAX);
    T("%X", (unsigned int)INT_MIN);
    T("%X", UINT_MAX);
    T("%X%X%X", 125u, 77885u, (unsigned int)INT_MAX);
    T("%x %X", 0xabcdefu, 0xabcdefu);

    display_score(score, total);
}

static void basic_percentage_p()
{
    int score = 0, total = 0;
    int p1 = 0, l = 0, *p2 = NULL, *p3 = &l;
    char *s = "hello";

    printf("Flag %%p:\t");

    T("%p", (void *)&p1);
    T("%p", (void *)p2);
    T("%p", (void *)p3);
    T("%p", (void *)NULL);
    T("%p", (void *)s);
    T("%p", (void *)1);
    T("%p", (void *)15);
    T("%p", (void *)16);
    T("%p", (void *)LONG_MAX);
    T("%p", (void *)LONG_MIN);
    T("%p", (void *)ULONG_MAX);
    T("%p%p%p", (void *)&p1, (void *)p2, (void *)p3);
    T("%p %p", (void *)NULL, (void *)NULL);

    display_score(score, total);
}

static void all_combine()
{
    int score = 0, total = 0;
    int p = 12, *p1 = &p;

    printf("All combine:\t");

    T("%X q%s s%u cdsc%dfsd%i\n%cfwef \t%psefs%%d\n",
      123u, "qwe", 1555u, 7788, 42, 'a', (void *)p1);
    T("%c%s%d%i%u%x%X%p%%", 'z', "str", -1, -2, 3u, 255u, 255u, (void *)p1);
    T("%s=%d, %s=%x, %s=%p", "dec", 42, "hex", 42u, "ptr", (void *)NULL);
    T("%d%%%d", 50, 50);
    T("[%c][%s][%c]", 0, "", 0);
    T("%s%c%s", "abc", '\n', "def");

    display_score(score, total);
}

void basic()
{
    basic_string();
    basic_percentage();
    basic_percentage_s();
    basic_percentage_c();
    basic_percentage_d();
    basic_percentage_i();
    basic_percentage_u();
    basic_percentage_x();
    basic_percentage_X();
    basic_percentage_p();
    all_combine();
}
