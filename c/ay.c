#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int ay;
	int counter=0;
	do{
		if(counter==0){
			printf("kacinci ay:");
			scanf("%d",&ay);
			counter=1;
			continue;}
		if(counter==1){
			printf("Hata.Lutfen 1-12 arasý bir sayý girin:");
			scanf("%d",&ay);
			}
	}while(ay<1 || ay>12);
	
	switch(ay){
		case 1:
			printf("31 gun");
			break;
		case 2:
			printf("30 gun");
			break;
		case 3:
			printf("31 gun");
			break;
		case 4:
			printf("30 gun");
			break;
		case 5:
			printf("31 gun");
			break;
		case 6:
			printf("30 gun");
			break;
		case 7:
			printf("31 gun");
			break;
		case 8:
			printf("31 gun");
			break;
		case 9:
			printf("30 gun");
			break;
		case 10:
			printf("31 gun");
			break;
		case 11:
			printf("30 gun");
			break;
		case 12:
			printf("31 gun");
			break;
	}
	return 0;
}
