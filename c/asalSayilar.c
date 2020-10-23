#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int asal(int sayi,int i){
	if(i==1){
		return 0;
	}
	if(sayi%i==0){
		return -1;
	}
	asal(sayi,i-1);
}
int ekran(int girdi){
	printf("1.ASAL SAYI BULMA\n");
    printf("2.SAYI CARPIMI\n");
	printf("3.CIKIS\n");
	scanf("%d",&girdi);
	return girdi;
}
int carpim(int a,int b){
	return a*b;
}

int main(int argc, char *argv[]) {
	int girdi;int sonuc=0;int sayi;int deger1;int deger2;
	
	printf("1.ASAL SAYI BULMA\n");
    printf("2.SAYI CARPIMI\n");
	printf("3.CIKIS\n");
	scanf("%d",&girdi);
	
	do{
		if(girdi>3){
			printf("hatali giris...\n");
			girdi=ekran(girdi);
		}
		else{
			switch(girdi){
				case 1:
					printf("Bir Sayi Giriniz:");
					scanf("%d",&sayi);
					int i=pow(sayi,0.5);
					sonuc=asal(sayi,i);
					if(sonuc==0){
						printf("Sayi Asaldir.\n");
					}
					else{
						printf("sayi asal degildir.\n");
					}
					girdi=ekran(girdi);
					break;
				case 2:
					srand(time(NULL));
					deger1=1+rand()%21;
					deger2=2+rand()%101;
					printf("ilk sayi:%d ikinci sayi:%d\n",deger1,deger2);
					sonuc=carpim(deger1,deger2);
					printf("carpimlari:%d\n",sonuc);
					girdi=ekran(girdi);
					break;	
			}
		}
		
	}while(girdi!=3);
	printf("CIKIS YAPILDI.");
	
	return 0;
}
