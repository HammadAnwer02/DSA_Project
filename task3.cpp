#include "helper.h"

int main()
{

    std::vector<std::vector<float>> data;
    data.resize(150);
    for (auto &row : data)
    {
        row.resize(4);
    }
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
                input >> data[i][j];
            }
        }
    }
    input.close();
    cout << endl;

    shuFFleing(data);


    vector<vector<float>> coeff;
    coeff.resize(150);
    for (auto &row : coeff)
    {
        row.resize(150);
    }
    
    for (size_t i = 0; i < 150; i++)
    {
        for (size_t j = 0; j < 150; j++)
        {
            coeff[i][j] = correlationCoefficient(data[i], data[j], 4);
        }
    }

    cout << "Enter a threshold value for the edges: ";
    float threshold;
    cin >> threshold;
    for (size_t i = 0; i < 150; i++)
    {
        for (size_t j = 0; j < 150; j++)
        {
            if (coeff[i][j] < threshold) {
                coeff[i][j] = 0;
            }
        }
        
    }
    

    vector <float> nodeWeights;
    nodeWeights.resize(150);

    for (size_t i = 0; i < 150; i++)
    {
        float sumWeights = 0;
        for (size_t j = 0; j < 150; j++)
        {
            sumWeights += coeff[i][j];
        }
        nodeWeights[i] = sumWeights;
    }

    auto maxElementIter = std::max_element(nodeWeights.begin(), nodeWeights.end());

    // Calculate the index of the maximum element using std::distance
    size_t maxElementIndex = std::distance(nodeWeights.begin(), maxElementIter);

    cout << "Your cluster is :\n";

    cout << "Node " << maxElementIndex << " with the value " << *maxElementIter << endl;

    cout << "The nodes adjacent to this are: \n\n";


    for (size_t j = 0; j < 150; j++)
    {
        if (coeff[maxElementIndex][j] != 0) {
            cout << "Node " << j << " with the value of " << coeff[maxElementIndex][j] << endl;
        }
    }


    
    // // file to store final output data
    // ofstream myfile;
    // myfile.open("outputTASK2.txt");
    // for (int i = 0; i < 150; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         myfile << data[i][j] << " \t";
    //     }
    //     myfile << endl;
    // }
    // myfile.close();

    return 0;
}