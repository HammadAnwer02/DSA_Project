#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "helper.h"
#include "Graph.h"

using namespace std;

struct Signature;

class DSA_Project
{
private:
    fstream input;
    fstream output;
    string inputFileName;
    string outputFileName;
    int rows;
    int cols;

    vector<vector<double>> inputData;
    vector<vector<double>> coorelationMatrix;
    vector<vector<int>> discretizedMatrix;
    unordered_map<int, Signature> signatures;    

    double correlationCoefficient(vector<double> &x, vector<double> &y, int size);
    void mean();
    void calc();
    void shuffling();

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

    Signature(double mean, double sum) {
        this->mean = mean;
        this->sum = sum;
    }
    
    void calcMean(int size) {
        this->mean = sum / size;
    }

    void calcSignature() {
        this->signature = this->mean * this->sum;
    }
};
