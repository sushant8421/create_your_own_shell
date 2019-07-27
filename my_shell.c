#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h>
#include <dirent.h> 

char **get_input(char *input) {

	if (strlen(input) != 0) 
		add_history(input);

    char **command = malloc(8 * sizeof(char *));
    if (command == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}


int SS(char *directory , char *argv[]){	
	int x , stat_loc;
	pid_t ch ;
	struct dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir(directory); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
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

int main() {
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;

    while (1) {
        input = readline("cheetah@sushant>> ");

        command = get_input(input);

        if (!command[0]) {      /* Handle empty commands */
            free(input);
            free(command);
            continue;
        }
		if(strcmp(command[0], "exit") == 0){
			printf("\tgoodbye!!\n") ;
			exit(0) ;
		}

		if(strcmp(command[0], "SS") == 0){
			int t =  SS(command[3] , command);
		//exit(0) ;
		}

		if(strcmp(command[0], "break") == 0){
			int x ;
			pid_t ch ;
			if((ch = fork()) < 0){
    			printf("child is not created\n") ;
    		}
    		else if(ch > 0){
    			waitpid(ch, &stat_loc, WUNTRACED);
    		}
    		else{
    			if(x=execv("./break", command)<0)
    				printf("execution error in break()\n");
			}
		//exit(0) ;
		}

		if(strcmp(command[0], "cwd") == 0){
			int x ;
			pid_t ch ;
			if((ch = fork()) < 0){
    			printf("child is not created\n") ;
    		}
    		else if(ch > 0){
    			waitpid(ch, &stat_loc, WUNTRACED);
    		}
    		else{
    			if(x=execv("./cwd", command)<0)
    				printf("execution error in break()\n");
			}
		//exit(0) ;
		}


		if(strcmp(command[0], "move") == 0){
			int x ;
			pid_t ch ;
			if((ch = fork()) < 0){
    			printf("child is not created\n") ;
    		}
    		else if(ch > 0){
    			waitpid(ch, &stat_loc, WUNTRACED);
    		}
    		else{
    			if(x=execv("./move", command)<0)
    				printf("execution error in break()\n");
				}
		//exit(0) ;
		}
	

		if (strcmp(command[0], "help") == 0){
			child_pid = fork();
        	if (child_pid < 0) {
            	perror("Fork failed");
            exit(1);
        }

        	else if (child_pid == 0) {
            /* Never returns if the call is successful */
				printf("\t\t ### help ####\n\n ") ;
        		printf("1.cwd - Display Current Working Directory \n Syntax : cwd (No Arguments Required)") ;
        		printf("\n\n") ;
        		printf("2.move - for moving File/Directory from Source_dir to Destination_dir \n Syntax : move [source_path] [destination_path]\n") ;
        		printf("\n3.SS - Search a given String in whole directory (Always take 4 arguments)\n ");
        		printf("Syntax : SS [options] [search_string] [directory_path]\n") ;
        		printf("options : n - position of line in the text file(line_no)\n");
        		printf("\t c - no_of_lines in which the search_string in present\n") ;
                printf("\t v - Display those lines in which the search_string is not present\n") ;
        		printf("\t nc - for implementing both n and c options simultaneously\n\n ") ;
        		printf("4.break - Split the given file \n Syntax : break [options] [file_name_path]\n");
        		printf("options : int_value - in how many lines you want to break the file\n");
        		printf("\n5.exit -for getting out of the shell\n\n") ;

                exit(1);
            }


    	 	else {
            	waitpid(child_pid, &stat_loc, WUNTRACED);
        	}
		}
		
	}

    return 0;
}



