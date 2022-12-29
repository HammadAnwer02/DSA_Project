#include "DSAProject.h"

double DSA_Project::correlationCoefficient(vector<double> &x, vector<double> &y, int size)
{
    double sum_X = 0, sum_Y = 0, sum_XY = 0, squareSum_X = 0, squareSum_Y = 0, n = 0;
    n = size;

    for (int i = 0; i < size; i++)
    {
        sum_X = sum_X + x[i];
        sum_Y = sum_Y + y[i];
        sum_XY = sum_XY + (x[i] * y[i]);
        squareSum_X = squareSum_X + (x[i] * x[i]);
        squareSum_Y = squareSum_Y + (y[i] * y[i]);
    }

    double num = 0, den = 0;
    num = (n * sum_XY) - (sum_X * sum_Y);
    den = sqrt(((n * squareSum_X) - (sum_X * sum_X)) * ((n * squareSum_Y) - (sum_Y * sum_Y)));

    double correlation = 0;
    correlation = num / den;
    return correlation;
}
// this function is used to calculate mean of each column and replacing each element by 1 or 0
void DSA_Project::mean()
{

    for (int i = 0; i < rows; i++)
    {
        double sum = 0, mean = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += coorelationMatrix[j][i];
        }
        mean = sum / rows;
        for (int l = 0; l < rows; l++)
        {
            if (coorelationMatrix[l][i] >= mean)
            {
                coorelationMatrix[l][i] = 1;
            }
            else
            {
                coorelationMatrix[l][i] = 0;
            }
        }
    }
}

void DSA_Project::runtask1()
{

    input.open("data.txt", ios::in); // write your input txt file here
    if (!input)
    {
        cout << "No such file";
    }
    else
    {
        string line;
        int rows, cols;
        input >> rows;
        input >> cols;
        this->rows = rows;
        this->cols = cols;
        inputData.resize(rows);
        for (int row = 0; row < rows; row++)
        {
            inputData[row].resize(cols);
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                input >> inputData[i][j];
            }
        }
    }
    input.close();

    // file to store final output data

    output.open("Task1Output.txt");

    coorelationMatrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        coorelationMatrix[i].resize(cols);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            coorelationMatrix[i][j] = correlationCoefficient(inputData[i], inputData[j], cols);
        }
    }

    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            output << coorelationMatrix[i][j] << '\t';
        }
        output << endl;
    }

    output.close();
}

void DSA_Project::shuffling()
{
    srand(time(NULL));
    for (int i = 0; i < 150; i++)
    {
        int row = rand() % 150;
        for (int j = 0; j < 4; j++)
        {
            swap(inputData[i][j], inputData[row][j]);
        }
    }
}

// calculating mean and sum in rows
void DSA_Project::calc()
{
    for (int i = 0; i < rows; i++)
    {
        float rowsum = 0;
        float rowmean = 0;
        for (int j = 0; j < 4; j++)
        {
            rowsum = rowsum + inputData[i][j];
        }
        signatures[i].sum = rowsum;
        signatures[i].calcMean(cols);
        signatures[i].calcSignature();
    }

    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (signatures[j].signature < signatures[i].signature)
            {
                for (int k = 0; k < this->cols; k++)
                {
                    swap(inputData[i][k], inputData[j][k]);
                }
            }
        }
    }
}

void DSA_Project::runtask2()
{
    input.open("data.txt", ios::in);
    if (!input)
    {
        cout << "No such file";
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                input >> inputData[i][j];
            }
        }
    }
    input.close();
    cout << endl;

    shuffling();
    calc();

    // file to store final output data
    output.open("outputTASK2BeforeApplyring Task1.txt");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            output << inputData[i][j] << " \t";
        }
        output << endl;
    }
    output.close();

    output.open("outputTask2AfterDoingTask1.txt");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            coorelationMatrix[i][j] = correlationCoefficient(inputData[i], inputData[j], cols);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            output << coorelationMatrix[i][j] << '\t';
        }
        output << endl;
    }

    output.close();
}


void DSA_Project::runtask3()
{
    input.open("data.txt", ios::in);
    if (!input)
    {
        cout << "No such file";
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                input >> inputData[i][j];
            }
        }
    }
    input.close();
    cout << endl;

    shuffling();

    ofstream output("outputTask3(CoorelationMatrix).txt");
    for (size_t i = 0; i < 150; i++)
    {
        for (size_t j = 0; j < 150; j++)
        {
            coorelationMatrix[i][j] = correlationCoefficient(inputData[i], inputData[j], cols);
            output << coorelationMatrix[i][j] << " ";
            
        }
        output << endl;
    }
    output.close();
    cout << endl;



    cout << "Enter a threshold value for the edges: ";
    double threshold;
    cin >> threshold;
    for (size_t i = 0; i < 150; i++)
    {
        for (size_t j = 0; j < 150; j++)
        {
            if (coorelationMatrix[i][j] < threshold)
            {
                coorelationMatrix[i][j] = 0;
            }
        }
    }

    vector<double> nodeWeights;
    nodeWeights.resize(150);

    for (size_t i = 0; i < 150; i++)
    {
        double sumWeights = 0;
        for (size_t j = 0; j < 150; j++)
        {
            sumWeights += coorelationMatrix[i][j];
        }
        nodeWeights[i] = sumWeights;
    }

    vector<Cluster> clusters;

    
    while (!isEmptyClusters(nodeWeights))
    {
        auto maxElementIter = std::max_element(nodeWeights.begin(), nodeWeights.end());

        // Calculate the index of the maximum element using std::distance
        size_t maxElementIndex = std::distance(nodeWeights.begin(), maxElementIter);

        cout << "Your cluster is :\n";

        cout << "Node " << maxElementIndex << " with the value " << *maxElementIter << endl;

        cout << "The nodes adjacent to this are: \n\n";

        nodeWeights[maxElementIndex] = INT_MIN;
        Node maxNode(maxElementIndex, maxElementIndex);

        Cluster currCluster;

        currCluster.nodes.push_back(maxNode);

        for (size_t j = 0; j < 150; j++)
        {
            if (coorelationMatrix[maxElementIndex][j] != 0)
            {
                cout << "Node " << j << " with the value of " << coorelationMatrix[maxElementIndex][j] << endl;
                nodeWeights[j] = INT_MIN;
                Node connnectedNode(j, j);
                Edge edgetoMax(maxNode, connnectedNode, coorelationMatrix[maxElementIndex][j]);
                currCluster.edges.push_back(edgetoMax);
                currCluster.nodes.push_back(connnectedNode);
            }
        }
        clusters.push_back(currCluster);

        std::this_thread::sleep_for(std::chrono::seconds(5));

    }

}