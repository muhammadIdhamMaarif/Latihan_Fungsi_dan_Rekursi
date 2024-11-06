#include <iostream>		//include iostream library
#include <vector>		//include vector library for dynamic array
#include <cstdlib>		//include cstdlib library for standard library for C
#include <ctime>		//include ctime library for random number
#include <numeric>		//include numeric library for numeric_limits
#include <limits>		//include limits library
#include <cmath>		//include cmath library

/*
	Muhammad Idham Ma'arif
	245150300111024
	Teknik Komputer 24
*/

int length, width;								//global variabel panjang dan lebar matriks
int maks = std::numeric_limits<int>::min();		//deklarasi maks dengan batas minimal int
int maksLen;									//global variabel untuk menyimpan maksLen untuk judul
void inputPanjangLebar(int& l, int& w);			//deklarasi fungsi untuk input panjang dan lebar
void standardInput	  (std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2); //deklarasi fungsi untuk input matriks 1 dan matriks 2 dengan STDIN
void templateInput	  (std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2); //deklarasi fungsi untuk input matriks 1 dan matriks 2 dengan random number
void inputMatriks	  (std::vector<std::vector<int>> &m, bool random = false);				  //deklarasi fungsi untuk menerima input baik random maupun STDIN
void tambahkanMatriks (std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, std::vector<std::vector<int>> &mh);	//menambahkan m1 dan m2 kemudian disimpan di mh
void cetakMatriks	  (std::vector<std::vector<int>> &m);									  //fungsi untuk mencetak matriks m
void cetakJudul		  (std::string s);														  //fungsi untuk mencetak template judul dengan nama s
int maksLength(int n);																		  //fungsi untuk mendapatkan panjang suatu integer
void cetakDash(int n);																		  //fungsi untuk cetak '=' agar judul cantik <3

int main() {	

	srand((unsigned)time(0));															//srand untuk random number

	do {
		inputPanjangLebar(length, width);												//memanggil fungsi untuk menerima input panjang dan lebar
		if (length <= 0 || width <= 0) {												//cek jika panjang atau lebar matriks <= 0
			std::cout << "Jangan main-main lah bang •`_´•" << std::endl;				//marahin user														
		}
	} while (length <= 0 || width <= 0);

	std::vector<std::vector<int>> matriks1		(length, std::vector<int> (width));		//deklarasi vektor 2 dimensi dengan nama matriks1 ukuran length x width
	std::vector<std::vector<int>> matriks2		(length, std::vector<int> (width));		//deklarasi vektor 2 dimensi dengan nama matriks2 ukuran length x width
	std::vector<std::vector<int>> matriksHasil	(length, std::vector<int> (width));		//deklarasi vektor 2 dimensi dengan nama matriksHasil ukuran length x width untuk menyimpan hasil penjumlahan m2 dan m2

	std::string pilihan;																//deklarasi string untuk pilihan user
	do {																				//looping do while
		std::cout << "Mau input sendiri satu-satu atau pake random?" << std::endl;		//cetak instruksi
		std::cout << "1. Input Sendiri-sendiri" << std::endl;							//cetak pilihan
		std::cout << "2. Pake random num aja cape ngetik" << std::endl;					//cetak pilihan
		std::cout << "Pilihan Anda : ";													//cetak masukkan
		std::cin >> pilihan;															//menerima STDIN
		std::cout << std::endl;															//newline
		if (pilihan != "1" && pilihan != "2") {											//cek jika input salah
			std::cout << "Jangan main-main lah bang •`_´•";								//marahin user
		}
		std::cout << std::endl;															//newline
	} while (pilihan != "1" && pilihan != "2");											//ulangi jika input salah

	pilihan == "1" ? standardInput(matriks1, matriks2) : templateInput(matriks1, matriks2);
	//standardInput(matriks1, matriks2);		//Jika ingin menggunakan STDIN, hapus komen kemudian tambahkan komen ke templateInput
	//templateInput(matriks1, matriks2);		//Jika ingin menggunakan Template (random num), hapus komen kemudian tambahkan komen ke standardInput

	tambahkanMatriks(matriks1, matriks2, matriksHasil);		//Menjumlahkan matriks 1 dan matriks 2

	maksLen = (width - 1) * 8 + maksLength(maks);			//assign panjang judul

	cetakJudul("Matriks 1");								//cetak judul dengan nama "Matriks 1"
	cetakMatriks(matriks1);									//cetak matriks1
	std::cout << "\n\n";									//newline 2x

	cetakJudul("Matriks 2");								//cetak judul dengan nama "Matriks 2"
	cetakMatriks(matriks2);									//cetak matriks2
	std::cout << "\n\n";									//newline 2x

	cetakJudul("Matriks 1 + Matriks 2");					//cetak judul dengan nama "Matriks 1 + Matriks 2"
	cetakMatriks(matriksHasil);								//cetak matriksHasil
	std::cout << "\n\n";									//newline 2x
	
	return 0;												//program sukses <3
}

void inputPanjangLebar(int& l, int& w) {
	std::cout << "Masukkan Panjang Matriks : ";				//cetak instruksi
	std::cin >> l;											//menerima STDIN panjang matriks
	std::cout << "Masukkan Lebar Matriks   : ";				//cetak instruksi
	std::cin >> w;											//menerima STDIN lebar matriks
	std::cout << "\n";										//newline 2x
}

void standardInput(std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2) {
	inputMatriks(m1);										//panggil fungsi untuk input STDIN m1
	inputMatriks(m2);										//panggil fungsi untuk input STDIN m2
}

void inputMatriks(std::vector<std::vector<int>> &m, bool random) {
	for (int i = 0; i < length; i++) {						//looping per row
		for (int j = 0; j < width; j++) {					//looping per column
			if (random) m[i][j] = rand() % 1000;			//jika pake template maka random num
			else std::cin >> m[i][j];						//jika tidak menerima STDIN
		}
	}
}

void templateInput(std::vector<std::vector<int>>& m1, std::vector<std::vector<int>>& m2) {
	inputMatriks(m1, true);									//panggil fungsi untuk input random m1
	inputMatriks(m2, true);									//panggil fungsi untuk input random m2
}

void tambahkanMatriks(std::vector<std::vector<int>> &m1, std::vector<std::vector<int>> &m2, std::vector<std::vector<int>> &mh) {
	for (int i = 0; i < length; i++) {						//looping per row
		for (int j = 0; j < width; j++) {					//looping per column
			mh[i][j] = m1[i][j] + m2[i][j];					//tambah m1 dan m2 simpan di mh
			maks = std::max(maks, mh[i][j]);				//update nilai maks <3
		}
	}
}

void cetakMatriks(std::vector<std::vector<int>>& m) {	

	for (int i = 0; i < length; i++) {						//looping per row
		for (int j = 0; j < width; j++) {					//looping per column
			std::cout << m[i][j] << "\t";					//cetak m dengan pisahan tab
		}
		std::cout << std::endl;								//newline 1x
	}

}

int maksLength(int n) {
	int len = 1;											//deklarasi len 1
	while (n /= 10) ++len;									//ulangi hingga n == 0
	return len;												//mengembalikan len
}

void cetakJudul(std::string s) {
	int len = maksLen - s.length();							//untuk panjang judul tanpa pesan
	cetakDash(len / 2 - 1);									//cetak dash sebelah kiri

	std::cout << ' ' << s << ' ';							//cetak pesan

	cetakDash(len / 2 - 1);									//cetak dash sebelah kanan

	std::cout << "\n\n";									//newline 2x
}

void cetakDash(int n) {
	while (n--) {											//ulangi hingga n = 0
		std::cout << '=';									//cetak '='
	}
}
