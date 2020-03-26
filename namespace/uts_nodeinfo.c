#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char *argv[]){

struct utsname *info,inf;
info=&inf;
int ret;
ret=uname(info);
if(ret==-1)
	perror("UTS: ");

printf("%s %s %s %s %s %s\n",info->sysname,info->nodename,info->release,info->version,info->machine,info->__domainname);
return 0;


}
