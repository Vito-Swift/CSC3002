/*
 * File: StackDFS.cpp
 * ------------------
 * This program reimplements the depth-first search algorithm using an
 * explicit stack.
 */

#include "graphtypes.h"
#include "foreach.h"
#include "stack.h"

void depthFirstSearch(Node *start) {
    Stack<Node*> s;
    Vector<std::string> visitedCities;
    s.push(start);
    visitedCities.push_back(start->name);

    while (!s.isEmpty()) {
        Node* n = s.pop();
        std::cout << n->name << std::endl;

        for (Arc* arch : n->arcs) {
            Node* city = arch->finish->name == n->name ? arch->start : arch->finish;
            if (!visitedCities.contains(city->name)) {
                visitedCities.push_back(city->name);
                s.push(city);
            }
        }
    }

}
