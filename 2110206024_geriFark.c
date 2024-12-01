#include<stdio.h>
#include<math.h>

int main()
{
    float x, u1, u, y;
    int i, j, terimSayisi, faktoriyel;
    	printf("Terim sayisini giriniz:\n");
    	scanf("%d", &terimSayisi);
    float tablo[terimSayisi][terimSayisi + 1];
    
    printf("x degerlerini giriniz:\n");
    for (i = 0; i < terimSayisi; i++)
        scanf("%f", &tablo[i][0]);
    
    printf("y degerlerini giriniz:\n");
    for (i = 0; i < terimSayisi; i++)
        scanf("%f", &tablo[i][1]);
    
    printf("Hangi x degeri icin y hesaplamak istediginizi girin:\n");
    scanf("%f", &x);
    for (j = 2; j < terimSayisi + 1; j++) {
        for (i = 0; i < terimSayisi - j + 1; i++)
            tablo[i][j] = tablo[i + 1][j - 1] - tablo[i][j - 1];
    }
    printf("Fark Tablosu asagidaki gibidir:\n");
    for (i = 0; i < terimSayisi; i++) {
        for (j = 0; j <= terimSayisi - i; j++)
            printf("%f ", tablo[i][j]);
        printf("\n");
    }
    u = (x - tablo[terimSayisi - 1][0]) / (tablo[1][0] - tablo[0][0]);
    y = tablo[terimSayisi - 1][1]; 
    u1 = u;
    faktoriyel = 1;
    j = 2;
    for (i = terimSayisi - 2; i >= 0; i--) {
        y = y + (u1 * tablo[i][j]) / faktoriyel;
        faktoriyel = faktoriyel * j; 
        u1 = u1 * (u + (j - 1));
        j++;
    }
    printf("\n\nX=%g noktasinda Y degeri = %f", x, y);
}
