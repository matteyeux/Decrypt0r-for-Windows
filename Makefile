CC = gcc

all : 
	@echo 'Building Decrypt0r for Windows'
	@$(CC) src/decrypt0r.c src/firmware_tools.c -o decrypt0r
	@echo 'Succesfully built Decrypt0r for Windows'
