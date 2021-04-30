global		_ft_write
section		.text

_ft_write:
			mov rax, 0x2000004
			syscall
			jc _err
			ret

_err:
			mov rax, -1
			ret