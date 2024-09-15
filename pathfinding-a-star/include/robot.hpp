#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <iostream>
#include <vector>
#include <string>
#include "node.hpp"

class Robot {
private:
    std::vector<std::string> map;
    int position_x, position_y;
    double time;
    double speed;
    bool is_there_wall;

    void find_initial_position();
    std::pair<int, int> get_destination();
    int heuristic(int x, int y, int goal_x, int goal_y);
    std::vector<Node*> get_neighbors(Node* node, int goal_x, int goal_y);
    std::vector<std::pair<int, int>> a_star();

public:
    Robot(std::vector<std::string> p);
    std::string move(int new_x, int new_y);
    std::string check_position();
    std::vector<std::string> simulate();
};

#endif // ROBOT_HPP
