#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*void random(){
	srand(time(NULL));
	int sayi=1+rand()%250;
	printf("%d",sayi);
}

int main(int argc, char *argv[]) {
	random();
	return 0;
}*/

int random(){
	srand(time(NULL));
	int sayi=1+rand()%1000;
	return sayi;
}

int main(int argc, char *argv[]) {
	int sayi=random();
	int tahmin;
	int counter=0;
	do{
		if(counter==1){
			if(sayi>tahmin){
				printf("Daha buyuk deger giriniz :");
				scanf("%d",&tahmin);
			}
			else{
				printf("Daha kucuk deger giriniz :");
				scanf("%d",&tahmin);
			}
		}
		if(counter==0){
		printf("Bir sayi tahmin edin :");
		scanf("%d",&tahmin);
		counter=1;
		}
		
	}while(sayi!=tahmin);
	if(sayi==tahmin)
		printf("tebrikler buldunuz...");
	
	return 0;
}
