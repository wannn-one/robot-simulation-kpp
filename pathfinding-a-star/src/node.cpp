#include "include/node.hpp"
#include <cmath>

Node::Node(int x, int y, int g, int h, Node* parent)
    : x(x), y(y), g(g), h(h), parent(parent) {}

int Node::getX() const {
    return x;
}

int Node::getY() const {
    return y;
}

int Node::getG() const {
    return g;
}

int Node::getH() const {
    return h;
}

int Node::f() const {
    return g + h;
}

Node* Node::getParent() const {
    return parent;
}

bool Node::operator<(const Node& other) const {
    return f() > other.f();  // Untuk priority_queue
}
