#include <stdio.h>
#include <stdlib.h>
void buffcrypt(char* pass)
{
	int buff, i = 0;
	while((buff = getchar()) != EOF)
	{
		if(pass[i] == '\0')
			i = 0;
		putchar((buff + pass[i]) % 256);
		i++;
	}
}
void monocrypt(char* file, char* pass)
{
	int i = 0;
	char tmpdst;
	FILE *fptr1 = fopen(file, "rb+");
	fseek(fptr1, 0, SEEK_END);
	long int size = ftell(fptr1);
	fseek(fptr1, 0, SEEK_SET);
	for(long int curs = 0; curs < size; curs++)
	{
		if(pass[i] == '\0')
			i = 0;
		fread(&tmpdst, 1, 1, fptr1);
		tmpdst = (tmpdst + pass[i]) % 256;
		fseek(fptr1, curs, SEEK_SET);
		fwrite(&tmpdst, 1, 1, fptr1);
		i++;
	}
	fclose(fptr1);
}
void duocrypt(char* txtfile, char* incfile, char* pass)
{
	int i = 0;
	char tmpdst;
	FILE *fptr1 = fopen(txtfile, "rb");
	FILE *fptr2 = fopen(incfile, "wb");
	fseek(fptr1, 0, SEEK_END);
	long int size = ftell(fptr1);
	fseek(fptr1, 0, SEEK_SET);
	for(long int curs = 0; curs < size; curs++)
	{
		if(pass[i] == '\0')
			i = 0;
		fread(&tmpdst, 1, 1, fptr1);
		tmpdst = (tmpdst + pass[i]) % 256;
		fwrite(&tmpdst, 1, 1, fptr2);
		i++;
	}
	fclose(fptr1);
	fclose(fptr2);
}
int main(int argn, char* args[])
{
	if(argn > 4 && argn < 2)
	{
		printf("a file encryption tool.\nusage:\nfor preserving original file: %s SRC DEST PASS\nto overwrite the original file: %s FILE PASS\n%s PASS\nto encrypt the beffer.", args[0], args[0], args[0]);
		return 1;
	}
	if(argn == 3)
		monocrypt(args[1], args[2]);
	else if(argn == 4)
		duocrypt(args[1], args[2], args[3]);
	else
		buffcrypt(args[1]);
	return 0;
}
