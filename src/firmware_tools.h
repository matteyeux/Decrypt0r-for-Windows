/*
*firmware_tools.h
*Dans ce dossier c'est la que toutes les fonctions sont déclarées.
*Le code de toutes les fonctions est dans firmware_tools.c
*Outil developpé par Mathieu Hautebas.
*/

int unziper(); //Ne pas ajouter à switch
int ipswDownloader(); //Ne pas ajouter à switch
int rootfs();
int updateRamdisk();
int restoreRamdisk();
int appleLogo();
int batteryCharging0(); 
int batteryCharging1();
int batteryFull();
int batteryLow0();
int batteryLow1();
int deviceTree();
int glyphPlugin();
int iBEC();
int iBoot();
int iBSS();
int kernelcache();
int LLB();
int recoveryMode();
int manifest();