#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//3 sayýnýn ortalamasýný alma...
/*int main(int argc, char *argv[]) {
	int a,b,c=0;
	int ort=0;
	printf("3 sayi giriniz :\n");
	scanf("%d %d %d",&a,&b,&c);
	a-=1;b+=2;c*=3;
	ort=(a+b+c)/3;
	printf("ortalama :%d",ort);
	
	return 0;
}*/

int main(){
	int sayi;
	int orta=0;
	printf("3 basamakli sayi giriniz:");
	scanf("%d",&sayi);
	if(sayi>999 || sayi<100){
		printf("hatali sayi girdiniz...");
	}
	else{
		sayi/=10;
		sayi=sayi%10;
		printf("%d",sayi);
		if(sayi%2==0){
			printf("\ncift");
		}
		else printf("\ntek");
	}
	
	
	return 0;
}
