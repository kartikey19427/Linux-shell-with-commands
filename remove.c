#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <dirent.h> 
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

void rm(char st1[]){

	FILE *fp;

	char finas[200];
	getcwd(finas,200);
	strcat(finas,"/helprm");
	fp=fopen("/home/karti/Desktop/Cprac/a12/helprm.txt","r");







	char *pointer=strstr(st1,"--help");
	struct stat sb;
	char stcopy[200];
	strcpy(stcopy,st1);
	char *pointer2=strstr(stcopy,"rm");
	int i=0;
	int j=0;



	char stcopy2[200];
	strcpy(stcopy2,st1);
	char *pointer3=strstr(stcopy2,"-v");
	char s[400];


	if(pointer3!=NULL){
	char *stval;
	stval = strtok (pointer3," ");

		while(stval!=NULL){

		if(j<1){
			int geg=0;
		}
		else {
		if (stat(stval, &sb) == 0 && S_ISDIR(sb.st_mode)){
    	printf("cannot remove %s is a Directory\n",stval);
	}
	else {
		 if (remove(stval) == 0) {
		 	printf("removed file %s\n", stval);
		  int ggg=0;
		 }
   else
      printf("rm:Unable to delete the file: File does not exist\n");


				}

			}
		stval=strtok(NULL," ");
		j++;




		}

	}

else if(pointer!=NULL){

	while (fgets(s, 400, fp) != NULL){
		printf("%s\n", s);
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
		if (stat(stval, &sb) == 0 && S_ISDIR(sb.st_mode)){
    	printf("cannot remove %s is a Directory\n",stval);
	}
	else {
		 if (remove(stval) == 0) {
		  int ggg=0;
		 }
   else
      printf("rm:Unable to delete the file: File does not exist\n");


			}

		}
		stval=strtok(NULL," ");
		i++;




	}
}

fclose(fp);


	



}


int main(int argc, char *argv[])
{
	rm(argv[1]);
	return 0;
}
