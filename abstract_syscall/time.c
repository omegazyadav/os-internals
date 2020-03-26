#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
	char *local_time,*c_time,*gm_time;

	struct tm *t,*gmt; 
	time_t t_m, rawtime; 
	t_m=time(&rawtime);
	if(t_m==-1)
		perror("Time:");

	t=localtime(&t_m);
	gmt=gmtime(&t_m);
	c_time=ctime(&t_m);
	
	local_time=asctime(t);
	gm_time=ctime(&t_m);
	printf("Standard Time: %s\n",local_time);

	printf("Local Time: %s\n",c_time);
	printf("Greenwich Mean Time:%s\n",gm_time);
	return 0;
	
	

}
