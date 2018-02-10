/*
struct EFI_SYSTEM_TABLE {
	char _buf[60];
	struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
		void *_buf;
		unsigned long long (*OutputString)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *, unsigned short *);
	} *ConOut;
};

void efi_main(void *ImageHandle __attribute__ ((unused)), struct EFI_SYSTEM_TABLE *SystemTable)
{
	SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello UEFI!\n");
	while (1);
}
*/
#include <stdbool.h>

#include <efi.h>
#include <efilib.h>
 
EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  InitializeLib(ImageHandle, SystemTable);
  Print(L"Hello, world!\n");
  while(true){};
  return EFI_SUCCESS;
}
