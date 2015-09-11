#include <stdlib.h>
#include <stdio.h>

int unziper ()
{	
	char choice[10];
	char firmware[80];
	char buildCommand[120];

	printf("\n\nDecompress firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	scanf("%s", choice);

	if (stricmp(choice, "yes")==0 || stricmp(choice, "1")==0)
	{
		printf("Firmware to decompress : ");
		scanf("%s", firmware);

		printf("Extracting firmware in the IPSW folder...\n");
		sprintf(buildCommand, "bin\\7z.exe x -oIPSW %s", firmware); 
		system(buildCommand);
	}
	else if (stricmp(choice, "no")== 0 || stricmp(choice, "2")==0 )
	{
		printf("");
	}
	
	return 0;
}

int rootfs()
{
	char choice[10];
	char rootfs[80];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	char decrypt[256];
	
	unziper();

	printf("Enter the firmware key : ");
	scanf("%s", key);


	printf("Entrer rootfs name : ");
	scanf("%s", rootfs);
	chdir("IPSW");
	
	sprintf(decrypt, "..\\bin\\dmg.exe extract %s rootfs_decrypt.dmg -k %s", rootfs, key); 
	system(decrypt);

	printf("Decrypting finished\n");
	system("PAUSE");

	printf("Do you want to reencrypt the firmware ? \n");
	printf("1) YES\n");
	printf("2) NO\n");
	scanf("%s", choice);

	if (stricmp(choice, "yes")==0 || stricmp(choice, "1")==0)
	{
		printf("Building rootfs...\n");
		sprintf(buildCommand,"..\\bin\\dmg.exe build rootfs_decrypt.dmg %s", rootfs);
		system(buildCommand);

		printf("Compressing IPSW...\n");
		system("..\\bin\\7z.exe u -tzip -mx0 custom_firmware.ipsw -x!7z.exe");

		printf("Your custom firmware has been created\n");			
	}
	else if(stricmp(choice, "no")==0 || stricmp(choice, "2")==0)
	{
		printf("\n"); //normal
	}

	return 0;
}

int updateRamdisk()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	
	unziper();

	printf("Enter the Update Ramdisk name : ");
	scanf("%s", name);

	printf("Enter key for Update Ramdisk : ");
	scanf("%s", key);

	printf("Enter the IV key for the Update Ramdisk : ");
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\%s %s.dec -k %s -iv %s ", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int restoreRamdisk()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the Restore Ramdisk name : ");
	scanf("%s", name);

	printf("Enter key for Restore Ramdisk : ");
	scanf("%s", key);

	printf("Enter the IV key for the Restore Ramdisk : ");
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\%s %s.dec -k %s -iv %s ", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int appleLogo()
{	

	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the Apple Logo name : ");
	scanf("%s", name);

	printf("Enter the key for %s: ", name);
	scanf("%s", key);

	printf("Enter the key IV for %s: ", name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int batteryCharging0()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the batteryCharging name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s : ", name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int batteryCharging1()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the batteryCharging name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s : ", name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int batteryFull()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the batteryFull name: ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s : ", name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;

}

int batteryLow0()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the batteryLow name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int batteryLow1()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the batteryLow1 name : ");
	scanf("%s", name);

	printf("Enter the key for %s ", name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int deviceTree()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the DeviceTree name : ");
	scanf("%s", name);

	printf("Enter the key for %s ", name);
	scanf("%s", key);

	printf("Entrer la cle IV for %s: ", name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int glyphPlugin()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the Glyph Plugin : ");
	scanf("%s", name);

	printf("Enter the key for %s ", name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int iBEC()
{

	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the iBEC name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\dfu\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int iBoot()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the iBoot name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int iBSS()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the iBSS name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\dfu\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int kernelcache()
{
	char key[80];
	char keyiv[80];
	char name[80];
	char buildCommand[120];

	printf("Enter the kernelcache name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);
	printf("Entrer the key IV for %s : ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand ,"bin\\xpwntool.exe %s %s.dec -k %s -iv %s", kernelcache, kernelcache, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n");

	return 0;
}

int LLB()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the LLB name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int recoveryMode()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the RecoveryMode name : ");
	scanf("%s", name);

	printf("Enter the key for %s : ",name);
	scanf("%s", key);

	printf("Enter the key IV for %s ",name);
	scanf("%s", keyiv);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int manifest()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	system("cat IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\manifest");

	return 0;
}

int ipswDownloader()
{
	char model[80];
	char choice1[10];
	char BuildID[80];
	char buildCommand[1024];
	char buildCommand2[1024];
	char firmware [80];

	printf("Download firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	scanf("%s", choice1);
	if (stricmp(choice1, "yes")==0 || stricmp(choice1, "1")==0)
	{
		printf("iPhone model : ");
		scanf("%s", model);

		printf("BuildID for the version: ");
		scanf("%s", BuildID);

		sprintf(buildCommand,"curl -A --silent http://api.ipsw.me/v2/%s/%s/url/ >url.txt", model, BuildID);
		system(buildCommand);
		printf("Downloading IPSW file...\n");
		system("wget -i url.txt");
		remove("url.txt");
		return 0;
	}
	else if(stricmp(choice1, "no")==0 || stricmp(choice1, "2")==0)
	{
		printf("\n");
	}
	return 0;
}

	
