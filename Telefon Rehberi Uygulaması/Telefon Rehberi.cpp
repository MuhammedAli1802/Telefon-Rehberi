
/*	NOT
--> Favori Menüsünde Düzenleme Yapýlamaz.
--> Program Cýkýs Yapmadan KAPATILMAMALIDIR !!!
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kisieklememenusu();
void anamenu();
void kisibilgilerimenusu();
void kisilermenusu();
void duzenlememenusu();
void favorimenusu();
void favorikisibilgilerimenusu();

struct kisiler{
	char ad[10],soyad[10],Not[20],posta[40];
	int favori;
	long long int tel;
}kayit[10];

    char mesaj[20];
	int kayitmenusecim,anamenusecim,kisilersecim,kisibilgilerimenusecim,duzenlememenusecim,favorisecim; //secimler
	int randomnum;
	int n=0; //n=kisisayisi
	int kontrol=0; // favorimenusunde kullandým
	FILE *yazma,*okuma,*nokuma,*nyazma,*favoriyazma,*favoriokuma; //dosya deðiþkenleri

void Yazma(){
	if((yazma=fopen("kayit.txt","w"))==NULL){
		printf("Kayit dosyasý yazmak icin acilamadi.\n");
	}
	for(int i=0;i<n-1;i++){
		fprintf(yazma,"%s %s %lld %s %s %d\n",kayit[i].ad,kayit[i].soyad,kayit[i].tel,kayit[i].Not,kayit[i].posta,kayit[i].favori);
	}
	fprintf(yazma,"%s %s %lld %s %s %d",kayit[n-1].ad,kayit[n-1].soyad,kayit[n-1].tel,kayit[n-1].Not,kayit[n-1].posta,kayit[n-1].favori);
	fclose(yazma);
}

void Okuma(){
	if((okuma=fopen("kayit.txt","r"))==NULL){
		printf("Kayit dosyasi okumak icin acilamadi.\n");
	}
	for(int i=0;i<n;i++){
		fscanf(okuma,"%s%s%lld%s%s%d\n",kayit[i].ad,kayit[i].soyad,&kayit[i].tel,kayit[i].Not,kayit[i].posta,&kayit[i].favori);
	}
	fclose(okuma);
}

int n_okuma(){
	if((nokuma=fopen("n.txt","r"))==NULL){
		printf("n dosyasý okumak icin acilamadi.\n");
		return 0;
	}
	fscanf(nokuma,"%d",&n);
	fclose(nokuma);
}

int n_yazdirma(){
	if((nyazma=fopen("n.txt","w"))==NULL){
		printf("n dosyasý yazmak icin acilamadi.\n");
		return 0;
	}
	fprintf(nyazma,"%d",n);
	fclose(nyazma);
}

void anamenu(){
	printf("*************** A N A  M E N U ***************\n");
    printf("1. Yeni Kisi Ekle\n2. Kisiler\n3. Arama Yap\n4. Favori Kisilerim\n5. Cikis\n");
    scanf("%d",&anamenusecim);
    switch(anamenusecim){
    	case 1: kisieklememenusu();
    	case 2: kisilermenusu();
    	case 3: printf("Numarayi Yaziniz\n"); scanf("%d",&randomnum); printf("ARANIYOR\n"); anamenu();
    	case 4:	for(int i=0;i<n;i++){
    			if(kayit[i].favori!=0){
    			kontrol=1;
			}
		}
		if(kontrol==0){
			printf("Favori Kisilerinizde Kimse Yok\n"); anamenu();
		}
		favorimenusu();
		case 5: Yazma(); exit(0);
	}
}

void kisieklememenusu(){
	system("cls");
	printf("Geri Gelmek Icin '0' a Basiniz\n Lutfen Once Ad Ekleyiniz\n1. Ad Ekle\n2. Soyad Ekle\n3. Telefon Numarasi Ekle\n4. E-posta Ekle\n5. Not Ekle\n");
    scanf("%d",&kayitmenusecim);
    switch(kayitmenusecim){
    	case 0: anamenu();
    	case 1: printf("Ad: "); scanf("%s",&kayit[n].ad);

			n++; n_yazdirma(); 
			strcpy(kayit[n-1].soyad,"."); 
			strcpy(kayit[n-1].posta,"."); 
			strcpy(kayit[n-1].Not,".");
			kayit[n-1].favori=0;
			kayit[n-1].tel=0;
			
			kisieklememenusu();
			
    	case 2: printf("Soyad: ");  scanf("%s",&kayit[n-1].soyad);  kisieklememenusu();
    	case 3: printf("Numara: ");  scanf("%lld",&kayit[n-1].tel);  kisieklememenusu();
    	case 4: printf("E-posta: ");  scanf("%s",&kayit[n-1].posta); kisieklememenusu();
    	case 5: printf("Not: ");  scanf("%s",&kayit[n-1].Not);  kisieklememenusu();
	}
}

void kisibilgilerimenusu(){
	system("cls");
	printf("           %s %s\n",kayit[kisilersecim-1].ad,kayit[kisilersecim-1].soyad); 
	printf("Numara: %lld\n",kayit[kisilersecim-1].tel);
	printf("E-posta: %s\n",kayit[kisilersecim-1].posta);
	printf("Not: %s\n",kayit[kisilersecim-1].Not);
    printf("Geri Gelmek Icin '0' a Basiniz\n1. Ara\n2. Mesaj Gonder\n3. Favorilere Ekle\n4. Engelle\n5. Duzenle\n6. Kisiyi Sil\n");
    scanf("%d",&kisibilgilerimenusecim);
        switch(kisibilgilerimenusecim){
        	case 0: kisilermenusu();
        	case 1: printf("ARANIYOR...\n"); kisibilgilerimenusu();
        	case 2: printf("Mesaj Yazin\n"); scanf("%s",&mesaj); kisibilgilerimenusu();
        	case 3: kayit[kisilersecim-1].favori=1;  kisibilgilerimenusu();
        	case 4: printf("Kisiyi Engellediniz\n"); kisibilgilerimenusu();
        	case 5: duzenlememenusu();
			case 6: 
				for(int i=(kisilersecim-1);i<n;i++){
				strcpy(kayit[i].ad,kayit[i+1].ad);
				strcpy(kayit[i].soyad,kayit[i+1].soyad);
				kayit[i].favori=kayit[i+1].favori;
				kayit[i].tel=kayit[i+1].tel;
				strcpy(kayit[i].posta,kayit[i+1].posta);
				strcpy(kayit[i].Not,kayit[i+1].Not);
			}
			n--; n_yazdirma();
			
			printf("Kisi Basariyla Silindi\n"); kisilermenusu();
		}
}

void favorikisibilgilerimenusu(){
	printf("%s %s\n",kayit[favorisecim-1].ad,kayit[favorisecim-1].soyad); 
	printf("Numara: %lld\n",kayit[favorisecim-1].tel);
	printf("E-posta: %s\n",kayit[kisilersecim-1].posta);
	printf("Not: %s\n",kayit[kisilersecim-1].Not);
    printf("Geri Gelmek Icin '0' a Basiniz\n1. Ara\n2. Mesaj Gonder\n3. Favorilere Ekle\n4. Engelle\n5. Kisiyi Sil\n");
    scanf("%d",&kisibilgilerimenusecim);
        switch(kisibilgilerimenusecim){
        	case 0: favorimenusu();
        	case 1: printf("ARANIYOR...\n"); favorimenusu();
        	case 2: printf("Mesaj Yazin\n"); scanf("%s",&mesaj); favorimenusu();
        	case 3: kayit[kisilersecim-1].favori=1; favorimenusu();
        	case 4: printf("Kisiyi Engellediniz\n"); favorimenusu();
			case 5: printf("Kisi Basariyla Silindi\n"); favorimenusu();		
		}
}
void kisilermenusu(){
	system("cls");
	printf("Geri Gelmek Icin '0' a Basiniz\n");

	for(int i=0;i<n;i++){
    		printf("%d. %s %s\n",i+1,kayit[i].ad,kayit[i].soyad);
		}
		scanf("%d",&kisilersecim);
		if(kisilersecim==0){
			anamenu();
		}
		kisibilgilerimenusu();
}

void duzenlememenusu(){
	printf("Geri Gelmek Icin '0' a Basiniz\n1. Ad Ekle/Degistir\n2. Soyad Ekle/Degistir\n3. Telefon Numarasi Ekle/Degistir\n4. E-posta Ekle/Degistir\n5. Not Ekle/Degistir\n");
	scanf("%d",&duzenlememenusecim);
                    switch(duzenlememenusecim){
                    	case 0: kisibilgilerimenusu(); break;
                    	case 1: printf("Ad: "); scanf("%s",&kayit[kisilersecim-1].ad); duzenlememenusu();
                    	case 2: printf("Soyad: "); scanf("%s",&kayit[kisilersecim-1].soyad); duzenlememenusu();
                    	case 3: printf("Numara: "); scanf("%lld",&kayit[kisilersecim-1].tel); duzenlememenusu();
                    	case 4: printf("E-posta: "); scanf("%s",&kayit[kisilersecim-1].posta); duzenlememenusu();
                    	case 5: printf("Not: "); scanf("%s",&kayit[kisilersecim-1].Not); duzenlememenusu();
					}
}

void favorimenusu(){
	system("cls");
	printf("Geri Gelmek Icin '0' a Basiniz\n");
	int a=1;
	for(int i=0;i<n;i++){
		if(kayit[i].favori==1){
			printf("%d. %s %s\n",a,kayit[i].ad,kayit[i].soyad); a++;
		}
	}
	a=1;
	scanf("%d",&favorisecim);
		if(favorisecim==0){
			anamenu();
		}
		favorikisibilgilerimenusu();
}

int main(){
	n_okuma();
	Okuma();
	anamenu();
	return 0;
}
