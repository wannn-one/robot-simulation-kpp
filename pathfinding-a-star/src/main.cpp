#include "include/robot.hpp"

int main() {
    int M, N;
    std::cin >> M >> N;
    std::cin.ignore();  // Membersihkan newline

    std::vector<std::string> peta(M);
    for (int i = 0; i < M; ++i) {
        std::getline(std::cin, peta[i]);
    }

    Robot robot(peta);
    std::vector<std::string> hasil = robot.simulate();

    for (const std::string& line : hasil) {
        std::cout << line << std::endl;
    }

    return 0;
}
