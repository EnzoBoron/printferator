*This project has been created as part of the 42 curriculum by eboron.*

# printferator

## Description

**printferator** is a tester for your own `ft_printf`, the 42 project where you reimplement the C standard library's `printf` function.

Every test calls `ft_printf` and the real `printf` with the same arguments, then compares:

- the **return value**
- the **output, byte by byte**

You can test the mandatory part, the bonus part, or both.

## Instructions

### Requirements

- Your `ft_printf` project folder, with a `Makefile` that builds `libftprintf.a` (and a `bonus` rule for `make b` and `make c`)

### Installation

```bash
git clone <git@github.com:EnzoBoron/printferator.git>
cd printferator
```

### Usage

Run the tester from the `printferator` folder with one of these commands:

| Command  | Tests run           |
|----------|---------------------|
| `make a` | Mandatory part only |
| `make b` | Bonus part only     |
| `make c` | Mandatory + bonus   |

You don't need to give the path to your project: the `Makefile` finds your `ft_printf` folder on its own by searching your home directory for `ft_printf.h`.

### Example

```bash
make c
```

### Reading the results

Each section prints `OK` with its score, or `KO` followed by the failing tests:

```
Flag %d:	OK	34/34

Flag %p:
		KO	ft_printf("%p", (void *)NULL)
			got:      >(nil)< (5)
			expected: >0x0< (3)
	KO	18/26
```

The value in brackets is the number of bytes written. Non-printable characters are shown escaped (`\n`, `\t`, `\x00`…).

> **Note:** the reference is the `printf` of the system you run the tests on. Some outputs differ between platforms. For example, `printf("%p", NULL)` prints `0x0` on macOS and `(nil)` on Linux.

### Adding a test

Tests live in `test/basic.c` (mandatory) and `test/bonus.c` (bonus). Use the `T(...)` macro from `test/test.h`: pass it exactly what you would pass to `printf`.

```c
static void my_section()
{
    int score = 0, total = 0;

    printf("My section:\t");

    T("%d", 42);
    T("[%-5s]", "abc");

    display_score(score, total);
}
```

Each `T(...)` counts as 2 checks (return value and output). Each section needs the local variables `score` and `total`.

## Resources

- `man 3 printf`: reference behaviour for every conversion and flag
- [cppreference – printf](https://en.cppreference.com/w/c/io/fprintf)
- The `ft_printf` subject from the 42 curriculum
