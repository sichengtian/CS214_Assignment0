#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countWord(char* a){

	char * input = a;
	//a loop used for counting separate chars
	int i=0;
	int isWord=0;//if is in the middle of a word, or if is starting a new word
	int numWords=0;
	while(input[i] != '\0'){
		int currentchar=input[i];
		if(isalpha(currentchar)==1 && isWord==0){ //true 1; false 0
			isWord=1;//since seperator might be more than one char
			numWords++;
		}else if(isalpha(currentchar)==0){
			isWord=0; //reset the isSeperator variable when seeing a valid letter
		}
		
		i++;
	}

	return numWords;
}

int main(int argc, char** argv){

	int i = 0;

	int j = 0;

	int isWord = 0;

	int numWords = countWord(argv[1]);

	char* str = (char*) malloc(strlen(argv[1])+1);

	strcpy(str,argv[1]);

	str[strlen(argv[1])] = '\0';

	char* staringChar = str;

	printf("There are %d words in the string.\n",numWords);
	
	char * unsorted[numWords];

	while(str[j] != '\0'){
		
		if(isalpha(str[j]) && isWord == 0){
			isWord = 1;
			j++;
		}

		else if(isalpha(str[j]) && isWord == 1){
			j++;
		}

		else if(!isalpha(str[j]) && isWord == 1){
			isWord = 0;
			unsorted[i] = (char*) malloc(j+1);
			strncpy(unsorted[i],str,j);
			unsorted[i][j] = '\0';
			str += j+1;
			i++;
			j = 0;
		}
		
		else if(!isalpha(str[j]) && isWord == 0){
			str += 1;
			j = 0;
		}
	}

	if(isWord == 1){
		unsorted[i] = (char*) malloc(j+1);
		strncpy(unsorted[i],str,j);
		unsorted[i][j] = '\0';
	}
	for(int i =0; i < numWords; i++){
		printf("%d word: %s\n",i+1, unsorted[i]);
	}
	str = staringChar;
	free(str);
	str = NULL;
	return 1;
}