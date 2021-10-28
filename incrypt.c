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
	fread(&tmpdst, 1, 1, fptr1);
	for(int curs = 0; curs == ftell(fptr1) - 1; ++curs)
	{
		if(args[3][i] == '\0')
			i = 0;
		tmpdst = (tmpdst + args[3][i]) % 256;
		i++;
		fwrite(&tmpdst, 1, 1, fptr2);
		fread(&tmpdst, 1, 1, fptr1);
	}
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}