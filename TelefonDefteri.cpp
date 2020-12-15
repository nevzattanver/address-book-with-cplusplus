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
// Çoðunlukla metin belgesinden yaptýðýmýz okumalarda "tokenizing" ve alt stringlerin eldesi gerektiði için
// string gerektiren tüm kütüphaneler eklendi.
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
	//Verilerimizin içerdiði isim soyisim gibi deðiþkenler burada tanýmlandý. Link oluþturuldu.
	// Bir kiþinin birden fazla epostasý ve telefon numarasýnýn olabilmesi istendiðinden eposta ve telefon numaralarý
	// Char pointer dizisi olarak tanýmlandý. Bu þekilde tanýmlanmalarýnýn sebebi, txt dosyasýndan okuma yapma yöntemimizin
	//"Tokenizing" dediðimiz string kütüphanesine ait "strtok" fonksiyonunun deðer döndürme biçiminden ötürüdür.
	// Aksi takdirde txtden okumak için ayrý, baðlý listeye eklemek için ayrý fonksiyon tanýmlamamýz gerekirdi.
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
		//Baðlý listede gerçekleþmiþ olan deðiþiklikleri(ekleme, silme, bir kaydýn belirli bir verisinin deðiþmesi,bir kayda email veya telefon ekleme)
		//txt dosyasýna yazabilmek için gerekli olan fonksiyon.
		//while döngüleri içinde email ve telefon dizisinde eleman görmeyene kadar txt ye yazýyor, yani bir anda 
		//bir kiþiye kaç email veya telefon eklendiðinin bir önemi olmadan iþini gerçekleþtirebiliyor.
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
		//Baðlý listede gerçekleþmiþ olan deðiþiklikleri(ekleme, silme, bir kaydýn belirli bir verisinin deðiþmesi,bir kayda email veya telefon ekleme)
		//txt dosyasýna yazabilmek için gerekli olan fonksiyon.
		//while döngüleri içinde email ve telefon dizisinde eleman görmeyene kadar txt ye yazýyor, yani bir anda 
		//bir kiþiye kaç email veya telefon eklendiðinin bir önemi olmadan iþini gerçekleþtirebiliyor.
		//üstteki fonksiyonun aynýsý, ama birisi tek bir kayýt deðiþtirildiðinde çaðýrýlýyor, diðeri ise baðlý listenin tamamýný txt dosyasýna yazýyor.
		//örneðin silme iþlemi yapýldýktan sonra bu fonksiyon çaðýrýlýyor ki baðlý liste txt dosyasýna basýlabilsin.
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
		//Baðlý listede gerçekleþmiþ olan deðiþiklikleri(ekleme, silme, bir kaydýn belirli bir verisinin deðiþmesi,bir kayda email veya telefon ekleme)
		//ekrana yazabilmek için gerekli olan fonksiyon.
		//while döngüleri içinde email ve telefon dizisinde eleman görmeyene kadar txt ye yazýyor, yani bir anda 
		//bir kiþiye ayný anda kaç email veya telefon eklendiðinin bir önemi olmadan iþini gerçekleþtirebiliyor.
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
		//Baðlý listenin boþ olup olmadýðýnýn kontrolü.
		return pFirst == NULL;
	}

	void insertFirst(string isim, string soyisim, string adres, char* eposta[], int epostauzunluk, char* telno[], int telnouzunluk) {
		//Baðlý listenin baþýna ekleme yapýyoruz.
		Link* pNewLink = new Link(isim, soyisim, adres, eposta, epostauzunluk, telno, telnouzunluk);
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	void removeFirst() {
		//Baðlý listenin baþýndan silme yapýyoruz.
		Link* pTemp = pFirst;
		pFirst = pFirst->pNext;
		delete pTemp;
		cout << endl;
	}

	void displayPerson(Link* pPerson) {
		//Tek bir kiþiyi ekrana bastýrmak istediðimiz durumlarda çalýþan fonksiyon.
		//Dýþarýdan Link* tipinde pointer alýyor.
		Link* pCurrent = pPerson;
		pCurrent->displayLinkPerson();
		cout << endl;
	}
	void printtotxt(Link* pFind) {
		//Tek bir kiþiyi txt ye bastýrmak istediðimiz durumlarda çalýþan fonksiyon.
		//Dýþarýdan Link* tipinde pointer alýyor.
		Link* pCurrent = pFind;
		pCurrent->displayLinktotxt();
		cout << endl;
	}
	void Listprinttotxt() {
		//Tüm baðlý listeyi txt ye bastýrmak istediðimiz durumlarda çalýþan fonksiyon(bu yüzden içeride while döngüsü mevcut).
		//Dýþarýdan deðiþken almýyor, pFirst yani ilk deðiþkeni gösteren yerden baþlayýp pNext kullana kullana sonraki elemana geçerek
		//Tüm listeyi taramýþ oluyor, txt ye basýyor taradýkça.
		Link* pCurrent = pFirst;

		while (pCurrent != NULL) {
			pCurrent->displayLinktotxt2();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}

	void displayFullList() {
		//Tüm baðlý listeyi ekrana bastýrmak istediðimiz durumlarda çalýþan fonksiyon.
		//Dýþarýdan deðiþken almýyor, pFirst yani ilk deðiþkeni gösteren yerden baþlayýp pNext kullana kullana sonraki elemana geçerek
		//Tüm listeyi taramýþ oluyor, ekrana basýyor taradýkça.
		Link* pCurrent = pFirst;

		while (pCurrent != NULL) {
			pCurrent->displayLinkPerson();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}
	Link* findName(string key) {
		//Ýsim ile arama fonksiyonu. Burada özetle yaptýðýmýz þey þu:
		//Kullanýcýdan hangi boyutta string gelirse gelsin, linklerin gösterdiði isimlerde o boyutta arama yapýyor.
		//Yani "nevzat" kelimesini "nev"-"ne-"nevz" gibi her kombinasyonda tespit edebilme özelliðine sahip arama fonksiyonum.
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
		//Burada en zor soru bir kiþinin bir telefonu, bir diðerinin iki telefonu olduðunda nasýl arama yapýlabileceði idi.
		//Bu sorunu aþaðýdaki algoritma ile çözdüm.
		//im deðiþkeni, bir kiþideki mevcut telefon numarasý sayýsýný temsil ediyo, eðer kiþi birden fazla telefon numarasýna sahipse
		//üstteki if yapýsý ile kontrol saðlanarak ayný kiþide iken "pCurrent = pCurrent->pNext;" yapmadan hemen ayný kiþinin ikinci
		//telefonunu da tarýyoruz bizim aradýðýmýz telefon ile ayný mý diye.
		//zaten kiþinin tek bir telefonu varsa üstteki if 0<0 olup çalýþmýyor, hemen diðer kiþiye atlanýyor.
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
		//rehberden(baðlý listeden) kayýt silme fonksiyonu.
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

	void editName(Link* pFind, string isim) {// kayýt bilgilerini güncelleyen fonksiyonlar.
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
		//Veritabanýmýzý baðlý listemize(rehbere) aktaran fonksiyon. Basitçe iç içe 3 while içeriyor.
		//"strtok" fonksiyonu yardýmý ile txt dosyasýný belirli kurallara göre kelimelere ayýrýyor.
		//isim-soyisim-adres-email/email2/telefon%telefon2 ( isim soyisim adres "-" ile ayrýlýyor, emailler "/" ile ayrýlýyor
		//Telefon numaralarý ise "%" ile ayrýlýyor. Burada en önemli husus "token" anahtar kelimeleri. tokenleri kullanýrken ilgili token
		//"NULL" olmadan hemen önce deðerini saklýyoruz ki tokenimizi "-" den "/" ye veya "/" den "%" a deðiþtirebilelim.

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
		//Veritabanýmýzý baðlý listemize(rehbere) aktaran fonksiyon. Basitçe iç içe 3 while içeriyor.
		//"strtok" fonksiyonu yardýmý ile txt dosyasýný belirli kurallara göre kelimelere ayýrýyor.
		//isim-soyisim-adres-email/email2/telefon%telefon2 ( isim soyisim adres "-" ile ayrýlýyor, emailler "/" ile ayrýlýyor
		//Telefon numaralarý ise "%" ile ayrýlýyor. Burada en önemli husus "token" anahtar kelimeleri. tokenleri kullanýrken ilgili token
		//"NULL" olmadan hemen önce deðerini saklýyoruz ki tokenimizi "-" den "/" ye veya "/" den "%" a deðiþtirebilelim.
		//üstteki fonksiyon ile ayný, yalnýzca farklý bir txt dosyasýný insert ediyor.
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
{	//Ana fonksiyon çoðunlukla switch-case lerden oluþuyor. Aþaðýda tanýmlanan deðiþkenlerin çoðu kullanýcýdan alýnacak stringlerin
	//atanabilmesi için tanýmlandý, kritik bir öneme sahip deðiller.
	//Program baþlangýcýnda txt dosyasý direk olarak okunup baðlý listeye aktarýlýyor.
	//Komut istemcisi üzerinde yazan tüm iþlemler eþzamanlý olarak hem rehber(baðlý liste) hem veritabaný(txt dosyasý) üzerinde gerçekleþtiriliyor.

	//Programýn ilerleyen kýsýmlarýnda ise eðer baðlý listede köklü bir deðiþiklik olmuþsa izlenen adým þu þekilde.
	//1. Baðlý listeyi güncelle
	//2. Veritabaný ile ayný isme sahip boþ bir txt dosyasý aç
	//3. Baðlý listeyi txt dosyasýna yazdýr.
	//Eðer yeni bir satýr eklenecekse yalnýzca sonuna ekleme yapýlmaktadýr.
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

			//Bu kýsýmlarýn bu þekilde olmasýnýn sebebi, txt dosyasýný okuyan fonksiyon ile kullanýcýdan
			//aldýðým verileri tek bir fonksiyon kullanarak baðlý listeye aktarabilmek,"tokenizing" in çalýþma mantýðýndan ötürü
			//char dizisine dönüþtürmek durumundayýz.
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

