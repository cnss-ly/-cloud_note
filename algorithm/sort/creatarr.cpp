#include<iostream>
using namespace std;
class array{
    public:
        int n = 0;
        float *arr = new float[n];
        array(int temp): n(temp){}
        void create();
        void printarr();
        // virtual void bubulesort() = 0;
        // virtual void bucketsort() = 0;
        // virtual void countingsort() = 0;
        // virtual void heapsort() = 0;
        // virtual void insertionsort() = 0;
        // virtual void mergesort() = 0;
        // virtual void quicksort() = 0;
        // virtual void radixsort() = 0;
        // virtual void selectionsort() = 0;
        // virtual void shellsort() = 0;
};
void array::create(){
    int i=0;
    int j=n;
    while (j){
        j--;
        cin >> *(arr+i);
        i++;
    }
}
void array::printarr(){
    int i=0;
    int j=n;
    while (j){
        j--;
        cout << *(arr+i) << ' ';
        i++;
    }
    cout << endl;
};

// int main(){
//     array test(15);
//     test.create();
//     test.printarr();
// }