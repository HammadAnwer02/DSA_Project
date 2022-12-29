#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <numeric>


using namespace std;

struct Signature;
struct Node;
struct Edge;
struct Cluster;


class DSA_Project
{
private:
    fstream input;
    fstream output;
    int rows;
    int cols;

    vector<vector<double>> inputData;
    vector<vector<double>> coorelationMatrix;
    vector<vector<int>> discretizedMatrix;
    unordered_map<int, Signature> signatures;   
    vector<double> nodeWeights; 
    vector<Cluster> clusters;

    double correlationCoefficient(vector<double> &x, vector<double> &y, int size);
    void mean();
    void calc();
    void shuffling();

    void readFileData(string filename);
    void outputCoorelationToFile(string filename);
    void getCoorelationMatrix();
    void editMatrixBasedOnThreshold();
    void setNodeWeights();  
    void setClusters();
    bool isEmptyClusters();

public:
    DSA_Project();
    void runtask1();
    void runtask2(); 
    void runtask3();
};


struct Signature {
    double mean;
    double sum;
    double signature;

    Signature(double mean = 0, double sum = 0) {
        this->mean = mean;
        this->sum = sum;
        this->signature = 0;
    }
    
    void calcMean(int size) {
        this->mean = this->sum / size;
    }

    void calcSignature() {
        this->signature = this->mean * this->sum;
    }
};

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





