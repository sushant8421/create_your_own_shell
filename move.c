#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
void formatError();

int main(int ac, char* av[])
{
    char *file= av[1];
    char *location= av[2];
    char newplace[50];

    if(ac!=3)
        formatError();
    else
    {
        if(location[0]=='/')             
        {
            strcat(location,"/");          
            strcat(location,file);
            if(rename(file, location) != 0)
                printf("Error:\nDirectory not found\n");
        }
        else
        {
            DIR *isD;
            isD = opendir(location);                // check if argument is a DIR in CWD

            if(isD==NULL)
            {
                if( rename(file,location)!= 0)
                    printf("Error: File not moved\n");
            }
            else
            {
                char *ptrL;
                ptrL = getcwd(newplace, 50);        // get current working directory path 
                strcat(newplace,"/");               
                strcat(newplace,location);          // attach mv location to path ptrL
                strcat(newplace,"/");
                strcat(newplace, file);             // keep original file name
                if(rename(file,ptrL)!=-1){
                    //printf("Successful\n");
                }
                else
                    printf("Error:\nDirectory not found in CWD\n");
                closedir(isD);
            }
        }
    }
    return 0;
}

void formatError()
{
    printf("Usage:\n./mv foo.txt new.txt\n./mv foot.txt subdir\n");
    exit(1);
}