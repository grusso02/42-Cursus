global		_ft_strlen
section		.text

_ft_strlen:
			mov rax, 0

_while:
			cmp byte[rdi + rax], 0x0
			je _return

_incrememt:
			inc rax
			jmp _while

_return:
			ret