#include <stdio.h>
#include <time.h>

/*0,0 noktas�ndaki at�, satran� tahtas�nda
rastgele gezdiren algoritma*/

void printTahta(int tahta[8][8]) {
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      printf("%2d ", tahta[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int tahta[8][8];
  int hareket[8][2] = // at�n yapabilece�i t�m hareketler
      {{+2, +1}, {+2, -1}, {-2, +1}, {-2, -1},
       {+1, +2}, {+1, -2}, {-1, +2}, {-1, -2}};
  int atX = 0, atY = 0;     // at�n konumlar�
  int tempX = 0, tempY = 0; // ge�ici olarak hareketi depolamak i�in
  int adim;                 // hareket say�s�
  int i, j, rastgele;

  srand(time(NULL)); // rastgele say�y� zamana ba�lama
  // t�m tahtay� s�f�rlama
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      tahta[i][j] = 0;
    }
  }
  printf("SATRANC TAHTASINDAKI AT");
  printf("\n\nAdim Sayisi: ");
  scanf("%d", &adim);

  for (i = 1; i <= adim; i++) {

    rastgele = rand() % 7;
    tempX = tempX + hareket[rastgele][0];
    tempY = tempY + hareket[rastgele][1];
    // hareketin tahta i�inde oldu�unu kontrol etme
    while (tempX > 7 || tempX < 0 || tempY > 7 || tempY < 0) {
      tempX = atX;
      tempY = atY;
      rastgele = rand() % 7;
      tempX = tempX + hareket[rastgele][0];
      tempY = tempY + hareket[rastgele][1];
    }
    // kontrol sonucu yeni konumu yazma
    atX = tempX;
    atY = tempY;

    tahta[atX][atY] = i; // hareket sonras� yeri yazma
    printf("\nAdim %d", i);
    printf("\nRastgele Sayi: %d\n", rastgele);
    printTahta(tahta); // tahtay� yazd�rma
  }
}
