#include "include/robot.hpp"

Robot::Robot(std::vector<std::string> p) : map(p), time(0), speed(1), is_there_wall(false) {
    find_initial_position();
}

void Robot::find_initial_position() {
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'S') {
                position_x = i;
                position_y = j;
                return;
            }
        }
    }
    position_x = position_y = -1;  // Tidak ditemukan
}

std::string Robot::move(char direction) {
    int x = position_x, y = position_y;
    if (direction == 'U'){
        x--;
    } else if (direction == 'D') {
        x++;
    } else if (direction == 'L') {
        y--;
    } else if (direction == 'R') {
        y++;
    } else {
        return "Perintah tidak dikenali";
    }

    if (x >= 0 && x < map.size() && y >= 0 && y < map[0].size()) { // Cek apakah posisi masih di dalam peta
        if (map[x][y] != 'x' || is_there_wall) { // Cek apakah posisi masih bisa dilewati
            position_x = x;
            position_y = y;
            time += 2.0 / speed;
            return check_position();
        } else {
            return "Robot nabrak, silahkan diperbaiki";
        }
    }
    return "Robot gagal dalam mencapai tujuan :(";
}

std::string Robot::check_position() {
    char symbol = map[position_x][position_y];
    switch (symbol) {
        case 'F': 
            return "Robot berresult mencapai tujuan";
        case 'M':
            is_there_wall = true;
            return "Bertemu dengan mekanik, siap membasmi rintangan";
        case 'E':
            speed = 2;
            return "Bertemu dengan electrical, kecepatan roda naik menjadi 200%";
        case 'P': 
            return "Hi Programmer";
        case 'O':
            time *= 2;
            return "Bertemu dengan official, diajak ngonten bareng";
        default: 
            return "";
    }
}

int Robot::get_time() {
    return static_cast<int>(time);
}

std::vector<std::string> simulate(std::vector<std::string> map, std::string command) {
    Robot robot(map);
    std::vector<std::string> result;

    for (char direction : command) {
        std::string response = robot.move(direction);
        if (!response.empty()) {
            result.push_back(response);
        }
        if (response == "Robot berresult mencapai tujuan" || response.find("Robot gagal") != std::string::npos) {
            break;
        }
    }

    if (result.empty() || result.back().find("Robot berresult mencapai tujuan") == std::string::npos) {
        result.push_back("Robot gagal dalam mencapai tujuan :(");
    }

    result.push_back("Robot telah berjalan selama " + std::to_string(robot.get_time()) + " menit");
    return result;
}
