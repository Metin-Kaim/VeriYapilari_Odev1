/*
* @file             SatirListesi.hpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme. 
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include <iostream>
#include "Dugum.hpp"
using namespace std;

class SatirListesi
{
public:
    SatirListesi(); // ilk=0
    ~SatirListesi();
    void d_ekle(int veri);
    void d_yazdir(int);
    float ortalamaGetir();
    int satirListesiDugumSayisi;
    void rastgeleDugumGetir();
    bool dugumSecme;
    int randomSayi;
    void seciliDugumuSil();
    int dugumSayisiGetir();

private:
    Dugum *ilk_sl;
    void boslukBirakSirali(int);
    Dugum *dugumAdresi;
};
#endif