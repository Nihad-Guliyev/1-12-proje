#include <stdio.h>
#include <string.h>

int main(void) {
    // Ürünlerin adlarını ve kalorilerini tutacak diziler
    char urunAdlari[11][30];
    int urunKalori[11];
    float pors[11];   // Kullanıcıdan alınan porsiyon miktarları
    float toplamKalori[11];   // Hesaplanan kalori miktarlarını tutacak dizi
    int n;  // Kullanıcıdan alınacak sipariş sayısı

    // Kalori dosyasını yazma modunda aç
    FILE* fp = fopen("C:\\Users\\Elif\\Documents\\proje\\kalori.txt", "w");
    if (fp == NULL) {
        printf("KALORI DOSYASI ACILAMADI\n");
        return 1;
    } else {
        // Ürünler ve kalorileri yazdırma
        fprintf(fp, "Balik 350\nBorek 300\nHamburger 240\nMakarna 350\nKabak 70\nPatates 200\nPilav 300\nTatli 400\nTurlu 200\nAyran 70\nKola 110\n");
        printf("KALORI DOSYASINA YAZILDI\n");
    }
    fclose(fp);

    // Kullanıcıdan sipariş sayısını alma
    printf("Secmek istediginiz siparis sayisini giriniz:");
    scanf("%d", &n);

    // Kalori dosyasını okuma modunda aç
    fp = fopen("C:\\Users\\Elif\\Documents\\proje\\kalori.txt", "r");
    if (fp == NULL) {
        printf("KALORI DOSYASI ACILAMADI\n");
        return 1;
    }

    // Kalori dosyasındaki verileri oku ve ürünleri dizimize kaydet
    for (int i = 0; i<11; i++) {
        fscanf(fp, "%s %d", &urunAdlari[i], &urunKalori[i]);
    }
    fclose(fp);

    // Kullanıcıdan siparişleri al
    FILE* siparis = fopen("C:\\Users\\Elif\\Documents\\proje\\siparis.txt", "w");
    if (siparis == NULL) {
        printf("SIPARIS DOSYASI ACILAMADI\n");
        return 1;
    }
    float toplam = 0;
    int secim;
    char secilenUrun[30];

    for (int i = 0; i < n; i++) {
        do {
            printf("\nBir urun secin (adini girin):");
            scanf("%s", secilenUrun);  // Kullanıcıdan yemek adı al

            // Kullanıcı adı ile eşleşen ürünü bul
            secim = -1;
            for (int j = 0; j < 11; j++) {
                if (strcmp(secilenUrun, urunAdlari[j]) == 0) {
                    secim = j;
                    break;
                }
            }
            if (secim == -1) {
                printf("Hata! Gecerli bir urun adi girin!\n");
            }
        } while (secim == -1);  // Geçerli bir yemek adı girene kadar devam et

        printf("Secilen urun icin porsiyon miktarini girin:");
        scanf("%f", &pors[i]);

        //Siparişin kalorisini hesapla
        toplamKalori[i] = urunKalori[secim] * pors[i];
        toplam += toplamKalori[i];

        //Sipariş dosyasına yaz
        fprintf(siparis, "%s %.2f\n", urunAdlari[secim], pors[i]);
    }
    fclose(siparis);

    printf( "\nToplam Kalori: %.2f\n", toplam);

    return 0;
}