//toplogical sort, union find, trie, Graph

// A C++ program to print topological
// sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;
 
// Class to represent a graph
class Graph {
    // No. of vertices'
    int V;
 
    // Pointer to an array containing adjacency listsList
    list<int>* adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
 
public:
    // Constructor
    Graph(int V);
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}

// edge structure
struct Edge
{
    int source;
    int target;
};

// bfs topological sort
std::vector<int> Topological_Sort_bfs(std::vector<Edge> &edges)
{
    // hash table for all outgoing edges
    std::unordered_map<int, vector<int>> umap;

    for (auto &edge : edges)
    {
        umap[edge.source].push_back(edge.target);
    }

    unsigned int num_vertices = umap.size();
    unsigned int indegree[num_vertices];
    memset(indegree, 0, num_vertices * sizeof(unsigned int));

    // fill indegrees
    for (auto &itr : umap)
    {
        for (auto &v : itr.second)
           ++indegree[v]; 
    }

    // push vertices with no incoming edges to queue
    std::queue<int> vq;
    for (int i = 0; i < num_vertices; ++i)
        if (indegree[i] == 0)
            vq.push(i);

    // pop all vertices from queue
    // deduct tagerts' indegree by one 
    // if a vertex's indgree become 0, push it to the queue
    std::vector<int> result;    
    while (!vq.empty())
    {
        int v = vq.front();
        vq.pop();
        result.push_back(v);

        for (auto &u : umap[v])
        {
            --indegree[u];
            if (indegree[u] == 0)
                vq.push(u);
        }
    }
    
    // if not all vertices are in the queue, there's one or more cycles.
    if (result.size() == num_vertices)
        return result;
    else
        return {};
}

// dfs topological sort
#define NOT_VISITED 0
#define TEMP_VISITED 1
#define VISITED 2
std::vector<int> result;

bool is_cyclic(std::unordered_map<int, std::vector<int> > &umap, std::vector<int> &visited, int vertex)
{
    if (visited[vertex] == TEMP_VISITED)
        return true;

    visited[vertex] = TEMP_VISITED;

    for (auto & itr : umap[vertex])
    {
        if (visited[itr] != VISITED && is_cyclic(umap, visited, itr))
            return true;
    }

    visited[vertex] = VISITED;
    result.push_back(vertex);

    return false;
}

std::vector<int> Topological_Sort_dfs(std::vector<Edge> &edges)
{
    // hash table for all outgoing edges
    std::unordered_map<int, vector<int>> umap;

    for (auto &edge : edges)
    {
        umap[edge.source].push_back(edge.target);
    }

    unsigned int num_vertices = umap.size();
    std::vector<int> visited(num_vertices, NOT_VISITED);

    // dfs. If there is a cycle, return empty vector to indicate errors.
    for (unsigned int i = 0; i < num_vertices; ++i)
        if (visited[i] == NOT_VISITED && is_cyclic(umap, visited, i))
            return {};
   
    return result;
}
