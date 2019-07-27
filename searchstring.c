#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Search_in_File(char *fname, char *str , char *argv);
void Usage(char *filename);

int main(int argc, char *argv[]) {
	int result, errno;

	if(argc < 4 || argc > 4) {
		Usage(argv[0]);
		exit(1);
	}

	result = Search_in_File(argv[2], argv[3] , argv[1]);
	if(result == -1) {
		perror("Error");
		printf("Error number = %d\n", errno);
		exit(1);
	}
	return(0);
}

void Usage(char *filename) {
	printf("You have Entered more OR less arguments than required\n");
}

int Search_in_File(char *fname, char *str , char *argv) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	
	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL) {
		if(((strstr(temp, str)) != NULL) && !(strcmp("v" , argv) == 0 || strcmp("nv" , argv) == 0)) {
			if(strcmp("n" , argv) == 0 || strcmp("nc" , argv) == 0){
				printf("%s : %d : ", fname , line_num);
			}
			printf(" %s\n", temp);
			find_result++;
		}
		else if((strstr(temp, str)) == NULL){
			if(strcmp("v" , argv) == 0 || strcmp("nv" , argv) == 0){
				printf("%s : %d : %s : \n", fname , line_num , temp);
			}
		}
		line_num++;
	}

	if(find_result == 0) {

		//printf("\nSorry, couldn't find a match.\n");
	}
	else {
		//printf("file name is : %s : " , fname) ;

		if(strcmp(argv , "c") == 0 || strcmp("nc" , argv) == 0)
			printf(" Number Of Lines Matched Are : %d \n" , find_result ) ;
		printf("\n") ;
	}

	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   	return(0);
}



