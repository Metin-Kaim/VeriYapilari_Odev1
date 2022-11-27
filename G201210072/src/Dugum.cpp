/*
* @file             Dugum.cpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme. 
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
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
