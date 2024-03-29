/*
 * Name: Chengbin Hu
 * Data: 07/12/2014
 *
 * Description.
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "Edge.h"
#include "UnionFind.h"

using namespace std;

int num_vertices;
vector<Edge> edges;

// Read the input from the user.
void
read_input()
{
    int tmp;
    int from, to, weight;

    Edge edge(0, 0, 0);

    num_vertices = 0;
    while (num_vertices <= 0) {
        cout << "Enter the number of vertices: ";
        cin >> tmp;
        if (tmp > 0) {
            num_vertices = tmp;
        } else {
            cout << "Please enter a positive number of vertices." << endl << endl;
        }
    }

    cout << "Vertices numbered from 0 to " << num_vertices - 1 << endl << endl;

    cout << "Enter edges:" << endl;
    cout << "Format: <from-vertex> <to-vertex> <weight>" << endl;
    cout << "Example: Edge from 1 to 2, weight 50:  1 2 50" << endl;
    cout << "Enter '-1 -1 -1' to end." << endl;

    while (true) {
        cin >> from;
        cin >> to;
        cin >> weight;

        if (from == -1) {
            break;
        }

        if (from >= num_vertices || from < 0) {
            cout << "Invalid from vertex: " << from << endl;
            continue;
        }

        if (to >= num_vertices || to < 0) {
            cout << "Invalid to vertex: " << to << endl;
            continue;
        }

        if (weight <= 0) {
            cout << "Invalid weight: " << weight << endl;
            continue;
        }

        edge = Edge(from, to, weight);

        edges.push_back(edge);
    }
}

// HINT: to sort a vector:
// sort(vector.begin(), vector.end())

vector<Edge>
kruskal()
{
    // TODO: Complete.
    sort(edges.begin(),edges.end());
    vector<Edge> minedges;
    UnionFind uni(num_vertices);
    //int count = 0;
    int i = 0, x=edges.size();
    while (i<x)
    {
        if(uni.FindSet(edges[i].From())!=uni.FindSet(edges[i].To())){
        minedges.push_back(edges[i]);
        //count=count+1;
        uni.Union(edges[i].From(),edges[i].To());
        }
        i=i+1;
    }
    return minedges;
}
int
main(int argc, char **argv)
{
    read_input();

    vector<Edge> kruskal_edges = kruskal();

    sort(kruskal_edges.begin(), kruskal_edges.end());
    for (vector<Edge>::iterator it = kruskal_edges.begin(); it != kruskal_edges.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}

/* vim: set et sw=4 ts=4: */
