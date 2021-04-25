#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <dirent.h> 
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>


void ls(char st1[]){
	char *pointer1=strstr(st1,"-a");
	char *pointer2=strstr(st1,"-1");



	if(pointer2!=NULL){
		char s[400];
		struct dirent *de;
		DIR *dr = opendir(".");
		if (dr == NULL){ 
	        printf("Could not open current directory" ); 
	    } 
		while((de=readdir(dr))!=NULL){
			if(strcmp("..",(de->d_name))==0 || strcmp(".",(de->d_name))==0){
			int ggg=0;
			
			}
			else {
				printf("%s\n", de->d_name); 

			}

		}
		closedir(dr);

	}
	else if(pointer1!=NULL){
		char s[400];
		struct dirent *de;
		DIR *dr = opendir(".");
		if (dr == NULL){ 
	        printf("Could not open current directory" ); 
	    } 
		while((de=readdir(dr))!=NULL){
				printf("	%s", de->d_name);

			

		}
		printf("\n");
		closedir(dr);

	}
	else {

		char s[400];
		struct dirent *de;
		DIR *dr = opendir(".");
		if (dr == NULL){ 
	        printf("Could not open current directory" ); 
	    } 
		while((de=readdir(dr))!=NULL){
			if(strcmp("..",(de->d_name))==0 || strcmp(".",(de->d_name))==0){
			int ggg=0;
			
			}
			else {
				printf("	%s", de->d_name); 

			}

		}
		printf("\n");
		closedir(dr);
	}
}




int main(int argc, char *argv[])
{
	ls(argv[1]);
	return 0;
}