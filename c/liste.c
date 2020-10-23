#include <stdio.h>
#include <stdlib.h>
struct list{
	struct list *onceki;
	int veri;
	struct list *sonraki;
}liste;
struct list *yeni,*ilk=NULL,*gecici,*son;


int main(int argc, char *argv[]) {
	int i,data,sayi;
	printf("Kac Eleman Eklensin: ");
	scanf("%d",&sayi);
	for(i=0;i<sayi;i++){
		printf("Veriyi Giriniz: ");
		scanf("%d",&data);
		ekle(data);
	}
	listele();
	
	return 0;
}

void ekle(int data){
	yeni=malloc(sizeof(liste));
	yeni->veri=data;
	if(ilk==NULL){
		ilk=yeni;
		son=yeni;
        ilk->onceki=NULL;
}
else{
	son->sonraki=yeni;
	yeni->onceki=son;
	son=yeni;
	son->sonraki=NULL;
}	
}
void listele(){
	gecici=ilk;
 printf("veri : %d , onceki : NULL , sonraki : %d",ilk->veri,ilk->sonraki->veri);
 gecici=gecici->sonraki;
	while(gecici->sonraki!=NULL){
		printf("\nSAYININ KENDISI: %d",gecici->veri);
		printf("\nSAYININ SONRASI: %d",gecici->sonraki->veri);
		printf("\n Sayinin Oncesi: %d",gecici->onceki->veri);
		gecici=gecici->sonraki;
	}
} 
