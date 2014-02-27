#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>


sem_t sem_a;
void *task1();

int main(void){
	int ret=0;
	pthread_t thrd1;

	sem_init(&sem_a,0,1);

	ret=pthread_create(&thrd1,NULL,task1,NULL); //创建子线程

	pthread_join(thrd1,NULL); //等待子线程结束
}

void *task1(){
	
	int sval = 0;

	sem_wait(&sem_a); //持有信号量

	sleep(5); //do_nothing


	sem_getvalue(&sem_a,&sval);

	printf("sem value = %d\n",sval);

	sem_post(&sem_a); //释放信号量
}
