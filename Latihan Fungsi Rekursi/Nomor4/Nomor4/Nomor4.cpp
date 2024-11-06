#include <iostream>
#include <cmath>

bool ApakahBilanganPrima(int bilangan);
void CetakBilanganPrima();

int main() {
	int n;
	std::cin >> n;
	std::cout << n << " Adalah " << (ApakahBilanganPrima(n) ? "Bilangan Prima\n\n" : "Bukan Bilangan Prima\n\n");
	CetakBilanganPrima();
	return 0;
};

bool ApakahBilanganPrima(int bilangan) {
	if (bilangan <= 1) return false;
	for (int i = 2, len = sqrt(bilangan) + 1; i < len; i++) {
		if (bilangan % i == 0) return false;
	}
	return true;
}

void CetakBilanganPrima() {
	std::cout << "Bilangan Prima dari 1-100 : \n";
	for (int i = 2; i <= 100; i++) {
		if (ApakahBilanganPrima(i)) std::cout << i << " ";
	}
	std::cout << "\n\n";
}