#include <iostream>
//#include <filesystem>
#include <fstream>

using namespace std;

void addBerkas(string berkas);
void writeText(string berkas);
void readBerkas(string berkas);
void editBerkas(string berkas);
void deleteBerkas(string berkas);

int main()
{
	char lanjut = 'y';
	int pilihan;
	string berkas;
	system("title Mini File Manager");
	
	while(lanjut == 'y' || lanjut == 'Y')
	{
		system("cls");
		cout << "=====[ Pilihan Menu ]=====\n";
		cout << "1. Buat File\n";
		cout << "2. Baca isi File\n";
		cout << "3. Tulis isi File\n";
		cout << "4. Ubah isi File\n";
		cout << "5. Hapus File\n";
		cout << "--------------------------\n";
		
		cout << "Masukkan Pilihan :";
		cin >> pilihan;
		cout << "--------------------------\n";
		
		switch(pilihan)
		{
			case 1:
				cout << "Masukkan nama file:";
				cin >> berkas;
				addBerkas(berkas);
				break;
			case 2:
				cout << "Masukkan nama file:";
				cin >> berkas;
				readBerkas(berkas);
				break;
			case 3:
				cout << "Masukkan nama file:";
				cin >> berkas;
				writeText(berkas);
				break;
			case 5:
				cout << "Masukkan nama file:";
				cin >> berkas;
				deleteBerkas(berkas);
				break;
		}
		
		cout << "Lanjut (y), tutup (x) :";
		cin >> lanjut;
	}
	
	return 0;
}

//buat berkas
void addBerkas(string berkas)
{
	ofstream buka(berkas.c_str());
	
	if( buka.is_open())
	{
		cout << "File berhasil dibuat\n";
		buka.close();
	}
	else cout << "File tidak berhasil dibuat\n";
}

//baca isi file
void readBerkas(string berkas)
{
	string konten;
	ifstream buka(berkas.c_str());
	
	if( buka.is_open())
	{
		cout << "Isi File Kamu adalah :\n";
		cout << "----------------------\n";
		while( getline(buka, konten) )
		{
			cout << "_";
			cout << konten << endl;
		}
		buka.close();
		cout << "----------------------\n";
	}
}

//Menulis isi konten
void writeText(string berkas)
{
	string konten;
	ofstream buka(berkas.c_str(), ios::out);
	
	if( buka.is_open())
	{
		cout << "File ditemukan\n";
		cout << "Silahkan mulai menulis tekan (q) untuk keluar:\n";
		cin.ignore();
		while(konten != "q")
		{
			cout << "_";
			getline(cin,konten);
			if(konten == "q") break;
			buka << konten << endl;
			
		}
		buka.close();
	}
	else cout << "File tidak ditemukan\n";
}

//ubah isi file
void editBerkas(string berkas);

//hapus file
void deleteBerkas(string berkas)
{
	ofstream buka(berkas.c_str());
	
	if( buka.is_open())
	{
		cout << "File ditemukan\n";
		buka.close();
		remove(berkas.c_str());
		cout << "File berhasil dihapus dari sistem\n";
	}
	else cout << "File tidak ditemukan\n";
	
}
