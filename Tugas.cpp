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
        std::cout << "Buku Tidak Tersedia." << std::endl;
    }
    else {
        std::cout << "Stok Buku:" << std::endl;
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
else if (option == "2") {
            while (true) {
                std::string namabuku;
                std::cout << "Masukkan nama buku yang dihapus (ketik 'kembali' untuk ke menu): ";
                std::getline(std::cin, namabuku);

                if (namabuku == "kembali") break;

                auto it = std::find_if(bukus.begin(), bukus.end(),
                    [&namabuku](const buku& w) {
                        return std::equal(w.name.begin(), w.name.end(),
                            namabuku.begin(), namabuku.end(),
                            [](char a, char b) {
                                return tolower(a) == tolower(b);
                            });
                    });

                if (it != bukus.end()) {
                    bukus.erase(it);
                    std::cout << "buku berhasil dihapus." << std::endl;
                }
                else {
                    std::cout << "buku tidak ditemukan." << std::endl;
                }
            }
        }
        else if (option == "3") {
            std::string namabuku;
            std::cout << "Masukkan nama buku untuk diperbarui: ";
            std::getline(std::cin, namabuku);

            std::string quantityStr;
            std::cout << "Masukkan Jumlah untuk ditambah atau dikurang dari stok " << namabuku << ": ";
            std::getline(std::cin, quantityStr);

            try {
                int quantity = std::stoi(quantityStr);
                updateStokBuku(bukus, namabuku, quantity);
            }
            catch (const std::exception& e) {
                std::cout << "Input tidak valid. Silakan coba lagi." << std::endl;
            }
        }
        else if (option == "4") {
            displaybukusStock(bukus);
        }
        else if (option == "5") {
            std::cout << "Selamat Tinggal" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid." << std::endl;
        }
    }

    return 0;
}
