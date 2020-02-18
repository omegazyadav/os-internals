#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
  
int main() 
{ 
	char buf1[1000],buf2[1000];
    int file_desc = open("omega.txt", O_CREAT | O_WRONLY | O_RDONLY | O_APPEND, 0644);
      
    if(file_desc < 0) 
        printf("Error opening the file\n"); 
    close(0)   ;
    int copy_desc = dup(file_desc); 
    printf("The value of file descritpor are : %d %d\n",file_desc,copy_desc) ;


    write(copy_desc,"omega\n", 6); 
          
    write(file_desc,"omegazyadav\n", 11); 
    close(file_desc);
    close(copy_desc);
    
// Reading the content of the file. 

    int fd1=open("omega.txt",O_RDWR);
    if(fd1==-1){
	    printf("Read Error\n!");
    }
    int fd2=dup(fd1);

    ssize_t rd1,rd2; 
    rd1=read(fd1,buf1,1000);
     if(rd1==-1)
	     printf("Read Error!");
    rd2=read(fd2,buf2,1000);
    if(rd2==-1)
	    printf("Read Error!");
    printf("The content of the file is :%s\n",buf2);
    return 0; 
}
