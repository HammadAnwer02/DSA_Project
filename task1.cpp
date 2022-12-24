#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
#include <time.h>
using namespace std;

// this function is used to calculate Pearson’s correlation coefficient
float correlationCoefficient(float x[], float y[], float size)
{
    float sum_X = 0, sum_Y = 0, sum_XY = 0, squareSum_X = 0, squareSum_Y = 0, n = 0;
    n = size;

    for (int i = 0; i < size; i++)
    {
        sum_X = sum_X + x[i];
        sum_Y = sum_Y + y[i];
        sum_XY = sum_XY + (x[i] * y[i]);
        squareSum_X = squareSum_X + (x[i] * x[i]);
        squareSum_Y = squareSum_Y + (y[i] * y[i]);
    }

    float num = 0, den = 0;
    num = (n * sum_XY) - (sum_X * sum_Y);
    den = sqrt(((n * squareSum_X) - (sum_X * sum_X)) * ((n * squareSum_Y) - (sum_Y * sum_Y)));

    float correlation = 0;
    correlation = num / den;
    return correlation;
}

// this function is used to calculate mean of each column and replacing each element by 1 or 0
void mean(float a[][150])
{
    for (int i = 0; i < 150; i++)
    {
        float sum = 0, mean = 0;
        for (int j = 0; j < 150; j++)
        {
            sum = sum + a[j][i];
        }
        mean = sum / 150;
        for (int l = 0; l < 150; l++)
        {
            if (a[l][i] > mean)
            {
                a[l][i] = 1;
            }
            else if (a[l][i] < mean)
            {
                a[l][i] = 0;
            }
        }
    }
}

int main()
{

    float **a;

    // storing input data in a matrix/2d array
    fstream input;
    input.open("data.txt", ios::in); //write your input txt file here
    if (!input)
    {
        cout << "No such file";
    }
    else
    {
        string line;
        int rows,cols;
        input >> rows;
        input >> cols;  
        a = new float*[rows];
        for (int row=0; row<rows; row++){
            a[row]= new float[cols]; 
        }
        cout << rows << " " << cols;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                input >> a[i][j];
            }
        }
    }
    input.close();

    // file to store final output data
    ofstream myfile;
    myfile.open("output.txt");

    float coef[150][150];

    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 150; j++)
        {
            coef[i][j] = correlationCoefficient(a[i], a[j], 4);
        }
    }

    cout << endl;

    mean(coef);


    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 150; j++)
        {
            myfile << coef[i][j] << '\t';
        }
        myfile << endl;
    }

    myfile.close();
    return 0;
}
