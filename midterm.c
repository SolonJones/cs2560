/*
   Write a C program to read from the standard input (keyboard) and write them to a file you named on the command line.
   An example usage would be:
   myprog  newfile
   This program will capture whatever you typed from keyboard and save them to newfile.
   Write your program using standard i/o functions for file access.
   Script your terminal session with timing log option to show how your program compiles and runs.
   Submit your script outputs as was done in lab and all source code.
   */
#include<stdio.h>

int main(int argc, char* argv[]){
    // check if input argc is 2 or print error message 
    
    if(argc != 2){
        perror("cmd line input incorrect");
    }
    
    // if the argument is legal, open a file stream for "w"
    // use fscanf with stdin to scan the input 
    else{
        FILE* ptr; 
   //     printf("%s",argv[1] );
        ptr = fopen(argv[1],"w");
        if(ptr==NULL){
            perror("open failed");
        }
        char buf[500]; 
        puts("type <C-d> to signal eof ");
        
        int size = scanf("%499[^\n]s", buf);
        fprintf(ptr,"%s",buf );
        fclose(ptr);
    }
}
