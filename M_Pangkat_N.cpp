#include <iostream>

int hasilPangkat(int m, int n);

int main() {
	int m, n;
	std::cout << "Masukkan m  : ";
	std::cin >> m;
	std::cout << "Masukkan n  : ";
	std::cin >> n;
	std::cout << "m pangkat n : " << hasilPangkat(m, n) << std::endl;
	return 0;
} 

int hasilPangkat(int m, int n) {
	if (n == 1) return m;
	else return m * hasilPangkat(m, n - 1);
}
