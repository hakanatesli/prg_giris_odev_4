/************************************************************
**                   SAKARYA �N�VERS�TES�
**          B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**              B�LG�SAYAR M�HEND�SL��� B�L�M�
**                 PROGRAMLAMAYA G�R�� DERS�
**
**      �DEV NUMARASI....:4
**      ��RENC� ADI......:HAKAN ATE�L�
**      ��RENC� NUMARASI.:G171210002
**      DERS GRUBU.......:2/A
************************************************************/
#include <iostream>
#include <time.h>
using namespace std;
int x;
bool elemanKontrol(int deg[100], int, int);//elemanKontrol fonksiyonunu olustur fonksiyonunun i�inde kulland���m�z i�in olusturdan �nce tan�tt�m.
int olustur(int c[10][10]);
void matrisYaz(int c[10][10]);
void sirala(int c[10][10]);
int main() {//olu�turdu�um fonksiyonlar�n i�leme ge�mesi i�in main fonksiyonunun i�inde �a��rd�m.
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
int olustur(int c[10][10])//dizimize de�er atamak i�in olustur fonksiyonu olu�turdum.
{
	srand(time(NULL));
	int gec1 = 0;
	int sayi = 0;
	int gec[100];
	for (x = 0; gec1 < 100; x++)// bu d�ng�y� rastgele de�er almak i�in olu�turdum.
	{
		sayi = rand() % 100 + 1;
		while (elemanKontrol(gec, sayi, gec1) == 1)//bu d�ng�y� ald���m�z rastgele de�er e�er daha �nceki atad�klar�m�zla ayn� de�ilse yeni dizi eleman� olarak atamak i�in olu�turdum.
		{
			gec[gec1] = sayi;
			gec1++;
		}
	}
	int sayac = -1;
	for (int i = 0; i < 10; i++)//olu�turdu�um bir boyutlu diziyi iki boyutlu diziye d�n��t�rmek i�in for d�ng�s� a�t�m.
	{
		for (int j = 0; j < 10; j++)
		{
			sayac++;
			c[i][j] = gec[sayac];
		}
	}
	return x;
}
bool elemanKontrol(int deg[100], int a, int b)//bu fonksiyonu atanan rastgele deger �ncceki atad�klar�m�zla ayn� m� diye kontrol etmek i�in olu�turdum.
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
void sirala(int c[10][10])//bu fonksiyonu dizimizin elemanlar�n� b�y�kten k����e s�ralamk i�in olu�turdum. selection sort ile s�ralama i�lemi yapt�m.
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
void matrisYaz(int c[10][10])//bu fonsiyonu parametre olarak �a��r�lan diziyi ekrana yazd�rmek i�in ol�turdum.
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