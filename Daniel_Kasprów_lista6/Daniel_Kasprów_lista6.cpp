#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

static int prevv[101], nextt[101],head;
 string key[101];

void dodawanie(string x)
{
	string text="";
	int i = 1,headx,g=0;
	while (!(key[i].empty()))
	{
		i++;
	}
	key[i] = x;

	if (i != 1)
	{
		headx = head;//najwiekszy element
		while (x < key[headx])
		{
			g = headx;//wiekszy
			headx = prevv[headx];//mniejszy
		}
		if (x > key[head])
			head = i;//jest nowy element jest najwiekszy

			//new
			prevv[i] = headx;//mniejszy
			nextt[i] = g;//wiekszy

			//change
			if (g != 0)
			{
				prevv[g] = i;
			}
//			if (g == 0)
//			{
//				prevv[g] = 0;
//			}
			if (headx != 0)
			{
				nextt[headx] = i;
			}
	}	
	else
	{
		prevv[i] = 0;
		nextt[i] = 0;
		head = 1;
	}
}

void wyswietlanieaz()
{
	int i = 1;
	while (prevv[i] != NULL && i!=0)
	{
		i = prevv[i];
	}
	while (i != NULL && i != 0)
	{
		cout << key[i]<<endl;
		i = nextt[i];
	}
}

void wyswietlanieza()
{
	int i = head;
		while (i != NULL && i != 0)
	{
		cout << key[i] << endl;
		i = prevv[i];
	}
}

void wyswietlanielitera()
{
	int nazwisko,i=1;
	char letter,litera;
	string word;
	cout << "Podaj na jaka litere maja sie zaczynac nazwiska: ";
	cin >> litera;
	while (prevv[i] != NULL && i != 0)
	{
		i = prevv[i];
	}
	while (i != NULL && i != 0)
	{
		word = key[i];
		letter = word[0];
		if (letter == litera)
		{
			cout << key[i] << endl;
		}
		i = nextt[i];
	}
}

int main()
{
	prevv[0] = 0;
	nextt[0] = 0;
	key[0] = "";
	int choice=1,i=0;
	string nazwisko = "";
	char yes;
	cout << "1: Dodaj Nazwisko\n2: Drukowanie Nazwisko alfabetycznie A-Z\n";
	cout << "3: Drukowanie Nazwisk alfabetycznie Z-A\n";
	cout << "4: Drukowanie Nazwisk poczawszy od nazwiska rozpoczynajacego sie podana litera\n";
	cout << "0: Zakonczenie programu\n";
	while (choice != 0)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Podaj Nazwisko: ";
			cin >> nazwisko;
			dodawanie(nazwisko);
		}
			break;
		case 2:
			wyswietlanieaz();
			break;
		case 3:
			wyswietlanieza();
			break;
		case 4:
		{
			wyswietlanielitera();
		}
			break;

		case 0:
			break;
		default:
			cout << "Bledna opcja " << endl;
			break;
		}
	}
}
