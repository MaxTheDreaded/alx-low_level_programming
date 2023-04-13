#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

typedef struct
{
  unsigned char  e_ident[EI_NIDENT];
  uint16_t  e_type;
  uint16_t e_machine;
  uint32_t e_flags;
  uint16_t e_ehsize;
  uint16_t e_phentsize;
  uint16_t e_phnum;
  uint16_t e_shentsize;
  uint16_t e_shnum;
  uint16_t e_shstrndx;
} ElfN_Ehdr;

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int copier(const char *file_from, const char *file_to);
void error_msg(int err, char *file);
int elf_magic(const char *file);
int elf_class(const char *file);
int elf_data(const char *file);
int elf_version(const char *file);
int elf_osabi(const char *file);
int elf_abiversion(const char *file);
int elf_type(const char *file);
int elf_entry(const char *file);
int elf_phoff(const char *file);
int elf_shoff(const char *file);
int elf_flags(const char *file);
int elf_ehsize(const char *file);
int elf_phentsize(const char *file);
int elf_phnum(const char *file);
int elf_shentsize(const char *file);
int elf_shnum(const char *file);
int elf_shstrndx(const char *file);

#endif /* MAIN_H_ */
