#include "include/robot.hpp"

int main() {
    int M, N, P;
    std::cin >> M >> N;
    std::cin.ignore();  // Membersihkan newline

    std::vector<std::string> map(M);
    for (int i = 0; i < M; ++i) {
        std::getline(std::cin, map[i]);
    }

    std::cin >> P;
    std::cin.ignore();  // Membersihkan newline

    std::string command;
    std::getline(std::cin, command);

    std::vector<std::string> hasil = simulate(map, command);

    for (std::string line : hasil) {
        std::cout << line << std::endl;
    }

    return 0;
}
