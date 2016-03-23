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
	swag_logo();
	ipswDownloader();
	swag_logo();
	printf("Which file you want to decrypt ?\n");
	printf(" 1) Root Filesystem\n");
	printf(" 2) Ramdisk\n");
	printf(" 3) IMG3 File\n");
	printf(" 4) DFU File\n");
	printf(" 5) Kernelcache\n");
	printf(" 6) Grab Keybags\n");
	printf(" 7) Print manifest\n");

	printf("Command : ");
	choice = fgetn();

	switch (choice)
	{
		case 1 : swag_logo(); rootfs(); break;
		case 2 : swag_logo(); Ramdisk(); break;
		case 3 : swag_logo(); IMG3(); break;
		case 4 : swag_logo(); DFU_file(); break;
		case 5 : swag_logo(); kernelcache(); break;
		case 6 : swag_logo(); get_keybags(); break;
		case 7 : swag_logo(); manifest(); break;
		default : printf("No option available yet\n"); 
	}

	printf("Press [ENTER] to quit the tool\n"); 
	getchar();

	return 0;	
}
