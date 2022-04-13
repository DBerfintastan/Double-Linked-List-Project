#ifndef LISTEFONKSIYONLARI_HPP
#define LISTEFONKSIYONLARI_HPP
#include <iostream>
#include "Dugum.hpp"
using namespace std;
class ListeFonksiyonlari{
    public:
    Dugum *ilkEleman;
    ListeFonksiyonlari(int *diziP, int boyut);
    void ekle(Dugum **ilkEleman, int eleman);
    void Yazdir(Dugum *ilkEleman);
    Dugum *ListeyeEkle(int dizi[], int boyut);
    Dugum *Goruntule(int index, Dugum *ilkEleman);
    void tersCevir(Dugum **ilk);
};

#endif