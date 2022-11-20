/*
* @file Node.cpp
* @description İki yönlü bağıl liste oluşturma ve Veri.txt dosyasında yer alan verileri dizi formatında listeye ekleme veya listeden çıkarma.
* @course 2. Öğretim C grubu
* @assignment 1. Ödev
* @date 10.11.2021
* @author Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "Dugum.hpp"
using namespace std;

Dugum::Dugum(int veri)
{
    this->veri = veri;
    sonraki_d = 0;
    //onceki_d = 0;
}
