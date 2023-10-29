#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void randomsayilaribuyuktenkucugesiralama(){
	int i,j,temp;
    int sayilar[100];
    srand(time(0)); // Rastgele sayý üretimi 

    // Rastgele 100 sayýyý diziye ekler
    for (i = 0; i < 100; i++) {
        sayilar[i] = rand() % 1000; // 0 ile 999 arasýnda rastgele sayýlar
    }

    printf("Rastgele Sayilar:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", sayilar[i]);
    }
    
	for(j=0;j<100;j++){
        for(i=0;i<100;i++){
            if(sayilar[i]<sayilar[i+1]){
                temp=sayilar[i];
                sayilar[i]=sayilar[i+1];
                sayilar[i+1]=temp;
            }
        }
    }
	printf("\n\nBuyukten kucuge siralanmis sayilar :\n");
    for(i=0;i<100;i++){
        printf("%d ",sayilar[i]);
    }
}
// Öðrenci düðüm yapýsý
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

// Yeni bir öðrenci düðümü oluþturan fonksiyon 
struct Ogrenci* yeniOgrenci(int numara, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strncpy(ogrenci->isim, isim, sizeof(ogrenci->isim));
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Öðrenci listesini yazdýran ve sayan fonksiyon
void ogrenciListesiniYazdirVeSay(struct Ogrenci* baslangic) {
    int sayac = 0;
    struct Ogrenci* current = baslangic;
    
    while (current != NULL) {
        sayac++;
        printf("%d- Numara: %d, Isim: %s, Yas: %d\n", sayac, current->numara, current->isim, current->yas);
        current = current->sonraki;
    }
    
    printf("Toplam ogrenci sayisi: %d\n", sayac);
}
// Öðrenci ismine göre arama yapan fonksiyon
struct Ogrenci* ogrenciAra(const char* arananIsim, struct Ogrenci* baslangic) {
    struct Ogrenci* current = baslangic;
    while (current != NULL) {
        if (strcmp(current->isim, arananIsim) == 0) {
            return current;
        }
        current = current->sonraki;
    }
    return NULL; // Aranan öðrenci bulunamadýysa NULL döner
}
// En uzun ismi yazdýran fonksiyon
void enUzunIsmiYazdir(struct Ogrenci* baslangic) {
    int maxUzunluk = 0;
    char enUzunIsim[50];
    struct Ogrenci* current = baslangic;
    
    while (current != NULL) {
        int uzunluk = strlen(current->isim);
        if (uzunluk > maxUzunluk) {
            maxUzunluk = uzunluk;
            strncpy(enUzunIsim, current->isim, sizeof(enUzunIsim));
        }
        current = current->sonraki;
    }
    
    printf("Listedeki en uzun isim: %s\n", enUzunIsim);
    printf("Uzunluk: %d\n", maxUzunluk);
}

// Baðlý liste baþlangýç düðümü
struct Ogrenci* baslangic = NULL;

// Öðrenci düðümünü liste sonuna ekleyen fonksiyon
void ogrenciEkle(struct Ogrenci* yeniDugum) {
    if (baslangic == NULL) {
        baslangic = yeniDugum;
    } else {
        struct Ogrenci* current = baslangic;
        while (current->sonraki != NULL) {
            current = current->sonraki;
        }
        current->sonraki = yeniDugum;
    }
}

//Öðrenciyi silen fonksiyon
void ogrenciSil(const char* silinecekIsim) {
    struct Ogrenci* prev = NULL;
    struct Ogrenci* current = baslangic;
    
    while (current != NULL) {
        if (strcmp(current->isim, silinecekIsim) == 0) {
            if (prev == NULL) {
                baslangic = current->sonraki;
            } else {
                prev->sonraki = current->sonraki;
            }
            free(current);
            printf("Ogrenci silindi: %s\n", silinecekIsim);
            return;
        }
        prev = current;
        current = current->sonraki;
    }
    printf("Silinecek ogrenci bulunamadi.\n");
}

// Öðrenci listesini yazdýran fonksiyon
void ogrenciListesiniYazdir(struct Ogrenci* baslangic) {
    int sayac = 1;
    struct Ogrenci* current = baslangic;
    
    while (current != NULL) {
        printf("%d- Numara: %d, Isim: %s, Yas: %d\n", sayac, current->numara, current->isim, current->yas);
        current = current->sonraki;
        sayac++;
    }
}



//
int main(int argc, char *argv[]) {
	struct Ogrenci* bulunanOgrenci =NULL;   
	
	// Aranacak öðrencinin adýný belirle
	char* arananIsim = "Hakan";
    //silinecek öðrencinin adýnýn belirlenmesi
   	const char* silinecekIsim = "Hakan";
    
	// Öðrenci düðümlerini liste sonuna ekleyin
    baslangic = yeniOgrenci(205, "Hakan", 23);
    baslangic->sonraki = yeniOgrenci(206, "Sude", 29);
    baslangic->sonraki->sonraki = yeniOgrenci(207, "Ahmet", 22);
	baslangic->sonraki->sonraki->sonraki = yeniOgrenci(209, "Hasancan", 20);
	baslangic->sonraki->sonraki->sonraki->sonraki = yeniOgrenci(210, "Elif", 26);
	baslangic->sonraki->sonraki->sonraki->sonraki->sonraki = yeniOgrenci(212, "Abdulrezzak", 24);
	
	char    cmd;
	
	printf("\n\nData Structure Lab\n");
    printf("\nKomut seciniz: 'q' = cikis\n '1' = 1.odev\n '2' = 2.odev\n '3' = 3.odev\n '4' = 4.odev\n '5' = 5.odev\n '6' = 6.odev\n");
	scanf("%c", &cmd); fflush(stdin);
	while (cmd != 'q')						// if not quit
	{
		switch (cmd)
		{
		case '1':  printf("\n\nBu ornek labta yapildigi icin eklemedim"); break;
        case '2':  randomsayilaribuyuktenkucugesiralama(); break;

		case '3':
    		// Öðrenci listesini yazdýr ve say
    		printf("\n");
    		ogrenciListesiniYazdirVeSay(baslangic);  break;

        case '4':
        	
    		// Öðrenci adýna göre arama yapar
    		bulunanOgrenci = ogrenciAra(arananIsim, baslangic);

    		if (bulunanOgrenci != NULL) {
       	 	printf("Aradiginiz Ogrenci: Numara: %d, Isim: %s, Yas: %d\n", bulunanOgrenci->numara, bulunanOgrenci->isim, bulunanOgrenci->yas);
    		} else {
        	printf("Aranan ogrenci bulunamadi.\n");
    		} break;

        case '5':   
		
			printf("Ogrenci Listesi:\n");
    		ogrenciListesiniYazdir(baslangic);
    
    		
    		// Öðrenci adýna göre düðümü sil
    		ogrenciSil(silinecekIsim);
    
    		printf("\nYeni Ogrenci Listesi:\n");
    		ogrenciListesiniYazdir(baslangic);
		
		
		break;
        
		
		case '6':  
			// En uzun ismi yazdýr
    		enUzunIsmiYazdir(baslangic); break;
			}
    		printf("\n\nData Structure Lab\n");
   			printf("\nKomut seciniz: 'q' = cikis\n '1' = 1.odev\n '2' = 2.odev\n '3' = 3.odev\n '4' = 4.odev\n '5' = 5.odev\n '6' = 6.odev\n");
			scanf("%c", &cmd); fflush(stdin);
	};

    return 0;

	
}
