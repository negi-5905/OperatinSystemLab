#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
int main() {
   DIR *dir;
   struct dirent *entity;
   dir = opendir(".");
   if(dir==NULL){
       printf("no directory\n");
       return 0;
   }
   while((entity=readdir(dir))!=NULL){
       printf("%s\n",entity->d_name);
   }
    closedir(dir);
    return 0;
}
