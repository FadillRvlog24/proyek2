#include <iostream>
#include <string>

const int MAX_DOSEN = 100; // Ukuran maksimum array

// Struktur untuk menyimpan informasi dosen
struct Dosen {
    std::string nama;
    std::string nip;
    std::string alamat;
    std::string email;
    std::string nomorTelepon;
    std::string mataKuliah;
    std::string hariMengajar;
    int umur;
};