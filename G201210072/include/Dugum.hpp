/*
* @file Dugum.hpp
* @description İki yönlü bağıl liste oluşturma ve Veri.txt dosyasında yer alan verileri dizi formatında listeye ekleme veya listeden çıkarma.
* @course 2. Öğretim C grubu
* @assignment 1. Ödev
* @date 10.11.2021
* @author Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp

#include <iostream>
using namespace std;

class Dugum // Düğüm sınıfı oluşturuluyor.
{
public:
    Dugum(int veri);

    int veri;

    Dugum *sonraki_d;
   //Dugum *onceki_d;
};
#endif