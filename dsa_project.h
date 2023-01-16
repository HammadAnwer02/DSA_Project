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
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QImage>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QLayout>
#include <QGraphicsView>
using namespace std;

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
struct Node;
struct Edge;
struct Cluster;


class DSA_Project : public QWidget
{
private:
    fstream input;
    fstream output;
    int rows;
    int cols;

    vector<vector<double>> inputData;
    vector<vector<double>> coorelationMatrix;
    vector<vector<int>> discretizedMatrix;
    vector<double>signatures;
    vector<double> nodeWeights;
    vector<Cluster> clusters;
vector<vector<double>> permutedData;
vector<vector<double>> permuatedCoorelation;
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
    void getPermutatedMean();
//    QGraphicsView *view;
friend class task1;
public:
    DSA_Project();
public slots:
    void runtask1();
    void runtask2();
    void runtask3();
    void showtask1();
    void display();
    void displayGraph();
    void displayPermute();
private slots:
//    void zoomIn(QGraphicsView *view);
//    void zoomOut(QGraphicsView *view);

};




class Node {
    public:
    int x;
    int y;
    double weight;

    Node(int x = 0, int y = 0, double w = 0) {
        this->x = x*20;
        this->y = y*10;
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
