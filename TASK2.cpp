#include <iostream>
#include <algorithm>
#include <time.h>   
using namespace std;
//function to shuffle rows
void swap(int a[4][3]){
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
}

//calculating mean and sum in rows
float calc(float a[4][3]){
    float mean[4];
    float sum[4];
    for(int i=0;i<4;i++){
        float rowsum=0;
       float rowmean=0;
        for(int j=0;j<3;j++){
          rowsum=rowsum+a[i][j];
           
        }
        sum[i]=rowsum;
      rowmean=rowsum/3;
        mean[i]=rowmean;
    }
   cout<<"Mean values of rows are"<<endl;
   for(int j=0 ;j<4;j++){
    cout<<mean[j]<<" ";
   }
   //signature for row
   float signature[4];
   for(int i=0;i<4;i++){
     signature[i]=mean[i]*sum[i];
   }
   for(int i=0;i<4;i++){
    cout<<signature[i]<<" ";
   }
}


int main() {
    float a[4][3] = {
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
    calc(a);
   //swap(a);





}