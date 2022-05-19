#include "fuggvenyek.h"
#include <iostream>
#include "Es.h"
#include "Nand.h"
#include "Nor.h"
#include "Vagy.h"
#include "Xor.h"
#include "Negalt.h"
using namespace std;

/**
 * Kiírja mit vár el a felhasználótól, és beolvassa a sztringbe ami bejön a standard bementen
 */
int fuggvenykeres(string &fv)
{
    int hossz=0;//beadott függvény hány karakterből áll
    cout<<"A program maximum 8 valtozos fuggvenyeket kepes lekezelni, es legfeljebb 80 karaktert olvas be."<<endl;
    cout<<"ES kapu jele *; Vagy kapu jele +; Nand kapu jele &; Nor kapu jele |; Xor kapu jele ^; Negalt kapu jele -"<<endl;
    cout<<"A valtozokat az angol abc betuivel lehet jelolni."<<endl<<"A program megkulonbozteti a kis es nagybetuket."<<endl;
    cout<<"Pelda beadhato fuggvenyre: A*B+-b&a|-c"<<endl;
    cout<<"Adja be a fuggvenyt:"<<endl;

    getline(cin, fv);
    hossz=fv.length();
    return hossz;
}

/**
 * Lehetséges hibákat lekezeli a függvény beadásakor
 */
bool hibakereses(string fv, int hossz)
{
    int felsolimit=80;//a fuggvény hosszának maximális mérete
    int alsolimit=2;
    try
    {
        if (hossz > felsolimit)//tul hosszu
        {
            throw "Tul hosszu a beadott fuggveny";
        }
        if (hossz < alsolimit)//tul rovid
        {
            throw "Tul rovid a beadott fuggveny, nincs mit kiertekelni";
        }
        if(fv.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+*|&-^")<hossz)//2^64 el tér vissza ami nagyobb 80 így nem számít
        {
            throw "Ismeretlen karakter tartalmaz";
        }
        if (!((fv[0] <= 'Z' && fv[0] >= 'A') || (fv[0] >= 'a' && fv[0] <= 'z') ||
              fv[0] == '-')) {
            throw "Rosszul kezdodik a fuggveny";
        }
        if (!((fv[hossz-1] <= 'Z' && fv[hossz-1] >= 'A') || (fv[hossz-1] >= 'a' && fv[hossz-1] <= 'z')))
        {
            throw "Rosszul fejezodik be a fuggveny";
        }
        for (int i = 0; i <= hossz; ++i)
        {
            if ((fv[i] == '+' || fv[i] == '*' || fv[i] == '|' || fv[i] == '&' || fv[i] == '-' || fv[i] == '^') &&
                (fv[i + 1] == '+' || fv[i + 1] == '*' || fv[i + 1] == '|' || fv[i + 1] == '&' || fv[i + 1] == '^')) {
                throw "Kimaradt egy valtozo";
            }
            if (((fv[i] >= 'A' && fv[i] <= 'Z') || (fv[i] >= 'a' && fv[i] <= 'z')) &&
                ((fv[i + 1] >= 'A' && fv[i + 1] <= 'Z') ||
                 (fv[i + 1] >= 'a' && fv[i + 1] <= 'z') || fv[i+1]=='-')) {
                throw "Kimaradt egy muveleti jel";
            }
        }
    }
    catch(const char* hibak)
    {
        cerr<<hibak<<endl;
        return true;
    }
    return false;
}

/**
 * Megnézi szerepel-e a változótömb elemei között az a karakter amit beleszeretnék tenni változónak
 */
bool tombberak(int db, char valtozo, char * tomb)
{
    for(int j = 0; j < db; j++)
    {
        if (valtozo==tomb[j])
            return false;
    }
    return true;
}

/**
 * Bekéri a változók értékeit és elkapja a hibát, ha rossz lett neki beadva
 */
int ertekadas(char valtozo)
{
    int ertek;
    cout<<"Adja be a/az "<<endl;
    cout<<valtozo;
    cout<<" valtozo erteket (0 vagy 1)"<<endl;
    cin>>ertek;
    try
    {
        if (ertek==0 || ertek==1);
        else
        {
            throw"A valtozonak rossz ertek lett beadva";
        }
    }
    catch(const char* hiba)
    {
        cerr<<hiba<<endl;
    }
    return ertek;
}

bool valtozo_kereses(int hossz, string &fv)
{
    char* valtozotomb= nullptr;//ide fogom rakni a változók értékeit
    int db=0;//itt számolom hány változóm van
    /**
     * Végig megyek a függvényen kiszedve belőle a betűket(változókat)
     */
    for (int i = 0; i <= hossz; ++i)
    {
        if ((fv[i]>='A' && fv[i]<='Z') || (fv[i]>='a' && fv[i]<='z'))
        {
            //ha első elemet teszem bele
            if (valtozotomb== nullptr)
            {
                db++;
                char *seged = new char[db];
                seged[0] = fv[i];
                valtozotomb = seged;
            }
            //több mint 8változós a függvény
            for (int j = 0; j < db; j++)
            {
                //tobb mint 8 valtozo
                try
                {
                    if (fv[i]!=valtozotomb[j] && db>=8)
                    {
                        throw "Tul sok a valtozo";
                    }
                }
                catch(const char* hiba)
                {
                    cerr<<hiba<<endl;
                    return 0;
                }
                //belerakja a tömbbe a többi elemet
                if(tombberak(db, fv[i], valtozotomb))//akkor lép be ide ha nem találja meg a változót a változótömbben
                {
                    char* seged=new char[db+1];
                    for (int k = 0; k < db; ++k)
                    {
                        seged[k]=valtozotomb[k];
                    }
                    seged[db]=fv[i];
                    valtozotomb=seged;
                    db++;
                }
            }
        }
    }
    /**
     * Bekéri a segédfüggvénnyel a változók értékeit, amit beletesz a függvény megfelelő helyére
     */
    for(int i=0; i<db; i++)
    {
        while(true)
        {
            int seged = ertekadas(valtozotomb[i]);//kiíratom ha rossz érték lett beadva és mivel utána lévő if-be nem jutok úgy be, a while ciklusban maradok
            if (seged == 0 || seged == 1)
            {
                //kicserélem a függvényben szereplő megfelelő karaktert az annak beadott értékre
                for (int j = 0; j < hossz; ++j)
                {
                    if (valtozotomb[i]==fv[j])
                    {
                        fv[j]=seged;
                    }
                }
                break;
            }
        }
    }
    return false;
}

template<class T>
void seged_ertekeles(string &fv, int &hossz, char műveletijel)
{
    int index=0;//hányadik helyen van a műveleti jel
    /**
     * Addig futtatom az adott műveleti jelre míg vagy nem ment végig a stringen(utolsó helyen nem állhat műveleti jel), vagy míg a hossza a stringnek nem lesz 1, hiszen ekkor már szintén nincs művelet, csak az eredmény
     */
    while(hossz!=1 && hossz!=index)
    {
        if (fv[index] == műveletijel)//megnézi az adott helyen szerepel e a kellő műveleti jel
        {
            bool a = fv[index - 1] && fv[index - 1] !='0' ? 1 : 0;
            bool b = fv[index + 1] && fv[index + 1] !='0' ? 1 : 0;
            T valami = T(a, b);
            valami.print(valami);
            string eredmeny;
            switch (műveletijel) {
                case '*':
                    eredmeny = to_string(a * b);
                    break;
                case '&':
                    eredmeny = to_string(not(a * b));
                    break;
                case '+':
                    eredmeny = to_string(a + b);
                    break;
                case '|':
                    eredmeny = to_string(not(a | b));
                    break;
                case '^':
                    eredmeny = to_string(a ^ b);
                    break;
            }
            fv.insert(index - 1, eredmeny);
            fv.erase(index, 3);
            hossz = hossz - 2;
            break;
        } else
            index++;
    }
}

/**
 * Kiértékeli a függvényt
 */
int kiertekeles(string fv, int hossz)
{
    int index=0;
    //a negálást nem tettem a templatebe mert más mennyiségű karaktert kéne törölni
    while(hossz!=1 && hossz!=index)
    {
        if (fv[index] == '-')
        {
            bool b = fv[index + 1] && fv[index + 1] !='0' ? 1 : 0;
            Negalt valami = Negalt(b);
            valami.print(valami);
            fv.insert(index, to_string(not b));
            fv.erase(index+1, 2);
            hossz = hossz - 1;
        } else
            index++;
    }
    //így előszőr az előbbrevaló műveleteket próbálja meg kiértékelni benne, tehát jó sorrendben lesz végrehajtvaa kiértékelés
    for (int i = 0; i < hossz; ++i)
    {
        if(fv[i]=='*')
        {
            seged_ertekeles<Es>(fv, hossz, '*');
            i = 0;
        }
        if(fv[i]=='&')
        {
            seged_ertekeles<Nand>(fv, hossz, '&');
            i=0;
        }
    }
    for (int i = 0; i < hossz; ++i)
    {
        if(fv[i]=='+')
        {
            seged_ertekeles<Vagy>(fv, hossz, '+');
            i=0;
        }
        if(fv[i]=='|')
        {
            seged_ertekeles<Nor>(fv, hossz, '|');
            i=0;
        }
        if(fv[i]=='^')
        {
            seged_ertekeles<Xor>(fv, hossz, '^');
            i=0;
        }
    }
}