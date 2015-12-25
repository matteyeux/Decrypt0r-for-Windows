/*
decrypt0r.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "firmware_tools.h"

int main(int argc, char const *argv[])
{
	int choice;
	char loop[5];
	system("cls");
	ipswDownloader();
	system("cls");
	printf("Which file you want to decrypt ?\n");
	printf(" 1) Root Filesystem\n");
	printf(" 2) Ramdisk\n");
	printf(" 3) IMG3 File\n");
	printf(" 4) DFU File\n");
	printf(" 5) Kernelcache\n");
	printf(" 6) Print manifest\n");

	printf("Command : ");
	choice = fgetn();

	switch (choice)
	{
		case 1 : rootfs(); break;
		case 2 : Ramdisk(); break;
		case 3 : IMG3(); break;
		case 4 : DFU_file(); break;
		case 5 : kernelcache(); break;
		case 6 : manifest(); break;
		default : printf("No option available yet\n"); 
	}

	return 0;	
}
