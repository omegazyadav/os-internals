#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
  
int main() 
{ 
    int file_desc = open("omega.txt", O_CREAT | O_WRONLY | O_RDONLY | O_APPEND, 0644);
      
    if(file_desc < 0) 
        printf("Error opening the file\n"); 
       
    int copy_desc = dup(file_desc); 
    printf("The value of file descritpor are : %d %d\n",file_desc,copy_desc) ;


    write(copy_desc,"omega\n", 6); 
          
    write(file_desc,"omegazyadav\n", 11); 
      
    return 0; 
}
