#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <dirent.h> 
#include <stdlib.h>



int comcounter=0;
int a=0;




void storehistory(char st1[], FILE *fp){
	comcounter++;
	char storestr[400];
	char *str;
	int MAX_CHAR=400;

	char finaltry[MAX_CHAR];
	snprintf(storestr, sizeof(storestr), "%d", comcounter);

	// int *storeptr=(int*)storestr;
	// *storeptr=comcounter;
	char stcopy[400];
	char *finalpointer=finaltry;
	*finalpointer=' ';
	strcpy(stcopy,st1);


	strcat(stcopy,"\n");
	strcat(storestr,finalpointer);
	strcat(storestr,stcopy);

	
	fprintf(fp, "%s", storestr);

}


void cd(char st1[]){
	char *epointer;
	epointer=strstr(st1,"--help");
	char s0[400];

	if(epointer!=NULL){
		char s[200];
		getcwd(s,200);
		char finas[200];
		strcat(s,"/cdhelp");
		FILE *fp;
		fp=fopen(s,"r");
		while (fgets(s0, 400, fp) != NULL){
			printf("%s", s0);
		}
		printf("\n");
		fclose(fp);

	}
	else {
	char s[100];
	int MAXCHAR2=100;
	char stcopy[MAXCHAR2];
	strcpy(stcopy,st1);
	char *stval;
	stval = strtok (stcopy," ");
	int i=0;
	while(stval!=NULL){
		if(i>0){
			if(strcmp("..",stval)==0){
				chdir(".."); 
				printf("%s\n",getcwd(s,100) );
			}
			else if(chdir(stval)==0){

				chdir(stval);
				printf("%s\n",getcwd(s,100) );
			}
			else{
				perror("cd:");
			}

		}
		i++;

		stval=strtok(NULL," ");


		}
	}
}
void echo(char st1[]){
	char s[200];
	struct dirent *de;
	DIR *dr = opendir(getcwd(s,200));
	int MAXCHAR2=200;
	char stcopy[MAXCHAR2];
	strcpy(stcopy,st1);
	char *stval;
	int i=0;
	char *epointer=strstr(stcopy, "-e");
	char *epointer2=strstr(stcopy, "*");


	if(epointer!= NULL){
		stval = strtok (epointer+3,"\\n");
		while(stval!=NULL){
			printf("%s\n",stval);
			stval=strtok(NULL,"\\n");


	}

}
	else if(epointer2!= NULL){
		while(de=readdir(dr)){
			printf("%s\n", de->d_name); 

	}
		closedir(dr);


	
}
	else {
		printf("%s\n", st1);
	// 	stval = strtok (stcopy,"\n");
	// 	int j=0;
	// 	while(stval!=NULL){
	// 		s[j]=stval;
	// 		j++;
			


	// 		stval=strtok(NULL,"\n");

	// 	// while(strstr(st1, "\n")!=NULL){
	// 	// 	st1[strcspn(st1,"\r\n")] = 0;
	// 	// 	printf("%d\n", 1);
	// 	// }
		
	// }
	// int hi=0;
	// while(j!=0){
	// 	printf("%s", s[hi]);
	// 	j--;
	// }
}

}



void history(FILE *fp, char st1[]){
	char *epointer;
	epointer=strstr(st1,"--help");
	char s0[400];
	char help[200];
	getcwd(help,200);
	strcat(help,"/histhelp");
	char *epointer2=strstr(st1,"-c");
	if(epointer!=NULL){
		FILE *fc;
		fc=fopen(help,"r");
		while (fgets(s0, 400, fc) != NULL){
			printf("%s", s0);
		}
		printf("\n");
		fclose(fc);

	}
	else if(epointer2!=NULL){
		if (remove("file") == 0) {
		  int ggg=0;
		 }
		 else
      		printf("Unable to delete history:history does not exist\n");

	}
	else {
		char c[100];
		FILE* f = fopen("/home/karti/Desktop/Cprac/a12/file","r");
		int maxchar=100;

		fgets(c,100,f);

		if(c != NULL)
			printf("%s\n",c);
		
		fclose(f);




	}

}
void pwd(char st1[]){
	char *epointer;
	epointer=strstr(st1,"--help");
	char s0[400];
	char help[200];
	getcwd(help,200);
	strcat(help,"/pwdhelp");
	char *epointer2=strstr(st1,"-L");
	if(epointer!=NULL){
		FILE *fp;
		fp=fopen(help,"r");
		while (fgets(s0, 400, fp) != NULL){
			printf("%s", s0);
		}
		printf("\n");
		fclose(fp);

	}
	else {

	char s[200];
	printf("%s\n", getcwd(s,200));
	}

}

void forkdate(char st1[]){
	char s[200];
	getcwd(s,200);
	char finas[200];
	strcat(s,"/date");
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr, "%s\n", "Fork Failed");
	}
	else if(pid==0){
		execlp(s,"date",st1,NULL);
	}
	else{
		pid=wait(NULL);
		
	}
}


void forkmkdir(char st1[]){
	char s[200];
	getcwd(s,200);
	char finas[200];
	strcat(s,"/mkdire");
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr, "%s\n", "Fork Failed");
	}
	else if(pid==0){
		execlp(s,"mkdire",st1,NULL);
	}
	else{
		pid=wait(NULL);
		
	}
}


void forkremove(char st1[]){
	char s[200];
	getcwd(s,200);
	char finas[200];
	strcat(s,"/remove");
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr, "%s\n", "Fork Failed");
	}
	else if(pid==0){
		execlp(s,"remove",st1,NULL);
	}
	else{
		pid=wait(NULL);
		
	}
}
void forkcat(char st1[]){
	char s[200];
	getcwd(s,200);
	char finas[200];
	strcat(s,"/cat");
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr, "%s\n", "Fork Failed");
	}
	else if(pid==0){
		execlp(s," cat",st1,NULL);
	}
	else{
		pid=wait(NULL);
		
	}
}
void forklist(char st1[]){
	char s[200];
	getcwd(s,200);
	char finas[200];
	strcat(s,"/list");
	pid_t pid;
	pid=fork();
	if(pid<0){
		fprintf(stderr, "%s\n", "Fork Failed");
	}
	else if(pid==0){
		execlp(s,"list",st1,NULL);
	}
	else{
		pid=wait(NULL);
		
	}
}

void exitnow(){
	a++;


}


int main(){


	FILE *fp;
	fp=fopen("/home/karti/Desktop/Cprac/a12/file","a+");
	int MAXCHAR2=1000;
	char input[MAXCHAR2];


	// echo("someth\ni\nng");
	// storehistory("echo something",fp);
	// storehistory("echo something2",fp);
	// storehistory("echo something3",fp);


	while(a<1){
		fgets(input,MAXCHAR2,stdin);
		input[strcspn(input, "\r\n")] = 0;

		if(strstr(input, "echo")!=NULL){
			if(strstr(input,"-")!=NULL){
				if(strstr(input,"-e")!=NULL){
					char *inputptr=input;
					fprintf(fp,"%s\n",input);
					echo(inputptr+5);

				}
				else {
					printf("%s\n", "Invalid Command Option");
				}
			}

			else {

				char *inputptr=input;

				fprintf(fp,"%s\n",input);
				echo(inputptr+5);
			}

		}
		else if(strstr(input, "cd")!=NULL){
			if(strstr(input,"-")!=NULL){
				if(strstr(input,"--help")!=NULL){
					fprintf(fp,"%s\n",input);
					cd(input);
				}
				else {
					printf("%s\n", "Invalid Command Option");

				}
			}
			else {
					fprintf(fp,"%s\n",input);
					cd(input);

			}

		}


		else if(strstr(input, "pwd")!=NULL){
			fprintf(fp,"%s\n",input);
			pwd(input);

		}
		else if(strstr(input, "exit")!=NULL){
			exitnow();
			
		}
		else if(strstr(input, "history")!=NULL){
			if(strstr(input,"-")!=NULL){
				if(strstr(input,"--help")!=NULL || strstr(input,"-c")!=NULL){
					fprintf(fp,"%s\n",input);
					history(fp,input);
				}
				else {
					printf("%s\n", "Invalid Command Option");

				}
			}
			else {
				fprintf(fp,"%s\n",input);
					history(fp,input);

			}
			
		}


		else if(strstr(input, "date")!=NULL){
			fprintf(fp,"%s\n",input);
			forkdate(input);
			
		}
		else if(strstr(input, "mkdir")!=NULL){
			fprintf(fp,"%s\n",input);
			forkmkdir(input);

			
		}
		else if(strstr(input, "rm")!=NULL){
			fprintf(fp,"%s\n",input);
			forkremove(input);
			
		}
		else if(strstr(input, "cat")!=NULL){
			fprintf(fp,"%s\n",input);
			forkcat(input);
			
		}
		else if(strstr(input, "ls")!=NULL){
			fprintf(fp,"%s\n",input);
			forklist(input);
			
		}

	}

	fclose(fp);

	

	return 0;
}