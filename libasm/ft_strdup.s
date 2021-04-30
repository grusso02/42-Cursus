global		_ft_strdup
section		.text
extern		_malloc

_ft_strdup:									
			cmp		rdi, 0
			jz		error

len_start:
			xor		rcx, rcx
			jmp		len_compare

len_increment:
			inc		rcx

len_compare:
			cmp		byte[rdi + rcx], 0
			jne		len_increment

malloc_start:
			inc		rcx	
			push	rdi	
			mov		rdi, rcx
			call	_malloc
			pop		rdi
			cmp		rax, 0
			jz		error

copy_start:
			xor		rcx, rcx
			xor		rdx, rdx
			jmp		copy_copy

copy_increment:
			inc		rcx

copy_copy:
			mov		dl, byte[rdi + rcx]
			mov		byte[rax + rcx], dl
			cmp		dl, 0
			jnz		copy_increment
			jmp		return

error:
			xor		rax, rax

return:
			ret