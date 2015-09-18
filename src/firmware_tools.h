/*
*firmware_tools.h
*Dans ce dossier c'est la que toutes les fonctions sont déclarées.
*Le code de toutes les fonctions est dans firmware_tools.c
*Outil developpé par Mathieu Hautebas.
*/

int unziper();
int ipswDownloader(); 
int rootfs();
int updateRamdisk();
int restoreRamdisk();
int IMG3();
int manifest();
int fget(char *chain, int sizee);
int fgetn();
void nBuffer();
float fgetf();
