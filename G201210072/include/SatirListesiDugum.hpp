/*
* @file             SatirListesiDugum.hpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme. 
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
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