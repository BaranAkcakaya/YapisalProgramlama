#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int sirala(int dizi[],int uzunluk){
	int i;int size;int temp;int a=0;int b=0;
	size=(uzunluk-1)/2;
	for(i=0;i<uzunluk;i++){
		if(dizi[i]<dizi[size]){
			a++;
		}
		else if(dizi[i]>dizi[size]){
			b++;
		}
	}
	if(a==0)
		a++;
	if(b==0)
		b++;
	int dizi1[a];
	int dizi2[b];
	a=0;b=0;
	printf("%d\n",a);
	printf("%d\n",b);
	for(i=0;i<uzunluk;i++){
		if(dizi[i]<dizi[size]){
			dizi1[a]=dizi[i];
			a++;
		}
		else if(dizi[i]>dizi[size]){
			dizi2[b]=dizi[i];
			b++;
		}
	}
	for(i=0;i<a;i++){
		printf("%d",dizi1[i]);
	}
	if(dizi1!=NULL)
		sirala(dizi1,a);
	else{
		return dizi[size];
	}
	printf("%d",dizi[size]);
	if(dizi2!=NULL)
		sirala(dizi2,b);
	else{
		return dizi[size];
	}
}

int main(int argc, char *argv[]) {
	int uzunluk;int i;int eleman;
	printf("dizi kac elemanli olacak:");
	scanf("%d",&uzunluk);
	int dizi[uzunluk];
	printf("dizinin elemanlarini girin:");
	for(i=0;i<uzunluk;i++){
		scanf("%d",&eleman);
		dizi[i]=eleman;
	}
	printf("SIRALANMADAN ONCE DIZI:");
	for(i=0;i<uzunluk;i++){
		printf("%d ",dizi[i]);
	}
	printf("\nSIRALANDIKTAN SONRA DIZI:");
	sirala(dizi,uzunluk);
	
	
	return 0;
}
