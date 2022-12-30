/**
 * @file DSAProject.h
 * @author Hammad Anwer 2021189, Mian Akbar Jan 2021295
 * @brief Stores the definition of the DSA_Projects class that has all the methods and attributes
 * @version 0.1
 * @date 2022-12-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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

// Store and calculate the signature values for each row the data


// Struct prototypes
struct Node;
struct Edge;
struct Cluster;

class DSA_Project
{
private:
    ifstream input; // stores the data for input file
    ofstream output; // stores the data for the output file
    int rows; // stores the number of rows of the data set
    int cols; // stores the number of cols of the data set

    vector<vector<double>> inputData;
    vector<vector<double>> permutedData;
    vector<vector<double>> coorelationMatrix;
    vector<vector<int>> permuatedCoorelation;
    vector<double> signatures;
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
    void getPermutatedCoorelation();

public:
    DSA_Project();
    void runtask1();
    void runtask2();
    void runtask3();
};

class Node
{
public:
    int x;
    int y;
    double weight;

    Node(int x = 0, int y = 0, double w = 0)
    {
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
    Edge(Node &from, Node &to, double weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

class Cluster
{
public:
    vector<Node> nodes;
    vector<Edge> edges;
};



