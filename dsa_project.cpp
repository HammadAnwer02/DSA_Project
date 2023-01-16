#include "dsa_project.h"
#include <QDebug>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QInputDialog>
#include <QMainWindow>
#include <QThread>
DSA_Project::DSA_Project()
{
    rows = cols = 0;
}

bool DSA_Project::isEmptyClusters()
{
    for (int i = 0; i < nodeWeights.size(); i++)
        if (nodeWeights[i] > INT_MIN)
            return false;

    return true;
}

void DSA_Project::readFileData(string filename)
{
    input.open(filename);
    if (!input.is_open())
    {
        cout << "Unable to open file " << filename << endl;
        return;
    }
    else
    {
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
}

void DSA_Project::outputCoorelationToFile(string filename)
{
    output.open(filename, ios::out);
    if (!output.is_open())
    {
        cout << "Unable to open file " << filename << endl;
        return;
    }
    else
    {
        for (auto &row : coorelationMatrix)
        {
            for (double i : row)
            {

                output << i << '\t';
            }
            output << endl;
        }

        output.close();
    }
}

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

void DSA_Project::getCoorelationMatrix()
{
    coorelationMatrix.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        coorelationMatrix[i].resize(rows);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            coorelationMatrix[i][j] = correlationCoefficient(inputData[i], inputData[j], cols);
        }
    }
}

void DSA_Project::runtask1()
{

    readFileData("data.txt");

    getCoorelationMatrix();
    mean();
    outputCoorelationToFile("Task1Output.txt");
showtask1();
}

void DSA_Project::shuffling()
{
    random_device rd;
    mt19937 gen(rd());
    shuffle(inputData.begin(), inputData.end(), gen);
}

// calculating mean and sum in rows
void DSA_Project::calc()
{
    signatures.resize(150);
        for (int i = 0; i < rows; i++)
        {
            double rowsum = 0;
            double rowmean = 0;
            rowsum = accumulate(inputData[i].begin(), inputData[i].end(), 0);
            rowmean = rowsum / cols;
            signatures[i] = rowmean * rowsum;
        }

        for (int i = 0 ; i < rows - 1; i++) {
            for (int j = i + 1; j < rows; j++) {
                if (signatures[j] < signatures[i]) {
                    for (int k = 0; k < cols; k++) {
                        swap(inputData[i][k], inputData[j][k]);
                    }
                    swap(signatures[j], signatures[i]);
                }
            }
        }
}

void DSA_Project::runtask2()
{
    readFileData("data.txt");
    cout << endl;

    shuffling();
    calc();

    // file to store final output data
    output.open("outputTASK2BeforeApplyringTask1.txt");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            output << inputData[i][j] << " \t";
        }
        output << endl;
    }
    output.close();
    qDebug() << "1";

getCoorelationMatrix();
qDebug() << "4";
mean();
qDebug() << "5";
outputCoorelationToFile("outputTask2AfterDoingTask1.txt");
    display();
}
void DSA_Project::getPermutatedMean() {
    for (int i = 0; i < rows; i++)
    {
        double sum = 0, mean = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += permuatedCoorelation[j][i];
        }
        mean = sum / rows;
        for (int l = 0; l < rows; l++)
        {
            if (permuatedCoorelation[l][i] >= mean)
            {
                permuatedCoorelation[l][i] = 1;
            }
            else
            {
                permuatedCoorelation[l][i] = 0;
            }
        }
    }
}
void DSA_Project::getPermutatedCoorelation() {
    permuatedCoorelation.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        permuatedCoorelation[i].resize(rows);
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            permuatedCoorelation[i][j] = correlationCoefficient(permutedData[i], permutedData[j], cols);
        }
    }
}
void DSA_Project::editMatrixBasedOnThreshold()
{
    // Create a pop-up window to get the threshold value from the user
    bool ok;
    double threshold = QInputDialog::getDouble(this, "Threshold Value", "Enter a threshold value for the edges:", 0, -2147483647, 2147483647, 4, &ok);

    // If the user clicked the "OK" button and entered a valid threshold value, update the coorelation matrix
    if (ok)
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < rows; j++)
            {
                if (coorelationMatrix[i][j] < threshold)
                {
                    coorelationMatrix[i][j] = 0;
                }
            }
        }
    }
}

void DSA_Project::setNodeWeights()
{
    nodeWeights.resize(rows);
    for (size_t i = 0; i < rows; i++)
    {
        nodeWeights[i] = accumulate(coorelationMatrix[i].begin(), coorelationMatrix[i].end(), 0);
    }
}

void DSA_Project::setClusters()
{

    while (!isEmptyClusters())
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


    }
}

void DSA_Project::runtask3()
{
    readFileData("data.txt");
    shuffling();
    getCoorelationMatrix();
    outputCoorelationToFile("outputTask3(CoorelationMatrix).txt");
    editMatrixBasedOnThreshold();
    setNodeWeights();

    setClusters();
    displayGraph();
}

void DSA_Project::showtask1()
{
    display();
}

void DSA_Project::display(){

    QImage greenImage(150, 150, QImage::Format_RGB888);
    try
    {
    // Set all pixels to green
    for (int i = 0; i < greenImage.height(); i++)
    {
    for (int j = 0; j < greenImage.width(); j++)
    {
    if (coorelationMatrix[i][j] == 1)
    {
    greenImage.setPixel(i, j, qRgb(0, 254, 0));
    }
    else if (coorelationMatrix[i][j] == 0)
    {
    greenImage.setPixel(i, j, qRgb(0, 150, 0));
    }
    }
    }
    }
    catch (const std::out_of_range &exception)
    {
    qDebug() << "Out of range" << exception.what();
    }
    QImage greyImage(150, 150, QImage::Format_RGB888);
    try
    {
        // Set all pixels to grey
        for (int i = 0; i < greyImage.height(); i++)
        {
            for (int j = 0; j < greyImage.width(); j++)
            {
                if (coorelationMatrix[i][j] == 1)
                {
                greyImage.setPixel(i, j, qRgb(254,254, 254));
                }
                else if (coorelationMatrix[i][j] == 0)
                {
                greyImage.setPixel(i, j, qRgb(0, 0, 0));
                }
            }
        }
    }
    catch (const std::out_of_range &exception)
    {
        qDebug() << "Out of range" << exception.what();
    }
//    QImage greenPermute(150, 150, QImage::Format_RGB888);
//    try
//    {
//    // Set all pixels to green
//    for (int i = 0; i < greenImage.height(); i++)
//    {
//    for (int j = 0; j < greenImage.width(); j++)
//    {
//    if (permuatedCoorelation[i][j] == 1)
//    {
//    greenImage.setPixel(i, j, qRgb(0, 254, 0));
//    }
//    else if (permuatedCoorelation[i][j] == 0)
//    {
//    greenImage.setPixel(i, j, qRgb(0, 150, 0));
//    }
//    }
//    }
//    }
//    catch (const std::out_of_range &exception)
//    {
//    qDebug() << "Out of range" << exception.what();
//    }
//    QImage greyPermute(150, 150, QImage::Format_RGB888);
//    try
//    {
//        // Set all pixels to grey
//        for (int i = 0; i < greyImage.height(); i++)
//        {
//            for (int j = 0; j < greyImage.width(); j++)
//            {
//                if (permuatedCoorelation[i][j] == 1)
//                {
//                greyImage.setPixel(i, j, qRgb(254,254, 254));
//                }
//                else if (permuatedCoorelation[i][j] == 0)
//                {
//                greyImage.setPixel(i, j, qRgb(0, 0, 0));
//                }
//            }
//        }
//    }
//    catch (const std::out_of_range &exception)
//    {
//        qDebug() << "Out of range" << exception.what();
//    }

    // Create a QGraphicsView to display the images
    QGraphicsView *view = new QGraphicsView();
    view->setRenderHint(QPainter::Antialiasing);
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Set the image as the background image for the view
    QGraphicsScene *scene = new QGraphicsScene();
    // Add the green image to the left side of the scene
    scene->addPixmap(QPixmap::fromImage(greenImage))->setPos(-200, -200);
    // Add the grey image to the right side of the scene
    scene->addPixmap(QPixmap::fromImage(greyImage))->setPos(200, -200);
//    scene->addPixmap(QPixmap::fromImage(greenPermute))->setPos(-200, 200);
//    // Add the grey image to the right side of the scene
//    scene->addPixmap(QPixmap::fromImage(greyPermute))->setPos(200,200);
    view->setScene(scene);
        // Create + and - buttons
//        QPushButton *buttonPlus = new QPushButton("+");
//        buttonPlus->setMaximumWidth(40);
//        QPushButton *buttonMinus = new QPushButton("-");
//        buttonMinus->setMaximumWidth(40);

//        // Connect buttons to zoom functions
//        connect(buttonPlus, &QPushButton::clicked, this, &DSA_Project::zoomIn(view));
//        connect(buttonMinus, &QPushButton::clicked, this, &DSA_Project::zoomOut(view));

//        // Add buttons to a layout
//        QHBoxLayout *buttonLayout = new QHBoxLayout();
//        buttonLayout->addStretch();
//        buttonLayout->addWidget(buttonPlus);
//        buttonLayout->addWidget(buttonMinus);
//        buttonLayout->addStretch();

//        // Add the view and button layout to the main layout
//        QVBoxLayout *mainLayout = new QVBoxLayout();
//        mainLayout->addWidget(view);
//        mainLayout->addLayout(buttonLayout);
//        setLayout(mainLayout);
    // Show the view in full screen mode
    view->showFullScreen();
    view->show();
}



void DSA_Project::displayGraph(){
    int nodeRadius= 5;
    QMainWindow* window = new QMainWindow;

    // Create a QGraphicsView widget and a QGraphicsScene
    QGraphicsView* view = new QGraphicsView;
    QGraphicsScene* scene = new QGraphicsScene;
    int color = 0;
qDebug() <<clusters.size();
    // Iterate through the clusters and create a QGraphicsItem for each node and edge
    for (const auto& cluster : DSA_Project::clusters) {

        // Create a QGraphicsEllipseItem for each node in the cluster
        for (const auto& node : cluster.nodes) {
            QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(node.x - nodeRadius, node.y - nodeRadius, 2 * nodeRadius, 2 * nodeRadius);
            if (color==0){
                ellipse->setBrush(QBrush(Qt::black));  // Set the fill color
            }
            else if(color==1) {
                ellipse->setBrush(QBrush(Qt::red));
            }
            else if(color==2){
                ellipse->setBrush(QBrush(Qt::green));
            }
            ellipse->setPen(QPen(Qt::black));  // Set the outline color and width
            scene->addItem(ellipse);
        }

        // Create a QGraphicsLineItem for each edge in the cluster
        for (const auto& edge : cluster.edges) {
            QLineF line(edge.from.x, edge.from.y, edge.to.x, edge.to.y);
            QGraphicsLineItem* lineItem = new QGraphicsLineItem(line);
            lineItem->setPen(QPen(Qt::black, edge.weight));  // Set the pen style, width, and color
            scene->addItem(lineItem);
        }
        color++;
    }

    // Set the scene for the view and add the view to the layout
    view->setScene(scene);

    // Set the view as the central widget of the main window
    window->setCentralWidget(view);

    // Show the main window
    window->show();
    window->showFullScreen();
}





