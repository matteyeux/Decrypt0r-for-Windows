#Decrypt0r
WINDOWS ONLY
You should install [Cygwin](https://www.cygwin.com/) to build and run it 
Decrypt0r is a utility which help you to decrypt all the iOS firmware components. <br>

```
Which file you want to decrypt ?  
 1) Root Filesystem               
 2) Ramdisk                       
 3) IMG3 File                     
 4) DFU File                      
 5) Kernelcache                   
 6) Print manifest                
Command :
```

###Rootfs decrypting

To decrypt rootfs or other components you have to grab keys from https://www.theiphonewiki.com/wiki/Firmware_Keys. <br>
If you choose to download directly from Decrypt0r, it will decompress automaticaly the firmware in a folder named "IPSW". <br>

Next you have specify the name of the file containing rootfs (ex 058-24465-023.dmg). <br>
In the IPSW file, there is three dmg files, that of rootfs is heaviest. <br>

Then the program is going to work automaticaly. <br>

If you want to modify rootfs you can use TransMac. <br>

### Encryption of rootfs and creating a Custom fimware

You can now create your own Custom fimware. <br>
Downgrades are already impossible without SHSHs blobs, on devices that do not have low level exploits. <br>
Is this fonction useless ? <br>
Yes, but it can still be used. <br>

#Other components

To decrypt other firmware components like kernelcache or iBoot, you have to grab the keys from theiphonewiki <br>
The first one to add is the largest, and the second one is the iv key (the smallest) <br>

## TODO

- Clean my code <br>

## Credits

Thank you to my friend Jam Elrhk Elro ([@Elro74](https://twitter.com/Elro74)) for his Liberati0n script and help for dev. <br>
Developed by Mathieu Hautebas ([@matteyeux](https://twitter.com/matteyeux)) <br>
Thank you to [Callum Jones](https://twitter.com/icj_) for his awesome website ipsw.me and Neal (@iNeal) for his API.<br>

For this tool I used: <br>

- xpwn developed by Planetbeing https://github.com/planetbeing/xpwn <br>
- dmg.exe (No idea how I got it, if you know where is the source code, contact me). <br>
- 7zip.exe (developed by Igor Pavlov) <br>

For more information contact me on Twitter: [@matteyeux](https://twitter.com/matteyeux) <br>
