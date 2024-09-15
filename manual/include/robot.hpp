#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <vector>
#include <string>

class Robot {
private:
    std::vector<std::string> map;
    int position_x, position_y;
    double time;
    double speed;
    bool is_there_wall;

    void find_initial_position();

public:
    Robot(std::vector<std::string> p);
    std::string move(char arah);
    std::string check_position();
    int get_time();
};

std::vector<std::string> simulate(std::vector<std::string> map, std::string command);

#endif // ROBOT_HPP
