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

// menambah barang
void tambahBarang() {
    ofstream file(NAMA_FILE, ios::app);

    string barang;

    cin.ignore();
    cout << "Masukkan nama barang: ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan!\n";
}

// UPDATE
void updateBarang() {
    ifstream file(NAMA_FILE);

    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) {
        cout << "Tidak ada data untuk diupdate.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang ingin diubah: ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cin.ignore();
    cout << "Masukkan nama barang baru: ";
    getline(cin, data[nomor - 1]);

    ofstream outFile(NAMA_FILE);

    for (string item : data) {
        outFile << item << endl;
    }

    outFile.close();

    cout << "Data berhasil diperbarui!\n";
}
