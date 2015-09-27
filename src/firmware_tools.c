#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int unziper ()
{	
	char choice[10];
	char firmware[80];
	char buildCommand[120];

	printf("\n\nDecompress firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice, 10);

	if (strcmp(choice, "yes")==0 || strcmp(choice, "1")==0)
	{
		printf("Firmware to decompress : ");
		fget(firmware, 80);

		printf("Extracting firmware in the IPSW folder...\n");
		sprintf(buildCommand, "bin\\7z.exe x -oIPSW %s", firmware); 
		system(buildCommand);
	}
	else if (strcmp(choice, "no")== 0 || strcmp(choice, "2")==0 )
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
	char buildCommand2[1024];
	char key[80];
	char keyiv[80];
	char decrypt[256];
	
	unziper();

	printf("Enter the firmware key : ");
	fget(key, 80);


	printf("Entrer rootfs name : ");
	fget(rootfs, 80);
	chdir("IPSW");
	
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

int updateRamdisk()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	
	unziper();

	printf("Enter the Update Ramdisk name : ");
	fget(name, 120);

	printf("Enter key for Update Ramdisk : ");
	fget(key, 80);

	printf("Enter the IV key for the Update Ramdisk : ");
	fget(keyiv, 80);

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
	fget(name, 120);

	printf("Enter key for Restore Ramdisk : ");
	fget(key, 80);

	printf("Enter the IV key for the Restore Ramdisk : ");
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

	unziper();

	printf("Enter the IMG3 filename : ");
	fget(name, 120);

	printf("Enter the key for %s: ", name);
	fget(key, 80);

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	sprintf(buildCommand, "bin\\xpwntool IPSW\\Firmware\\all_flash\\all_flash.n49ap.production\\%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

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
	fget(choice1, 10);
	if (strcmp(choice1, "yes")==0 || strcmp(choice1, "1")==0)
	{
		printf("iPhone model : ");
		fget(model, 80);

		printf("BuildID for the version: ");
		fget(BuildID, 80);

		sprintf(buildCommand,"curl -A --silent http://api.ipsw.me/v2/%s/%s/url/ >url.txt", model, BuildID);
		system(buildCommand);
		printf("Downloading IPSW file...\n");
		system("wget -i url.txt");
		remove("url.txt");
		return 0;
	}
	else if(strcmp(choice1, "no")==0 || strcmp(choice1, "2")==0)
	{
		printf("\n");
	}
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
