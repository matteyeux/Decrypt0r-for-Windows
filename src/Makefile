decrypt0r : decrypt0r.o firmware_tools.o
	gcc -o decrypt0r decrypt0r.o firmware_tools.o
	cp decrypt0r ../
	rm *.o
	rm decrypt0r.exe

decrypt0r.o : decrypt0r.c
	gcc -c decrypt0r.c 

firmware_tools.o : firmware_tools.c firmware_tools.h
	gcc -c firmware_tools.c
