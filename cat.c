#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <dirent.h> 
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>


void cat(char st1[]){

	char *pointer=strstr(st1,"--help");
	char stcopy[200];
	strcpy(stcopy,st1);
	
	int i=0;
	int j=0;
	int k=0;



	char stcopy2[200];
	strcpy(stcopy2,st1);
	char *pointer3=strstr(stcopy2,"-n");
	char s[400];
	int counter=1;
	char stcopy3[200];
	strcpy(stcopy3,st1);
	char *pointer2=strstr(stcopy3,"-E");



	if(pointer3!=NULL){
	char *stval;
	stval = strtok (pointer3," ");
	while(stval!=NULL){
		if(j<1){
			int geg=0;
			}
		else{
			FILE *fp;
			fp=fopen(stval,"r");
			if(fp==NULL){
				printf("cat:Error while opening the file:file does not exist\n");
			}
			else {
				while (fgets(s, 400, fp) != NULL){

					printf("%d %s", counter,s);
					counter++;
				}
			}

		}
		j++;
		stval = strtok (NULL," ");
		}

	}
	else if(pointer2!=NULL){
		char *stval;
		stval = strtok (pointer2," ");
		while(stval!=NULL){
			if(k<1){
			int geg=0;
			}
			else{
				FILE *fp;
				fp=fopen(stval,"r");
				if(fp==NULL){
				printf("cat:Error while opening the file:file does not exist\n");
				k++;
				stval = strtok (NULL," ");
				continue;
				}
				while (fgets(s, 400, fp) != NULL){
					s[strcspn(s, "\r\n")] = 0;

					printf("%s%s\n", s,"$");
					counter++;
				}
			}
			k++;
			stval = strtok (NULL," ");
		}


	}
	else {
		char *stval;
		stval = strtok (stcopy," ");

		while(stval!=NULL){
			if(i<1){
			int geg=0;
			}

			else {
				FILE *fp;
				fp=fopen(stval,"r");
				if(fp==NULL){
					printf("cat:Error while opening the file:file does not exist\n");
					k++;
					stval = strtok (NULL," ");
					continue;
			
				}

				while (fgets(s, 400, fp) != NULL){
					printf("%s", s);
				}
				printf("\n");


			}
			i++;
			stval = strtok (NULL," ");

		}

	}


}


int main(int argc, char *argv[])
{
	cat(argv[1]);
	return 0;
}