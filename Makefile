CC = gcc

all : 
	@echo 'Building Decrypt0r for Windows'
	@$(CC) src/decrypt0r.c src/firmware_tools.c src/firmware_tools.h -o decrypt0r -lcurl
	@echo 'Succesfully built Decrypt0r for Windows'