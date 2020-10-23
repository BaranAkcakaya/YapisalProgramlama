#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -100000000

struct dugum {
        int icerik;
        struct dugum *sol;
        struct dugum *sag;
};

struct ikili_arama_agaci {
        struct dugum *kok;
};

void ikili_arama_agaci_olustur(struct ikili_arama_agaci **agac){
        *agac=(struct ikili_arama_agaci*)malloc(sizeof(struct ikili_arama_agaci));
        if(*agac==NULL) {
                printf("Heapte gerekli yer ayrilamadi... exit ...\n");
                exit(1);
        }
        (*agac)->kok=NULL;
}

int ikili_agac_bosmu(struct ikili_arama_agaci *agac){
        if(agac->kok==NULL) return 1;
        else return 0;
}

struct dugum* dugum_olustur(int icerik){
        struct dugum *d = (struct dugum*)malloc(sizeof(struct dugum));
        if(d==NULL) {
                printf("Heapte gerekli yer ayrilamadi... exit ...\n");
                exit(1);
        }
        d->icerik = icerik; //(*d).icerik=icerik;
        d->sol=d->sag=NULL;
        return d;
}


void ekle(struct ikili_arama_agaci *agac,int icerik){
        struct dugum *dugum;
        struct dugum *d;
        struct dugum *geri;

        d=agac->kok;
        while(d!=NULL) {
                geri=d;
                if(icerik < d->icerik) d=d->sol;
                else if(icerik > d->icerik) d= d->sag;
                else return;
        }
        dugum=dugum_olustur(icerik);
        if(agac->kok==NULL) {
                agac->kok = dugum;
                return;
        }
        if(icerik < geri->icerik) geri->sol = dugum;
        else geri->sag = dugum;

}

void inorder_yardimci(struct dugum *kok){

        if(kok==NULL) return;
        inorder_yardimci(kok->sol);
        printf("%4d ",kok->icerik);
        inorder_yardimci(kok->sag);

}

void inorder(struct ikili_arama_agaci *agac){
        if(agac==NULL) return;
        inorder_yardimci(agac->kok);
        printf("\n");
}

void preorder_yardimci(struct dugum *kok){

        if(kok==NULL) return;
        printf("%4d ",kok->icerik);
        preorder_yardimci(kok->sol);
        preorder_yardimci(kok->sag);

}
void preorder(struct ikili_arama_agaci *agac){
        if(agac==NULL) return;
        preorder_yardimci(agac->kok);
        printf("\n");
}

void postorder_yardimci(struct dugum *kok){
        if(kok==NULL) return;
        postorder_yardimci(kok->sol);
        postorder_yardimci(kok->sag);
        printf("%4d ",kok->icerik);

}

void postorder(struct ikili_arama_agaci *agac){
        if(agac==NULL) return;
        postorder_yardimci(agac->kok);
        printf("\n");
}

int dugum_sayisi(struct dugum *kok){
        if(kok==NULL) return 0;
        return 1+dugum_sayisi(kok->sol)+dugum_sayisi(kok->sag);
}

int yaprak_sayisi(struct dugum *kok){
        if(kok==NULL) return 0;
        if(kok->sol==NULL && kok->sag == NULL) return 1;
        else return yaprak_sayisi(kok->sol)+yaprak_sayisi(kok->sag);
}

void sil(struct ikili_arama_agaci *agac, int silinen){

        struct dugum *d=agac->kok;
        struct dugum *parent=NULL;
        struct dugum *d1,*d2;
        int sol;
        while(d!=NULL) {
                if(silinen < d->icerik) {
                        parent=d; d=d->sol; sol=1;
                }
                else if(silinen > d->icerik) {
                        parent=d; d=d->sag; sol = 0;
                }
                else break;
        }
        if(d==NULL) return;
        if(d->sol==NULL) { // silinen dugumun solu bos
                if(parent==NULL) agac->kok=d->sag;
                else{
                        if(sol==1) parent->sol=d->sag;
                        else parent->sag=d->sag;
                }
        }
        else if(d->sag==NULL) { // silinen dugumun sagi bos
                if(parent==NULL) agac->kok=d->sol;
                else {
                        if(sol==1) parent->sol=d->sol;
                        else parent->sag = d->sol;
                }
        }
        else { // silinen dugumun hem sagi hem de solu dolu
               // silinencek dugumun saginin en soluna git
               // en soldaki dugum silinen dugumun konumunu alir
                d1=d->sag;
                d2=NULL;
                while(d1->sol!=NULL) {
                        d2=d1;
                        d1=d1->sol;
                }
                if(d2!=NULL) {
                        d2->sol= d1->sag;
                        d1->sag=d->sag;
                }
                d1->sol = d->sol;
                if(parent==NULL) agac->kok=d1; // agacin koku degisti
                else {
                        if(sol==1) parent->sol=d1;
                        else parent->sag=d1;
                }
        }
        free(d);
}

void yoket(struct dugum **kok){
        if(*kok!=NULL) {
                yoket(&(*kok)->sol);
                yoket(&(*kok)->sag);
                free(*kok);
                *kok=NULL;
        }
}


int foo(struct dugum *kok){ // ic dugum sayisi
        if(kok==NULL) return 0;
        else if(kok->sol!=NULL || kok->sag!=NULL)
                return 1+foo(kok->sol) + foo(kok->sag);
        else return 0;
}
int kardes_mi(struct dugum *kok,struct dugum *d1,struct dugum *d2){
struct dugum *once=kok;
struct dugum *temp;
int kontrol;
if(once==NULL){
return 0;
}
//printf("sa");
while(once!=NULL && once->sag!=NULL && once->sol!=NULL){
if((once->sol->icerik == d1->icerik && once->sag->icerik == d2->icerik) || (once->sol->icerik == d2->icerik && once->sag->icerik == d1->icerik)){
kontrol=1;
//printf("1");
break;
}
else{
kontrol=0;
//printf("2");
}
if(once->icerik<d1->icerik && once->sag!=NULL){
temp=once;
once=once->sag;
//printf("3");
}
else if (once->icerik>d1->icerik && once->sol!=NULL){
temp=once;
once=once->sol;
//printf("4");
}
else{
break;
}
}
if (kontrol==1){
return 1;
}
else{
return 0;
}
}

void ayni_mi(struct dugum *temp1,struct dugum *temp2){
		///printf("\n%d %d",temp1->icerik,temp2->icerik);
		if(temp1->icerik!= temp2->icerik){
			printf("\n\tAyni Degil!!!!!!");exit(1);}
		if(temp1->sol!=NULL && temp2->sol!=NULL) ayni_mi(temp1->sol,temp2->sol);	
    	if(temp1->sag!=NULL && temp2->sag!=NULL) ayni_mi(temp1->sag,temp2->sag);	
}

int main(int argc, char** argv) {
        struct ikili_arama_agaci *agac=NULL;
        struct ikili_arama_agaci *agac1=NULL;

        ikili_arama_agaci_olustur(&agac);
        ikili_arama_agaci_olustur(&agac1);
        struct dugum *d1,*d2;
        d1=dugum_olustur(50);
        d2=dugum_olustur(75);

        ekle(agac,100);ekle(agac1,10);
        ekle(agac,50); ekle(agac1,50); 
        ekle(agac,200);ekle(agac1,200);
        ekle(agac,25); ekle(agac1,25); 
        ekle(agac,75); ekle(agac1,75); 
        ekle(agac,20); ekle(agac1,20); 
        ekle(agac,35); ekle(agac1,35); 
        ekle(agac,9);  ekle(agac1,9);  
        ekle(agac,99); ekle(agac1,99); 
        ekle(agac,500);ekle(agac1,500);
        ekle(agac,400);ekle(agac1,400);
        ekle(agac,300);ekle(agac1,300);
        ekle(agac,210);ekle(agac1,210);
        ekle(agac,375);ekle(agac1,375);
        ekle(agac,30); ekle(agac1,30); 
        ekle(agac,170);ekle(agac1,170);
        inorder(agac); inorder(agac1); 
        
ayni_mi(agac->kok,agac1->kok);

        return 0;
}

