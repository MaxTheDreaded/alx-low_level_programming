section .data
msg: DB 'Hello, Holberton', 10
msgSize EQU $ - msg

global _main
extern _printf

section .text

_main:
	push	msg
	call	_printf
	add	esp, 4
	ret
