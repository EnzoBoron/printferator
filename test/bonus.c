#include "test.h"

#define test_int(expected, got) (test_int)("valeur de retour", expected, got)

static void minus()
{
    int score = 0, total = 0;
    int c = 42;
    int *d = &c;

    printf("Flag -:\t\t");

    T("%-10s.", "qwe");
    T("%-10c.", 'a');
    T("%-30p.", (void *)d);
    T("%-5d.", 42);
    T("%-5i.", 42);
    T("%-5u.", 42u);
    T("%-6x.", 42u);
    T("%-6X.", 42u);
    T("%-15i.", 42);
    T("%-2d", 42);
    T("%-5d", 42);
    T("%-3d", -42);
    T("%-3d", -4242);
    T("%-2d%-3d%-20d", 42, 42, INT_MAX);
    T("[%-1c]", 'x');
    T("[%-5c]", 0);
    T("[%-5s]", "");
    T("[%-3s]", "abcdef");
    T("[%-12d]", INT_MIN);
    T("[%-12u]", UINT_MAX);
    T("[%-20p]", (void *)NULL);

    display_score(score, total);
}

static void zero()
{
    int score = 0, total = 0;

    printf("Flag 0:\t\t");

    T("%010d.", 42);
    T("%010i", 42);
    T("%030u", 42u);
    T("%05x", 42u);
    T("%05X", 42u);
    T("%02d", 42);
    T("%00d", 42);
    T("%05d", 42);
    T("%03d", -42);
    T("%02d%03d%020d", 42, 42, INT_MAX);
    T("[%05d]", -42);
    T("[%05d]", 0);
    T("[%01d]", 0);
    T("[%012d]", INT_MIN);
    T("[%011u]", UINT_MAX);
    T("[%010x]", 0xdeadbeefu);
    T("[%010X]", 0u);

    display_score(score, total);
}

static void hash()
{
    int score = 0, total = 0;

    printf("Flag #:\t\t");

    T("%#x", 42u);
    T("%#x", 9861u);
    T("%#x", (unsigned int)-42);
    T("%#x", 0u);
    T("%#X", (unsigned int)-4242);
    T("%#x%#x%#xd", 42u, 42u, (unsigned int)INT_MAX);
    T("%#X", 0u);
    T("%#x", 1u);
    T("%#X", 255u);
    T("%#x", UINT_MAX);
    T("%#X %#x", 0xabcu, 0xabcu);

    display_score(score, total);
}

static void space()
{
    int score = 0, total = 0;
    int c = 42;
    int *d = &c;

    printf("Flag ' ':\t");

    T("%30p\n", (void *)d);
    T("%5d\n", 42);
    T("%5i\n", 42);
    T("%5u\n", 42u);
    T("%6X\n", 42u);
    T("%6x\n", 42u);
    T("%10c\n", 'a');
    T("%10s\n", "aze");
    T("% d", 42);
    T("% 9d", 9861);
    T("% 9d", -42);
    T("% d", -4242);
    T("% d% 5d% 8d", 42, 42, INT_MAX);
    T("[% d]", 0);
    T("[% i]", INT_MAX);
    T("[% i]", INT_MIN);
    T("[%1s]", "abc");
    T("[%5c]", 0);
    T("[%20p]", (void *)NULL);
    T("[%12d]", INT_MIN);

    display_score(score, total);
}

static void plus()
{
    int score = 0, total = 0;

    printf("Flag +:\t\t");

    T("%+d", 42);
    T("%+d", -42);
    T("%+i", 42);
    T("%+i", -42);
    T("%+d", -9861);
    T("%+d %+d %+d", 42, INT_MIN, INT_MAX);
    T("%+d", 0);
    T("%+i", 0);
    T("[%+5d]", 42);
    T("[%+5d]", -42);
    T("[%+05d]", 42);
    T("[%-+5d]", 42);
    T("[%+ d]", 42);

    display_score(score, total);
}

static void precision()
{
    int score = 0, total = 0;

    printf("Precision:\t");

    T("%.10d", 200);
    T("%.10d", -42);
    T("%.10i", 42);
    T("%.30u", 42u);
    T("%.5x", 42u);
    T("%.5X", 42u);
    T("%.3s", "hello");
    T("%.10s", "hello");
    T("%.5s", "hello");
    T("%.4s", "hello");
    T("[%.0d]", 0);
    T("[%.d]", 0);
    T("[%.0i]", 0);
    T("[%.0u]", 0u);
    T("[%.0x]", 0u);
    T("[%.0X]", 0u);
    T("[%.0d]", 42);
    T("[%.1d]", 0);
    T("[%.2d]", -1);
    T("[%.11d]", INT_MIN);
    T("[%.0s]", "hello");
    T("[%.s]", "hello");
    T("[%.0s]", "");
    T("[%.1s]", "");
    T("[%.8x]", 0xabcu);

    display_score(score, total);
}

static void combine()
{
    int score = 0, total = 0;

    printf("Combine:\t");

    T("[%05.3d]", 7);
    T("[%+.0d]", 0);
    T("[%#08.3x]", 255u);
    T("[%#5x]", 0u);
    T("[%#5x]", 1436u);
    T("%#10x.", 42u);
    T("%-#10X.", 42u);
    T("[%10.5d]", 42);
    T("[%-10.5d]", -42);
    T("[%010.5d]", 42);
    T("[%5.0d]", 0);
    T("[%-5.0d]", 0);
    T("[%+8.4d]", 42);
    T("[% 8.4d]", 42);
    T("[%-+8.4d]", -42);
    T("[%08.3d]", -7);
    T("[%10.3s]", "hello");
    T("[%-10.3s]", "hello");
    T("[%10.0s]", "hello");
    T("[%#10.6x]", 42u);
    T("[%-#10.6X]", 42u);
    T("[%#.0x]", 0u);
    T("[%#012x]", UINT_MAX);
    T("[%-5c|%5c]", 'a', 'b');
    T("[%-8s|%8s]", "ab", "cd");
    T("[%+d|% d|%-4d|%04d|%.3d]", 1, 2, 3, 4, 5);

    display_score(score, total);
}

void bonus()
{
    minus();
    zero();
    hash();
    space();
    plus();
    precision();
    combine();
}
