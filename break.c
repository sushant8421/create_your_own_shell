#include <stdio.h>
#include<string.h>
#include<stdlib.h>


FILE *write_in(int split_no) {
	char split_file[300];
    	sprintf(split_file, "file_part%d.txt", split_no);
	return fopen(split_file, "w");
}

int main(int argc , char *argv[]) {
	FILE *read;
	FILE *write;
	char line [128]; 
	int split_no=1, nof_lines=1,total_lines ;
	sscanf(argv[1], "%d", &total_lines); 
   
	read = fopen(argv[2],"r");
	if (!read)
		return 1;

	write= write_in(split_no);

	while (fgets(line, sizeof(line), read)!=NULL) {
		if (nof_lines == (total_lines+1)) 
		{
			fclose(write);
			nof_lines = 1;
			split_no++;
			write= write_in(split_no);	
			if (!write)
			return 1;
		}
		fprintf(write,"%s", line);
		nof_lines++;
	}
	fclose(read);
	return 0;
}
