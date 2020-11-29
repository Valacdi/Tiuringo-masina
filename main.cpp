#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <unistd.h>

using namespace std;

class Tiuringo_Masina
{
    private:
        int GalPoz, Indeksas = 0, Ilgis;
        string Juosta, EsamBus[100], NaujBus[100], PradineBusena;
        char EsamSimb[100], NaujSimb[100], Kryptis[100];
    public:
        void Skaitymas(string Failas);
        void RodytiRez();
};

void Tiuringo_Masina::Skaitymas(string Failas)
{
    ifstream fd(Failas);
    fd >> Juosta >> GalPoz;
    while (!fd.eof())
    {
        fd >> EsamBus[Indeksas] >> EsamSimb[Indeksas] >> NaujSimb[Indeksas] >> Kryptis[Indeksas] >> NaujBus[Indeksas];
        Indeksas++;
    }
    fd.close();
}

void Tiuringo_Masina::RodytiRez()
{
    Ilgis = Juosta.length();
    PradineBusena = "0";
    while (GalPoz!=Juosta[Ilgis-1] || GalPoz!=Juosta[0]) ///vykdo cikla tol, kol pozicija neiseina is juostos ribu
    {
        for (int i=0; i<Indeksas; i++) ///paleidziamas ciklas per programos eilutes
        {
            if (EsamBus[i]==PradineBusena) ///tikrina ar pradine busena lygi 0 (ar buvusi busena pries tai)
            {
                if (EsamSimb[i]==Juosta[GalPoz])///tikrina ar esamas simbolis atitinka simboli, ant kurio yra galvute
                {
                    Juosta[GalPoz]=NaujSimb[i]; ///juostoje simboli pakeicia nauju
                    PradineBusena=NaujBus[i]; /// pakeiciama busena, su kuria tikrinama
                    if (Kryptis[i]=='R') ///tikrina ar galvute turi judeti i desine
                    {
                        GalPoz++; /// jei taip, pozicija padideja
                    }
                    if (Kryptis[i]=='L') ///tikrina ar turi judeti i kaire
                    {
                        GalPoz--; ///jei taip, pozicijos sk mazeja
                    }
                }
            }
        }
        cout << Juosta << endl;
        usleep(3000);
    }
}

int main()
{
    Tiuringo_Masina obj;
    string Failas;
    int Pasirinkimas;

    do
    {
    cout << "Pasirinkite faila\n";
    cout << "1. 1.txt\n";
    cout << "2. 2.txt\n";
    cout << "3. 3.txt\n";
    cout << "4. 4.txt\n";
    cout << "5. Baigti\n";
    cout << "Pasirinkite: ";
    cin >> Pasirinkimas;

    switch (Pasirinkimas)
        {
        case 1:
            Failas = "1.txt";
            obj.Skaitymas(Failas);
            obj.RodytiRez();
            /// pildyt
            break;
        case 2:
            Failas = "2.txt";
            obj.Skaitymas(Failas);
            obj.RodytiRez();
            /// pildyt
            break;
        case 3:
            Failas = "3.txt";
            obj.Skaitymas(Failas);
            obj.RodytiRez();
            /// pildyt
            break;
        case 4:
            Failas = "4.txt";
            obj.Skaitymas(Failas);
            obj.RodytiRez();
            /// pildyt
            break;
        case 5:
            break;

        default:
            cout << "Blogas pasirinkimas!!!";
        }
    } while(Pasirinkimas != 5);

	return 0;
}
