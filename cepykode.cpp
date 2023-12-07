// Implementasi fungsi untuk mengupdate data dosen berdasarkan nama
void DatabaseDosen::updateDataDosen(const std::string& namaDosen, const Dosen& newData) {
    int index = -1;
    for (int i = 0; i < jumlahDosen; ++i) {
        if (dataDosen[i].nama == namaDosen) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        dataDosen[index] = newData;
        std::cout << "Data dosen berhasil diupdate.\n";
    } else {
        std::cout << "Dosen dengan nama '" << namaDosen << "' tidak ditemukan. Apakah Anda ingin menambahkannya? (Y/N): ";
        char tambahData;
        std::cin >> tambahData;

        if (std::toupper(tambahData) == 'Y') {
            tambahDataDosen(newData);
            std::cout << "Data dosen berhasil ditambahkan.\n";
        } else {
            std::cout << "Update dibatalkan.\n";
        }
    }
}

// Implementasi fungsi untuk menghapus data dosen berdasarkan nama
void DatabaseDosen::hapusDataDosen(const std::string& namaDosen) {
    int index = -1;
    for (int i = 0; i < jumlahDosen; ++i) {
        if (dataDosen[i].nama == namaDosen) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < jumlahDosen - 1; ++i) {
            dataDosen[i] = dataDosen[i + 1];
        }
        --jumlahDosen;
        std::cout << "Data dosen berhasil dihapus.\n";
    } else {
        std::cout << "Dosen dengan nama '" << namaDosen << "' tidak ditemukan. Hapus dibatalkan.\n";
    }
}

// Implementasi fungsi untuk validasi input hari
bool DatabaseDosen::isValidHari(const std::string& hari) const {
    std::string hariUpper;
    std::transform(hari.begin(), hari.end(), std::back_inserter(hariUpper), ::toupper);
    
    std::vector<std::string>daftarHari = {"SENIN", "SELASA", "RABU", "KAMIS", "JUMAT"};
    	return std::find(daftarHari.begin(), daftarHari.end(), hariUpper) != daftarHari.end();
}

// Implementasi fungsi untuk validasi apakah string hanya berisi huruf
bool DatabaseDosen::isAlpha(const std::string& str) const {
    return std::all_of(str.begin(), str.end(), ::isalpha);
}

// Implementasi fungsi untuk validasi apakah string hanya berisi angka
bool DatabaseDosen::isNumeric(const std::string& str) const {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

// Implementasi fungsi untuk validasi apakah nama dosen sudah ada dalam database
bool DatabaseDosen::isDosenExist(const std::string& namaDosen) const {
    for (int i = 0; i < jumlahDosen; ++i) {
        if (dataDosen[i].nama == namaDosen) {
            return true; // Nama dosen ditemukan
        }
    }
    return false; // Nama dosen tidak ditemukan
}

// Fungsi utama program
int main() {
    std::cout << "=====================================\n";
    std::cout << "   Pengembangan Aplikasi CRUD Dosen  \n";
    std::cout << "=====================================\n";

    // Membuat objek database untuk menyimpan data dosen
    DatabaseDosen database;
    
    char pilihan;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tambah Data Dosen\n";
        std::cout << "2. Lihat Data Dosen\n";
        std::cout << "3. Update Data Dosen\n";
        std::cout << "4. Hapus Data Dosen\n";
        std::cout << "5. Keluar\n";
        std::cout << "Masukkan Pilihan : ";
        std::cin >> pilihan;