// Divo Casino.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;
string ime;
void Menu(int &chipovi, int &novci);
void Igre(int &chipovi,int &novci);
void Uplata(int &chipovi, int &novci);
void Isplata(int &chipovi, int &novci);
void Jack(int &chipovi, int novci);
void BacanjeKocke(int &chipovi, int novci);
void LogIn(string &ime, int &chipovi, int &novci);
void LogOut(string &ime, int &chipovi, int &novci);
void RandomVoce(int &novci, int &chipovi);
void Provjera(int ulog, int &chipovi, bool dobitak1red, bool dobitak2red, bool dobitak3red, bool dobitak1diagonala, bool dobitak2diagonala, int prvi[], int drugi[], int treci[]);
int chip = 5;
vector<string>imena;
int korisnici = 0;
int novciPocetak;
int chipovi = 0;
//int novci = 0;
int main()
{
	int novci = 0;
	cout << "Dobro Dosli u casino \"Nemos Dobit\" " << endl;
	LogIn(ime, chipovi, novci);
	
	
	system("CLS");
	
	Menu(chipovi,novci);
	int chipovi = 0;
	
	system("PAUSE");
    return 0;
}

void Menu(int &chipovi, int &novci) {

	int menuIzbor = 0;
	do {
		cout << "Logirano na ime: " << ime << endl;
		cout << "Kredit: " << novci << endl << "Chipovi: " << chipovi<<endl;
		cout << "Upisite broj za odgovarajucu opciju !" << endl;
		cout << "1. Uplata novca" << endl;
		cout << "2. Isplata novca" << endl;
		cout << "3. Odabit igre" << endl;
		cout << "4. Logout" << endl;
		cout << "5. Izlaz" << endl;

		cin >> menuIzbor;
		switch (menuIzbor) {
		case 1:
			Uplata(chipovi,novci);
			break;
		case 2:
		    Isplata(chipovi,novci);
			break;
		case 3:
			Igre(chipovi,novci);
			break;
		case 4:
			LogOut(ime,chipovi,novci);
			break;

		}

	} while (menuIzbor != 5);
}
void Igre(int &chipovi, int &novci) {
	int izborCase = 0;
	system("CLS");
	cout << " Izaberite zeljenu igru: " << endl;
	cout << "----------------" << endl;
	cout << "1: Jack" << endl;
	cout << "----------------" << endl;
	cout << "2: Bacanje kockice" << endl;
	cout << "----------------" << endl;
	cout << "3: Vockice " << endl;
	cout << "----------------" << endl;
	cin >> izborCase;
	switch (izborCase) {
	case 1:
		Jack(chipovi, novci);
		break;
	case 2:
		BacanjeKocke(chipovi, novci);
		break;
	case 3:
		RandomVoce(novci,chipovi);
		break;
	}

 }
void Uplata(int &chipovi, int &novci) {
	system("CLS");
	cout << "UPLATA NOVCA" << endl;
	cout << "--------------" << endl;
	int chipoviTu;
	//int novciTu = novci;
	int razlika = 0;
	int izborTu;
	
	chipoviTu = novci / chip;
	razlika = novci % chip;
	cout << "Sa " << novci << " kredita mozete kupiti " << chipoviTu << " chipova i ostane vam " << razlika << " kredita !" << endl;
	cout << "Jeste li sigurni da zelite zamjeniti kredit za chipove" << endl;
	cout << "         Pritisnite:    1/Da   ili    2/Ne  " << endl;
	cin >> izborTu;
	if (izborTu == 1) {
		system("CLS");
		cout << "kupili ste " << chipoviTu << " chipova i ostalo vam je " << razlika << " kredita !!" << endl << " Sretno !!" << endl;
		chipovi += chipoviTu;
		novci = novci-(chipoviTu * 5);
		
		cout << "Sada imate: " << chipovi << " chipova!" << endl;
		system("CLS");
		return Menu(chipovi, novci);
	}
	else if (izborTu == 2) {
		return Uplata(chipovi, novci);
	}
}
void Isplata(int &chipovi, int &novci) {
	int sadChipovi = chipovi;
	int broj = 0;
	int novacSad = novci;
	//int ostatak = 0;
	
	cout << "Trenutno imate " << sadChipovi << " !!" << endl;
	cout << "Upisite broj chipova koje zelite unovcit" << endl;
	cin >> broj;
	if (broj <= chipovi) {
		int izbor = 0;
		int zaIsplatu = 0;
		
		

		zaIsplatu = broj * 5;
		
		cout << "Jeste li sugurni da zelite unovciti " << broj << "chipova za " << zaIsplatu << " ?" << endl;
		cout << "         Pritisnite:    1/Da   ili    2/Ne  " << endl;
		cin >> izbor;
		if (izbor == 1) {
			chipovi = sadChipovi - broj;
			novci = novacSad + zaIsplatu;
			cout << "Ostalo vam je " << chipovi << " chipova i " << novci << " kredita !" << endl;
			system("CLS");
			return Menu(chipovi, novci);
		}
		else if (izbor == 2) {
			return Menu(chipovi, novci);
		}
		else {
			cout << "Vas unos nije ispravan ! Pokusajte opet : " << endl;
			return Isplata(chipovi,novci);
		}



	}
}
void Jack(int &chipovi,int novci) {

	srand(time(NULL));
	char prvi = '+';
	char drugi = 'X';
	char treci = 'O';
	char cetvrti = '*';
	int random[4] = { 1,2,3,4 };
	int pocetak = 0;
	int ulog = 0;
	cout << "Dobro Dosli u Jack Igru" << endl;
	cout << "Upisite ulog : " << ulog << endl;
	cin >> ulog;
	cout << "pritisnite 2 za pocetak igre ili 1 za povratak na Menu" << endl;
	cin >> pocetak;
	if (pocetak == 2) {
		
		if (ulog>chipovi ) {
			
			cout << "Nedovoljno cipova !" << endl;
			system("CLS");
			Menu(chipovi,novci);
		}

		//cin >> pocetak;
		chipovi -= ulog;

		system("CLS");
		cout << "                *********JACK*********" << endl;
		cout << "                ----------------------------------" << endl;
		cout << endl << endl;
		for (int i = 0; i < 4; i++) {

			int n = (rand() % 4) + 1;

			cout << "   |    ";
			if (n == 1) {

				cout << prvi << "  ";
				random[i] = 1;
			}
			else if (n == 2) {
				cout << drugi << "  ";
				random[i] = 2;
			}
			else if (n == 3) {
				cout << treci << "  ";
				random[i] = 3;
			}
			else if (n == 4) {
				cout << cetvrti << "  ";
				random[i] = 4;

			}
		}
		cout << endl;
		if ((random[0] == random[1]) && (random[1] == random[2]) && (random[2] == random[3])) {
			chipovi += (ulog * 16);
			cout << "Imate jos " << chipovi << " chipova!" << endl;
			cout << "Dobitak" << endl;
		}
		else {
			cout << "Imate jos " << chipovi << " chipova!" << endl;
			cout << "nista" << endl;
		}


	}
	else if(pocetak == 1) {
		system("CLS");
		Menu(chipovi, novci);
	}

}
void BacanjeKocke(int &chipovi, int novci) {
	srand(time(NULL));
	int d1ti = 0;
	int d2ti = 0;
	int d1Cpu = 0;
	int d2Cpu = 0;
	int stagod;
	int izbor = 0;
	cout << "Upisite ulog" << endl;
	cout << "Max bet = " << chipovi << endl;
	int bet = 1;
	cin >> bet;
	if (bet > chipovi) {
		cout << "Nemate dovoljno chipova !" << endl;
		Menu(chipovi, novci);

	}

	cout << " pritisnite 2 za bacanje prve kockice ili 1 za Izlaz" << endl;
	cin >> izbor;
	if (izbor == 1) {
		system("CLS");
		Menu(chipovi, novci);
		
	}
	//if(izbor !=1||izbor !=2) {
	//	cout << "Krivi unos!! Pokusajte ponovo !!" << endl;
	//	BacanjeKocke(chipovi, novci);

	//}

	while (izbor == 2) {


		if (chipovi > bet) {
			system("CLS");
			cout << "                *********BACANJE KOCKICA*********" << endl;
			cout << "                ----------------------------------" << endl;

			d1ti = (rand() % 6) + 1;
			cout << " Dobili ste broj: " << d1ti << endl;
			d1Cpu = (rand() % 6) + 1;
			cout << " Komp je dobio broj: " << d1Cpu << endl;
			cout << " pritisnite 2 za drugo bacanje ili 1 za izlaz" << endl;
			cin >> stagod;
			if (stagod != 1) {

				chipovi -= (1 * bet);
				d2ti = (rand() % 6) + 1;
				cout << " Dobili ste broj: " << d2ti << endl;
				d2Cpu = (rand() % 6) + 1;
				cout << " Komp je dobio broj: " << d2Cpu << endl;
				cout << " ------------------------" << endl;
				cout << " Vi: " << (d1ti + d2ti) << endl;
				cout << " Komp: " << (d1Cpu + d2Cpu) << endl;
				if ((d1ti + d2ti) < (d1Cpu + d2Cpu)) {
					cout << " Nista" << endl;
					cout << " Imate jos " << chipovi << " chipova!" << endl;
					BacanjeKocke(chipovi, novci);
				}
				else if ((d1ti + d2ti) > (d1Cpu + d2Cpu)) {
					cout << " Bravo osvojili ste " << (bet * 5) << "  chipova!" << endl;
					chipovi += (5 * bet) ;
					cout << " Imate jos " << chipovi << " chipova!" << endl;
					BacanjeKocke(chipovi, novci);
				}
				else if ((d1ti + d2ti) > (d1Cpu + d2Cpu)) {
					cout << " Nerjeseno !! Vas ulog je vracen !!" << endl;
					chipovi += bet;
					cout << " Imate jos " << chipovi << " chipova!" << endl;
					BacanjeKocke(chipovi, novci);
				}

			}
			else if (stagod == 1) {
				Menu(chipovi, novci);
			}


		}
		else {
			cout << "Nemate dovoljno chipova !" << endl;
			Menu(chipovi, novci);
		}
	}
}
void LogIn(string &ime, int &chipovi, int &novci){
	ifstream listaImenaVan;
	string i;
	listaImenaVan.open("Text.txt", ios::out);
	while (listaImenaVan) {
		listaImenaVan >> i;
		imena.push_back(i);
		korisnici++;

	}
	
	
	cout << "Ime na koje se zelite logirati" << endl;
	cin >> ime;
	for (int i = 0; i < korisnici; i++) {
		if (ime == imena[i]) {
			cout << "Vase ime se vec koristi" << endl;
			return LogIn(ime, chipovi, novci);
		}
	}

		//	cout << "Dobro Dosli" << endl;
			//continue;
			//korisnici++;
			

			cout << "Koliko novaca imate?" << endl;
			cin >> novci;
			novciPocetak = novci;
			
		

		


	
}
void LogOut(string &ime, int &chipovi, int &novci) {
	ofstream listaImena;
	listaImena.open("Text.txt", ios::app);
	listaImena << ime + " " << (novci-novciPocetak) << + "\n";
	listaImena.close();
	ime = "";
	novci = 0;
	chipovi = 0;
	novciPocetak = 0;
	system("CLS");
	LogIn(ime,chipovi, novci);


}
void RandomVoce(int &novci,int &chipovi) {


	bool play = false;
	int slots = 3;
	int prvi[3] = { 1,2,3 };
	int drugi[3] = { 1,2,3 };
	int treci[3] = { 1,2,3 };
	bool dobitak1red = false;
	bool dobitak2red = false;
	bool dobitak3red = false;
	bool dobitak1diagonala = false;
	bool dobitak2diagonala = false;
	int ulog = 0;

	int start = 0;
	vector<string> voce1;
	voce1.push_back("Visnja  ");
	voce1.push_back("Lubenica");
	voce1.push_back("sedmica ");
	vector<string> voce2;
	voce2.push_back("Visnja  ");
	voce2.push_back("Lubenica");
	voce2.push_back("sedmica ");
	vector<string> voce3;
	voce3.push_back("Visnja  ");
	voce3.push_back("Lubenica");
	voce3.push_back("sedmica ");

	//cin >> start;
	srand(time(NULL));
	cout << "Upisite ulog" << endl;
	cin >> ulog;
	
	

	do {
		cout << "5 da zavrti" << endl;
		cin >> start;
		play = true;
		if (ulog > chipovi) {
			cout << "Nemate dovoljno chipova" << endl;
			system("CLS");
			Menu(chipovi, novci);
		}


		system("CLS");
		
		cout << "            VOCKICE" << endl;
		cout << "********************************" << endl;
		for (int i = 0; i < slots; i++) {
			int n = rand() % 3;

			prvi[i] = n;
            cout << voce1[n] << "  |  ";

		}

		cout << endl;
		for (int i = 0; i < slots; i++) {


			int n = rand() % 3;

			drugi[i] = n;
            cout << voce2[n] << "  |  ";
		}
		cout << endl;
		for (int i = 0; i < slots; i++) {


			int n = rand() % 3;

			treci[i] = n;
          cout << voce3[n] << "  |  ";
		}
		cout << endl;
		cout << "   -------------------------------" << endl;

		Provjera(ulog, chipovi, dobitak1red, dobitak2red, dobitak3red, dobitak1diagonala, dobitak2diagonala, prvi, drugi, treci);

		if ((dobitak1red == false) && (dobitak2red == false) && (dobitak3red == false) && (dobitak1diagonala == false) && (dobitak2diagonala)) {
			cout << "             NISTA" << endl;
		}
		/*if (play == true) {
		poeni -= da;
		}
		*/
		chipovi -= ulog;
		cout << "   -------------------------------" << endl;
		cout << "          imate : " << chipovi << "poena" << endl;
		cout << "   -------------------------------" << endl;
		cout << "Pritisnite 1 za promjenu uloga ili 2 za povratak u Menu" << endl;
		if (start == 1) {
			RandomVoce(novci, chipovi);
		}
		else if (start == 2) {
			system("CLS");
			Menu(chipovi, novci);
		}
	} while (start != 1 || start !=2);
	/*if (start == 1) {
		RandomVoce(novci, chipovi);
	}
	else if (start == 2) {
		Menu(chipovi, novci);
	}*/

}
void Provjera(int ulog ,int &chipovi,bool dobitak1red, bool dobitak2red, bool dobitak3red, bool dobitak1diagonala, bool dobitak2diagonala, int prvi[], int drugi[], int treci[]) {

	if ((prvi[0] == drugi[0]) && (prvi[0] == treci[0])) {
		if (prvi[0] == 0) {
			cout << "      VISNJE !! 2 bodova * " << ulog << endl;
			chipovi += 2 *ulog;
			dobitak1red = true;
		}
		else if (prvi[0] == 1) {
			cout << "      LUBENICE !! 3 bodova * " << ulog << endl;
			chipovi += 3 * ulog;
			dobitak1red = true;
		}
		else if (prvi[0] == 2) {
			cout << "      SEDMICE !! 7 bodova * " << ulog << endl;
			chipovi += 7 * ulog;
			dobitak1red = true;
		}
	}
	else {
		dobitak1red = false;
	}

	if ((prvi[1] == drugi[1]) && (prvi[1] == treci[1])) {
		if (prvi[1] == 0) {
			cout << "      VISNJE !! 2 bodova * " << ulog << endl;
			chipovi += 2 * ulog;
			dobitak2red = true;
		}
		else if (prvi[1] == 1) {
			cout << "      LUBENICE !! 3 bodova * " << ulog << endl;
			chipovi += 3 * ulog;
			dobitak2red = true;
		}
		else if (prvi[1] == 2) {
			cout << "      SEDMICE !! 7 bodova * " << ulog << endl;
			chipovi += 7 * ulog;
			dobitak2red = true;
		}
	}
	else {
		dobitak2red = false;
	}

	if ((prvi[2] == drugi[2]) && (prvi[2] == treci[2])) {
		if (prvi[2] == 0) {
			cout << "      VISNJE !! 2 bodova * " << ulog << endl;
			chipovi += 2 * ulog;
			dobitak3red = true;

		}
		else if (prvi[2] == 1) {
			cout << "      LUBENICE !! 3 bodova * " << ulog << endl;
			chipovi += 3 * ulog;
			dobitak3red = true;
		}
		else if (prvi[2] == 2) {
			cout << "      SEDMICE !! 7 bodova * " << ulog << endl;
			chipovi += 7 * ulog;
			dobitak3red = true;

		}
	}
	else {
		dobitak3red = false;
	}

	if ((prvi[1] == drugi[2]) && (prvi[1] == treci[3])) {
		if (prvi[1] == 0) {
			cout << "      VISNJE !! 2 bodova * " << ulog << endl;
			chipovi += 2 * ulog;
			dobitak1diagonala = true;
		}
		else if (prvi[1] == 1) {
			cout << "      LUBENICE !! 30 bodova * " << ulog << endl;
			chipovi += 3 * ulog;
			dobitak1diagonala = true;
		}
		else if (prvi[1] == 2) {
			cout << "      SEDMICE !! 70 bodova * " << ulog << endl;
			chipovi += 7 * ulog;
			dobitak1diagonala = true;

		}
	}
	else {
		dobitak1diagonala = false;
	}
	if ((prvi[3] == drugi[2]) && (prvi[3] == treci[1])) {
		if (prvi[1] == 0) {
			cout << "      VISNJE !! 2 bodova * " << ulog << endl;
			chipovi += 2 * ulog;
			dobitak2diagonala = true;

		}
		else if (prvi[1] == 1) {
			cout << "      LUBENICE !! 3 bodova * " << ulog << endl;
			chipovi += 3 * ulog;
			dobitak2diagonala = true;


		}
		else if (prvi[1] == 2) {
			cout << "      SEDMICE !! 70 bodova * " << ulog << endl;
			chipovi += 7 * ulog;
			dobitak2diagonala = true;

		}
	}
	else {
		dobitak2diagonala = false;
	}
}
void HighScore(string ime,int novci, int chipovi) {

	
}
