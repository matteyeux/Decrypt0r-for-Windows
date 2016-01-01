/*firmware_tools.c*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int unziper()
{	
	char choice[10];
	char firmware[1024];
	char buildCommand[1024];

	printf("\n\nDecompress firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice, 10);

	if (strcmp(choice, "yes")==0 || strcmp(choice, "1")==0)
	{
		printf("Drag the ipsw here : ");
		fget(firmware, 1024);

		printf("Extracting firmware in the IPSW folder...\n");
		sprintf(buildCommand, "bin\\7z.exe x -oIPSW %s", firmware); 
		system(buildCommand);
	}
	else if (strcmp(choice, "no")== 0 || strcmp(choice, "2")==0 )
	{
		//HAX
	}
	
	return 0;
}

int ipswDownloader()
{
	char model[10];
	char choice1[10];
	char version[7];
	char link[1024];
	char rep2[3];
	char firmware [80];

	printf("Download firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice1, 10);
	if (strcmp(choice1, "yes")==0 || strcmp(choice1, "1")==0)
	{
		printf("Model : ");
		fget(model, 10);
		printf("Version : ");
		fget(version, 7);

		printf("The firmware will be automaticaly extracted\n");

		printf("Downloading IPSW, please wait...\n");
		
		sprintf(link,"wget http://api.ipsw.me/v2/%s/%s/url/dl -O firmware.ipsw",model,version);
		/*sprintf(link,"bin\\wget.exe http://api.ipsw.me/v2/%s/%s/url/dl -O firmware.ipsw",model,version);*/
		system(link);
		system("bin\\7z.exe x -oIPSW firmware.ipsw");
		
		return 0;
	}
	else if(strcmp(choice1, "no")==0 || strcmp(choice1, "2")==0)
	{
		printf("\n");
	}
	return 0;
}

int rootfs()
{
	char choice[10];
	char rootfs[80];
	char buildCommand[1024];
	char buildCommand2[1024];
	char key[80];
	char keyiv[80];
	char decrypt[256];
	
	unziper();

	printf("Entrer rootfs name : ");
	fget(rootfs, 80);
	chdir("IPSW");

	printf("Enter the firmware key : ");
	fget(key, 80);
	
	sprintf(decrypt, "..\\bin\\dmg.exe extract %s rootfs_decrypt.dmg -k %s", rootfs, key); 
	system(decrypt);
	
	printf("Decrypting finished\n");
	sleep(2);

	printf("Do you want to reencrypt the firmware ? \n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice, 10);

	if (strcmp(choice, "yes")==0 || strcmp(choice, "1")==0)
	{
		printf("Building rootfs...\n");
		sprintf(buildCommand2, "%s", rootfs);
		remove(buildCommand2);
		sprintf(buildCommand,"..\\bin\\dmg.exe build rootfs_decrypt.dmg %s", rootfs);
		system(buildCommand);

		printf("Compressing IPSW...\n");
		system("..\\bin\\7z.exe u -tzip -mx0 custom_firmware.ipsw -x!7z.exe");

		printf("Your custom firmware has been created\n");			
	}
	else if(strcmp(choice, "no")==0 || strcmp(choice, "2")==0)
	{
		return EXIT_SUCCESS;
	}

	return 0;
}

int Ramdisk() //Not a priority yet I'll work on after Christmas
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	
	unziper();

	printf("Enter the Ramdisk name : ");
	fget(name, 120);

	printf("Enter key for Ramdisk : ");
	fget(key, 80);

	printf("Enter the IV key for the Update Ramdisk : ");
	fget(keyiv, 80);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\%s %s.dec -k %s -iv %s ", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int IMG3()
{	
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	char boardID[10];
	char img3_dir[1024];

	unziper();

	printf("Board ID (e.g n49ap for iPhone5,4) : ");
	fget(boardID, 10);

	printf("Enter the IMG3 filename : ");
	fget(name, 120);

	sprintf(img3_dir,"IPSW/Firmware/all_flash/all_flash.%s.production", boardID);
	chdir(img3_dir);

	rename(name, "target");

	printf("Enter the key for %s: ", name);
	fget(key, 80);


	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	sprintf(buildCommand, "..\\..\\..\\..\\bin\\xpwntool.exe target %s.dec -k %s -iv %s",name, key, keyiv);
	system(buildCommand);
	rename("target", name);
	printf("%s.dec created at IPSW/Firmware/all_flash/all_flash.%s.production\n", name, boardID);

	return 0;
}

int DFU_file()
{	
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	char dfu_dir[80];


	unziper();
	
	sprintf(dfu_dir, "IPSW/Firmware/dfu/");
	chdir(dfu_dir);
	
	printf("Enter the name of the iBEC/iBSS : ");
	fget(name, 120);
	rename(name, "target");


	printf("Enter the key for %s: ", name);
	fget(key, 80);

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	sprintf(buildCommand, "..\\..\\..\\bin\\xpwntool.exe target %s.dec -k %s -iv %s", name, key, keyiv);
	system(buildCommand);

	rename("target", name);

	printf("%s.dec created at IPSW/Firmware/dfu\n", name);

	return 0;
}

int kernelcache()
{	

	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	char boardID[10];

	unziper();

	printf("Enter the kernel filename : ");
	fget(name, 120);

	printf("Enter the key for %s: ", name);
	fget(key, 80);

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\%s %s.dec -k %s -iv %s",name, name, key, keyiv);
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
	char boardID[10];

	unziper();

	printf("Board ID (e.g n49ap for iPhone5,4) : ");
	fget(boardID, 10);
	sprintf(buildCommand,"cat IPSW\\Firmware\\all_flash\\all_flash.%s.production\\manifest", boardID);
	system(buildCommand);

	return 0;
}

void nBuffer()
{
   int c;
   while (c != '\n' && c != EOF)
   {
       c = getchar();
   }
}

int fget(char *chain, int sizee)
{
   char *charn = NULL;
   if (fgets(chain, sizee, stdin) != NULL)
   {
       charn = strchr(chain, '\n');
       if (charn != NULL)
       {
           *charn = '\0';
       }
       else
       {
           nBuffer();
       }
       return(EXIT_SUCCESS);
   }
   else
   {
       nBuffer();
       return(EXIT_FAILURE);
   }
}

int fgetn()
{
	char chain[64];
	fget(chain, 64);
	return atoi(chain);
}

float fgetf()
{
	char chain[64];
	fgetf(chain, 64);
	return atof(chain);
}



