#include <iostream>

/*
	Muhammad Idham Ma'arif
	245150300111024
	Teknik Komputer 24
*/

// Deklarasi fungsi untuk menghitung hasil pangkat
int hasilPangkat(int m, int n);

int main() {
	int m, n;														// Deklarasi variabel untuk basis (m) dan eksponen (n)
	std::cout << "Masukkan m  : ";												// Tampilkan pesan untuk input nilai m
	std::cin >> m;														// Terima input nilai m
	std::cout << "Masukkan n  : ";												// Tampilkan pesan untuk input nilai n
	std::cin >> n;														// Terima input nilai n
	std::cout << "m pangkat n : " << hasilPangkat(m, n) << std::endl; // Tampilkan hasil pangkat
	return 0;														// Mengembalikan 0 sebagai tanda program berhasil dijalankan
}

// Fungsi rekursif untuk menghitung pangkat
int hasilPangkat(int m, int n) {		
	if (n == 1) return m;													// Jika eksponen n adalah 1, kembalikan nilai m (basis)
	else return m * hasilPangkat(m, n - 1);											// Kalikan m dengan hasil pangkat
}
