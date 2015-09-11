#Decrypt0r

Decrypt0r is a utility which help you to decrypt all the iOS firmware components.

###Rootfs decrypting

To decrypt rootfs or other components you have to get keys from https://www.theiphonewiki.com/wiki/Firmware_Keys.

You have to enter the IPSW filename (ex : iPhone5,4_8.4.1_12H321_Restore.ipsw).
The program will ask you to add the keys grabed from iphonewiki (only one for the rootfs).

Then, the tool will decompress you'll have to add the rootgs name
Next you have specify the name of the file containing rootfs (ex 058-24465-023.dmg).
In the IPSW file, there is three dmg files, that of rootfs is heaviest.

Then the program is going to work automaticaly.

If you want to modify rootfs (ex Setup.app -ASR will not accept the feat without BootROM firmware) you can use TransMac.

### Encryption of rootfs and creating a Custom fimware

You can now create your own Custom fimware.
Downgrades are already impossible without SHSHs blobs, on devices that do not have low level exploits.
Is this fonction useless ?
Yes, but it can still be used.

#Other components

To decrypt other firmware components like kernelcache or iBoot, you have to grab the keys from theiphonewiki
The first one to add is the largest, and the second one is the iv key (the smallest)

## TODO

- Add a version for GNU/Linux and OS X
- Clean my code

## Credits

Thank you to my Jam Elrhk Elro (@Elro74) for his Liberati0n script and help for dev.
Developed by Mathieu Hautebas (matteyeux)

For this tool I used:

- xpwn developed by Planetbeing https://github.com/planetbeing/xpwn
- dmg.exe (No idea how I got it, if you know where is the source code, contact me).
- 7zip.exe (developed by Igor Pavlov)

For more information contact me on Twitter: matteyeux