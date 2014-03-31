.file "entry.s"

#grub でブートするために必要なデータ
MULTIBOOT_HEADER_MAGIC = 0x1BADB002
MULTIBOOT_HEADER_FLAGS = 0x0001
CHECKSUM = -(MULTIBOOT_HEADER_MAGIC+MULTIBOOT_HEADER_FLAGS) 

.code32
.section .entry

multiboot_header:
    .align 4
    .long MULTIBOOT_HEADER_MAGIC
    .long MULTIBOOT_HEADER_FLAGS
    .long CHECKSUM

.text
.align 2
.globl entry
entry:
    jmp kernel_entry


.globl start_hlt
start_hlt:
    hlt
    jmp start_hlt

