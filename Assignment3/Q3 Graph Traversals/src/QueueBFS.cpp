/*
 * File: QueueBFS.cpp
 * ------------------
 * This program reimplements the breadth-first search algorithm using an
 * explicit queue.
 */
#include "graphtypes.h"
#include "foreach.h"
#include "queue.h"

void breadthFirstSearch(Node *start) {
    Queue<Node*> q;
    Vector<std::string> visitedCities;
    q.enqueue(start);
    visitedCities.push_back(start->name);

    while (!q.isEmpty()) {
        Node* n = q.dequeue();
        std::cout << n->name << std::endl;

        for (Arc* arch : n->arcs) {
            Node* city = arch->finish->name == n->name ? arch->start : arch->finish;
            if (!visitedCities.contains(city->name)) {
                visitedCities.push_back(city->name);
                q.enqueue(city);
            }
        }
    }
}
