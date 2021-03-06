
#include <iostream> // cout, cin
//#include <stdio> // printf, getchar
#include <string> // strcpy
//#include <stdlib> // malloc, free
#include <fstream>


using namespace std;

void wprowadzanie();
void wyjscie();
void skasuj(int);
void znajdz_stud();
void wyswietlenie();
void nie_gotowa();
int znajdz();
void wyswietl(int);
void nadpisz(int);
void dodaj();
void zapis_do_pliku();
void odczyt_z_pliku();

int ilosc = 500;
int ostatni, liczba, indeks;
int ilosc_osob;
int ind;
float liczba1;
struct student
{
	char imie[25];
	char nazwisko[25];
	int wiek;
	float srednia;
} *lista[500], *osoba; /* Definicja 500 wskaznikow, zadnych zmiennych */

int main(void)
{
	ostatni = -1;
	indeks = 0;
	lista[indeks] = new student;
	//lista[indeks] = (struct student *)malloc(sizeof(struct student));

	strcpy(lista[indeks]->imie, "Dariusz");
	strcpy(lista[indeks]->nazwisko, "Przepiora");
	lista[indeks]->wiek = 4;
	lista[indeks]->srednia = 3.77;

	indeks = 1;
	lista[indeks] = new student;
	//lista[indeks] = (struct student *)malloc(sizeof(struct student));
	strcpy(lista[indeks]->imie, "Tomasz");
	strcpy(lista[indeks]->nazwisko, "krolak");
	lista[indeks]->wiek = 3;
	lista[indeks]->srednia = 2.25;

	indeks = 2;
	lista[indeks] = new student;
	//lista[indeks] = (struct student *)malloc(sizeof(struct student));
	strcpy(lista[indeks]->imie, "Malgorzata");
	strcpy(lista[indeks]->nazwisko, "Chmiel");
	lista[indeks]->wiek = 2;
	lista[indeks]->srednia = 4.66;

	indeks = 3;
	lista[indeks] = new student;
	//lista[indeks] = (struct student *)malloc(sizeof(struct student));
	strcpy(lista[indeks]->imie, "Ziuta");
	strcpy(lista[indeks]->nazwisko, "Zeta");
	lista[indeks]->wiek = 2;
	lista[indeks]->srednia = 3.23;
	ostatni = 3;


	int opcja;


	do
	{


		cout << "\n\n 1 - dodaj studenta\n";
		cout << " 2 - skasuj studenta\n";
		cout << " 3 - zmiana danych\n";
		cout << " 4 - wyswietlenie danych studenta\n";
		cout << " 5 - wyswietlenie danych wszytkich studentow\n";
		cout << " 6 - koniec\n";
		cout << " 7 - zapis bazy do pliku\n";
		cout << " 8 - odczyt bazy z pliku\n";
		cin >> opcja;

		ind = -1;

		switch (opcja)
		{

		case 1:
			wprowadzanie();
			break;

		case 2:
			ind = znajdz();
			if (ind != -1) {
				wyswietl(ind);
				skasuj(ind); //skasuj();
			}
			break;

		case 3:
			ind = znajdz();
			if (ind != -1)
			{
				nadpisz(ind);
			}
			break;

		case 4:
			ind = znajdz();
			if (ind != -1) {
				wyswietl(ind);
			}
			break;

		case 5:
			wyswietlenie();
			break;

		case 6:
			wyjscie();
			break;

		case 7:
			zapis_do_pliku();
			break;

		case 8:
			odczyt_z_pliku();
			break;

		default:
			wyjscie();
		}
	} while (opcja != 6);

	for (indeks = 0; indeks < ostatni; indeks++)
		free(lista[indeks]);

	printf("\nNacisnij ENTER, aby zakonczyc program...");
	while (getchar() != '\n'); /* Czekaj na ENTER */
	return 0;
}

/************** Procedura wprowadzania danych ****************/

void wprowadzanie()
{
	char napis[20];
	indeks;
	indeks = 0;
	int a;
	ostatni++;

	//lista[ostatni] = osoba*;
	//lista[ostatni] = new osoba;
	lista[ostatni] = new student; //(struct student *)malloc(sizeof(struct student));
	cout << " To jest " << ostatni << " rekord\n";
	cout << "wprowadz imie - ";
	cin >> napis;
	strcpy(lista[ostatni]->imie, napis);
	cout << "wprowadz nazwisko - ";
	cin >> napis;
	strcpy(lista[ostatni]->nazwisko, napis);
	cout << "wprowadz ktory rok studiow: ";
	cin >> liczba;
	lista[ostatni]->wiek = liczba;
	cout << "wprowadz jaka srednia ocen\n (rozdielnik w postaci kropki}: ";
	cin >> liczba1;
	lista[ostatni]->srednia = liczba1;
}

void wyjscie()
{
	cout << " ********** koniec *********** ";
	for (indeks = 0; indeks < ostatni; indeks++)
		free(lista[indeks]);
	exit(0);
}

int znajdz()
{
	char dana[30];
	char dana1[30];
	char nazw[30];
	int znalal, tru, len, len1, dlug, i, j;
	cout << "\n\npodaj nazwisko studenta - ? ";
	cin >> nazw;
	int indeks = -1;
	i = 0;
	j = 0;
	do
	{
		tru = strcmp(nazw, lista[++indeks]->nazwisko);
		if (tru && (indeks == ostatni))
		{
			cout << "******* PRZYKRO MI ALE *******\n";
			cout << "W bazie nie ma takiego studenta";
			return -1;
		}

	} while (tru);

	//cout << "FINAL result: record = " << indeks << " a ostatni to: " << ostatni
	//<< "\n";
	if (tru)
	{
		cout << "******* PRZYKRO MI ALE *******\n";
		cout << "W bazie nie ma takiego studenta";
		return -1;
	}
	else
	{
		return indeks;
	}

	// if(!tru && indeks==ostatni)
}


void wyswietlenie()
{
	indeks; /* Wyswietl dane wygenerowane powyzej */
	printf("\n\n\n Imie Nazwisko Rok Srednia\n\n");
	for (indeks = 0; indeks <= ostatni; indeks++)
	{
		osoba = lista[indeks];
		printf(" %s %s %d %.1f\n",
			osoba->imie, osoba->nazwisko, osoba->wiek, osoba->srednia);
	}

}


void nie_gotowa()
{
	cout << " ********** opcja nie jest *********** \n";
	cout << " ********** jeszcze gotowa *********** \n";
	cout << " ********** sprobuj innej! *********** \n\n\n\n";
}

void wyswietl(int ind)
{
	// printf("\nPozycja nr Imie Nazwisko Rok Srednia\n\n");
	osoba = lista[ind];
	cout << "\n\npozycja nr " << ind << " ";
	printf(" %s %s %d %.1f\n",
		osoba->imie, osoba->nazwisko, osoba->wiek, osoba->srednia);
}

void nadpisz(int indeks)
{
	char napis[30];
	cout << " \n***************** UWAGA!!! *****************";
	cout << "\n rekord o nr " << indeks << " zostanie nadpisany\n\n";
	lista[indeks] = (struct student *)malloc(sizeof(struct student));
	cout << "wprowadz imie - ";
	cin >> napis;
	strcpy(lista[indeks]->imie, napis);
	cout << "wprowadz nazwisko - ";
	cin >> napis;
	strcpy(lista[indeks]->nazwisko, napis);
	cout << "wprowadz, ktory rok studiow: ";
	cin >> liczba;
	lista[indeks]->wiek = liczba;
	cout << "wprowadz jaka srednia ocen\n (rozdielnik w postaci kropki}: ";
	cin >> liczba1;
	lista[indeks]->srednia = liczba1;
	cout << "\n rekord o nr " << indeks << " zostal nadpisany\n\n";

}

void skasuj(int indeks)
{
	char polec[3], napis1[25], napis2[25];
	int tru, len, liczba3;
	float liczba2;
	cout << "\n\nCzy chcesz skasowac rekord t/n? ";
	cin >> polec;
	tru = strcmp(polec, "t");
	len = strlen(polec);
	if (len == 1)
	{
		int zacz = indeks;
		if (tru == 0)
		{
			for (int i = 0; i <= zacz; i++)
			{
				// lista[i] = (struct student *)malloc(sizeof(struct student));
				osoba = lista[i];
				strcpy(napis1, osoba->imie);
				strcpy(napis2, osoba->nazwisko);
				liczba3 = osoba->wiek;
				liczba2 = osoba->srednia;
			}
			zacz++;
			for (int i = zacz; i <= ostatni; i++)
			{
				indeks = i;

				osoba = lista[i];
				strcpy(napis1, osoba->imie);
				strcpy(napis2, osoba->nazwisko);
				liczba3 = osoba->wiek;
				liczba2 = osoba->srednia;
				i--;

				osoba = lista[i];
				strcpy(osoba->imie, napis1);
				strcpy(osoba->nazwisko, napis2);
				osoba->wiek = liczba3;
				osoba->srednia = liczba2;
				i++;
			}
			ostatni--;
		}
	}
	else
	{
		cout << "\n\nzrezygnowales";
	}

}


void dodaj()
{

	char napis[20];
	lista[indeks] = new student; //(struct student *)malloc(sizeof(struct student));
	cout << "wprowadz imie - ";
	cin >> napis;
	strcpy(lista[indeks]->imie, napis);
	cout << "wprowadz nazwisko - ";
	cin >> napis;
	strcpy(lista[indeks]->nazwisko, napis);
	cout << "wprowadz ktory rok studiow: ";
	cin >> liczba;
	lista[indeks]->wiek = liczba;
	cout << "wprowadz jaka srednia ocen\n (rozdielnik w postaci kropki}: ";
	cin >> liczba;
	lista[indeks]->srednia = liczba1;
}


void zapis_do_pliku()
{
	char napis[30];
	int licz;
	float licz1;
	fstream stud("//tmp//stud.tmp", ios::in | ios::out | ios::trunc);
	stud.seekg(0);
	stud << ostatni << " ";
	if (ostatni == -1)
	{
		stud.close();
		return;
	}
	for (int i = 0; i <= ostatni; i++)
	{
		indeks = i;
		stud << indeks << " ";
		osoba = lista[i];
		strcpy(napis, osoba->imie);
		stud << napis << " ";
		strcpy(napis, osoba->nazwisko);
		stud << napis << " ";
		licz = osoba->wiek;
		stud << licz << " ";
		licz1 = osoba->srednia;
		stud << licz1 << " \n";
	}
	stud.close();
}

void odczyt_z_pliku()
{
	char napis[30];
	int licz;
	float licz1;
	indeks = 0;
	fstream stud("//tmp//stud.tmp", ios::in | ios::out);
	stud.seekg(0);
	stud >> ostatni;
	if (ostatni == -1)
	{
		stud.close();
		return;
	}
	for (int i = 0; i <= ostatni; i++)
	{
		stud >> indeks;
		lista[indeks] = (struct student *)malloc(sizeof(struct student));
		osoba = lista[indeks];
		stud >> napis;
		strcpy(osoba->imie, napis);
		stud >> napis;
		strcpy(osoba->nazwisko, napis);
		stud >> licz;
		osoba->wiek = licz;
		stud >> licz1;
		osoba->srednia = licz1;
	}
	stud.close();

}

