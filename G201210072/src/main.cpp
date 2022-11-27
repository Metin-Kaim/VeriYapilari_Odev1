/*
* @file             main.cpp
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
#include <string>
#include <fstream>
#include <cmath>
#include <windows.h>

#include "YoneticiListesi.hpp"

using namespace std;
int main()
{
    YoneticiListesi *y = new YoneticiListesi();
    int satirSayisi = 0;
    // int *myArray[SIZE] = new int[SIZE];

    ifstream dosya;
    dosya.open("./veriler.txt");

    while (!dosya.eof())
    {
        string satir;
        int sayiBaslangic = 0;
        int sayiAdedi = 0;
        int diziDolasimi = -1;
        int *sayilar = 0;

        getline(dosya, satir);

        if (satir == "") // Satirin boş olup olmadigini kontrol eden yapi.
        {
            continue;
        }
        satirSayisi++;
        for (int i = 0; i < satir.length(); i++) // bir satirda kac adet sayi oldugunu hesaplama
        {
            string islem = satir.substr(i, 1);
            if (islem != " ")
            {
                if (i == (satir.length()) - 1) // satir sonu
                    sayiAdedi++;
            }
            else
            { // boşluk ise
                sayiAdedi++;
            }
        }

        sayilar = new int[sayiAdedi]; // okunan satirdaki sayi adedi uzunlugunda bir dizi olusturma

        for (int i = 0; i < sayiAdedi; i++) // dizideki degerleri default 0'a cekme
        {
            sayilar[i] = 0;
        }

        for (int i = 0; i < satir.length(); i++) // okunan satirdaki sayilari "sayilar" adli diziye aktarma
        {
            string islem = satir.substr(i, 1);
            if (islem == " ")
            { // boşluk ise
                ++diziDolasimi;
                sayilar[diziDolasimi] = stoi(satir.substr(sayiBaslangic, i - sayiBaslangic));
                sayiBaslangic = i + 1;
                // cout << sayilar[diziDolasimi] << " ";
            }
            else if (islem != " ")
            {
                if (i == (satir.length()) - 1) // satir sonu
                {
                    ++diziDolasimi;
                    sayilar[diziDolasimi] = stoi(satir.substr(sayiBaslangic, i - sayiBaslangic + 1));
                    sayiBaslangic = i + 1;
                    // cout << sayilar[diziDolasimi] << " ";
                }
            }
        }
        y->ekle(sayilar, sayiAdedi);
    }
    
    int kacinciKume = 0;
    int seciliDugum = 0;
    int k_sayac = 0;
    int sonSatirdakiDugumSayisi = satirSayisi % 8; // son satirda kac adet dugum oldugunu bulma
    system("cls");
    y->yazdir_Yonetici(seciliDugum, kacinciKume, (kacinciKume * 8) + seciliDugum);

    while (true)
    {
        cout << endl;
        string tercih;
        cin >> tercih;

        system("cls");

        if (tercih == "c")
        {
            if (seciliDugum < 7)
                if (kacinciKume == floor(satirSayisi / 8)) // eger ki son kumede isen
                {
                    if (seciliDugum < sonSatirdakiDugumSayisi - 1)
                        seciliDugum++;
                }
                else
                    seciliDugum++;
            else
            {
                if (kacinciKume < floor(satirSayisi / 8) && sonSatirdakiDugumSayisi != 0) // toplam kume sayisi
                {
                    kacinciKume++;
                    seciliDugum = 0;
                }
            }
        }
        else if (tercih == "z")
        {
            if (seciliDugum > 0)
                seciliDugum--;
            else
            {
                if (kacinciKume > 0)
                {
                    kacinciKume--;
                    seciliDugum = 7;
                }
            }
        }
        else if (tercih == "a")
        {
            if (kacinciKume > 0)
                kacinciKume--;
        }
        else if (tercih == "d")
        {
            if (kacinciKume < floor(satirSayisi / 8) && sonSatirdakiDugumSayisi != 0)
            {
                kacinciKume++;
            }

            if (kacinciKume == floor(satirSayisi / 8))
            {
                if (seciliDugum > sonSatirdakiDugumSayisi - 1)
                    seciliDugum = sonSatirdakiDugumSayisi - 1;
            }
        }
        else if (tercih == "p")
        {
            int silinecekDugum = (kacinciKume * 8) + seciliDugum;
            y->dugumSil(silinecekDugum);
            satirSayisi--;
            sonSatirdakiDugumSayisi = satirSayisi % 8;

            if (y->sonSatirSilindi)
            {
                seciliDugum--;
            }
            if (sonSatirdakiDugumSayisi == 0 && kacinciKume == floor(satirSayisi / 8))
            {
                kacinciKume--;
                seciliDugum = 7;
            }
        }
        else if (tercih == "k")
        {
            k_sayac++;
            if (k_sayac == 1)
            {
                y->satirListesiDugumSayisi((kacinciKume * 8) + seciliDugum, 0);
            }
            else if (k_sayac == 2)
            {
                y->satirListesiDugumSayisi((kacinciKume * 8) + seciliDugum, 1);
                if (y->dugumAzaltma)
                {
                    satirSayisi--;
                    sonSatirdakiDugumSayisi = satirSayisi % 8;
                }
                if (y->sonSatirSilindi)
                {
                    seciliDugum--;
                }
                if (sonSatirdakiDugumSayisi == 0 && kacinciKume == floor(satirSayisi / 8))
                {
                    kacinciKume--;
                    seciliDugum = 7;
                }

                k_sayac = 0;
            }
        }
        else if(tercih=="111")//uygulamadan cikis kodu
        {
            return 0;
        }
        else
        {
            y->yazdir_Yonetici(seciliDugum, kacinciKume, (kacinciKume * 8) + seciliDugum);
            cout << endl
                 << "Gecersiz Islem Girisi!!!\nTekrar Deneyin...";
            k_sayac = 0;
            continue;
        }

        y->yazdir_Yonetici(seciliDugum, kacinciKume, (kacinciKume * 8) + seciliDugum);

        if (tercih != "k")
        {
            k_sayac = 0;
        }
    }
    dosya.close();
}