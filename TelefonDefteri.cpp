//============================================================================
// Name        :AddressBook.cpp
// Author      :Nevzat TANVER
// Version     :v1.7
// Copyright   :No rights are reserved.  Suitable for general use. 
// Description :AddressBook which you can store personal information such as Name, Surname, Address, Email , Mobile Number.
//				Search, Edit and Append data, Delete, Backup, List and Print functions are available.

// Warning :	Only one string is allowed for each section(name, surname, address etc...)
//				In database, emails are seperated with "/" and mobile numbers are seperated with "%".
//				All tokenizing processes are related to this rule. Please don't add data to the txt file manually
//				or if you want to add, please add newliner (\n) each eof(end of file) and consider the "tokenizing" rule.
//============================================================================

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
// �o�unlukla metin belgesinden yapt���m�z okumalarda "tokenizing" ve alt stringlerin eldesi gerekti�i i�in
// string gerektiren t�m k�t�phaneler eklendi.
#include <iostream>  
#include <fstream>
#include <string>
#include <cstring>
#include "string.h"
#include <stdlib.h>

using namespace std;

class Link {
private:
public:
	//Verilerimizin i�erdi�i isim soyisim gibi de�i�kenler burada tan�mland�. Link olu�turuldu.
	// Bir ki�inin birden fazla epostas� ve telefon numaras�n�n olabilmesi istendi�inden eposta ve telefon numaralar�
	// Char pointer dizisi olarak tan�mland�. Bu �ekilde tan�mlanmalar�n�n sebebi, txt dosyas�ndan okuma yapma y�ntemimizin
	//"Tokenizing" dedi�imiz string k�t�phanesine ait "strtok" fonksiyonunun de�er d�nd�rme bi�iminden �t�r�d�r.
	// Aksi takdirde txtden okumak i�in ayr�, ba�l� listeye eklemek i�in ayr� fonksiyon tan�mlamam�z gerekirdi.
	string name, surname, adress;
	string email[100], mobileno[100];
	int emaillength, mobilenumberlength;
	Link* pNext;
	Link(string isim, string soyisim, string adres, char* eposta[], int epostauzunluk, char* telno[], int telnouzunluk) {
		name = isim;
		surname = soyisim;
		adress = adres;
		emaillength = epostauzunluk;
		mobilenumberlength = telnouzunluk;
		for (int i = 0; i < epostauzunluk; i++)
			email[i] = eposta[i];
		for (int i = 0; i < telnouzunluk; i++)
			mobileno[i] = telno[i];
		pNext = NULL;
	}
	void displayLinktotxt() {
		//Ba�l� listede ger�ekle�mi� olan de�i�iklikleri(ekleme, silme, bir kayd�n belirli bir verisinin de�i�mesi,bir kayda email veya telefon ekleme)
		//txt dosyas�na yazabilmek i�in gerekli olan fonksiyon.
		//while d�ng�leri i�inde email ve telefon dizisinde eleman g�rmeyene kadar txt ye yaz�yor, yani bir anda 
		//bir ki�iye ka� email veya telefon eklendi�inin bir �nemi olmadan i�ini ger�ekle�tirebiliyor.
		ofstream myfile;
		myfile.open("RehberVeritabani.txt", std::ios_base::app);
		myfile << name << "-" << surname << "-" << adress << "-" << email[0];
		int j = 1;
		while (email[j] != "") {
			if (email[j] == "")
				continue;
			else
				myfile << "/" << email[j];
			j++;
		}

		myfile << "/" << mobileno[0];
		j = 1;
		while (mobileno[j] != "") {
			if (mobileno[j] == "")
				continue;
			else
				myfile << "%" << mobileno[j];
			j++;
		}
		myfile << endl;

		myfile.close();
	}

	void displayLinktotxt2() {
		//Ba�l� listede ger�ekle�mi� olan de�i�iklikleri(ekleme, silme, bir kayd�n belirli bir verisinin de�i�mesi,bir kayda email veya telefon ekleme)
		//txt dosyas�na yazabilmek i�in gerekli olan fonksiyon.
		//while d�ng�leri i�inde email ve telefon dizisinde eleman g�rmeyene kadar txt ye yaz�yor, yani bir anda 
		//bir ki�iye ka� email veya telefon eklendi�inin bir �nemi olmadan i�ini ger�ekle�tirebiliyor.
		//�stteki fonksiyonun ayn�s�, ama birisi tek bir kay�t de�i�tirildi�inde �a��r�l�yor, di�eri ise ba�l� listenin tamam�n� txt dosyas�na yaz�yor.
		//�rne�in silme i�lemi yap�ld�ktan sonra bu fonksiyon �a��r�l�yor ki ba�l� liste txt dosyas�na bas�labilsin.
		ofstream myfile;
		myfile.open("RehberVeritabani.txt", ::std::ios::app);
		myfile << name << "-" << surname << "-" << adress << "-" << email[0];
		int j = 1;
		while (email[j] != "") {
			if (email[j] == "")
				continue;
			else
				myfile << "/" << email[j];
			j++;
		}

		myfile << "/" << mobileno[0];
		j = 1;
		while (mobileno[j] != "") {
			if (mobileno[j] == "")
				continue;
			else
				myfile << "%" << mobileno[j];
			j++;
		}
		myfile << endl;

		myfile.close();
	}

	void displayLinkPerson() {
		//Ba�l� listede ger�ekle�mi� olan de�i�iklikleri(ekleme, silme, bir kayd�n belirli bir verisinin de�i�mesi,bir kayda email veya telefon ekleme)
		//ekrana yazabilmek i�in gerekli olan fonksiyon.
		//while d�ng�leri i�inde email ve telefon dizisinde eleman g�rmeyene kadar txt ye yaz�yor, yani bir anda 
		//bir ki�iye ayn� anda ka� email veya telefon eklendi�inin bir �nemi olmadan i�ini ger�ekle�tirebiliyor.
		cout << "isim : " << name << " soyisim : " << surname << " adres : " << adress << " eposta : " << email[0] << " ";
		int j = 1;
		int f = 1;
		while (email[f] != "")
		{
			if (email[f] == "")
				break;
			else
				cout << f + 1 << ".eposta : " << email[f] << " ";
			f++;
		}

		cout << " telefon numarasi : " << mobileno[0] << " ";
		while (mobileno[j] != "")
		{

			if (mobileno[j] == "")
				break;
			else
				cout << j + 1 << ".telefon numarasi : " << mobileno[j] << " ";

			j++;
		}
		cout << endl;
	}

};
class LinkList {
private:
	Link* pFirst;
public:
	LinkList()
	{
		pFirst = NULL;

	}

	bool isEmpty()
	{
		//Ba�l� listenin bo� olup olmad���n�n kontrol�.
		return pFirst == NULL;
	}

	void insertFirst(string isim, string soyisim, string adres, char* eposta[], int epostauzunluk, char* telno[], int telnouzunluk) {
		//Ba�l� listenin ba��na ekleme yap�yoruz.
		Link* pNewLink = new Link(isim, soyisim, adres, eposta, epostauzunluk, telno, telnouzunluk);
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	void removeFirst() {
		//Ba�l� listenin ba��ndan silme yap�yoruz.
		Link* pTemp = pFirst;
		pFirst = pFirst->pNext;
		delete pTemp;
		cout << endl;
	}

	void displayPerson(Link* pPerson) {
		//Tek bir ki�iyi ekrana bast�rmak istedi�imiz durumlarda �al��an fonksiyon.
		//D��ar�dan Link* tipinde pointer al�yor.
		Link* pCurrent = pPerson;
		pCurrent->displayLinkPerson();
		cout << endl;
	}
	void printtotxt(Link* pFind) {
		//Tek bir ki�iyi txt ye bast�rmak istedi�imiz durumlarda �al��an fonksiyon.
		//D��ar�dan Link* tipinde pointer al�yor.
		Link* pCurrent = pFind;
		pCurrent->displayLinktotxt();
		cout << endl;
	}
	void Listprinttotxt() {
		//T�m ba�l� listeyi txt ye bast�rmak istedi�imiz durumlarda �al��an fonksiyon(bu y�zden i�eride while d�ng�s� mevcut).
		//D��ar�dan de�i�ken alm�yor, pFirst yani ilk de�i�keni g�steren yerden ba�lay�p pNext kullana kullana sonraki elemana ge�erek
		//T�m listeyi taram�� oluyor, txt ye bas�yor tarad�k�a.
		Link* pCurrent = pFirst;

		while (pCurrent != NULL) {
			pCurrent->displayLinktotxt2();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}

	void displayFullList() {
		//T�m ba�l� listeyi ekrana bast�rmak istedi�imiz durumlarda �al��an fonksiyon.
		//D��ar�dan de�i�ken alm�yor, pFirst yani ilk de�i�keni g�steren yerden ba�lay�p pNext kullana kullana sonraki elemana ge�erek
		//T�m listeyi taram�� oluyor, ekrana bas�yor tarad�k�a.
		Link* pCurrent = pFirst;

		while (pCurrent != NULL) {
			pCurrent->displayLinkPerson();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}
	Link* findName(string key) {
		//�sim ile arama fonksiyonu. Burada �zetle yapt���m�z �ey �u:
		//Kullan�c�dan hangi boyutta string gelirse gelsin, linklerin g�sterdi�i isimlerde o boyutta arama yap�yor.
		//Yani "nevzat" kelimesini "nev"-"ne-"nevz" gibi her kombinasyonda tespit edebilme �zelli�ine sahip arama fonksiyonum.
		Link* pCurrent = pFirst;
		while ((pCurrent->name).substr(0, key.length()) != key) {

			if (pCurrent->pNext == NULL)
				return NULL;
			else
				pCurrent = pCurrent->pNext;
		}
		return pCurrent;
	}
	Link* findMobileNumer(string key) {
		//Burada en zor soru bir ki�inin bir telefonu, bir di�erinin iki telefonu oldu�unda nas�l arama yap�labilece�i idi.
		//Bu sorunu a�a��daki algoritma ile ��zd�m.
		//im de�i�keni, bir ki�ideki mevcut telefon numaras� say�s�n� temsil ediyo, e�er ki�i birden fazla telefon numaras�na sahipse
		//�stteki if yap�s� ile kontrol sa�lanarak ayn� ki�ide iken "pCurrent = pCurrent->pNext;" yapmadan hemen ayn� ki�inin ikinci
		//telefonunu da tar�yoruz bizim arad���m�z telefon ile ayn� m� diye.
		//zaten ki�inin tek bir telefonu varsa �stteki if 0<0 olup �al��m�yor, hemen di�er ki�iye atlan�yor.
		Link* pCurrent = pFirst;
		int im = 0;
		while (pCurrent->mobileno[im] != key) {

			if (im < pCurrent->mobilenumberlength) {
				im++;
				continue;
			}

			if (pCurrent->pNext == NULL) {
				return NULL;
			}

			else {
				pCurrent = pCurrent->pNext;
				im = 0;
			}

		}


		return pCurrent;
	}

	bool remove(string key) {
		//rehberden(ba�l� listeden) kay�t silme fonksiyonu.
		Link* pCurrent = pFirst;
		Link* pPrevious = pFirst;

		while (pCurrent->name != key)
		{
			if (pCurrent->pNext == NULL)
				return false;
			else {
				pPrevious = pCurrent;
				pCurrent = pCurrent->pNext;
			}
		}
		if (pCurrent == pFirst)
			pFirst = pFirst->pNext;
		else
			pPrevious->pNext = pCurrent->pNext;
		delete pCurrent;
		return true;
	}

	void editName(Link* pFind, string isim) {// kay�t bilgilerini g�ncelleyen fonksiyonlar.
		pFind->name = isim;
	}
	void editSurname(Link* pFind, string soyisim) {
		pFind->surname = soyisim;
	}
	void editAdress(Link* pFind, string adres) {
		pFind->adress = adres;
	}
	void editEmail(Link* pFind, string eposta, int istenen) {
		pFind->email[istenen] = eposta;
	}
	void editMobileNumber(Link* pFind, string telno, int istenen) {
		pFind->mobileno[istenen] = telno;
	}
	void eMailAppend(Link* pFind, string eposta) {//mevcut kayda email ve telefon ekleyen fonksiyonlar.
		pFind->email[pFind->emaillength] = eposta;
		pFind->emaillength++;
	}
	void MobileNoAppend(Link* pFind, string telno) {
		pFind->mobileno[pFind->mobilenumberlength] = telno;
		pFind->mobilenumberlength++;
	}
	int insertdataBase() {
		//Veritaban�m�z� ba�l� listemize(rehbere) aktaran fonksiyon. Basit�e i� i�e 3 while i�eriyor.
		//"strtok" fonksiyonu yard�m� ile txt dosyas�n� belirli kurallara g�re kelimelere ay�r�yor.
		//isim-soyisim-adres-email/email2/telefon%telefon2 ( isim soyisim adres "-" ile ayr�l�yor, emailler "/" ile ayr�l�yor
		//Telefon numaralar� ise "%" ile ayr�l�yor. Burada en �nemli husus "token" anahtar kelimeleri. tokenleri kullan�rken ilgili token
		//"NULL" olmadan hemen �nce de�erini sakl�yoruz ki tokenimizi "-" den "/" ye veya "/" den "%" a de�i�tirebilelim.

		ifstream dataBase("RehberVeritabani.txt");
		string satir = "-";
		char* emailler[100], * telefonlar[100], * dBase[3];
		int t = 0, l = 0;

		if (dataBase.is_open()) {
			while (getline(dataBase, satir)) {
				char str[200];
				strcpy(str, satir.c_str());
				char* token = strtok(str, "-");
				int i = 0;
				while (token != NULL)
				{
					dBase[i] = token;

					i++;
					token = strtok(NULL, "-");
					if (i == 3) {
						char* token4 = NULL;;
						char* token2 = strtok(token, "/");
						l = 0;
						while (token2 != NULL) {
							emailler[l] = token2;
							token4 = token2;
							token2 = strtok(NULL, "/");
							l++;
						}
						char* token3 = strtok(token4, "%");
						t = 0;
						while (token3 != NULL) {
							telefonlar[t] = token3;

							token3 = strtok(NULL, "%");
							t++;
						}

						break;
					}
				}
				insertFirst(dBase[0], dBase[1], dBase[2], emailler, l - 1, telefonlar, t);
			}
			dataBase.close();
			return 1;
		}
		else
			return -1;
	}
	void insertNewDataBase() {
		//Veritaban�m�z� ba�l� listemize(rehbere) aktaran fonksiyon. Basit�e i� i�e 3 while i�eriyor.
		//"strtok" fonksiyonu yard�m� ile txt dosyas�n� belirli kurallara g�re kelimelere ay�r�yor.
		//isim-soyisim-adres-email/email2/telefon%telefon2 ( isim soyisim adres "-" ile ayr�l�yor, emailler "/" ile ayr�l�yor
		//Telefon numaralar� ise "%" ile ayr�l�yor. Burada en �nemli husus "token" anahtar kelimeleri. tokenleri kullan�rken ilgili token
		//"NULL" olmadan hemen �nce de�erini sakl�yoruz ki tokenimizi "-" den "/" ye veya "/" den "%" a de�i�tirebilelim.
		//�stteki fonksiyon ile ayn�, yaln�zca farkl� bir txt dosyas�n� insert ediyor.
		ifstream dataBase("EskiVeritabani.txt");
		string satir = "-";
		char* emailler[100], * telefonlar[100], * dBase[4];
		int t = 0, l = 0;

		if (dataBase.is_open()) {
			while (getline(dataBase, satir)) {
				char str[200];
				strcpy(str, satir.c_str());
				char* token = strtok(str, "-");
				int i = 0;
				while (token != NULL)
				{
					dBase[i] = token;

					i++;
					token = strtok(NULL, "-");
					if (i == 3) {
						char* token4 = NULL;
						char* token2 = strtok(token, "/");
						l = 0;
						while (token2 != NULL) {
							emailler[l] = token2;
							token4 = token2;
							token2 = strtok(NULL, "/");
							l++;
						}
						char* token3 = strtok(token4, "%");
						t = 0;
						while (token3 != NULL) {
							telefonlar[t] = token3;
							token3 = strtok(NULL, "%");
							t++;
						}
						break;
					}
				}
				insertFirst(dBase[0], dBase[1], dBase[2], emailler, l - 1, telefonlar, t);

				Link* bastir = findName(dBase[0]);
				printtotxt(bastir);
			}
			dataBase.close();
		}
	}
};

int main()
{	//Ana fonksiyon �o�unlukla switch-case lerden olu�uyor. A�a��da tan�mlanan de�i�kenlerin �o�u kullan�c�dan al�nacak stringlerin
	//atanabilmesi i�in tan�mland�, kritik bir �neme sahip de�iller.
	//Program ba�lang�c�nda txt dosyas� direk olarak okunup ba�l� listeye aktar�l�yor.
	//Komut istemcisi �zerinde yazan t�m i�lemler e�zamanl� olarak hem rehber(ba�l� liste) hem veritaban�(txt dosyas�) �zerinde ger�ekle�tiriliyor.

	//Program�n ilerleyen k�s�mlar�nda ise e�er ba�l� listede k�kl� bir de�i�iklik olmu�sa izlenen ad�m �u �ekilde.
	//1. Ba�l� listeyi g�ncelle
	//2. Veritaban� ile ayn� isme sahip bo� bir txt dosyas� a�
	//3. Ba�l� listeyi txt dosyas�na yazd�r.
	//E�er yeni bir sat�r eklenecekse yaln�zca sonuna ekleme yap�lmaktad�r.
	LinkList AddressBook;
	Link* pFind = NULL;
	int secim, email_sayisi, telefon_sayisi, case5secim;
	int emailveyatelefonekleme;
	int telefonsayisi, emailsayisi;
	string silinecekkayit, verieklenecekkayit, yenieklenecektelefon, yenieklenecekemail;
	string namekey, mobilenumberkey, konulanisim, konulansoyisim, konulanadres, konulanemail, konulantelefon, email_temp, telefon_temp;
	string yeni_isim, yeni_soyisim, yeni_adres;
	char* yeni_telefon[100], * yeni_email[100];
	ofstream myfile;

	if (AddressBook.insertdataBase() == 1) {
		cout << "Rehber basari ile aktarildi." << endl;
	}
	else
		cout << "Rehber aktarilamadi, rehberin ismini yanlis girdiniz herhalde." << endl;

	while (1)
	{
		cout << "Adres Defterine Hos Geldiniz." << endl;
		cout << "Lutfen yapmak istediginiz islemi giriniz." << endl
			<< endl
			<< "Rehbere yeni kisi eklemek icin  2 ye" << endl
			<< "Isim ile rehberde kisi aramak icin 3 e" << endl
			<< "Numara ile rehberde kisi aramak icin 4 e " << endl
			<< "Mevcut bir kaydi duzenlemek icin 5 e" << endl
			<< "Mevcut bir kaydi silmek icin 6 ya" << endl
			<< "Rehberi goruntulemek icin 7 ye" << endl
			<< "Mevcut kayda e mail veya telefon eklemek icin 11 e" << endl
			<< "Programi kapatmak icin 9 a basiniz..." << endl
			<< "						" << endl
			<< "						" << endl
			<< "EK OZELLIKLER (Olasi bir veri kaybini engellemek icin...)			" << endl
			<< "Eski veritabaninizi mevcut rehbere eklemek icin 1 e --> (EskiVeritabani.txt) yi (RehberVeritabani.txt) ye ekler." << endl
			<< "Rehberi sifirlamak icin 8 e --> Bagli Listenin Icini Sifirlar !!! " << endl
			<< "Veritabanini rehbere aktarmak icin 10 a --> Sifirlanmis olan bagli listeyi mevcut veritabani (RehberVeritabani.txt) ile doldurur." << endl
			<< endl
			<< "Seciminiz : ";

		cin >> secim;
		system("cls");

		if (secim == 9) {
			break;
		}
		switch (secim) {
		case 1:
			AddressBook.insertNewDataBase();
			break;
		case 2:
			cout << "Isim : ";
			cin >> yeni_isim;
			cout << endl;
			cout << "Soyisim : ";
			cin >> yeni_soyisim;
			cout << endl;
			cout << "Adres : ";
			cin >> yeni_adres;
			cout << endl;
			cout << "Kac email kaydedeceksiniz : ";
			cin >> email_sayisi;
			cout << endl;
			cout << "Kac telefon kaydedeceksiniz : ";
			cin >> telefon_sayisi;
			cout << endl;

			//Bu k�s�mlar�n bu �ekilde olmas�n�n sebebi, txt dosyas�n� okuyan fonksiyon ile kullan�c�dan
			//ald���m verileri tek bir fonksiyon kullanarak ba�l� listeye aktarabilmek,"tokenizing" in �al��ma mant���ndan �t�r�
			//char dizisine d�n��t�rmek durumunday�z.
			for (int u = 0; u < email_sayisi; u++) {
				cout << u + 1 << ".Emaili giriniz : ";
				cin >> email_temp;
				cout << endl;
				char cstr[200];
				strcpy(cstr, email_temp.c_str());
				yeni_email[u] = cstr;
			}

			for (int x = 0; x < telefon_sayisi; x++) {
				cout << x + 1 << ".Telefonu giriniz : ";
				cin >> telefon_temp;
				char cstr[200];
				strcpy(cstr, telefon_temp.c_str());
				yeni_telefon[x] = cstr;
			}
			AddressBook.insertFirst(yeni_isim, yeni_soyisim, yeni_adres, yeni_email, email_sayisi, yeni_telefon, telefon_sayisi);
			pFind = AddressBook.findName(yeni_isim);
			AddressBook.printtotxt(pFind);
			system("cls");
			cout << "Kayit basari ile kaydedildi." << endl;
			break;
		case 3:
			cout << "Lutfen aramak istediginiz ismi yaziniz : ";
			cin >> namekey;
			pFind = AddressBook.findName(namekey);
			if (pFind != NULL) {
				cout << "Isim basari ile bulundu, rehberde mevcut, kisiye ait bilgiler asagidaki gibidir." << endl;
				AddressBook.displayPerson(pFind);
			}
			else
				cout << "Isim bulunamadi, rehberde mevcut degil." << endl;
			break;

		case 4:
			cout << "Lutfen aramak istediginiz numarayi yaziniz : ";
			cin >> mobilenumberkey;
			pFind = AddressBook.findMobileNumer(mobilenumberkey);
			if (pFind != NULL) {
				cout << "Numara basari ile bulundu, rehberde mevcut, kisiye ait bilgiler asagidaki gibidir." << endl;
				AddressBook.displayPerson(pFind);
			}
			else
				cout << "Numara bulunamadi, rehberde mevcut degil." << endl;
			break;

		case 5:
			cout << "Lutfen duzenlemek istediginiz ismi yaziniz : ";
			cin >> namekey;
			pFind = AddressBook.findName(namekey);
			if (pFind != NULL) {
				cout << "Isim basari ile bulundu, rehberde mevcut, kisiye ait bilgiler asagidaki gibidir." << endl;
				AddressBook.displayPerson(pFind);
			}
			else {
				cout << "Isim bulunamadi, rehberde mevcut degil." << endl;
				break;
			}
			cout << "Lutfen yapmak istediginiz islemi seciniz." << endl
				<< "Ismini duzenlemek icin 1 e" << endl
				<< "Soyismini duzenlemek icin  2 ye" << endl
				<< "Adresini duzenlemek icin 3 e" << endl
				<< "Email adresini duzenlemek icin 4 e basiniz." << endl
				<< "Telefon numarasini duzeltmek icin 5 e " << endl
				<< "Cikmak icin 9 a basiniz... " << endl;
			cout << "Seciminiz : ";
			cin >> case5secim;
			switch (case5secim) {
			case 1:
				cout << "Yeni isim ? : ";
				cin >> konulanisim;
				AddressBook.editName(pFind, konulanisim);
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Isim basari ile degistirildi." << endl;
				break;
			case 2:
				cout << "Yeni Soyisim ? : ";
				cin >> konulansoyisim;
				AddressBook.editSurname(pFind, konulansoyisim);
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Soyisim basari ile degistirildi." << endl;
				break;
			case 3:
				cout << "Yeni adres ? : ";
				cin >> konulanadres;
				AddressBook.editAdress(pFind, konulanadres);
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Adres basari ile degistirildi." << endl;
				break;
			case 4:
				cout << "Hangi emaili degistirmek istersiniz ? : ";
				for (int k = 0; k < pFind->emaillength; k++)
					cout << k + 1 << ".email :" << pFind->email[k] << " ";
				cout << endl;
				cout << "Seciminiz : ";
				cin >> emailsayisi;
				cout << endl;
				cout << "Yeni eposta ? : ";
				cin >> konulanemail;
				AddressBook.editEmail(pFind, konulanemail, emailsayisi);
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Email basari ile degistirildi." << endl;
				break;
			case 5:
				cout << "Hangi telefon numarasini degistirmek istersiniz ? : " << "	";
				for (int k = 0; k < pFind->mobilenumberlength; k++)
					cout << k + 1 << ".numara " << "	" << pFind->mobileno[k] << " ";
				cout << endl;
				cout << "Seciminiz : ";
				cin >> telefonsayisi;
				cout << endl;
				cout << "Yeni telefon numarasi ? : ";
				cin >> konulantelefon;
				AddressBook.editMobileNumber(pFind, konulantelefon, telefonsayisi);
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Telefon numarasi basari ile degistirildi." << endl;
				break;
			case 9:
				system("cls");
				break;
			default:
				cout << "Yanlis giris, program yeniden baslatiliyor." << endl;
			}
			break;
		case 6:
			cout << "Lutfen silmek istediginiz kaydin ismini giriniz : ";
			cin >> silinecekkayit;
			if (AddressBook.remove(silinecekkayit) == 1) {
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Kayit basarili bir sekilde silindi." << endl;
			}
			else
				cout << "Aradiginiz kayit bulunamadi, program yeniden baslatiliyor..." << endl;
			break;
		case 7:
			cout << "Telefon Rehberi" << endl;
			if (AddressBook.isEmpty() == 1) {
				cout << "Telefon Rehberi Bos...." << endl;
				cout << endl;
				break;
			}
			cout << endl;
			AddressBook.displayFullList();
			break;
		case 8:
			while (AddressBook.isEmpty() != 1)
				AddressBook.removeFirst();
			break;
		case 10:
			if (AddressBook.insertdataBase() == 1) {
				cout << "Rehber basari ile aktarildi." << endl;
			}
			else
				cout << "Rehber aktarilamadi, rehberin ismini yanlis girdiniz herhalde." << endl;
			break;
		case 11:
			cout << "Lutfen e mail veya telefon eklemek istediginiz kaydin ismini giriniz : ";
			cin >> verieklenecekkayit;
			pFind = AddressBook.findName(verieklenecekkayit);
			if (pFind != NULL) {
				cout << "Isim basari ile bulundu, rehberde mevcut, kisiye ait bilgiler asagidaki gibidir." << endl;
				AddressBook.displayPerson(pFind);
			}
			else {
				cout << "Isim bulunamadi, rehberde mevcut degil." << endl;
				break;
			}
			cout << "Lutfen yapmak istediginiz islemi seciniz - 1) email ekleme  2)telefon ekleme  9)Cikis" << endl;
			cout << "Seciminiz : ";
			cin >> emailveyatelefonekleme;
			switch (emailveyatelefonekleme) {
			case 1:
				cout << "Yeni eklenecek email ? : ";
				cin >> yenieklenecekemail;
				AddressBook.eMailAppend(pFind, yenieklenecekemail);
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Email basarili bir sekilde eklendi." << endl;
				break;
			case 2:
				cout << "Yeni eklenecek telefon ? : ";
				cin >> yenieklenecektelefon;
				AddressBook.MobileNoAppend(pFind, yenieklenecektelefon);
				myfile.open("RehberVeritabani.txt");
				AddressBook.Listprinttotxt();
				myfile.close();
				system("cls");
				cout << "Telefon basarili bir sekilde eklendi." << endl;
				break;
			case 9:
				system("cls");
				break;
			default:
				cout << "Yanlis girdi. Program bastan baslatiliyor..." << endl;
			}
			break;
		default:
			cout << "Yanlis secim yaptiniz, lutfen tekrar giris yapiniz. Program yeniden baslatiliyor." << endl;
		}
	}
}

