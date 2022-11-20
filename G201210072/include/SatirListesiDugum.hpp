/*
* @file Dugum.hpp
* @description İki yönlü bağıl liste oluşturma ve Veri.txt dosyasında yer alan verileri dizi formatında listeye ekleme veya listeden çıkarma.
* @course 2. Öğretim C grubu
* @assignment 1. Ödev
* @date 10.11.2021
* @author Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#ifndef SatirListesiDugum_hpp
#define SatirListesiDugum_hpp
#include "SatirListesi.hpp"
#include <iostream>
using namespace std;

class SatirListesiDugum // Düğüm sınıfı oluşturuluyor.
{
public:
    SatirListesiDugum(SatirListesi *satirListAdres);

    SatirListesi *satirListAdres;

    SatirListesiDugum *sonraki_sld;
    SatirListesiDugum *onceki_sld;
};
#endif