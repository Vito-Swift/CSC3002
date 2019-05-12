/*
 * File: QueueBFS.cpp
 * ------------------
 * This program reimplements the breadth-first search algorithm using an
 * explicit queue.
 */
#include "graphtypes.h"
#include "foreach.h"
#include "queue.h"

/*
 * Method: breadthFirstSearch
 * Usage: breadthFirstSearch(start);
 * ---------------------------------
 * Search a simple graph by BFS using a queue.
 */

void breadthFirstSearch(Node *start) {

    // queue to store cities
    Queue<Node*> q;

    // array to record visited cities
    Vector<std::string> visitedCities;

    // initialize the queue and the array
    q.enqueue(start);
    visitedCities.push_back(start->name);

    while (!q.isEmpty()) {

        // dequeue the first elements of queue and print its name
        Node* n = q.dequeue();
        std::cout << n->name << std::endl;

        for (Arc* arch : n->arcs) {

            // iterate the neighbours of the dequeued city
            Node* city = arch->finish->name == n->name ? arch->start : arch->finish;

            // push the neighbour into the queue if it has not been visited before
            if (!visitedCities.contains(city->name)) {
                visitedCities.push_back(city->name);
                q.enqueue(city);
            }
        }
    }
}
