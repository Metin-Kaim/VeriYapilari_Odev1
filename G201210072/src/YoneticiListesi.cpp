#include <iostream>
#include <iomanip>
#include "YoneticiListesi.hpp"
using namespace std;

YoneticiListesi::YoneticiListesi()
{
    ilk_yl = 0;
    sonSatirSilindi = false;
    dugumAzaltma = false;
}

void YoneticiListesi::ekle(int *sayiDizisi, int sayiAdedi)
{
    SatirListesiDugum *yeni_sld = new SatirListesiDugum(new SatirListesi());

    if (ilk_yl == 0)
    {
        ilk_yl = yeni_sld;

        for (int i = 0; i < sayiAdedi; i++)
        {
            ilk_yl->satirListAdres->d_ekle(sayiDizisi[i]);
        }
    }
    else
    {
        for (int i = 0; i < sayiAdedi; i++)
        {
            yeni_sld->satirListAdres->d_ekle(sayiDizisi[i]);
        }

        SatirListesiDugum *gec = ilk_yl;

        float yeniDugumOrtalama = yeni_sld->satirListAdres->ortalamaGetir();

        while (gec != 0)
        {
            float gecOrtalama = gec->satirListAdres->ortalamaGetir();

            if (yeniDugumOrtalama <= gecOrtalama)
            {
                if (gec == ilk_yl) // yeni dugumu ilk dugum yapma
                {
                    yeni_sld->sonraki_sld = ilk_yl;
                    ilk_yl->onceki_sld = yeni_sld;
                    ilk_yl = yeni_sld;
                }
                else // yeni dugumu araya alma
                {
                    yeni_sld->onceki_sld = gec->onceki_sld;
                    yeni_sld->sonraki_sld = gec;
                    gec->onceki_sld->sonraki_sld = yeni_sld;
                    gec->onceki_sld = yeni_sld;
                }
                return;
            }
            gec = gec->sonraki_sld;
        }
        if (yeni_sld->onceki_sld == 0 && yeni_sld->sonraki_sld == 0) // yeni dugum yerlestirilmedi // yeni dugumu sona ekleme
        {
            gec = ilk_yl;
            while (gec->sonraki_sld != 0)
            {
                gec = gec->sonraki_sld;
            }

            gec->sonraki_sld = yeni_sld;
            yeni_sld->onceki_sld = gec;
        }
    }
}

void YoneticiListesi::yazdir_Yonetici(int tercih, int kacinciKume, int sira)
{ //--------------------------------- seciliDugum                  kacinciDugum
    if (ilk_yl == 0)
        return;
    bilgilendirmeYazilari(kacinciKume);
    cout << endl;
    adresCizdir(kacinciKume);
    cout << endl;
    cizgiCizdir(kacinciKume);
    cout << endl;
    oncekiAdresCizdir(kacinciKume);
    cout << endl;
    cizgiCizdir(kacinciKume);
    cout << endl;
    ortalamaDegerCizdir(kacinciKume);
    cout << endl;
    cizgiCizdir(kacinciKume);
    cout << endl;
    sonrakiAdresCizdir(kacinciKume);
    cout << endl;
    cizgiCizdir(kacinciKume);
    boslukBirak(tercih);
    cout << "^^^^^^^^^^";
    cout << endl;
    siraliDugumleriCizdir(sira, tercih);
}

void YoneticiListesi::cizgiCizdir(int kacinciKume)
{
    int sayac = 0;
    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < kacinciKume; i++)
    {
        while (gec != 0 && sayac != 8)
        {
            gec = gec->sonraki_sld;
            sayac++;
        }
        sayac = 0;
    }

    while (gec != 0 && sayac != 8)
    {
        cout << "----------  ";
        gec = gec->sonraki_sld;
        sayac++;
    }
}

void YoneticiListesi::adresCizdir(int kacinciKume)
{
    int sayac = 0;
    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < kacinciKume; i++)
    {
        while (gec != 0 && sayac != 8)
        {
            gec = gec->sonraki_sld;
            sayac++;
        }
        sayac = 0;
    }

    while (gec != 0 && sayac != 8)
    {
        cout << " " << gec << "   ";
        gec = gec->sonraki_sld;
        sayac++;
    }
}

void YoneticiListesi::ortalamaDegerCizdir(int kacinciKume)
{
    int sayac = 0;
    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < kacinciKume; i++)
    {
        while (gec != 0 && sayac != 8)
        {
            gec = gec->sonraki_sld;
            sayac++;
        }
        sayac = 0;
    }

    while (gec != 0 && sayac != 8)
    {
        cout << "|" << setw(8) << gec->satirListAdres->ortalamaGetir() << "|  ";

        gec = gec->sonraki_sld;
        sayac++;
    }
}

void YoneticiListesi::oncekiAdresCizdir(int kacinciKume)
{
    int sayac = 0;
    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < kacinciKume; i++)
    {
        while (gec != 0 && sayac != 8)
        {
            gec = gec->sonraki_sld;
            sayac++;
        }
        sayac = 0;
    }
    while (gec != 0 && sayac != 8)
    {
        if (gec->onceki_sld == 0)
        {
            cout << "|"
                 << "00000000"
                 << "|  ";
        }
        else
        {
            cout << "|" << gec->onceki_sld << "|  ";
        }

        gec = gec->sonraki_sld;
        sayac++;
    }
}

void YoneticiListesi::sonrakiAdresCizdir(int kacinciKume)
{
    int sayac = 0;
    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < kacinciKume; i++)
    {
        while (gec != 0 && sayac != 8)
        {
            gec = gec->sonraki_sld;
            sayac++;
        }
        sayac = 0;
    }

    while (gec != 0 && sayac != 8)
    {
        if (gec->sonraki_sld == 0)
        {
            cout << "|"
                 << "00000000"
                 << "|  ";
        }
        else
            cout << "|" << gec->sonraki_sld << "|  ";
        gec = gec->sonraki_sld;
        sayac++;
    }
}

void YoneticiListesi::boslukBirak(int sira)
{
    cout << endl
         << setw(12 * sira) << "";
}

void YoneticiListesi::siraliDugumleriCizdir(int sira, int tercih)
{
    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < sira; i++)
    {
        gec = gec->sonraki_sld;
    }
    gec->satirListAdres->d_yazdir(tercih);
}

void YoneticiListesi::dugumSil(int index)
{
    SatirListesiDugum *gec = ilk_yl;
    sonSatirSilindi = false;
    for (int i = 0; i < index; i++) // gec pointer'ini silinecek dugume getirme
    {
        gec = gec->sonraki_sld;
    }

    if (gec == ilk_yl) // silinecek dugum ilk dugum  ise
    {
        gec->sonraki_sld->onceki_sld = 0;
        ilk_yl = gec->sonraki_sld;
    }
    else if (gec->sonraki_sld != 0) // aradaki dugumlerden birisi silinecek ise
    {
        gec->sonraki_sld->onceki_sld = gec->onceki_sld;
        gec->onceki_sld->sonraki_sld = gec->sonraki_sld;
    }
    else // sondugum silinecek ise
    {
        gec->onceki_sld->sonraki_sld = 0;
        sonSatirSilindi = true;
    }

    delete gec->satirListAdres;
    delete gec;
}

void YoneticiListesi::satirListesiDugumSayisi(int index, int islem)
{
    dugumAzaltma = false;

    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < index; i++)
    {
        gec = gec->sonraki_sld;
    }

    if (islem == 0)
        gec->satirListAdres->rastgeleDugumGetir();
    else if (islem == 1)
    {
        gec->satirListAdres->seciliDugumuSil(); // verileri tutan dugumlerden secilen dugumu silecek

        if (gec->satirListAdres->dugumSayisiGetir() == 0) // verileri tutan dugumlerin sayısı 0 oldugunda satirlistesi dugumunu silecek
        {
            dugumSil(index);
            dugumAzaltma = true;
        }
        else // verileri tutan dugum sayisi 0'dan fazla ise satirlistesi dugumunu yeniden konumlandıracak
            yenidenKonumlandir(index);
    }
}

void YoneticiListesi::yenidenKonumlandir(int index)
{
    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < index; i++)
    {
        gec = gec->sonraki_sld;
    }
    if (gec == ilk_yl) // ilk dugum
    {
        ilk_yl = gec->sonraki_sld;
        gec->sonraki_sld->onceki_sld = gec->onceki_sld;
        gec->sonraki_sld = 0;
    }
    else
    {
        gec->onceki_sld->sonraki_sld = gec->sonraki_sld;
        if (gec->sonraki_sld != 0)
            gec->sonraki_sld->onceki_sld = gec->onceki_sld;
        gec->onceki_sld, gec->sonraki_sld = 0;

    } // baglantilar koparıldı

    float seciliDugumOrtalama = gec->satirListAdres->ortalamaGetir();
    SatirListesiDugum *secili = gec;
    gec = ilk_yl;
    while (gec != 0)
    {

        float geciciDugumOrtalama = gec->satirListAdres->ortalamaGetir();
        if (seciliDugumOrtalama < geciciDugumOrtalama)
        {
            if (gec == ilk_yl)
            {
                secili->sonraki_sld = gec;
                gec->onceki_sld = secili;
                secili->onceki_sld = 0;
                ilk_yl = secili;
                break;
            }
            else if (gec->sonraki_sld != 0)
            {
                gec->onceki_sld->sonraki_sld = secili;
                secili->onceki_sld = gec->onceki_sld;
                gec->onceki_sld = secili;
                secili->sonraki_sld = gec;
                break;
            }
            else // son dugum
            {
                secili->onceki_sld = gec;
                gec->sonraki_sld = secili;
                secili->sonraki_sld = 0;
                break;
            }
        }
        gec = gec->sonraki_sld;
    }
}

void YoneticiListesi::bilgilendirmeYazilari(int kacinciKume)
{
    int sayac = 0;

    int _kacinciKume = kacinciKume * 8;

    SatirListesiDugum *gec = ilk_yl;
    for (int i = 0; i < _kacinciKume; i++)
    {
        gec = gec->sonraki_sld;
    } // kumenin ilk elemani

    if (gec->onceki_sld == 0 && gec->sonraki_sld == 0)//tek dugum kaldi ise
    {
        cout<<"  ~Son~";
        return;
    }

    if (gec->onceki_sld == 0) // kumenin ilk elemani ise
    {
        cout << "  ILK";
    }
    else
    {
        cout << "  <---";
    }

    for (int i = 0; i < 7; i++)
    {
        if (gec->sonraki_sld == 0) // kume elemanlari bitti ise donguyu kir
            break;
        gec = gec->sonraki_sld;
        sayac++;
    }

    if (gec->sonraki_sld == 0)
    {
        cout << setw((sayac * 12) + 3) << "SON";
    }
    else
    {
        cout << setw((sayac * 12) + 3) << "--->";
    }
}
