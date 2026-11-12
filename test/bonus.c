#include "test.h"

static void minus()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;
    int c = 42;
    int *d = &c;

    printf("Flag -:\t\t");

    capture_start();
    a = ft_printf("%-10s.", "qwe");
    str = capture_end(&l);
    capture_start();
    b = printf("%-10s.", "qwe");
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-10s.\", \"qwe\")", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-10c.", 'a');
    str = capture_end(&l);
    capture_start();
    b = printf("%-10c.", 'a');
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-10c.\", 'a')", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-30p.", d);
    str = capture_end(&l);
    capture_start();
    b = printf("%-30p.", (void *)d);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-30p.\", d)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-5d.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-5d.", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-5d.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-5i.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-5i.", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-5i.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-5u.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-5u.", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-5u.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-6x.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-6x.", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-6x.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-6X.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-6X.", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-6X.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-15i.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-15i.", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-15i.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-2d", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-2d", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-2d\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-5d", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-5d", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-5d\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-3d", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-3d", -42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-3d\", -42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-3d", -4242);
    str = capture_end(&l);
    capture_start();
    b = printf("%-3d", -4242);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-3d\", -4242)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%-2d%-3d%-20d", 42, 42, INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%-2d%-3d%-20d", 42, 42, INT_MAX);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-2d%-3d%-20d\", 42, 42, INT_MAX)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 28);
}

static void zero()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;
    const char *fmt;

    printf("Flag 0:\t\t");

    capture_start();
    a = ft_printf("%010d.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%010d.", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%010d.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%010i", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%010i", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%010i\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%030u", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%030u", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%030u\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%05x", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%05x", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%05x\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%05X", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%05X", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%05X\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%02d", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%02d", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%02d\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    /* Flag '0' repete : volontaire, format en variable pour eviter le warning gcc */
    fmt = "%00d";
    capture_start();
    a = ft_printf(fmt, 42);
    str = capture_end(&l);
    capture_start();
    b = printf(fmt, 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%00d\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%05d", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%05d", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%05d\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%03d", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%03d", -42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%03d\", -42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%02d%03d%020d", 42, 42, INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%02d%03d%020d", 42, 42, INT_MAX);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%02d%03d%020d\", 42, 42, INT_MAX)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 20);
}

static void hash()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;

    printf("Flag #:\t\t");

    capture_start();
    a = ft_printf("%#x", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%#x", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%#x\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%#x", 9861);
    str = capture_end(&l);
    capture_start();
    b = printf("%#x", 9861u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%#x\", 9861)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%#x", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%#x", (unsigned int)-42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%#x\", -42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    /* Avant : doublon de "%#x", 42. Cas piege : # avec 0 n'affiche pas "0x" */
    capture_start();
    a = ft_printf("%#x", 0);
    str = capture_end(&l);
    capture_start();
    b = printf("%#x", 0u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%#x\", 0)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%#X", -4242);
    str = capture_end(&l);
    capture_start();
    b = printf("%#X", (unsigned int)-4242);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%#X\", -4242)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%#x%#x%#xd", 42, 42, INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%#x%#x%#xd", 42u, 42u, (unsigned int)INT_MAX);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%#x%#x%#xd\", 42, 42, INT_MAX)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 12);
}

static void space()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;
    int c = 42;
    int *d = &c;

    printf("Largeur / ' ':\t");

    capture_start();
    a = ft_printf("%30p\n", d);
    str = capture_end(&l);
    capture_start();
    b = printf("%30p\n", (void *)d);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%30p\\n\", d)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%5d\n", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%5d\n", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%5d\\n\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%5i\n", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%5i\n", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%5i\\n\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%5u\n", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%5u\n", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%5u\\n\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%6X\n", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%6X\n", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%6X\\n\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%6x\n", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%6x\n", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%6x\\n\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%10c\n", 'a');
    str = capture_end(&l);
    capture_start();
    b = printf("%10c\n", 'a');
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%10c\\n\", 'a')", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%10s\n", "aze");
    str = capture_end(&l);
    capture_start();
    b = printf("%10s\n", "aze");
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%10s\\n\", \"aze\")", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("% d", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("% d", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"% d\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("% 9d", 9861);
    str = capture_end(&l);
    capture_start();
    b = printf("% 9d", 9861);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"% 9d\", 9861)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("% 9d", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("% 9d", -42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"% 9d\", -42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("% d", -4242);
    str = capture_end(&l);
    capture_start();
    b = printf("% d", -4242);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"% d\", -4242)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("% d% 5d% 8d", 42, 42, INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("% d% 5d% 8d", 42, 42, INT_MAX);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"% d% 5d% 8d\", 42, 42, INT_MAX)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 26);
}

static void plus()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;

    printf("Flag +:\t\t");

    capture_start();
    a = ft_printf("%+d", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%+d", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%+d\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%+d", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%+d", -42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%+d\", -42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%+i", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%+i", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%+i\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%+i", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%+i", -42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%+i\", -42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%+d", -9861);
    str = capture_end(&l);
    capture_start();
    b = printf("%+d", -9861);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%+d\", -9861)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%+d %+d %+d", 42, INT_MIN, INT_MAX);
    str = capture_end(&l);
    capture_start();
    b = printf("%+d %+d %+d", 42, INT_MIN, INT_MAX);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%+d %+d %+d\", 42, INT_MIN, INT_MAX)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 12);
}

static void precision()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;

    printf("Flag .:\t\t");

    capture_start();
    a = ft_printf("%.10d", 200);
    str = capture_end(&l);
    capture_start();
    b = printf("%.10d", 200);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.10d\", 200)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.10d", -42);
    str = capture_end(&l);
    capture_start();
    b = printf("%.10d", -42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.10d\", -42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.10i", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%.10i", 42);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.10i\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.30u", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%.30u", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.30u\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.5x", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%.5x", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.5x\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.5X", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%.5X", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.5X\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.3s", "hello");
    str = capture_end(&l);
    capture_start();
    b = printf("%.3s", "hello");
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.3s\", \"hello\")", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.10s", "hello");
    str = capture_end(&l);
    capture_start();
    b = printf("%.10s", "hello");
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.10s\", \"hello\")", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.5s", "hello");
    str = capture_end(&l);
    capture_start();
    b = printf("%.5s", "hello");
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.5s\", \"hello\")", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%.4s", "hello");
    str = capture_end(&l);
    capture_start();
    b = printf("%.4s", "hello");
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%.4s\", \"hello\")", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 20);
}

static void combine()
{
    int score = 0;
    char *str;
    char *rep;
    int l, a, b;
    const char *fmt;

    printf("Combine:\t");

    /* '0' ignore avec une precision : volontaire, format en variable pour eviter le warning gcc */
    fmt = "[%05.3d]";
    capture_start();
    a = ft_printf(fmt, 7);
    str = capture_end(&l);
    capture_start();
    b = printf(fmt, 7);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"[%05.3d]\", 7)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("[%+.0d]", 0);
    str = capture_end(&l);
    capture_start();
    b = printf("[%+.0d]", 0);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"[%+.0d]\", 0)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    fmt = "[%#08.3x]";
    capture_start();
    a = ft_printf(fmt, 255);
    str = capture_end(&l);
    capture_start();
    b = printf(fmt, 255u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"[%#08.3x]\", 255)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("[%#5x]", 0);
    str = capture_end(&l);
    capture_start();
    b = printf("[%#5x]", 0u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"[%#5x]\", 0)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("[%#5x]", 1436);
    str = capture_end(&l);
    capture_start();
    b = printf("[%#5x]", 1436u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"[%#5x]\", 1436)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    capture_start();
    a = ft_printf("%#10x.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%#10x.", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%#10x.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    /* Avant : doublon exact du test precedent */
    capture_start();
    a = ft_printf("%-#10X.", 42);
    str = capture_end(&l);
    capture_start();
    b = printf("%-#10X.", 42u);
    rep = capture_end(&l);
    score += test_int("ft_printf(\"%-#10X.\", 42)", b, a);
    score += test_string(rep, str);
    free(str);
    free(rep);

    display_score(score, 14);
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