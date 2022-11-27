/*
* @file             Dugum.hpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme. 
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
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
};
#endif