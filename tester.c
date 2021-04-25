#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <sys/wait.h>

int main(){

	int c;
	int cr;
  while (c != EOF)
    {
      printf("\n Enter input: ");
      c = getchar();
      cr = getchar();
      putchar(c);
    }
	return 0;
}