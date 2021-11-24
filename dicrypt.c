#include <stdio.h>
#include <stdlib.h>
int main(int argn, char* args[])
{
	if(argn != 4)
	{
		printf("a file encryption tool.\nusage:\n%s SRC DEST PASS\n", args[0]);
		return 1;
	}
	int i = 0;
	char tmpdst;
	FILE *fptr1 = fopen(args[1], "rb");
	FILE *fptr2 = fopen(args[2], "wb");
	fseek(fptr1, 0, SEEK_END);
	long int size = ftell(fptr1);
	fseek(fptr1, 0, SEEK_SET);
	for(long int curs = 0; curs < size; curs++)
	{
		if(args[3][i] == '\0')
			i = 0;
		fwrite(&tmpdst, 1, 1, fptr2);
		tmpdst = (tmpdst - args[3][i]) % 256;
		fread(&tmpdst, 1, 1, fptr1);
		i++;
	}
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
