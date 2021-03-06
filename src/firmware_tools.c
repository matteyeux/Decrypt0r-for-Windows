/*firmware_tools.c*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void swag_logo()
{
	system("cls");
    printf(" ____                             _    ___\n");
    printf("|  _ \\  ___  ___ _ __ _   _ _ __ | |_ / _ \\ _ __\n");
	printf("| | | |/ _ \\/ __| '__| | | | '_ \\| __| | | | '__|\n");
    printf("| |_| |  __/ (__| |  | |_| | |_) | |_| |_| | |\n");
    printf("|____/ \\___|\\___|_|   \\__, | .__/ \\__|\\___/|_|\n");
    printf("                      |___/|_| by matteyeux\n\n");
}

void init_process (){
	/* TODO 
	 *	- Check if bin directory is not missing (including all bins)
	 */
}

int im4p = 0;
int check4im4p (char *name)
{
	char begin_file[12], filetype[5];
    int fd=0, nb;
    memset(begin_file, 0, 12);
    memset(filetype, 0, 5);

    fd = open(name, O_RDONLY);
    if (fd == -1)
    {
        printf("Could not open %s : %s\n", name, strerror(errno));
        exit(1);
    }
    nb = read(fd, begin_file, 11);
    strncpy(filetype, begin_file+7, 4);
    printf("%s\n",filetype);

    if(strcmp(filetype, "IM4P")==0)
    {
        im4p = 1;
    }

    else {
        strncpy(filetype, begin_file+0, 4);
        if (strcmp(filetype, "3gmI")==0)
        {
                im4p = 0;
                printf("%s\n",filetype);
        }
        else {
                printf("%s is not an IM4P nor an IMG3 file\n", name);
                exit(1);
        }
    }
    close(fd);
    return 0;
}


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
		//HAXX
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
	chdir("IPSW");
	printf("Enter the Ramdisk name : ");
	fget(name, 120);
	if (fopen(name,"r")==NULL){
		printf("File %s is missing\n", name);
		exit(1);
	}
	printf("Enter key for Ramdisk : ");
	fget(key, 80);

	printf("Enter the IV key for the Update Ramdisk : ");
	fget(keyiv, 80);

	sprintf(buildCommand, "..\\bin\\xpwntool IPSW\\%s %s.dec -k %s -iv %s ", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int IMG3()
{	
	char name[120], buildCommand[1024], key[80], keyiv[80], boardID[10], img3_dir[1024];

	unziper();

	printf("Board ID (e.g n49ap for iPhone5,4) : ");
	fget(boardID, 10);

	printf("Enter the IMG3 filename : ");
	fget(name, 120);

	sprintf(img3_dir,"IPSW/Firmware/all_flash/all_flash.%s.production", boardID);
	chdir(img3_dir);

	if (fopen(name,"r")==NULL){
		printf("File %s is missing\n", name);
		exit(1);
	}
	rename(name, "target");

	printf("Enter the key for %s: ", name);
	fget(key, 80);


	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	if (im4p == 0) {
		sprintf(buildCommand, "..\\..\\..\\bin\\xpwntool.exe target %s.dec -k %s -iv %s", name, key, keyiv);
	}

	else if (im4p == 1){
		sprintf(buildCommand, "dd if=target bs=52 skip=1 | openssl aes-256-cbc -K %s -iv %s -nopad -d > %s.dec", keyiv, key, name);
	}
	else {
		printf("im4p value : %d\n Wat?", im4p);
	}

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
	if (fopen(name,"r")==NULL){
		printf("File %s is missing\n", name);
		exit(1);
	}
	rename(name, "target");

	printf("Enter the key for %s: ", name);
	fget(key, 80);
	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	if (im4p == 0) {
		sprintf(buildCommand, "..\\..\\..\\bin\\xpwntool.exe target %s.dec -k %s -iv %s", name, key, keyiv);
	}

	else if (im4p == 1){
		sprintf(buildCommand, "dd if=target bs=52 skip=1 | openssl aes-256-cbc -K %s -iv %s -nopad -d > %s.dec", keyiv, key, name);
	}
	else {
		printf("im4p value : %d\n Wat?", im4p);
		return -1;
	}
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
	chdir("IPSW");
	printf("Enter the kernel filename : ");
	fget(name, 120);

	printf("Enter the key for %s: ", name);
	fget(key, 80);

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	sprintf(buildCommand, "..\\bin\\xpwntool IPSW\\%s %s.dec -k %s -iv %s",name, name, key, keyiv);
	system(buildCommand);
	printf("%s.dec copied at the folder's root\n", name);
	return 0;
}

int get_keybags()
{
	char file_here[1024], buildCommand[1024];
	printf("Drag file here : ");
	fget(file_here, 1024);
	sprintf(buildCommand, "bin\\xpwntool %s nul | cut -f2 -d ' '", file_here);
	system(buildCommand);
	remove("nul");
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



