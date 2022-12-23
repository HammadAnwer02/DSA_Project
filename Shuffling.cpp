#include <iostream>
#include <algorithm>
#include <time.h>   

using namespace std;

int main() {
    int a[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
        
    };

    cout << "Before swapping rows:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int row = rand() % 4;
        for (int j = 0; j < 3; j++) {
            swap(a[i][j], a[row][j]);
        }
    }

    cout << "After swapping rows:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
