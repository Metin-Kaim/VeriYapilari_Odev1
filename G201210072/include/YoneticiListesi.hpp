/*
* @file             YoneticiListesi.hpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme. 
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include <iostream>
#include "SatirListesiDugum.hpp"
#include "SatirListesi.hpp"

using namespace std;

class YoneticiListesi
{
public:
    YoneticiListesi(); // ilk=0
    ~YoneticiListesi();
    void ekle(int *, int);
    void yazdir_Yonetici(int, int, int);
    void dugumSil(int);
    void satirListesiDugumSayisi(int,int);
    bool sonSatirSilindi;
    bool dugumAzaltma;
private:
    SatirListesiDugum *ilk_yl;
    void adresCizdir(int);
    void cizgiCizdir(int);
    void sonrakiAdresCizdir(int);
    void oncekiAdresCizdir(int);
    void ortalamaDegerCizdir(int);
    void boslukBirak(int);
    void siraliDugumleriCizdir(int,int);
    void yenidenKonumlandir(int);
    void bilgilendirmeYazilari(int);

};
#endif