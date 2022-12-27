#include <iostream>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cctype>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

// function to shuffle rows
void shuFFleing(vector<vector<double>> &a)
{
    srand(time(NULL));
    int rows = a.size();
    int cols = a[0].size();
    for (int i = 0; i < rows; i++)
    {
        int row = rand() % rows;
        for (int j = 0; j < cols; j++)
        {
            swap(a[i][j], a[row][j]);
        }
    }
}

struct Signature
{
    double mean;
    double sum;
    double signature;

    void findSignature()
    {
        signature = mean * sum;
    }
    Signature(int m = 0, int s = 0)
    {
        mean = m;
        sum = s;
    }
};

// calculating mean and sum in rows
void calc(vector<vector<double>> &a)
{

    int rows = a.size();
    int cols = a[0].size();

    vector<Signature> signatures;
    signatures.resize(rows);

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            signatures[i].sum += a[i][j];
        }
        signatures[i].mean = signatures[i].sum / 4;
        signatures[i].findSignature();
    }

    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (signatures[j].signature < signatures[i].signature)
            {
                for (int k = 0; k < 4; k++)
                {
                    swap(a[i][k], a[j][k]);
                }
                swap(signatures[j], signatures[i]);
            }
        }
    }
    cout << "Task 2 output: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << signatures[i].signature << '\t';
        cout << endl;
    }
    cout << endl
         << endl;
}

struct Pearson
{
    double sum_X;
    double sum_Y;
    double sum_XX;
    double sum_YY;
    double sum_XY;
    double n;
    double squareSum_X;
    double squareSum_Y;

    Pearson(int sz)
    {
        n = sz;
        sum_X = sum_Y = sum_XX = sum_YY = sum_XY = squareSum_X = squareSum_Y = 0;
    }

    double getCoorelationCoeff()
    {
        double num = 0, den = 0;
        num = (n * sum_XY) - (sum_X * sum_Y);
        den = std::sqrt(((n * squareSum_X) - (sum_X * sum_X)) * ((n * squareSum_Y) - (sum_Y * sum_Y)));

        return num / den;
    }
};

double pearson(const std::vector<double>& x, const std::vector<double>& y)
{
  // Check that the two sets of data have the same number of elements
  if (x.size() != y.size())
  {
    std::cerr << "Error: sets of data have different sizes" << std::endl;
    return 0;
  }

  size_t n = x.size();

  double sum_xy = 0;
  double sum_x = 0;
  double sum_y = 0;
  double sum_x2 = 0;
  double sum_y2 = 0;

  // Calculate the sums
  for (size_t i = 0; i < n; i++)
  {
    sum_xy += x[i] * y[i];
    sum_x += x[i];
    sum_y += y[i];
    sum_x2 += x[i] * x[i];
    sum_y2 += y[i] * y[i];
  }

  // Calculate the Pearson correlation coefficient
  
  double r = (n * sum_xy - sum_x * sum_y) /
             std::sqrt((n * sum_x2 - sum_x * sum_x) * (n * sum_y2 - sum_y * sum_y));

  return r;
}


bool isEmptyClusters(vector<double> &nodeWeights) {
    for (size_t i = 0; i < nodeWeights.size(); i++)
    {
        if (nodeWeights[i] > INT_MIN)
            return false;
    }

    return true;
    
}