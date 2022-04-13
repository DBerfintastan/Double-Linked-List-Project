/** 
* @file Liste.cpp
* @description DosyaOku classından gelen sayıları gerekli işlemler yaparak önce diziye atayıp sonra liste oluşturur.
* @course 1.Öğretim B grubu
* @assignment 1
* @date 07.08.2021
* @author Deniz Berfin Taştan / deniz.tastan@ogr.sakarya.edu.tr
**/

#include "Liste.hpp"
#include "DosyaOku.hpp"
#include "ListeFonksiyonlari.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
void Liste::liste()
{
    DosyaOku d1;
    d1.dosyaOku(); // Sayilar.txt'yi okuduk.

    n1 = d1.sayi1.length();
    n2 = d1.sayi2.length(); //İşlem yaparken kullanmak için dizilerin boyutunu aldım.

    int degerler1[d1.sayi1.length() + 1];
    int degerler2[d1.sayi2.length() + 1]; // asıl değerlerimizi tutmak için dizi oluşturdum.

    if (d1.sayi1.length() == d1.sayi2.length()) //Eğer gelen 2 sayının uzunluğu eşitse
    {
        if (d1.sayi1.length() % 3 == 0 && d1.sayi2.length() % 3 == 0) //Bu uzunluk 3'ün katıysa
        {
            char gecici_char1[d1.sayi1.length() + 1];
            char gecici_char2[d1.sayi2.length() + 1]; //String gelen ifadeyi char dizisine bölmek için geçiçi char dizileri oluşturdum.

            int gecici_int1[d1.sayi1.length() + 1];
            int gecici_int2[d1.sayi2.length() + 1]; //Yukarıda oluşturduğumuz char dizilerini int dizine aktarmak için geçiçi int dizileri oluşturdum.

            strcpy(gecici_char1, d1.sayi1.c_str());
            strcpy(gecici_char2, d1.sayi2.c_str()); //String olarak gelen sayıları char dizisine böldüm.

            for (int i = 0; i < d1.sayi1.length(); i++)
            {
                if (gecici_char1[i * 3] == '0') //Gelen sayının yüzler basamağı yani 3'ün katı olan indexli elemanı(basamağı) 0 ise 1 yaptım.
                {
                    gecici_char1[i * 3] = '1';
                }
                gecici_int1[i] = gecici_char1[i] - '0'; //Sayi1'in char elemanlarını int'e çevirdim.
            };
            int c = 0;
            for (int i = 0; i < d1.sayi1.length(); i = i + 3)
            {
                degerler1[c] = gecici_int1[i] * 100 + gecici_int1[i + 1] * 10 + gecici_int1[i + 2]; // Sayi1'in bulunduğu int dizisindeki değerlerimi 3 basamaklı hale getirdim.
                c++;
            };
            for (int i = 0; i < d1.sayi2.length(); i++)
            {
                if (gecici_char2[i * 3] == '0') //Gelen sayının yüzler basamağı yani 3'ün katı olan indexli elemanı(basamağı) 0 ise 1 yaptım.
                {
                    gecici_char2[i * 3] = '1';
                }
                gecici_int2[i] = gecici_char2[i] - '0'; //Sayi2'nin char elemanlarını int'e çevirdim.
            };
            int b = 0;
            for (int i = 0; i < d1.sayi2.length(); i = i + 3)
            {
                degerler2[b] = gecici_int2[i] * 100 + gecici_int2[i + 1] * 10 + gecici_int2[i + 2]; //Sayi2'nin bulunduğu int dizisindeki değerlerimi 3 basamaklı hale getirdim.
                b++;
            };

            ListeFonksiyonlari *liste1 = new ListeFonksiyonlari(degerler1, n1 / 3);
            ListeFonksiyonlari *liste2 = new ListeFonksiyonlari(degerler2, n2 / 3);
            for (int i = 0; i < n1 / 3; i++)
            {
                if (liste1->Goruntule(i, liste1->ilkEleman)->veri > liste2->Goruntule(i, liste2->ilkEleman)->veri) //Üzerinde bulunduğumuz düğümün verisini karşılaştırma işlemleri.
                {
                    liste1->tersCevir(&liste1->ilkEleman);
                }

                else if (liste1->Goruntule(i, liste1->ilkEleman)->veri < liste2->Goruntule(i, liste2->ilkEleman)->veri) 
                {
                    Dugum *tmp1 = liste1->Goruntule(i, liste1->ilkEleman);
                    Dugum *tmp2 = liste2->Goruntule(i, liste2->ilkEleman);
                    Dugum *geciciOnceki = liste1->Goruntule(i, liste1->ilkEleman)->onceki;
                    Dugum *gecici2Onceki = liste2->Goruntule(i, liste2->ilkEleman)->onceki;
                    Dugum *geciciSonraki = liste1->Goruntule(i, liste1->ilkEleman)->sonraki;
                    Dugum *gecici2Sonraki = liste2->Goruntule(i, liste2->ilkEleman)->sonraki;
                    if (geciciOnceki != NULL && gecici2Onceki != NULL)
                    {
                        geciciOnceki->sonraki = tmp2;
                        gecici2Onceki->sonraki = tmp1;
                    }
                    if (geciciSonraki != NULL && gecici2Sonraki != NULL)
                    {
                        geciciSonraki->onceki = tmp2;
                        gecici2Sonraki->onceki = tmp1;
                    }
                    tmp1->sonraki = gecici2Sonraki;
                    tmp1->onceki = gecici2Onceki;
                    tmp2->sonraki = geciciSonraki;
                    tmp2->onceki = geciciOnceki; //İki düğümün yerini değiştirir.
                }
                else
                    liste2->tersCevir(&liste2->ilkEleman);
            }
            cout << "Sayi1:";
            liste1->Yazdir(liste1->ilkEleman);
            cout << endl;
            cout << "Sayi2:";
            liste1->Yazdir(liste2->ilkEleman);
        }
        else
        {
            cout << "Boyut 3'e bolunebilmeli.";
        }
    }
    else
    {
        cout << "Boyutlar esit degil.";
    }
}
