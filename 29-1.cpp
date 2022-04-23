#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    std::cout << "How many numbers?\n";
    int number;
    std::cin >> number;
    std::cout << "Min number?\n";
    int min_number;
    std::cin >> min_number;
    std::cout << "Max number?\n";
    int max_number;
    std::cin >> max_number;

    // Set numbers in F file
    std::fstream f_file;
    f_file.open("f_file.txt", std::ios::out);
    for (int i = 0; i < number; i++) {
        f_file << rand() % (max_number + 1 - min_number) + min_number << " ";
    }
    f_file.close();

    // Get numbers from F file and set even to G
    std::fstream g_file;
    g_file.open("g_file.txt", std::ios::out);
    f_file.open("f_file.txt", std::ios::in);
    int current;
    for (int i = 0; i < number; i++) {
        f_file >> current;
        if (current % 2 == 0) {
            g_file << current << " ";
        }
    }
    g_file.close();
    f_file.close();
    return 0;
}
