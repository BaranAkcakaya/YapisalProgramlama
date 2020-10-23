#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
	int a;
	int b;
	int c;
	float x1;float x2;
	float kok; 
	printf("2.dereceden ifadenin katsayýsý :");
	scanf("%d",&a);
	printf("tekkatlý sayýnýn katsayýsýný girin :");
	scanf("%d",&b);
	printf("sabit sayýyý giriniz :");
	scanf("%d",&c);
	kok=pow(b,2)-(4*a*c);
	kok=sqrt(kok);
	if(kok>0){
		x1=(-b-kok)/(2*a);
		x2=(-b+kok)/(2*a);
		printf("birinci kok: %.2f""\nikinci kok: %.2f",x1,x2);
	}
	else if(kok==0){
		x1=b/2*a;
		printf("x1=x2=%.2f",x1);
	}
	else{
		printf("kok yok...");
	}
	
	
	
	return 0;
}
