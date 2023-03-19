#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Data {
private:
    int zi;
    string luna;
    int an;
public:
    Data()
    {
        cout << "constructor Data " << endl;
    }
   

    Data(const int& zi_, const string& lunaParam, const int& an_)
    {

        zi = zi_;
        luna = lunaParam;
        an = an_;

    }
    
    ~Data()
    {
        cout << "destructor Data " << endl;
    }
    friend ostream& operator<<(ostream& os, const Data& d)
    {
        os << "Ziua: " << d.zi << ' ' << " Luna: " << d.luna << " An: " << d.an << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Data& d)
    {
        cout << "Ziua : ";
        is >> d.zi;
        cout << "Luna : ";
        is >> d.luna;
        cout << "An: ";
        is >> d.an;
        return is;

    }
    bool operator<(const Data& other) const
    {
        if (this->an < other.an) 
        {
            return true;
        }
        else if (this->an > other.an) 
        {
            return false;
        }
        else 
        {
            if (this->luna < other.luna) 
            {
                return true;
            }
            else if (this->luna > other.luna) 
            {
                return false;
            }
            else 
            {
                if (this->zi < other.zi) 
                {
                    return true;
                }
                else 
                    return false;
                
            }
        }
    }
};

class Medicament {

private:
    string denumire;
    float pret;
    Data fabricat;
public:
    Medicament()
    {
        cout << "constructor Medicament" << endl;
    }
    friend ostream& operator<<(ostream& os, const Medicament& m)
    {
        os << "Denumire: " << m.denumire << ' ' << " Pret: " << m.pret << " An fabricatie : " << m.fabricat << endl;
        return os;
    }
    friend istream& operator>>(istream& in, Medicament& m)
    {
        cout << "Denumire: ";
        in >> m.denumire;
        cout << "Pret: ";
        in >> m.pret;
        cout << "An fabricatie: ";
        in >> m.fabricat;
        return in;
    }
    Medicament(const string& denumire_, const float& pret_, const Data& fabricat_)
    {
        denumire = denumire_;
        pret = pret_;
        fabricat = fabricat_;
    }
    /* nu a iesit..
    Medicament(const string& denumire_, const float& pret_, const int& fabricat_)
    {
        denumire = denumire_;
        pret = pret_;
        fabricat - fabricat_;
    }*/
    Medicament(const string& denumire_,const Data& fabricat_)
    {
        denumire = denumire_;
        fabricat = fabricat_;
    }

    ~Medicament()
    {
        cout << "destructor Medicament" << endl;
    }

    bool operator<(const Medicament& other) const
    {
        return this->fabricat < other.fabricat;
    }
  
    


};

class Farmacie {
private:
    string denumire;
    int nrMedicamente;
    vector <Medicament> Med;
    

public:
    Farmacie()
    {
        cout << "constructor Farmacie" << endl;
    }
    ~Farmacie()
    {
        cout << "destructor Farmacie" << endl;
    }
    Farmacie(const string& denumireParam)
    {
        denumire = denumireParam;
        nrMedicamente = 0;

    }
  
    
    friend ostream& operator<<(ostream& os, const Farmacie& f)
    {
        os << "Denumire: " << f.denumire << ' ' << " NrMedicamente: " << f.nrMedicamente <<endl;
        for (Medicament x : f.Med)
        {
            os << x << ' ';
        };
        return os;
    }
    
   

    Farmacie& operator=(const Farmacie& other)
    {
        denumire = other.denumire;
        nrMedicamente = other.nrMedicamente;
        Med = other.Med;
        return *this;

    }

    Farmacie& operator+=(const Medicament& m)
    {
        nrMedicamente++;
        /*for (int i=0; i < nrMedicamente; i++)
        {

        }*/
        return *this;
    }

   
};
    

int main()
{
    
    Data d(1, "ianuarie", 2018), d2;
    cout << d;
    cin >> d2;
    cout << d2;
    //Medicament m1("Parasinus", 9.5, 10),m2("Aspirina",d), m3;
    cout << m2;
    cin >> m3;
    cout << m1;
    if (m1 < m2) cout << "m1 este fabricat inaintea m2";
    else cout << "m2 este fabricat inaintea m1";
    Farmacie f1("Farmac");
    f1 += m1; //adaugare medicament m1 in lista de medicamente a farmaciei
    //f1 = m2 + f1; //adaugare medicament m2 in lista de medicamente a farmaciei
    Farmacie f2 = f1;
     cout << f2;    //afisarea tuturor medicamentelor

}