#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    int x, y;
    int g, h;
    Node* parent;

public:
    Node(int x, int y, int g, int h, Node* parent);

    int getX() const;
    int getY() const;
    int getG() const;
    int getH() const;
    int f() const;
    Node* getParent() const;

    bool operator<(const Node& other) const;
};

#endif