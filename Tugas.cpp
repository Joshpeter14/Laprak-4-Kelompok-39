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
