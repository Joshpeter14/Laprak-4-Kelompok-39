#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class buku {
public:
    std::string name;
    int stock;

    buku(std::string name, int stock) : name(name), stock(stock) {}
};

int getStockByName(const std::vector<buku>& bukus, const std::string& namabuku) {
    auto it = std::find_if(bukus.begin(), bukus.end(),
        [&namabuku](const buku& w) {
            return std::equal(w.name.begin(), w.name.end(),
                namabuku.begin(), namabuku.end(),
                [](char a, char b) {
                    return tolower(a) == tolower(b);
                });
        });

    return (it != bukus.end()) ? it->stock : -1;
}

void updateStokBuku(std::vector<buku>& bukus, const std::string& namabuku, int quantity) {
    auto it = std::find_if(bukus.begin(), bukus.end(),
        [&namabuku](const buku& w) {
            return std::equal(w.name.begin(), w.name.end(),
                namabuku.begin(), namabuku.end(),
                [](char a, char b) {
                    return tolower(a) == tolower(b);
                });
        });

    if (it != bukus.end()) {
        it->stock += quantity;
    }
}

void displaybukusStock(const std::vector<buku>& bukus) {
    if (bukus.empty()) {
        std::cout << "Senjata Tidak Tersedia." << std::endl;
    }
    else {
        std::cout << "Stok Senjata:" << std::endl;
        for (const auto& buku : bukus) {
            std::cout << "- " << buku.name << ": " << buku.stock << std::endl;
        }
    }
}
int main() {
    std::vector<buku> bukus = {
        buku("a book", 1),
        buku("buku 2", 23),
        buku("buku 3", 1337),
        buku("buku 4", 42),
        buku("buku 5", 0),
        buku("buku 6", 888)
    };

    while (true) {
        std::cout << "\nOpsi:" << std::endl;
        std::cout << "1. Tambah Jenis buku" << std::endl;
        std::cout << "2. Hapus Jenis buku" << std::endl;
        std::cout << "3. Perbarui Stok buku" << std::endl;
        std::cout << "4. Tampilkan Stok buku" << std::endl;
        std::cout << "5. Keluar" << std::endl;

        std::string option;
        std::cout << "Masukkan Opsi (1/2/3/4/5): ";
        std::getline(std::cin, option);

        if (option == "1") {
            while (true) {
                std::string namabuku;
                std::cout << "Masukkan Nama buku (ketik 'kembali' untuk ke menu): ";
                std::getline(std::cin, namabuku);

                if (namabuku == "kembali") break;

                std::string stockStr;
                std::cout << "Masukkan jumlah stock " << namabuku << " : ";
                std::getline(std::cin, stockStr);

                try {
                    int stock = std::stoi(stockStr);
                    bukus.emplace_back(namabuku, stock);
                }
                catch (const std::exception& e) {
                    std::cout << "Input tidak valid. Silakan coba lagi." << std::endl;
                }
            }
        }
