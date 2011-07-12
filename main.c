#include <pthread.h>
#include <stdlib.h>

void*run_job(void*a){
	int i=0;
	int j=0;
	for(i=0;i<100000000;i++){
		j+=i;
	}
}

int main(int argc,char**argv){

	pthread_attr_t threadAttributes;
	pthread_attr_setscope(PTHREAD_SCOPE_PROCESS);

	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1,NULL,run_job,NULL);
	pthread_create(&thread2,NULL,run_job,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	return EXIT_SUCCESS;
}
