#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>
#include <dirent.h> 
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

void date(char st1[]){
	time_t current;

	time(&current);
	struct stat filestat;
	int ds=0;
	char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char * days[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
	if(strstr(st1,"-u")!=NULL){
		struct tm *gtime=gmtime(&current);
		char currentmon[20];
		char *monpointer=currentmon;
		char currentday[20];
		char *daypointer=currentday;
		monpointer=months[gtime->tm_mon];
		daypointer=days[gtime->tm_wday];



		 printf("%s %s %2d %2d:%02d:%d %2d\n", daypointer,monpointer,gtime->tm_mday,gtime->tm_hour,gtime->tm_min,gtime->tm_sec,gtime->tm_year+1900);
		}
	
	else if(strstr(st1,"-r")!=NULL){

		char *epointer=strstr(st1,"-r");
		 stat(epointer+3,&filestat);
		  printf(" File lastmodified: %s",
            ctime(&filestat.st_mtime));


	
	}
	else {
		printf("%s", ctime(&current));

	}


}


int main(int argc, char *argv[])
{
	date(argv[1]);
	return 0;
}