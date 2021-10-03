#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	// declaring variables
	int i,j,len;
	char con;
	char *ent;
	char *entries[] = {"article", "book", "booklet", "inbook", "incollection", "inproceedings", "manual", "mastersthesis", "misc", "phdthesis", "misc", "phdthesis", "proceedings", "techreport", "unpublished"};
	char fields[13][8][15] = {{"key","author","title","journal","year","note"},{"key","author","title","publisher","year","note"},{"key","title","note"},{"key","author","title","chapter","pages","publisher","year","note"},{"key","author","title","booktitle","publisher","year","note"},{"key","author","title","booktitle","year","note"},{"key","title","note"},{"key","author","title","school","year","note"},{"key","author","title","howpublished","note"},{"key","author","title","school","year","note"},{"key","title","year","note"},{"key","author","title","institution","year","note"},{"key","author","title","note","note"}};
	int fieldSize[13] = {6,6,3,8,7,6,3,6,5,6,4,6,5};
	char **enter;
	FILE *file;
	// allocating memory
	ent = malloc(15*sizeof(char));

	// opening file
	file = fopen(argv[1],"a");

	while(1){
		printf("What entry type?\t");
		scanf("%s",ent);
		

		for(i=0;i<13;i++){
			if(strcmp(ent,entries[i]) == 0){
			len = fieldSize[i];
			enter = malloc(sizeof(char*)*len);
			fprintf(file,"@%s{",ent);
				for(j=0;j<len;j++){
					enter[j] = malloc(sizeof(char)*200);
					printf("%s:\t",fields[i][j]);
					scanf("%s",enter[j]);
					if(j==0){
						fprintf(file,"%s,\n",enter[j]);
					}
					else if(j<len-1 && j !=0){
						fprintf(file,"%s = {%s},\n",fields[i][j],enter[j]);
					} else if(j==len-1){
						fprintf(file,"%s = {%s}}\n",fields[i][j], enter[j]);
					}
				}
			}
		}
		printf("Would you like to continue? y/n\n");
		scanf(" %c",&con);

		if(con == 'y'){
			continue;
		} else if(con == 'n'){
			break;
		}
	}

	// freeing memory and clsing file
	free(ent);
	fclose(file);
}
