#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
	char *local_time,*c_time;

	struct tm *t; 
	time_t t_m, rawtime; 
	t_m=time(&rawtime);
	if(t_m==-1)
		perror("Time:");

	t=localtime(&t_m);
	c_time=ctime(&t_m);
	
	local_time=asctime(t);

	printf("Standard Time: %s\n",local_time);

	printf("Local Time: %s\n",c_time);
	return 0;
	
	

}
