#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void harfdondur(char dizi[]){
	int fark;int i;
	char *p=dizi;
	fark='a'-'A';
	/*while(p[i] !='\0'){
		if(p[i] >= 'A' && p[i] <= 'Z') {
            p[i] += fark;
        } 
		else if(p[i] >= 'a' && p[i] <= 'z') {
            p[i] -= fark;
        }
        printf("%c", p[i]);
        i++;*/
    for(i=0;i<strlen(p)-1;i++){
    	if(isupper(dizi[i])){
    		dizi[i]=tolower(dizi[i]);
		}
		else{
			dizi[i]=toupper(dizi[i]);
		}
	}
}

int main(int argc, char *argv[]) {
	char girdi[30];
	
	printf("bir karakter giriniz:");
	scanf("%s",&girdi);
	harfdondur(girdi);
	
	return 0;
}
