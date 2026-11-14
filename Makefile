PRINTF_DIR	=	$(shell find ~ -maxdepth 10 -type f -name ft_printf.h -not -path '*/.*' 2>/dev/null | head -n 1 | xargs -I{} dirname {} | sed 's,/include$$,,')

a:
	@./printferator $(PRINTF_DIR) 0

b:
	@./printferator $(PRINTF_DIR) 1

c:
	@./printferator $(PRINTF_DIR) 2
