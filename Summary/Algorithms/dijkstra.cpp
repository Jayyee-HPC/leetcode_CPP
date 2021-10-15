#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
class Graph
{
private:    
    std::unordered_map<char, const std::unordered_map<char, int>> vertices;

public:
    void add_vertex(char name, const std::unordered_map<char, int>& edges)
    {
        vertices.insert(std::unordered_map<char, const std::unordered_map<char, int>>::value_type(name, edges));
    }

    std::vector<char> shortest_path(char start, char finish)
    {
        std::unordered_map<char, int> distances;
        std::unordered_map<char, char> previous;
        std::vector<char> nodes;
        std::vector<char> path;

        auto comparator = [&] (char left, char right) {return distances[left] > distances[right];};

        for (auto& vertex : vertices)
        {
            if (vertex.first == start)
            {
                distances[vertex.first] = 0;
            }
            else
            {
                distances[vertex.first] = std::numeric_limits<int>::max();
            }
            nodes.push_back(vertex.first);
            std::push_heap(std::begin(nodes), std::end(nodes), comparator);
        }

        while (!nodes.empty())
        {
            std::pop_heap(std::begin(nodes), std::end(nodes), comparator);
            char smallest = nodes.back();
            nodes.pop_back();

            if (smallest == finish)
            {
                while (previous.find(smallest) != std::end(previous))
                {
                    path.push_back(smallest);
                    smallest = previous[smallest];
                }

                break;
            }

            if (distances[smallest] == std::numeric_limits<int>::max())
            {
                break;
            }

            for (auto& neighbor : vertices[smallest])
            {
                int alt = distances[smallest] + neighbor.second;

                if (alt < distances[neighbor.first])
                {
                    distances[neighbor.first] = alt;
                    previous[neighbor.first] = smallest;
                    std::make_heap(std::begin(nodes), std::end(nodes), comparator);
                }
            }
        }

        return path;
    }
};

int main()
{
    Graph g;
    g.add_vertex('A', {{'B', 7}, {'C', 8}});
    g.add_vertex('B', {{'A', 7}, {'F', 2}});
    g.add_vertex('C', {{'A', 8}, {'F', 6}, {'G', 4}});
    g.add_vertex('D', {{'F', 8}});
    g.add_vertex('E', {{'H', 1}});
    g.add_vertex('F', {{'B', 2}, {'C', 6}, {'D', 8}, {'G', 9}, {'H', 3}});
    g.add_vertex('G', {{'C', 4}, {'F', 9}});
    g.add_vertex('H', {{'E', 1}, {'F', 3}});    

    for (char vertex : g.shortest_path('H', 'A'))
    {
        std::cout << vertex << std::endl;
    }

    return 0;
}


// edge structure
struct Edge
{
    int source;
    int target;
    int weight;
};

// shortest_path
std::vector<int> shortest_path(std::vector<Edge> edges, int start, int end)
{
    // hash table for all successors of all edges
    std::unordered_map<int, std::unordered_map<int, int>> umap_edges;

    for (auto &edge : edges)
    {
        umap_edges[edge.source][edge.target] = edge.weight;
    }

    std::vector<int> nodes;
    // To track the distances of all nodes
    std::unordered_map<int, int> distances;
    // To keep track of the path to a node
    std::unordered_map<int, int> previous;
    // Path fro start to end
    std::vector<int> path;

    // comparator for min heap on nodes. Distances are stored in umap distances, hence & is needed.
    auto comparator = [&](int a, int b){return distances[a] > distances[b];};

    // initial all distances to infinity except for the start node with a zero
    for (auto &u_edge : umap_edges)
    {
        if (u_edge.first == start)
            distances[u_edge.first] = 0;
        else
            distances[u_edge.first] = INT_MAX;

        nodes.push_back(u_edge.first);
        std::push_heap(std::begin(nodes), std::end(nodes), comparator);
    }

    // main loop. always find the node with minmum distance.
    while (! nodes.empty())
    {
        // remove current node from the nodes vector.
        std::pop_heap(std::begin(nodes), std::end(nodes), comparator);
        int current = nodes.back();
        nodes.pop_back();

        // reach the end node
        if (current == end)
        {
            while (previous.find(current) != previous.end())
            {
                path.push_back(current);
                current = previous[current];
            }
        }

        // All un-visited nodes have infinite distances
        if (distances[current] == INT_MAX)
        {
            break;
        }

        // Update distances
        for (auto &neighbor : umap_edges[current])
        {
            int temp_dist = distances[current] + neighbor.second;
            // update a neighbor's distance if shorter distance is found
            if (temp_dist < distances[neighbor.first])
            {
                distances[neighbor.first] = temp_dist;
                previous[neighbor.first] = current;
                std::make_heap(std::begin(nodes), std::end(nodes), comparator);
            }
        }
    }

    // path is empty if no path from start to end is avaliable
    return path;
}
