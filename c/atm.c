#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int islem;
	int bakiye=1000;
	int tutar,iban;
	
	printf("islemler:/nPara Cekme:/nPara Yat�rma:/Eft:/nExit/n");
	printf("�slem Seciniz:/n");
	scanf("%d",&islem);
	
	switch(islem){
		case 1:
			printf("Bakiyeniz:%d",bakiye);
			printf("Cekmek Istediginiz Tutar:");
			scanf("%d",&tutar);
			if(tutar>bakiye)
				printf("/nYetersiz Bakiye...");
			else{
				bakiye-=tutar;
				printf("/nBakiyeniz:%d",bakiye);
			}
			break;
		case 2:
			printf("Bakiyeniz:%d",bakiye);
			printf("yat�rmak Istediginiz Tutar:");
			scanf("%d",&tutar);
			bakiye+=tutar;
			printf("/nBakiyeniz:%d",bakiye);
			break;
		case 3:
			printf("Bakiyeniz:%d",bakiye);
			printf("IBAN NO:");
			scanf("%d",&iban);
			printf("yat�rmak Istediginiz Tutar:");
			scanf("%d",&tutar);
			if(tutar>bakiye)
				printf("/nYetersiz Bakiye...");
			else{
				bakiye-=tutar;
				printf("Eft islemi basar�l�...");
				printf("/nBakiyeniz:%d",bakiye);
			}
			break;
		case 4:
			printf("Kart�n�z� Al�n...");
			break;
}
			
	
	return 0;
}
