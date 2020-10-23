#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sum;
void *runner(void *param); //burada void paramýn tipinin olmadigini ifade ediyor
int main(int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t attr;
	
	if(argc != 2){ //argc kac tane arguman aldýgýný kontrol edýyor
		fprintf(stderr,"usage:a.out<integer value>\n");
		return -1;
	}
	if(atoi(argv[1])<0){ //atoi = ascii to int verilen ilk parametreyi int ceviriyor
		fprintf(stderr,"½d must be >= 0\n",atoi(argv[1]));
		return -1;
	}
	
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	
	void *runner(void *param){
		int i,upper = atoi(param);
		sum = 0;
		for(i=1;i<=upper;i++){
			sum += 1;
		}
		pthread_exit(0);
	}
	return 0;
}
