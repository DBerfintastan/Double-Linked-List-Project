/** 
* @file ListeFonksiyonlari.cpp
* @description Liste.cpp 'deki ekleme, ters çevirme, görüntüleme gibi fonksiyonlar burada tanımlandı. Yeni düğüm oluşturma fonksiyonu da bu classta bulunuyor.
* @course 1.Öğretim B grubu
* @assignment 1
* @date 03.08.2021
* @author Deniz Berfin Taştan / deniz.tastan@ogr.sakarya.edu.tr
**/



#include "Dugum.hpp"
#include "ListeFonksiyonlari.hpp"
#include <iostream>
using namespace std;

ListeFonksiyonlari::ListeFonksiyonlari(int *diziP, int boyut)
{
    ilkEleman = ListeyeEkle(diziP, boyut);
}
void ListeFonksiyonlari::ekle(Dugum **ilkEleman, int eleman) //Listeye düğüm ekleme işlemini gerçekleştirir..
{
    Dugum *gecici = new Dugum; //yeni bir düğüm oluşturdum.
    Dugum *ptr; //ilk elemanın adresini tutacak olan bir pointer oluşturdum.
    gecici->veri = eleman; //oluşan yeni düğümün verisine parametreden aldığım elemanı atadım.
    gecici->sonraki = NULL; 
    gecici->onceki = NULL;// önceki ve sonraki düğümlerin adreslerini gösteren pointerları atadım.

    if (*ilkEleman == NULL) //Eğer eleman yoksa (liste boşsa) yeni bir düğüm oluşturdum.
        *ilkEleman = gecici;
    else //Eğer liste boş değilse verilen indexe göre araya,başa veya sona ekleme yaptım.
    {
        ptr = *ilkEleman; 
        while (ptr->sonraki != NULL)
            ptr = ptr->sonraki; 
        ptr->sonraki = gecici;
        gecici = ptr;
        ptr = ptr->sonraki;
        ptr->onceki = gecici;
    }
}

void ListeFonksiyonlari::Yazdir(Dugum *ilkEleman) //İlk elemandan başlayarak tüm listeyi yazdırır.
{
    while (ilkEleman != NULL)
    {
        cout << ilkEleman->veri;
        ilkEleman = ilkEleman->sonraki;
    }
}

Dugum *ListeFonksiyonlari::ListeyeEkle(int dizi[], int boyut)
{
    Dugum *ilkEleman = NULL;
    for (int i = 0; i < boyut; i++)
        ekle(&ilkEleman, dizi[i]); //Dizideki elemanları ekle fonksiyonunu kullanarak listeye ekleme işleme yaptık.
    return ilkEleman;
}

Dugum *ListeFonksiyonlari::Goruntule(int index, Dugum *ilkEleman) //Girilen indexli elemanı görüntülemeyi sağlar.
{
    for (int i = 0; i < index; i++) //Girilen indexe göre for kaç kere dönerse o kadar sayıda sonraki düğüme atlama yapacak.
    {
        ilkEleman = ilkEleman->sonraki;
    }
    return ilkEleman;
}

void ListeFonksiyonlari::tersCevir(Dugum **ilk) //
{
    Dugum *gecici = NULL; //Düğüm sınıfından geçiçi bir pointer oluşturdum.
    Dugum *anlik = *ilk; //üzerinde bulunduğumuz düğümün adresini tutması için düğüm sınıfından geçiçi bir düğüm oluşturdum.
    while (anlik != NULL)
    {
        gecici = anlik->onceki; //Gecici pointer'ıma üzerinde bulunduğum düğümün bir önceki düğümünü atadım.
        anlik->onceki = anlik->sonraki; //Anlık düğümün bir önceki düğümüne, bir sonraki düğümü atadım.
        anlik->sonraki = gecici; //Anlık düğümün bir sonraki düğümüne geciciyi yani anlık düğümün önceki düğümünü atadık. Yani önceki düğüm,sonraki düğüm;sonraki düğüm,önceki düğüm oldu.
        anlik = anlik->onceki; //Döngüm için bir önceki düğümü artık anlık düğüm yaptım.
    }
    ilkEleman = gecici->onceki;
}