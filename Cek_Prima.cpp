#include <iostream>
#include <cmath>

/*
	Muhammad Idham Ma'arif
	245150300111024
	Teknik Komputer 24
*/

// Deklarasi fungsi untuk mengecek apakah suatu bilangan prima
bool ApakahBilanganPrima(int bilangan);

// Deklarasi fungsi untuk mencetak bilangan prima dari 1 sampai 100
void CetakBilanganPrima();

int main() {
	int n;															// Deklarasi variabel untuk bilangan yang akan dicek
	std::cin >> n;														// Menerima input bilangan n dari pengguna
	std::cout << n << " Adalah " << (ApakahBilanganPrima(n) ? "Bilangan Prima\n\n" : "Bukan Bilangan Prima\n\n");  		// Menampilkan hasil apakah bilangan prima atau bukan
	CetakBilanganPrima();													// Memanggil fungsi untuk mencetak bilangan prima dari 1-100
	return 0;														// Mengembalikan 0 sebagai tanda program berhasil dijalankan
};

// Fungsi untuk mengecek apakah bilangan prima
bool ApakahBilanganPrima(int bilangan) {
	if (bilangan <= 1) return false;											// Bilangan <= 1 bukan bilangan prima
	for (int i = 2, len = sqrt(bilangan) + 1; i < len; i++) {								// Looping dari 2 hingga akar bilangan
		if (bilangan % i == 0) return false;										// Jika ditemukan pembagi selain 1 dan bilangan itu sendiri, maka bukan bilangan prima
	}
	return true;														// Jika tidak ditemukan pembagi, maka bilangan tersebut prima
}

// Fungsi untuk mencetak bilangan prima dari 1 sampai 100
void CetakBilanganPrima() {
	std::cout << "Bilangan Prima dari 1-100 : \n";										// Menampilkan header
	for (int i = 2; i <= 100; i++) {											// Looping untuk memeriksa setiap bilangan dari 2 hingga 100
		if (ApakahBilanganPrima(i)) std::cout << i << " ";								// Jika bilangan i adalah prima, cetak bilangan tersebut
	}
	std::cout << "\n\n";													// Menampilkan newline setelah daftar bilangan prima
}
