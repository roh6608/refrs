#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	// declaring variables
	int i,j,len;
	char *ent;
	char *entries[] = {"article", "book", "booklet", "inbook", "incollection", "inproceedings", "manual", "mastersthesis", "misc", "phdthesis", "misc", "phdthesis", "proceedings", "techreport", "unpublished"};
	char fields[13][7][15] = {{"key","author","title","journal","year"},{"key","author","title","publisher","year"},{"key","title"},{"key","author","title","chapter","pages","publisher","year"},{"key","author","title","booktitle","publisher","year"},{"key","author","title","booktitle","year"},{"key","title"},{"key","author","title","school","year"},{"key"},{"key","author","title","school","year"},{"key","title","year"},{"key","author","title","institution","year"},{"key","author","title","note"}};
	int fieldSize[13] = {5,5,2,7,6,5,2,5,1,5,3,5,4};
	char **enter;
	FILE *file;
	// allocating memory
	ent = malloc(15*sizeof(char));

	// opening file
	file = fopen("dat.bib","a");

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
		break; // before break ask user if they would like to continue writing entries.
	}

	// freeing memory and clsing file
	free(ent);
	fclose(file);
}
