#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this will have what entries are need as arries, can actually define array size in here too.
int main(){
	// declariung variables
	int i;
	char *ent;
	char *entries[15] = {"article", "book", "booklet", "inbook", "incollection", "inproceedings", "manual", "mastersthesis", "misc", "phdthesis", "misc", "phdthesis", "proceedings", "techreport", "unpublished"};

	// allocating memory
	ent = malloc(15*sizeof(char));

	while(1){
		printf("What entry type?\n");
		scanf("%s",ent);
		
		for(i=0;i<13;i++){
			if(strcmp(ent,entries[i]) == 0){
				printf("%s\n",entries[i]); // this gets entry type, need to figure out how it will write from here getting it to ask for the entries is trivial, can have a struct with a *article[] that can store the info
			}
		}
		break;
	}

	// freeing memory
	free(ent);
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
