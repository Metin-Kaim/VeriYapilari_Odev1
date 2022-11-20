/*
* @file Node.cpp
* @description İki yönlü bağıl liste oluşturma ve Veri.txt dosyasında yer alan verileri dizi formatında listeye ekleme veya listeden çıkarma.
* @course 2. Öğretim C grubu
* @assignment 1. Ödev
* @date 10.11.2021
* @author Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "SatirListesiDugum.hpp"
using namespace std;

SatirListesiDugum::SatirListesiDugum(SatirListesi *satirListAdres)
{
    this->satirListAdres = satirListAdres;
    sonraki_sld = 0;
    onceki_sld = 0;
}
