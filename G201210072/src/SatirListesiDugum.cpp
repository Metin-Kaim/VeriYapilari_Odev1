/*
* @file             SatirListesiDugum.cpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme. 
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
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
