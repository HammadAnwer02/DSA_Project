#include <vector>

using namespace std;


class Node {
    public:
    int x;
    int y;
    double weight;

    Node(int x = 0, int y = 0, double w = 0) {
        this->x = x;
        this->y = y;
    }
};

class Edge
{
    public:
    Node from;
    Node to;
    float weight;
    Edge(Node &from, Node &to, double weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

class Cluster {
    public:
    vector<Node> nodes;
    vector<Edge> edges;  
};


