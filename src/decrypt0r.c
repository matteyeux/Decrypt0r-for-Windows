#include <stdio.h>
#include <stdlib.h>
#include "firmware_tools.h"

int main(int argc, char const *argv[])
{
	int choice;
	
	system("cls");
	ipswDownloader();
	system("cls");
	printf("Which file you want to decrypt ?\n");
	printf(" 1) Root Filesystem\n");
	printf(" 2) Update Ramdisk\n");
	printf(" 3) Restore Ramdisk\n");
	printf(" 4) AppleLogo\n");
	printf(" 5) BatteryCharging0\n");
	printf(" 6) BatteryCharging1\n");
	printf(" 7) BatteryFull\n");
	printf(" 8) BatteryLow0\n");
	printf(" 9) BatteryLow1\n");
	printf("10) DeviceTree\n");
	printf("11) GlyphPlugin\n");
	printf("12) iBEC\n");
	printf("13) iBoot\n");
	printf("14) iBSS\n");
	printf("15) Kernelcache\n");
	printf("16) LLB\n");
	printf("17) RecoveryMode\n");
	printf("18) Print manifest\n");
	printf("Command : ");
	scanf("%d", &choice);

	switch (choice)
	{
		case 1 : rootfs(); break;
		case 2 : updateRamdisk(); break;
		case 3 : restoreRamdisk(); break;
		case 4 : appleLogo(); break;
		case 5 : batteryCharging0(); break; 
		case 6 : batteryCharging1(); break;
		case 7 : batteryFull(); break;
		case 8 : batteryLow0(); break;
		case 9 : batteryLow1(); break;
		case 10 : deviceTree(); break;
		case 11 : glyphPlugin(); break;
		case 12 : iBEC(); break;
		case 13 : iBoot(); break;
		case 14 : iBSS(); break;
		case 15 : kernelcache(); break;
		case 16 : LLB(); break;
		case 17 : recoveryMode(); break;
		case 18 : manifest(); break;
		default : printf("No option available yet\n"); 
	}	
}
