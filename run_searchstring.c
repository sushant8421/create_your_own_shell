#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h>
#include <dirent.h> 


int main(int argc , char *argv[]){	
	int x , stat_loc;
	pid_t ch ;
	struct dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir(argv[3]); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory\n" ); 
        return 0; 
    }
    
    while ((de = readdir(dr)) != NULL) {
     	char *args[] = {"./searchstring" , argv[1] ,  de->d_name, argv[2], NULL};
    	if((ch = fork()) < 0){
    		printf("child is not created\n") ;
    	}
    	else if(ch > 0){
    		waitpid(ch, &stat_loc, WUNTRACED);
    	}
    	else{
    		if(x=execv("./searchstring", args)<0)
    			printf("execution error");
		}
	}
    		
    return 0;
}