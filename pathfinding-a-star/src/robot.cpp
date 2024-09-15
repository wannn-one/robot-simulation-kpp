#include "include/robot.hpp"
#include <queue>
#include <algorithm>
#include <cmath>

Robot::Robot(std::vector<std::string> p) : map(p), time(0), speed(1), is_there_wall(false) {
    find_initial_position();
}

void Robot::find_initial_position() { // Find the initial position of the robot
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'S') {
                position_x = i;
                position_y = j;
                return;
            }
        }
    }
}

std::pair<int, int> Robot::get_destination() { // Find the destination of the robot
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'F') {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // If there is no destination, return {-1, -1}
}

int Robot::heuristic(int x, int y, int goal_x, int goal_y) { // Calculate the heuristic value, in this case, Manhattan distance
    return std::abs(x - goal_x) + std::abs(y - goal_y);
}

std::vector<Node*> Robot::get_neighbors(Node* node, int goal_x, int goal_y) { // Get the neighbors of the current node
    std::vector<Node*> neighbors; // List of neighbors of the current node
    int dx[] = {-1, 1, 0, 0}; 
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) { // Check the neighbors of the current node
        int new_x = node->getX() + dx[i]; // Calculate the new x position
        int new_y = node->getY() + dy[i]; // Calculate the new y position

        if (new_x >= 0 && new_x < map.size() && new_y >= 0 && new_y < map[0].size()) { // Check if the new position is inside the map
            if (map[new_x][new_y] != 'x' || is_there_wall) { // Check if the new position is not a wall or the robot has encountered a mechanic
                int new_g = node->getG() + 1; // Calculate the new g value
                int new_h = heuristic(new_x, new_y, goal_x, goal_y); // Calculate the new h value
                neighbors.push_back(new Node(new_x, new_y, new_g, new_h, node)); // Add the new node to the list of neighbors
            }
        }
    }
    return neighbors;
}

std::vector<std::pair<int, int>> Robot::a_star() { // A* algorithm to find the shortest path
    auto [goal_x, goal_y] = get_destination(); // Get the destination of the robot
    if (goal_x == -1 || goal_y == -1){
        return {};
    }  // If there is no destination, return an empty vector

    std::priority_queue<Node*> open_set; // Priority queue to store the nodes that are being evaluated
    std::vector<std::vector<bool>> closed_set(map.size(), std::vector<bool>(map[0].size(), false)); // 2D vector to store the nodes that have been evaluated

    Node* start = new Node(position_x, position_y, 0, heuristic(position_x, position_y, goal_x, goal_y), nullptr); // Create the start node
    open_set.push(start); // Add the start node to the open set

    while (!open_set.empty()) { // While the open set is not empty
        Node* current = open_set.top(); // Get the node with the lowest f value
        open_set.pop(); // Remove the node from the open set

        if (current->getX() == goal_x && current->getY() == goal_y) { // If the current node is the goal node
            std::vector<std::pair<int, int>> path; // Vector to store the path
            while (current != nullptr) { // Reconstruct the path
                path.push_back({current->getX(), current->getY()}); // Add the current node to the path
                current = current->getParent(); // Move to the parent node
            }
            std::reverse(path.begin(), path.end()); // Reverse the path
            return path; // Return the path
        }

        closed_set[current->getX()][current->getY()] = true; // Mark the current node as evaluated

        for (Node* neighbor : get_neighbors(current, goal_x, goal_y)) { // Get the neighbors of the current node
            if (closed_set[neighbor->getX()][neighbor->getY()]) { // If the neighbor has been evaluated
                delete neighbor; // Delete the neighbor
                continue;
            }

            open_set.push(neighbor); // Add the neighbor to the open set
        }
    }

    return {}; // If no path is found, return an empty vector
}

std::string Robot::move(int new_x, int new_y) {
    if (position_x != new_x || position_y != new_y) { // If the new position is different from the current position
        position_x = new_x;
        position_y = new_y;
        time += 2.0 / speed; // Update the time
    }
    return check_position();
}

std::string Robot::check_position() {
    char symbol = map[position_x][position_y]; // Get the symbol at the current position
    switch (symbol) {
        case 'F': 
            return "Robot berhasil mencapai tujuan";
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

std::vector<std::string> Robot::simulate() {
    std::vector<std::string> hasil;
    std::vector<std::pair<int, int>> path = a_star();

    if (path.empty()) {
        hasil.push_back("Robot gagal dalam mencapai tujuan :(");
    } else {
        for (const auto& [x, y] : path) {
            std::string respon = move(x, y);
            if (!respon.empty()) {
                hasil.push_back(respon);
            }
            if (respon == "Robot berhasil mencapai tujuan") break;
        }
    }

    hasil.push_back("Robot telah berjalan selama " + std::to_string(static_cast<int>(time)) + " menit");
    return hasil;
}
