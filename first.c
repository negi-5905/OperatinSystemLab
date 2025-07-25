#include<stdio.h>
#include<unistd.h>
int main(){
    int z = fork();
    int x = getpid();
    int y = getppid();
    if(z==0) printf("Child process\npid = %d \nppid = %d \n",x,y);
    else if(z>=1) printf("Parent process\npid = %d \n",x);
    else printf("process create\n");
   
    return 0;
}