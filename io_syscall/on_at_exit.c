/* 
 * atexit is POSIX implementation.  
 * function definition : void out(void);
 */

#include <stdio.h>
#include <stdlib.h>

static void atexitFunc1(void)
{
	printf("atexit function 1 called\n");
}

static void atexitFunc2(void)
{
	printf("atexit function 2 called!\n");
}

static void onexitFunc(int exitStatus, void *args)
{
	printf("on_exit function called: status=%d, args=%ld\n",
			exitStatus, (long)args);
}

int main(void)	{

	/* 
	 * on_exit is supported by glibc library. 
	 * All the registered functions are called on LIFO fashion. 
	 */

	if (on_exit(onexitFunc,(void *) 10)!= 0)
		printf("on_exit failed!\n");
	if (atexit(atexitFunc1)!=0)
		printf("atexit 1 failed!\n");
	if (atexit(atexitFunc2))
		printf("atexit 2 failed!\n");
	if (on_exit(onexitFunc, (void *) 20)!=0)
		printf("on_exit 2 failed\n");
return 0;
}

