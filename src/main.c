#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 256
#define WRDLEN 15

int main(int argc, char *argv[]){
	// declaring variables
	int i,j,len;
	char *ent;
	char *entries[] = {"article", "book", "booklet", "inbook", "incollection", "inproceedings", "manual", "mastersthesis", "misc", "phdthesis","proceedings", "techreport", "unpublished"};
	char fields[13][8][15] = {{"key","author","title","journal","year","note"},{"key","author","title","publisher","year","note"},{"key","title","note"},{"key","author","title","chapter","pages","publisher","year","note"},{"key","author","title","booktitle","publisher","year","note"},{"key","author","title","booktitle","year","note"},{"key","title","note"},{"key","author","title","school","year","note"},{"key","author","title","howpublished","note"},{"key","author","title","school","year","note"},{"key","title","year","note"},{"key","author","title","institution","year","note"},{"key","author","title","note","note"}};
	int fieldSize[13] = {6,6,3,8,7,6,3,6,5,6,4,6,5};
	char *enter;
	FILE *file;

	// allocating memory
	ent = malloc(WRDLEN);
	enter = malloc(STRLEN);


	// opening file
	file = fopen(argv[1],"a");

	while(1){
		printf("What entry type, or x to quit? ");
		fgets(ent,sizeof(char)*15,stdin);

		if(ent[0] == '\n'){
			ent[0] = '\0';
		}

		ent[strlen(ent)-1]='\0';

		if(strcmp(ent,"x") == 0){
			break;
		}

		for(i=0;i<13;i++){
			if(strcmp(ent,entries[i]) == 0){
			len = fieldSize[i];

			fprintf(file,"@%s{",ent);

				for(j=0;j<len;j++){

					printf("%s: ",fields[i][j]);

					fgets(enter,sizeof(char)*200, stdin);
					if((strlen(enter) > 0) && (enter[strlen(enter)-1] == '\n')){
						enter[strlen(enter)-1]='\0';
					}

					if(j==0){
						fprintf(file,"%s,\n",enter);
					}
					else if(j<len-1 && j !=0){
						fprintf(file,"%s = {%s},\n",fields[i][j],enter);
					} else if(j==len-1){
						fprintf(file,"%s = {%s}}\n",fields[i][j], enter);
					}
				}
			}
		}
	}


	// freeing memory and clsing file
	free(ent);
	free(enter);
	fclose(file);
}
