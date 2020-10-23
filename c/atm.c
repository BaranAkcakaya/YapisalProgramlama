#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int islem;
	int bakiye=1000;
	int tutar,iban;
	
	printf("islemler:/nPara Cekme:/nPara Yatırma:/Eft:/nExit/n");
	printf("İslem Seciniz:/n");
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
			printf("yatırmak Istediginiz Tutar:");
			scanf("%d",&tutar);
			bakiye+=tutar;
			printf("/nBakiyeniz:%d",bakiye);
			break;
		case 3:
			printf("Bakiyeniz:%d",bakiye);
			printf("IBAN NO:");
			scanf("%d",&iban);
			printf("yatırmak Istediginiz Tutar:");
			scanf("%d",&tutar);
			if(tutar>bakiye)
				printf("/nYetersiz Bakiye...");
			else{
				bakiye-=tutar;
				printf("Eft islemi basarılı...");
				printf("/nBakiyeniz:%d",bakiye);
			}
			break;
		case 4:
			printf("Kartınızı Alın...");
			break;
}
			
	
	return 0;
}
