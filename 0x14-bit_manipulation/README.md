# C - Bit manipulation

ALX project on C - Bit manipulation

## Functions

Here is a table of the functions used in this project and their corresponding files:

| Function | File | Description |
| :--- | :--- | :--- |
| `binary_to_uint` | [0-binary\_to\_uint.c](./0-binary_to_uint.c) | Converts a binary number to an `unsigned int`. |
| `get_bit` | [0-get\_bit.c](./0-get_bit.c) | Returns the value of a bit at a given index. |
| `set_bit` | [1-set\_bit.c](./1-set_bit.c) | Sets the value of a bit to `1` at a given index. |
| `clear_bit` | [2-clear\_bit.c](./2-clear_bit.c) | Sets the value of a bit to `0` at a given index. |
| `flip_bits` | [5-flip\_bits.c](./5-flip_bits.c) | Returns the number of bits you would need to flip to get from one number to another. |
| `get_endianness` | [100-get\_endianness.c](./100-get_endianness.c) | Checks the endianness. |

## Explanation of what each file shows:

### 0-binary_to_uint.c

This function converts a binary number to an `unsigned int`. It returns the converted number, or `0` if there is one or more chars in the string `b` that is not `0` or `1` or `b` is `NULL`. It takes a string of 0 and 1 chars as an argument.

### 1-print_binary.c

This function prints the binary representation of a number. It takes an `unsigned long int` as an argument. It returns nothing.

### 2-get_bit.c

This function returns the value of a bit at a given index. It takes an `unsigned long int` and an `unsigned int` as arguments. It returns `-1` if an error occurs, or the value of the bit at the index `index` if no error occurs.

### 3-set_bit.c

This function sets the value of a bit to `1` at a given index. It takes a pointer to an `unsigned long int` and an `unsigned int` as arguments. It returns `-1` if an error occurs, or `1` if no error occurs.

### 4-clear_bit.c

This function sets the value of a bit to `0` at a given index. It takes a pointer to an `unsigned long int` and an `unsigned int` as arguments. It returns `-1` if an error occurs, or `1` if no error occurs.

### 5-flip_bits.c

This function returns the number of bits you would need to flip to get from one number to another. It takes two `unsigned long int` as arguments. It returns `-1` if an error occurs, or the number of bits you would need to flip to get from one number to another if no error occurs.

### 100-get_endianness.c

This function checks the endianness. It takes no arguments. It returns `0` if big endian, `1` if little endian.
