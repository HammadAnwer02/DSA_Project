#include <iostream>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

// function to shuffle rows
// float signature[150];
void shuFFleing(vector<vector<float>> &a)
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
    float mean;
    float sum;
    float signature;

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
void calc(vector<vector<float>> &a)
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
    float sum_X;
    float sum_Y;
    float sum_XX;
    float sum_YY;
    float sum_XY;
    float n;
    float squareSum_X;
    float squareSum_Y;

    Pearson(int sz)
    {
        n = sz;
        sum_X = sum_Y = sum_XX = sum_YY = sum_XY = squareSum_X = squareSum_Y = 0;
    }

    float getCoorelationCoeff()
    {
        float num = 0, den = 0;
        num = (n * sum_XY) - (sum_X * sum_Y);
        den = std::sqrt(((n * squareSum_X) - (sum_X * sum_X)) * ((n * squareSum_Y) - (sum_Y * sum_Y)));

        return num / den;
    }
};

float correlationCoefficient(vector<float> &x, vector<float> &y, float size)
{
    Pearson pearson(size);

    for (int i = 0; i < size; i++)
    {
        pearson.sum_X += x[i];
        pearson.sum_Y += y[i];
        pearson.sum_XX += x[i] * x[i];
        pearson.sum_YY += y[i] * y[i];
        pearson.sum_XY += x[i] * y[i];
        pearson.squareSum_X += (x[i] * x[i]);
        pearson.squareSum_Y += (y[i] * y[i]);
    }

    return pearson.getCoorelationCoeff();
}