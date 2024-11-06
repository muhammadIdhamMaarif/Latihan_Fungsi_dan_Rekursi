#include <iostream>      //include library iostream untuk input-output
#include <vector>        //include library vector untuk array dinamis
#include <ctime>         //include library ctime untuk random number
#include <string>        //include library string untuk manipulasi string
#include <numeric>       //include library numeric
#include <limits>        //include library limits untuk batasan nilai int
#include <cmath>         //include library cmath untuk fungsi matematika

/*
    Muhammad Idham Ma'arif
    245150300111024
    Teknik Komputer 24
    <3
*/

int len;                                        //variabel global untuk panjang array
int maks = std::numeric_limits<int>::min();     //variabel untuk nilai maksimum, diinisialisasi dengan nilai minimum int
int maksLen;                                    //variabel global untuk menyimpan panjang maksimum judul

// Deklarasi fungsi
int addition(int a, int b);                      //fungsi penjumlahan
int subtraction(int a, int b);                   //fungsi pengurangan
int division(int a, int b);                      //fungsi pembagian
int multiplication(int a, int b);                //fungsi perkalian
void standardInput(std::vector<int>& arr1, std::vector<int>& arr2); //fungsi input manual
void templateInput(std::vector<int>& arr1, std::vector<int>& arr2); //fungsi input random
void inputArray(std::vector<int>& arr, bool random = false);        //fungsi untuk input array, random atau manual
void cetakArray(std::vector<int>& arr);                             //fungsi untuk cetak array
void cetakJudul(std::string s);                                     //fungsi untuk cetak judul
void cetakDash(int n);                                              //fungsi untuk cetak garis "="
int maksLength(int n);                                              //fungsi untuk mendapatkan panjang karakter suatu angka

int main() {
    std::string pilihan;       //variabel untuk pilihan input

    bool lanjut = true;        //variabel untuk loop utama program

    while (lanjut) {           //loop utama program

        std::cout << "Masukkan Panjang Array : ";                   //cetak instruksi panjang array
        std::cin >> len;                                            //menerima input panjang array

        std::vector<int> arr1(len);                                 //deklarasi array 1 dengan panjang len
        std::vector<int> arr2(len);                                 //deklarasi array 2 dengan panjang len
        std::vector<int> arrHasil(len);                             //deklarasi array hasil dengan panjang len

        do {                                                        //looping untuk input jenis masukkan
            std::cout << "\nMau input sendiri satu-satu atau pake random?" << std::endl; //cetak pilihan
            std::cout << "1. Input Sendiri-sendiri" << std::endl;   //cetak pilihan manual
            std::cout << "2. Pake random num aja cape ngetik" << std::endl; //cetak pilihan random
            std::cout << "Pilihan Anda : ";                         //cetak instruksi pilihan
            std::cin >> pilihan;                                    //menerima input pilihan
            std::cout << std::endl;                                 //newline

            if (pilihan != "1" && pilihan != "2") {                 //cek jika input salah
                std::cout << "Jangan main-main lah bang •`_´•";     //marahin user
            }

        } while (pilihan != "1" && pilihan != "2");                 //ulangi jika input salah

        pilihan == "1" ? standardInput(arr1, arr2) : templateInput(arr1, arr2); //pilihan input array

        do {                                                        //looping untuk pilihan operasi
            std::cout << "Pilih Operasi : \n";                      //cetak pilihan operasi
            std::cout << "1. Penambahan \n";                        //penjumlahan
            std::cout << "2. Pengurangan \n";                       //pengurangan
            std::cout << "3. Perkalian \n";                         //perkalian
            std::cout << "4. Pembagian \n";                         //pembagian
            std::cout << "Pilihan Anda : ";                         //instruksi pilihan operasi
            std::cin >> pilihan;                                    //menerima input pilihan
            if (pilihan != "1" && pilihan != "2" && pilihan != "3" && pilihan != "4") { //cek jika input salah
                std::cout << "\nJangan main-main lah bang •`_´•\n"; //marahin user
            }
        } while (pilihan != "1" && pilihan != "2" && pilihan != "3" && pilihan != "4"); //ulangi jika input salah

        int pilih;
        try {
            pilih = stoi(pilihan);                                  //konversi pilihan ke integer
        }
        catch (...) {
            std::cout << "Program Error dalam konversi ke Integer\n"; //pesan error konversi
            return 1;                                               //return error code 1
        }

        switch (pilih) {                                             //switch untuk pilihan operasi
        case 1:
            for (int i = 0; i < len; i++) {                          //looping array
                arrHasil[i] = addition(arr1[i], arr2[i]);            //operasi penjumlahan
                maks = std::max(maks, arrHasil[i]);                  //update nilai maksimum
            }
            break;
        case 2:
            for (int i = 0; i < len; i++) {                          //looping array
                arrHasil[i] = subtraction(arr1[i], arr2[i]);         //operasi pengurangan
                maks = std::max(maks, arrHasil[i]);                  //update nilai maksimum
            }
            break;
        case 3:
            for (int i = 0; i < len; i++) {                          //looping array
                arrHasil[i] = multiplication(arr1[i], arr2[i]);      //operasi perkalian
                maks = std::max(maks, arrHasil[i]);                  //update nilai maksimum
            }
            break;
        case 4:
            for (int i = 0; i < len; i++) {                          //looping array
                arrHasil[i] = division(arr1[i], arr2[i]);            //operasi pembagian
                maks = std::max(maks, arrHasil[i]);                  //update nilai maksimum
            }
            break;
        }

        maksLen = (len - 1) * 8 + maksLength(maks);                  //hitung panjang judul

        std::cout << "\n";
        cetakJudul("Array 1");                                       //cetak judul Array 1
        cetakArray(arr1);                                            //cetak array 1
        cetakJudul("Array 2");                                       //cetak judul Array 2
        cetakArray(arr2);                                            //cetak array 2
        cetakJudul("Array 1 + Array 2");                             //cetak judul hasil operasi
        cetakArray(arrHasil);                                        //cetak hasil operasi

        std::cout << "\n\n";

        char lanjutGa;                                               //variabel untuk input lanjut

        do {
            std::cout << "Lanjut ? (Y/n) : ";                        //tanya apakah mau lanjut
            std::cin >> lanjutGa;                                    //menerima input
            if (toupper(lanjutGa) != 'Y' && toupper(lanjutGa) != 'N') { //cek input benar/salah
                std::cout << "Masukkan hanya \"Y\" atau \"N\"\n";    //marahin user
            }
        } while (toupper(lanjutGa) != 'Y' && toupper(lanjutGa) != 'N'); //ulangi jika input salah

        lanjut = (toupper(lanjutGa) == 'Y');                         //cek jika lanjut atau tidak
    }
}

void standardInput(std::vector<int>& arr1, std::vector<int>& arr2) {
    inputArray(arr1);                                                //input manual array 1
    inputArray(arr2);                                                //input manual array 2
}

void templateInput(std::vector<int>& arr1, std::vector<int>& arr2) {
    inputArray(arr1, true);                                          //input random array 1
    inputArray(arr2, true);                                          //input random array 2
}

void inputArray(std::vector<int>& arr, bool random) {
    for (int i = 0; i < len; i++) {                                  //looping array
        if (random) arr[i] = rand() % 1000;                          //input random jika dipilih
        else std::cin >> arr[i];                                     //input manual jika dipilih
    }
}

int addition(int a, int b) {
    return a + b;                                                    //fungsi penjumlahan
}

int subtraction(int a, int b) {
    return a - b;                                                    //fungsi pengurangan
}

int division(int a, int b) {
    return a / b;                                                    //fungsi pembagian
}

int multiplication(int a, int b) {
    return a * b;                                                    //fungsi perkalian
}

void cetakArray(std::vector<int>& arr) {
    for (int i = 0; i < len; i++) {                                  //looping untuk cetak array
        std::cout << arr[i] << "\t";                                 //cetak nilai array
    }
    std::cout << "\n\n\n";                                           //newline 3x
}

void cetakJudul(std::string s) {
    int len = maksLen - s.length();                                  //hitung panjang judul
    cetakDash(len / 2 - 1);                                          //cetak dash kiri

    std::cout << ' ' << s << ' ';                                    //cetak judul

    cetakDash(len / 2 - 1);                                          //cetak dash kanan

    std::cout << "\n\n";                                             //newline 2x
}

void cetakDash(int n) {
    while (n--) {                                                    //looping cetak dash
        std::cout << '=';                                            //cetak '='
    }
}

int maksLength(int n) {
    int len = 1;                                                     //deklarasi panjang 1
    while (n /= 10) ++len;                                           //looping hingga n == 0
    return len;                                                      //return panjang
}
