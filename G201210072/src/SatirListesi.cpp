/*
* @file             SatirListesi.cpp
* @description      Verilen "veriler.txt" dosyasındaki verileri bağlı liste yapısıyla tutup,
                    o bağlı listeyi de çift yönlü başka bir bağlı liste ile kontrol ederek
                    istenen işlemleri yerine getirme. 
* @course           1. Öğretim A grubu
* @assignment       1. Ödev
* @date             21.11.2022
* @author           Metin Kaim -- metin.kaim@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <iomanip>
#include "SatirListesi.hpp"
using namespace std;

SatirListesi::SatirListesi()
{
    ilk_sl = 0;
    satirListesiDugumSayisi = 0;
    dugumAdresi = 0;
    dugumSecme = false;
    randomSayi = 0;
}

SatirListesi::~SatirListesi()
{
    Dugum *gec = ilk_sl;

    while (gec != 0)
    {
        Dugum *sil = gec;
        gec = gec->sonraki_d;
        delete sil;
    }
}

void SatirListesi::d_ekle(int veri)
{
    Dugum *yeni_sl = new Dugum(veri);

    if (ilk_sl == 0)
        ilk_sl = yeni_sl;
    else // eger ki halihazirda dugum var ise
    {
        Dugum *gec_sl = ilk_sl;

        while (gec_sl->sonraki_d != 0) // gec son dugumu gostermekte
        {
            gec_sl = gec_sl->sonraki_d;
        }

        gec_sl->sonraki_d = yeni_sl;
        // yeni_sl->onceki_d = gec_sl;
    }
}
void SatirListesi::d_yazdir(int sira) // satir listesinin dugumlerini yazdirma
{
    Dugum *gecici = ilk_sl;
    
    while (gecici != 0)
    {
        boslukBirakSirali(sira);
        cout << " " << gecici;
        boslukBirakSirali(sira);
        cout << "-----------  ";
        boslukBirakSirali(sira);
        cout << "|" << setw(6) << gecici->veri << setw(4) << "|";
        if (dugumAdresi == gecici && dugumSecme == true)
        {
            dugumSecme = false;
            cout << "    <----- secilen dugum";
        }
        boslukBirakSirali(sira);
        cout << "-----------  ";
        boslukBirakSirali(sira);
        if (gecici->sonraki_d == 0)
        {
            cout << "|"<<setw(9)
                 << "00000000"
                 << "|  ";
        }
        else
            cout << "|" <<setw(9)<< gecici->sonraki_d << "|  ";
        boslukBirakSirali(sira);
        cout << "-----------  \n";

        gecici = gecici->sonraki_d;

    }
}

float SatirListesi::ortalamaGetir()
{
    if (ilk_sl == 0)
        return 0;

    Dugum *gec = ilk_sl;
    float toplamDeger = 0;
    float dugumSayisi = 0;

    while (gec != 0)
    {
        toplamDeger += gec->veri;
        gec = gec->sonraki_d;
        dugumSayisi++;
    }

    return toplamDeger / dugumSayisi;
}

void SatirListesi::boslukBirakSirali(int sira)
{
    cout << endl
         << setw(13 * sira) << "";
}

void SatirListesi::rastgeleDugumGetir()
{
    dugumSecme = true;
    randomSayi = rand() % dugumSayisiGetir();

    Dugum *gec = ilk_sl;
    for (int i = 0; i < randomSayi; i++)
    {
        gec = gec->sonraki_d;
    }
    dugumAdresi = gec;
}

void SatirListesi::seciliDugumuSil()
{
    Dugum *gec = ilk_sl;

    for (int i = 0; i < randomSayi - 1; i++)
    {
        gec = gec->sonraki_d;
    }

    if (randomSayi != 0 && randomSayi != dugumSayisiGetir() - 1) // silinecek dugum ilk dugum degil
    {
        Dugum *sil = gec->sonraki_d;
        gec->sonraki_d = gec->sonraki_d->sonraki_d;
        delete sil;
    }
    else if (randomSayi == 0) // ilk dugum
    {
        ilk_sl = gec->sonraki_d;
        delete gec;
    }
    else // son dugum ise
    {
        delete gec->sonraki_d;
        gec->sonraki_d = 0;
    }
}

int SatirListesi::dugumSayisiGetir()
{
    satirListesiDugumSayisi = 0;
    Dugum *gec = ilk_sl;
    while (gec != 0)
    {
        gec = gec->sonraki_d;
        satirListesiDugumSayisi++;
    }
    
    return satirListesiDugumSayisi;
}