#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct student{
	char name[20];
	int number;
	int vize;
	int final;
};
struct student bilgiAl(struct student dizi[5]){
	int i;
	for(i=0;i<5;i++){
		printf("%d . ogrenci bilgileri:\n",i+1);
		scanf("%s %d %d %d",&dizi[i].name,&dizi[i].number,&dizi[i].vize,&dizi[i].final);
	}
}
struct student yazdir(struct student dizi[5]){
	int i;
	for(i=0;i<5;i++){
		printf("%s %d %d %d\n",dizi[i].name,dizi[i].number,dizi[i].vize,dizi[i].final);
	}
}
struct student sirala(struct student dizi[5]){
	int i,j;
	struct student temp;
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(dizi[i].final>dizi[j].final){
				temp=dizi[i];
				dizi[i]=dizi[j];
				dizi[j]=temp;
			}
			
		}
		
	}
}

int main(int argc, char *argv[]) {
	int girdi;
	struct student dizi[5];
	printf("1.BILGI GIRIS:\n");
	printf("2.YAZDIR:\n");
	printf("3.SIRALA:\n");
	printf("4.CIKIS:\n");
	scanf("%d",&girdi);
	do{
		if(girdi>4){
			printf("hatali giris.\n");
				printf("1.BILGI GIRIS:\n");
				printf("2.YAZDIR:\n");
				printf("3.SIRALA:\n");
				printf("4.CIKIS:\n");
				scanf("%d",&girdi);
		}
		if(girdi==1){
			bilgiAl(dizi);
				printf("1.BILGI GIRIS:\n");
				printf("2.YAZDIR:\n");
				printf("3.SIRALA:\n");
				printf("4.CIKIS:\n");
				scanf("%d",&girdi);
		}
		if(girdi==2){
			yazdir(dizi);
				printf("1.BILGI GIRIS:\n");
				printf("2.YAZDIR:\n");
				printf("3.SIRALA:\n");
				printf("4.CIKIS:\n");
	scanf("%d",&girdi);
		}
		if(girdi=3){
			sirala(dizi);
			yazdir(dizi);
				printf("1.BILGI GIRIS:\n");
				printf("2.YAZDIR:\n");
				printf("3.SIRALA:\n");
				printf("4.CIKIS:\n");
				scanf("%d",&girdi);
		}
		
	}while(girdi!=4);
	printf("cikis yapildi.\n");
	
	
	return 0;
}
