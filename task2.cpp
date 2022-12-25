#include <iostream>
#include <algorithm>
#include <time.h>
#include <fstream>
using namespace std;

// function to shuffle rows
void shuFFleing(float a[150][4])
{ 
    // uncooment to see output on console
    /* cout << "Before shuffling rows:" << endl;
    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl
         << endl; */

    srand(time(NULL));
    for (int i = 0; i < 150; i++)
    {
        int row = rand() % 150;
        for (int j = 0; j < 4; j++)
        {
            swap(a[i][j], a[row][j]);
        }
    }
    // uncooment to see output on console
    /* cout << "After shuffling rows:" << endl;
    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl
         << endl; */
}

// calculating mean and sum in rows
void calc(float a[150][4])
{
    float mean[150];
    float sum[150];
    for (int i = 0; i < 150; i++)
    {
        float rowsum = 0;
        float rowmean = 0;
        for (int j = 0; j < 4; j++)
        {
            rowsum = rowsum + a[i][j];
        }
        sum[i] = rowsum;
        rowmean = rowsum / 3;
        mean[i] = rowmean;
    }
    cout << "Mean values of rows are" << endl;
    for (int j = 0; j < 150; j++)
    {
        cout << mean[j] << '\t';
    }
    cout << endl
         << endl;

    // signature for each row
    float signature[150];
    for (int i = 0; i < 150; i++)
    {
        signature[i] = mean[i] * sum[i];
    }

    // uncooment to see output on console
    /* cout << "Signature values of rows are" << endl;
    for (int i = 0; i < 150; i++)
    {
        cout << signature[i] << '\t';
    }
    cout << endl
         << endl; */

    float smallest;
    for (int i = 0; i < 149; i++)
    {
        smallest = 1000;
        for (int j = 0; j < 150; j++)
        {
            if (signature[j] < smallest)
            {
                smallest = signature[j];
            }
        }
        for (int k = 0; k < 150; k++)
        {
            if (signature[k] == smallest)
            {
                swap(a[i], a[k]);
                signature[k] == 10000;
            }
        }
    }
    cout << "Task 2 output: " << endl;
    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

int main()
{
    float a[150][4];
    fstream input;
    input.open("data.txt", ios::in);
    if (!input)
    {
        cout << "No such file";
    }
    else
    {
        for (int i = 0; i < 150; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                input >> a[i][j];
            }
        }
    }
    input.close();
    cout << endl;

    shuFFleing(a);
    calc(a);

    // file to store final output data
    ofstream myfile;
    myfile.open("outputTASK2.txt");
    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            myfile << a[i][j] << " \t";
        }
        myfile << endl;
    }
    myfile.close();

    return 0;
}