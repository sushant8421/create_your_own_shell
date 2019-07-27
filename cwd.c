#include<unistd.h> 
#include<stdlib.h>
#include<stdio.h>

int main(int argc , char* argv[]) {
char *buf;
buf=(char *)malloc(100*sizeof(char));
getcwd(buf,100);
printf("Current Working Directory is : %s \n",buf);
return 0 ;
}
