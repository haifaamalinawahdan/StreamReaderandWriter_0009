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

// menghapus barang
void hapusBarang() {
    ifstream file(NAMA_FILE);

    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) {
        cout << "Tidak ada data untuk dihapus.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "\nPilih nomor barang yang ingin dihapus: ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    data.erase(data.begin() + (nomor - 1));

    ofstream outFile(NAMA_FILE);

    for (string item : data) {
        outFile << item << endl;
    }

    outFile.close();

    cout << "Data berhasil dihapus!\n";
}

// simulasi etalase
void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // Skenario 1
    cout << "\nSkenario 1 (Rak indeks 1)\n";

    try {
        cout << "Barang berhasil diambil: "
             << toko.ambilProduk(1)
             << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }

    // Skenario 2
    cout << "\nSkenario 2 (Rak indeks 5)\n";

    try {
        cout << "Barang berhasil diambil: "
             << toko.ambilProduk(5)
             << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n=================================\n";
        cout << " SISTEM MANAJEMEN TOKO GIBRAN JAYA\n";
        cout << "=================================\n";

        tampilkanBarang();

        cout << "\nMenu:\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Tampilkan Barang (Read)\n";
        cout << "3. Update Barang (Update)\n";
        cout << "4. Hapus Barang (Delete)\n";
        cout << "5. Simulasi Etalase (Exception)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahBarang();
            break;

        case 2:
            tampilkanBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 0);

    return 0;
}