/************************************************************
**                   SAKARYA ÜNÝVERSÝTESÝ
**          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**              BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                 PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**      ÖDEV NUMARASI....:4
**      ÖÐRENCÝ ADI......:HAKAN ATEÞLÝ
**      ÖÐRENCÝ NUMARASI.:G171210002
**      DERS GRUBU.......:2/A
************************************************************/
#include <iostream>
#include <time.h>
using namespace std;
int x;
bool elemanKontrol(int deg[100], int, int);//elemanKontrol fonksiyonunu olustur fonksiyonunun içinde kullandýðýmýz için olusturdan önce tanýttým.
int olustur(int c[10][10]);
void matrisYaz(int c[10][10]);
void sirala(int c[10][10]);
int main() {//oluþturduðum fonksiyonlarýn iþleme geçmesi için main fonksiyonunun içinde çaðýrdým.
	int dizi[10][10];
	cout << "Toplam rastgele cagirim adedi: " << olustur(dizi) << endl;
	cout << "rastgele olusan ve elemanlari birbirinden farkli olan matris" << endl;
	matrisYaz(dizi);
	cout << endl << endl << endl << "buyukten kucuge siralanmis matris" << endl;
	sirala(dizi);
	matrisYaz(dizi);
	system("pause");
	return 0;
}
int olustur(int c[10][10])//dizimize deðer atamak için olustur fonksiyonu oluþturdum.
{
	srand(time(NULL));
	int gec1 = 0;
	int sayi = 0;
	int gec[100];
	for (x = 0; gec1 < 100; x++)// bu döngüyü rastgele deðer almak için oluþturdum.
	{
		sayi = rand() % 100 + 1;
		while (elemanKontrol(gec, sayi, gec1) == 1)//bu döngüyü aldýðýmýz rastgele deðer eðer daha önceki atadýklarýmýzla ayný deðilse yeni dizi elemaný olarak atamak için oluþturdum.
		{
			gec[gec1] = sayi;
			gec1++;
		}
	}
	int sayac = -1;
	for (int i = 0; i < 10; i++)//oluþturduðum bir boyutlu diziyi iki boyutlu diziye dönüþtürmek için for döngüsü açtým.
	{
		for (int j = 0; j < 10; j++)
		{
			sayac++;
			c[i][j] = gec[sayac];
		}
	}
	return x;
}
bool elemanKontrol(int deg[100], int a, int b)//bu fonksiyonu atanan rastgele deger öncceki atadýklarýmýzla ayný mý diye kontrol etmek için oluþturdum.
{
	for (int c = 0; c <= b; c++)
	{
		if (deg[c] == a)
		{
			return 0;
		}
	}
	return 1;
}
void sirala(int c[10][10])//bu fonksiyonu dizimizin elemanlarýný büyükten küçüðe sýralamk için oluþturdum. selection sort ile sýralama iþlemi yaptým.
{
	int i, j, k, l, gec;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++)
			{
				for (l = 0; l < 10; l++)
				{
					if (c[i][j] > c[k][l])
					{
						gec = c[i][j];
						c[i][j] = c[k][l];
						c[k][l] = gec;
					}
				}
			}
		}
	}
}
void matrisYaz(int c[10][10])//bu fonsiyonu parametre olarak çaðýrýlan diziyi ekrana yazdýrmek için olþturdum.
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}