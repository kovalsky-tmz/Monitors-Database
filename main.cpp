#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>


using namespace std;
struct monitor
{
string producent;
string model;
string kolor_monitora;
string typ;
float cal;
float kolor_mln;
float waga_kg;
unsigned int rok;
};




void dodaj(struct monitor baza[], int ile)
{

	     for(int i=1; i<=ile;i++){
	cout<<"Producent: "<<endl;
	cin>>baza[i].producent;
	cout<<"Model: "<<endl;
	cin>>baza[i].model;
	cout<<"Kolor monitora: "<<endl;
	cin>>baza[i].kolor_monitora;
	cout<<"Typ: "<<endl;
	cin>>baza[i].typ;
	cout<<"Ile cali?: "<<endl;
	cin>>baza[i].cal;
	cout<<"Ile kolorow?(w milionach): "<<endl;
	cin>>baza[i].kolor_mln;
	cout<<"Waga (w kg): "<<endl;
	cin>>baza[i].waga_kg;
	cout<<"Rok: "<<endl;
	cin>>baza[i].rok;
	}
}

void zapisz (struct monitor baza[], int ile){
     fstream plik( "plik.txt", ios::out | ios::app);
    if( plik.good() )
    {
        for( int i = 1; i <= ile; i++ )
        {
        	plik <<endl;
            plik <<"Producent: "<< baza[i].producent <<endl;
            plik <<"Model: "<< baza[i].model<< endl;
            plik << "Kolor Monitora: "<<baza[i].kolor_monitora << endl;
            plik << "Typ: "<<baza[i].typ<< endl;
            plik << "Cal: "<< baza[i].cal << endl;
            plik << "Kolory w milionach: "<<baza[i].kolor_mln <<endl;
            plik << "Waga: "<<baza[i].waga_kg << endl;
            plik << "Rok: "<<baza[i].rok<< endl;
			plik << endl;
            plik.flush();
        }
        plik.close();
    }


}



bool wczytaj(string sNazwaPliku ){


	std::ifstream plik;
    plik.open( sNazwaPliku.c_str() );
    if( !plik.good() )
         return false;

    std::string wiersz;
    while( std::getline( plik, wiersz ) )
         std::cout << wiersz << std::endl;

    plik.close();
    return true;

	    }



void wyswietl(struct monitor baza[], int ile){
 	for(int i=1; i<=ile;i++){
     cout<<i<<": "<<endl;
  	cout<<"Producent:"<<baza[i].producent<<endl;
	 cout<<"Model:"<<baza[i].model<<endl;
	 cout<<"Kolor monitora:"<<baza[i].kolor_monitora<<endl;
	cout<<"Typ:"<<baza[i].typ<<endl;
	cout<<"Cal:"<<baza[i].cal<<endl;
	cout<<"Kolor w mln:"<<baza[i].kolor_mln<<endl;
	cout<<"Waga w kg: "<<baza[i].waga_kg<<endl;
	cout<<"Rocznik: "<<baza[i].rok<<endl;
     }
 }





void szukajj(string  tekst, string szukanaFraza )
{
	int i=0;

    size_t znalezionaPozycja = tekst.find( szukanaFraza );
    if( znalezionaPozycja == string::npos )
    {

        return;
    }

    do
    {
        i=i+1;
        znalezionaPozycja = tekst.find( szukanaFraza, znalezionaPozycja + szukanaFraza.size() );
    } while( znalezionaPozycja != string::npos );
    cout<<"Ile razy? : " << i<<endl;
}


void edytuj (struct monitor baza[], int ile){
  int j = 1;
                cout<<"Podaj numer monitora do edycji: ";
                cin>>j;

                cout<<"Podaj Producenta :\n";
                cin>>baza[j].producent;
                cout<<"Podaj model:\n";
                cin>>baza[j].model;
                cout<<"Podaj kolor :\n";
                cin>>baza[j].kolor_monitora;
                cout<<"Podaj typ :\n";
                cin>>baza[j].typ;
                  cout<<"Podaj ile cali :\n";
                cin>>baza[j].cal;
                  cout<<"Podaj kolor monitora :\n";
                cin>>baza[j].kolor_mln;
                  cout<<"Podaj wage :\n";
                cin>>baza[j].waga_kg;
                  cout<<"Podaj rok :\n";
                cin>>baza[j].rok;

}

void kasuj( struct monitor baza[], int ile )
{

                int j = 0;
                cout<<"Podaj numer samochodu do usuniecia: ";
                cin>>j;

                for(int i = j;i<=ile;i++)
                {
                    baza[i].producent = baza[i+1].producent;
                    baza[i].model = baza[i+1].model;
                    baza[i].kolor_monitora = baza[i+1].kolor_monitora;
                    baza[i].rok = baza[i+1].rok;
                }
                ile--;

            }


int main()
{
    struct monitor baza[100];
int wybor;
int ile;
int wybor1;
int wybor2;
int wybor3;
do{
    cout<<"1.Dodaj"<<endl;
    cout<<"2.Edytuj/Usun"<<endl;
    cout<<"3.Wyswietl dodane"<<endl;
    cout<<"4.Zapisz do pliku"<<endl;
    cout<<"5.Wczytaj z pliku"<<endl;
    cout<<"6.Znajdz"<<endl;
    cout<<"7.Srednie"<<endl;
    cout<<"8.Wyjscie"<<endl;
    cout<<"Wybierz liczbe: "<<endl;
    cin>>wybor;
    switch (wybor)
    {
    case 1:
            cout<<"Wybrales 'Dodaj'"<<endl;
            cout<<"Ile monitorow dodac?"<<endl;
            cin>>ile;
            dodaj (baza, ile);
            break;

    case 2:
            cout<<"Wybrales 'Edytuj/Usun'"<<endl;
            do{
                cout<<"1.Edytuj"<<endl;
                cout<<"2.Usun"<<endl;
                cout<<"3.Wroc do menu"<<endl;
                cout<<"Wybor:"<<endl;
            cin>>wybor1;
            switch(wybor1){
            case 1:
                cout<<"Wybra³eœ edycje"<<endl;
                edytuj (baza, ile);
            break;
            case 2:
             break;
            case 3:
            break;
            }
            }while(wybor1!=3);
            break;
    case 3:
        cout<<"Wybrales 'Wyswietl dodane': "<<endl;
        cout<<endl;
        wyswietl (baza, ile);
        cout<<endl;
        break;

    case 4:
        cout<<"ZAPISANO!"<<endl;
        zapisz (baza, ile);
        break;

    case 5:
        cout<<" Wybrales 'Wczytaj z pliku'"<<endl;
            wczytaj("plik.txt");
            break;
    case 6:
        cout<<"Wybrales 'Znajdz'"<<endl;
            do{
                cout<<"1.Znajdz Model"<<endl;
                cout<<"2.Znajdz Producenta"<<endl;
                cout<<"3.Znajdz Typ"<<endl;
                cout<<"4.Znajdz Kolor"<<endl;
                cout<<"5.Wroc do menu"<<endl;
            cout<<"Wybor:"<<endl;
            cin>>wybor2;
            switch(wybor2){
        case 1:
            string slowo;
            ifstream plik;
        plik.open( "plik.txt" );
        if( !plik.good() )
             return false;

        string wiersz;
        cin>>slowo;
        while( getline( plik, wiersz ) ){

        szukajj(wiersz,slowo.c_str());
    }





        }


        }while(wybor2!=5);
        break;
    case 7:
            cout<<"Wybrales 'Srednie'"<<endl;
            do{
                cout<<"1.Srednia roku produkcji"<<endl;
                cout<<"2.Srednia przekatnych ekranu"<<endl;
                cout<<"3.Wroc do menu"<<endl;
            cout<<"Wybor:"<<endl;
            cin>>wybor3;
            switch(wybor3){
                case 1:

                break;
                case 2:
                break;
                case 3:
                break;
                }
                }while(wybor3!=3);
	case 8:
        cout<<"Koniec"<<endl;
            break;
    case 9:
        kasuj (baza, ile);

            default:
            cout<<"Nieprawidlowa liczba"<<endl;
            }
            }while(wybor!=8);


}
