#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this will have what entries are need as arries, can actually define array size in here too.
int main(){
	// declariung variables
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
					scanf("%s",enter[j]); // most likely just after here, can free memory after file is written as well
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
		break; // before break ask user if they would like to continue.
	}

	// freeing memory and clsing file
	free(ent);
	fclose(file);
}


//To-do
//- character double pointer of all the possible entry types
//- structs for each of the entry types
//- use fopen and fprintf to write to the file
//- use scanf to read strings in for each of them
//-make efficient both in a usage sense and a coding sense try and reduce the amount of re-writing similar stuff
// so prototype properly etc. encapsulate in functions, possible use header file for the data structure sort of things
// - make the program easily extensible
// - take command line flags and file name as arguments in the main function, then have a parser or something for the 
// options so that mroe options can be added easily.

// - add tests if possible and can run the tests with the makefile, not particularly important for this but just something to consider
// - find a way to give the link that can create another file that is a list of links with associated key names, can then search to find the link where the article is located etc.
// - header file can include my function prototypes - not that I think there will be too many
