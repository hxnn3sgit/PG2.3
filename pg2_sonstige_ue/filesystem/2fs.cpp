#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using std::cout, std::endl;

int main() {
    fs::path src;
    fs::path dst; 
    cout << "Geben Sie den Zielpfad der zu kopierenden Datei an: ";
    std::cin >> dst;

    cout << "\nGeben Sie den Quellpfad der zu kopierenden Datei an :";
    std::cin >> src;
    cout << endl;

    fs::copy(src, dst);

    return 0;
}