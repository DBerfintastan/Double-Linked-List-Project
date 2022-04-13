/** 
* @file DosyaOku.cpp
* @description Dosya okuma ve string olarak dosyayı bölme işlemleri burada yapılıyor.
* @course 1.Öğretim B grubu
* @assignment 1
* @date 02.08.2021
* @author Deniz Berfin Taştan / deniz.tastan@ogr.sakarya.edu.tr
**/

#include <iostream>
#include <fstream>
#include <string>
#include "DosyaOku.hpp"
using namespace std;

void DosyaOku::dosyaOku()
{
  ifstream dosyaOku("docs/Sayilar.txt"); //Dosyayı bütüm olarak okudum.
  satir = "";
  if (dosyaOku.is_open())
  {
    while (getline(dosyaOku, satir)) //Dosya satırını okudum.
    {
      //cout << satir << endl;
      bolme = "#"; 
      boyut1 = satir.find(bolme); //Tanımladığım karaktere göre bölme işlemi yaptım.
      sayi1 = satir.substr(0, boyut1); //Böldüğüm yere kadar olan sayıyı sayi1 değişkenine atadım.
      boyut2 = satir.length(); //boyut2'ye dosyadaki sayının uzunluğunu verdim.
      sayi2 = satir.substr(boyut1 + 1, boyut2); //İlk böldüğüm yerden, sayının sonuna kadarki sayıyı sayi2 değişkenine atadım.
    }
  }
}
