#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

void*run_job(void*a){
	printf("Before yield\n");
	sched_yield();
	printf("After yield\n");

	while(1){
	}

	return NULL;
}

int main(int argc,char**argv){
	printf("Setting attributes\n");
	pthread_attr_t threadAttributes;

	/* PTHREAD_SCOPE_PROCESS not supported in Linux */
	if(0!=pthread_attr_setscope(&threadAttributes,PTHREAD_SCOPE_SYSTEM))
		printf("pthread_attr_setscope failed.\n");

	pthread_t thread1;
	pthread_t thread2;

	printf("Creating threads\n");
	pthread_create(&thread1,NULL,run_job,NULL);
	pthread_create(&thread2,NULL,run_job,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	return EXIT_SUCCESS;
}
