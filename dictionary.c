#include "dict.h"

int writedict(const char *dictname, struct dict_elem *elist){

	int j;
	FILE *outf;

	if ((outf = fopen(dictname, "wb")) == NULL){
		return ERROR;
	}

	for (j = 0; elist[j].d_length != 0; j++)
		;

	if (fwrite((void*)elist, sizeof(struct dict_elem), j, outf)){
		fclose(outf);
		return ERROR;
	}


	fclose(outf);
	return SUCCESS;
}

//**************************************************************************


struct dict_elem * readdict(const char *dictname, 
  				     struct dict_elem *inlist, int maxlength)
{

	int i;
	FILE *inf;

	if ((inf = fopen(dictname, "rb")) == NULL){
		return NULL;
	}

	for (i = 0; i < maxlength - 1; i++)
	{
		if (fread((void*)&inlist, sizeof(struct dict_elem), 1, inf)<1)
		{
			break;
		}
	}


	fclose(inf);

	inlist[i].d_length = 0;

	return inlist;
}


// your main function goes here.
int main(int argc, char* argv[])
{
    struct dict_elem * buffer; 
    readdict("structData.data", buffer, 4);
    writedict("dest.data", buffer); 
}
