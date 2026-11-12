*This project has been created as part of the 42 curriculum by eboron.*
 
# printferator
 
## Description
 
**printferator** is a tester for your own `ft_printf`, the 42 project where you reimplement the C standard library's `printf` function.
 
It runs your implementation on a set of test cases and compares its output and return value with the real `printf`. You can test the mandatory part, the bonus part, or both.
 
## Instructions
 
### Requirements
 
- Your `ft_printf` project folder, with a `Makefile` that builds `libftprintf.a`
- `cc` and `make`
### Installation
 
```bash
git clone <repository-url> printferator
cd printferator
```
 
### Usage
 
```bash
./printferator <path_to_ft_printf> <mode>
```
 
| Argument             | Description                                     |
|----------------------|-------------------------------------------------|
| `<path_to_ft_printf>` | Path to your `ft_printf` project folder         |
| `<mode>`             | Which part of the project to test (see below)   |
 
| Mode | Tests run            |
|------|----------------------|
| `0`  | Mandatory part only  |
| `1`  | Bonus part only      |
| `2`  | Mandatory + bonus    |
 
### Example
 
```bash
./printferator ../ft_printf 2
```
 
## Resources
 
- `man 3 printf`: reference behaviour for every conversion and flag
- [cppreference – printf](https://en.cppreference.com/w/c/io/fprintf)
- The `ft_printf` subject from the 42 curriculum