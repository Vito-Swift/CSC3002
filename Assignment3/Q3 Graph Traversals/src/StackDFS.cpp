/*
 * File: StackDFS.cpp
 * ------------------
 * This program reimplements the depth-first search algorithm using an
 * explicit stack.
 */

#include "graphtypes.h"
#include "foreach.h"
#include "stack.h"

/*
 * Method: depthFirstSearch
 * Usage: depthFirstSearch(start);
 * -------------------------------
 * Search a simple graph by DFS using a stack.
 */

void depthFirstSearch(Node *start) {

    // stack to store cities
    Stack<Node*> s;

    // array to record visited cities
    Vector<std::string> visitedCities;

    // initialize the queue and the array
    s.push(start);
    visitedCities.push_back(start->name);

    while (!s.isEmpty()) {

        // pop the topmost elements of the stack and print its name
        Node* n = s.pop();
        std::cout << n->name << std::endl;

        for (Arc* arch : n->arcs) {

            // iterate the neighbours of the popped city
            Node* city = arch->finish->name == n->name ? arch->start : arch->finish;

            // push the neighbour into the queue if it has not been visited before
            if (!visitedCities.contains(city->name)) {
                visitedCities.push_back(city->name);
                s.push(city);
            }
        }
    }

}
