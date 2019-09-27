#include<stdio.h>
#include<stdlib.h>
//defining macro for predefined size of the variable.
#define size 1000
int main()
{
    char c[1000];
    //file pointer *fptr 

    FILE *fptr;
    if((fptr=fopen("file1.txt","w"))==NULL)
    {
        printf("Error!");
         exit(1);
    }

    printf("Enter a sentence:\n");
    //fgets takes exactly three arguments
    fgets(c,size,stdin);
    fprintf(fptr,"%s",c);

    if ((fptr=fopen("file1.txt","r"))==NULL)
    {
        printf("Error occured!");
        exit(1);
    }
    fscanf(fptr,"%c",c);
    printf("Reading data from the file :\n%s",c);
    fclose(fptr);
    return 0;
}
