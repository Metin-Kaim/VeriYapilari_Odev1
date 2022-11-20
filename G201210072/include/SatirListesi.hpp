/*
 * @file SatirListesi.hpp
 * @description İki yönlü bağıl liste oluşturma ve Veri.txt dosyasında yer alan verileri dizi formatında listeye ekleme veya listeden çıkarma.
 * @course 2. Öğretim C grubu
 * @assignment 1. Ödev
 * @date 10.11.2021
 * @author Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
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
    // int gec_satirListesiDugumSayisi;
};
#endif