section .text
_main:
    push    message
    call    printf
    add     esp, 4
    ret
message:
    db  'Hello, Holberton', 10, 0