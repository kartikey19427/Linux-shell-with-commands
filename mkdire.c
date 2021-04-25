#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <dirent.h> 
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>



void mkdirectory(char st1[]){
	char *epointer;
	epointer=strstr(st1,"kdir");
	char stcopy[200];
	strcpy(stcopy,st1);
	char *epointer2=strstr(stcopy,"-p");
	struct stat st = {0};


	char stcopy2[200];
	strcpy(stcopy2,st1);
	char *epointer3=strstr(stcopy2,"-v");

	char stcopy3[200];
	strcpy(stcopy3,st1);
	char *epointer4=strstr(stcopy2,"-v");

if(epointer2!=NULL){
	char *stval;
	stval = strtok (stcopy,"/");
	int i=0;
	while(stval!=NULL){
		if(i<1){
		mkdir(epointer2+3,0700);
		chdir(epointer2+3);
		}
		else {

		mkdir(stval,0700);
		chdir(stval);
		
		}
		stval=strtok(NULL,"/");
		i++;
	}

}
	else if(epointer3!=NULL){
		char *stval;
		stval=strtok(epointer3+3," ");
		while(stval!=NULL){
			if (stat(stval, &st) == -1) {
    			mkdir(stval, 0700);
    			printf("mkdir created directory %s\n",stval);
			}
			else {
				printf("%s\n", "mkdir cannot create directory: Folder already exists\n");
			}

			stval=strtok(NULL," ");
		}


		

	}
	else {

		if (stat(epointer+5, &st) == -1) {
    	mkdir(epointer+5, 0700);
		}
		else {
			printf("%s\n", "mkdir cannot create directory: Folder already exists\n");
		}
	}



}






int main(int argc, char *argv[])
{
	mkdirectory(argv[1]);
	return 0;
}