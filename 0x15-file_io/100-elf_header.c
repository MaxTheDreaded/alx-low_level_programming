#include "main.h"

/**
 * elf_magic - checks if file is an ELF file
 * @file: file to check
 * Return: 1 if file is an ELF file, 0 otherwise
 */
int elf_magic(const char *file) {
  unsigned char e_ident[EI_NIDENT];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    return (0);
  close(fd);
  if (e_ident[0] != 0x7f || e_ident[1] != 'E' || e_ident[2] != 'L' ||
      e_ident[3] != 'F')
    return (0);
  printf("ELF Header:\n");
  printf("  Magic:   ");
  for (i = 0; i < EI_NIDENT; i++)
    printf("%02x ", e_ident[i]);
  printf("\n");
  printf("  Class:                             ");
  return (1);
}

/**
 * elf_class - checks if file is 32-bit or 64-bit
 * @file: file to check
 * Return: 1 if file is 32-bit, 2 if file is 64-bit, 0 otherwise
 */
int elf_class(const char *file) {
  unsigned char e_ident[EI_NIDENT];
  int fd;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    return (0);
  close(fd);
  if (e_ident[4] == ELFCLASS32)
    printf("ELF32\n");
  else if (e_ident[4] == ELFCLASS64)
    printf("ELF64\n");
  else
    return (0);
  printf("  Data:                             ");
  return (e_ident[4]);
}

/**
 * elf_data - checks if file is little or big endian
 * @file: file to check
 * Return: 1 if file is little endian, 2 if file is big endian, 0 otherwise
 */
int elf_data(const char *file) {
  unsigned char e_ident[EI_NIDENT];
  int fd;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    return (0);
  close(fd);
  if (e_ident[5] == ELFDATA2LSB)
    printf("2's complement, little endian\n");
  else if (e_ident[5] == ELFDATA2MSB)
    printf("2's complement, big endian\n");
  else
    return (0);
  printf("  Version:                          ");
  return (e_ident[5]);
}

/**
 * elf_version - checks if file is version 1
 * @file: file to check
 * Return: 1 if file is version 1, 0 otherwise
 */
int elf_version(const char *file) {
  unsigned char e_ident[EI_NIDENT];
  int fd;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    return (0);
  close(fd);
  if (e_ident[6] == EV_CURRENT)
    printf("1 (current)\n");
  else
    return (0);
  printf("  OS/ABI:                           ");
  return (e_ident[6]);
}

/**
 * elf_osabi - checks if file is UNIX System V ABI
 * @file: file to check
 * Return: 1 if file is UNIX System V ABI, 0 if otherwise
 */
int elf_osabi(const char *file) {
  unsigned char e_ident[EI_NIDENT];
  int fd;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    return (0);
  close(fd);
  if (e_ident[7] == ELFOSABI_SYSV)
    printf("UNIX - System V\n");
  else
    return (0);
  printf("  ABI Version:                      ");
  return (e_ident[7]);
}

/**
 * elf_abiversion - checks if file is version 0
 * @file: file to check
 * Return: 1 if file is version 0, 0 otherwise
 */
int elf_abiversion(const char *file) {
  unsigned char e_ident[EI_NIDENT];
  int fd;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    return (0);
  close(fd);
  if (e_ident[8] == 0)
    printf("0\n");
  else
    return (0);
  printf("  Type:                             ");
  return (e_ident[8]);
}

/**
 * elf_type - checks if file is executable
 * @file: file to check
 * Return: 1 if file is executable, 0 otherwise
 */
int elf_type(const char *file) {
  unsigned char e_type[2];
  int fd;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_type, 2) != 2)
    return (0);
  close(fd);
  if (e_type[0] == ET_EXEC)
    printf("EXEC (Executable file)\n");
  else
    return (0);
  printf("  Entry point address:               ");
  return (e_type[0]);
}

/**
 * elf_entry - checks if file has entry point address
 * @file: file to check
 * Return: 1 if file has entry point address, 0 otherwise
 */
int elf_entry(const char *file) {
  unsigned char e_entry[8];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_entry, 8) != 8)
    return (0);
  close(fd);
  for (i = 0; i < 8; i++)
    printf("%02x", e_entry[i]);
  printf("\n");
  return (e_entry[0]);
}

/**
 * elf_phoff - checks if file has program header offset
 * @file: file to check
 * Return: 1 if file has program header offset, 0 otherwise
 */
int elf_phoff(const char *file) {
  unsigned char e_phoff[8];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_phoff, 8) != 8)
    return (0);
  close(fd);
  for (i = 0; i < 8; i++)
    printf("%02x", e_phoff[i]);
  printf("\n");
  return (e_phoff[0]);
}

/**
 * elf_shoff - checks if file has section header offset
 * @file: file to check
 * Return: 1 if file has section header offset, 0 otherwise
 */
int elf_shoff(const char *file) {
  unsigned char e_shoff[8];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_shoff, 8) != 8)
    return (0);
  close(fd);
  for (i = 0; i < 8; i++)
    printf("%02x", e_shoff[i]);
  printf("\n");
  return (e_shoff[0]);
}

/**
 * elf_flags - checks if file has flags
 * @file: file to check
 * Return: 1 if file has flags, 0 otherwise
 */
int elf_flags(const char *file) {
  unsigned char e_flags[4];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_flags, 4) != 4)
    return (0);
  close(fd);
  for (i = 0; i < 4; i++)
    printf("%02x", e_flags[i]);
  printf("\n");
  return (e_flags[0]);
}

/**
 * elf_ehsize - checks if file has ELF header size
 * @file: file to check
 * Return: 1 if file has ELF header size, 0 otherwise
 */
int elf_ehsize(const char *file) {
  unsigned char e_ehsize[2];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_ehsize, 2) != 2)
    return (0);
  close(fd);
  for (i = 0; i < 2; i++)
    printf("%02x", e_ehsize[i]);
  printf("\n");
  return (e_ehsize[0]);
}

/**
 * elf_phentsize - checks if file has program header entry size
 * @file: file to check
 * Return: 1 if file has program header entry size, 0 otherwise
 */
int elf_phentsize(const char *file) {
  unsigned char e_phentsize[2];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_phentsize, 2) != 2)
    return (0);
  close(fd);
  for (i = 0; i < 2; i++)
    printf("%02x", e_phentsize[i]);
  printf("\n");
  return (e_phentsize[0]);
}

/**
 * elf_phnum - checks if file has program header entry count
 * @file: file to check
 * Return: 1 if file has program header entry count, 0 otherwise
 */
int elf_phnum(const char *file) {
  unsigned char e_phnum[2];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_phnum, 2) != 2)
    return (0);
  close(fd);
  for (i = 0; i < 2; i++)
    printf("%02x", e_phnum[i]);
  printf("\n");
  return (e_phnum[0]);
}

/**
 * elf_shentsize - checks if file has section header entry size
 * @file: file to check
 * Return: 1 if file has section header entry size, 0 otherwise
 */
int elf_shentsize(const char *file) {
  unsigned char e_shentsize[2];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_shentsize, 2) != 2)
    return (0);
  close(fd);
  for (i = 0; i < 2; i++)
    printf("%02x", e_shentsize[i]);
  printf("\n");
  return (e_shentsize[0]);
}

/**
 * elf_shnum - checks if file has section header entry count
 * @file: file to check
 * Return: 1 if file has section header entry count, 0 otherwise
 */
int elf_shnum(const char *file) {
  unsigned char e_shnum[2];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_shnum, 2) != 2)
    return (0);
  close(fd);
  for (i = 0; i < 2; i++)
    printf("%02x", e_shnum[i]);
  printf("\n");
  return (e_shnum[0]);
}

/**
 * elf_shstrndx - checks if file has section header string table index
 * @file: file to check
 * Return: 1 if file has section header string table index, 0 otherwise
 */
int elf_shstrndx(const char *file) {
  unsigned char e_shstrndx[2];
  int fd, i;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (0);
  if (read(fd, e_shstrndx, 2) != 2)
    return (0);
  close(fd);
  for (i = 0; i < 2; i++)
    printf("%02x", e_shstrndx[i]);
  printf("\n");
  return (e_shstrndx[0]);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
    return (EXIT_FAILURE);
  }
  if (elf_magic(argv[1]) == 0) {
    dprintf(
        STDERR_FILENO,
        "Error: Not an ELF file - it has the wrong magic bytes at the start\n");
    return (EXIT_FAILURE);
  }
  if (elf_class(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: ELF class invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_data(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Data encoding invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_version(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: ELF version invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_osabi(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: OS/ABI invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_abiversion(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: ABI Version invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_type(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Type invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_entry(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Entry point address invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_phoff(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Start of program headers invalid\n",
            argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_shoff(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Start of section headers invalid\n",
            argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_ehsize(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Size of ELF header invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_phentsize(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Size of program header entry invalid\n",
            argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_phnum(argv[1]) == 0) {
    dprintf(STDERR_FILENO,
            "Error: %s: Number of program header entries invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_shentsize(argv[1]) == 0) {
    dprintf(STDERR_FILENO, "Error: %s: Size of section header entry invalid\n",
            argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_shnum(argv[1]) == 0) {
    dprintf(STDERR_FILENO,
            "Error: %s: Number of section header entries invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  if (elf_shstrndx(argv[1]) == 0) {
    dprintf(STDERR_FILENO,
            "Error: %s: Section header string table index invalid\n", argv[1]);
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
