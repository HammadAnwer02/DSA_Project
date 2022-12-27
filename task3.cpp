#include "helper.h"
#include "Graph.h"

int main()
{

    std::vector<std::vector<double>> data;
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

    vector<vector<double>> coeff;
    coeff.resize(150);
    for (auto &row : coeff)
    {
        row.resize(150);
    }

    ofstream output("outputmatrix.txt");
    for (size_t i = 0; i < 150; i++)
    {
        for (size_t j = 0; j < 150; j++)
        {
            coeff[i][j] = pearson(data[i], data[j]);
            output << coeff[i][j] << " ";
            
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
            if (coeff[i][j] < threshold)
            {
                coeff[i][j] = 0;
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
            sumWeights += coeff[i][j];
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
            if (coeff[maxElementIndex][j] != 0)
            {
                cout << "Node " << j << " with the value of " << coeff[maxElementIndex][j] << endl;
                nodeWeights[j] = INT_MIN;
                Node connnectedNode(j, j);
                Edge edgetoMax(maxNode, connnectedNode, coeff[maxElementIndex][j]);
                currCluster.edges.push_back(edgetoMax);
                currCluster.nodes.push_back(connnectedNode);
            }
        }
        clusters.push_back(currCluster);

        std::this_thread::sleep_for(std::chrono::seconds(5));

    }

    

    return 0;
}