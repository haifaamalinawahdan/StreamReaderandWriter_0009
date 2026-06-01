#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

using namespace std;

//enkapsulasi
class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop";
        etalase[1] = "Smartphone";
        etalase[2] = "Printer";
    }
    // Mengambil produk berdasarkan nomor rak
    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&) {
            throw string(
                "Gagal Mengambil Barang : Rak nomor " +
                to_string(nomorRak) +
                " kosong atau tidak tersedia!"
            );
        }
    }
};    
const string NAMA_FILE = "gudang.txt";

// membaca file
void tampilkanBarang() {
    ifstream file(NAMA_FILE);

    cout << "\n===== DAFTAR BARANG DI GUDANG =====\n";

    string barang;
    int nomor = 1;
    bool kosong = true;

    while (getline(file, barang)) {
        cout << nomor++ << ". " << barang << endl;
        kosong = false;
    }

    if (kosong) {
        cout << "Gudang masih kosong.\n";
    }

    file.close();
}