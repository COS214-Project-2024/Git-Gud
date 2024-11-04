#ifndef NODE_H
#define NODE_H


struct Node {
    struct Point {
        int x, y;
    };

    Point point;
    Node* next;
};

#endif //NODE_H
