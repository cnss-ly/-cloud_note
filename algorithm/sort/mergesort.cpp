#include "creatarr.cpp"
using namespace std;
class Merge: public array{
    public:
        Merge(int temp): array(temp){};
        void mergesort(float*, int);
        void merge(float*, float*, float*, int, int);
};
void Merge::merge(float* _arr, float *leftarr, float *rightarr, int rightlen, int leftlen){
    int i=0, j=0, k=0;
    while (i < leftlen && j < rightlen){
        if (*(leftarr+i) <= *(rightarr+j)){
            *(_arr+k) = *(leftarr+i);
            i++;
        }
        else{
            *(_arr+k) = *(rightarr+j);
            j++;
        }
        k++;
    }
    while (j < rightlen){
        *(_arr + k) = *(rightarr + j);
        k++;
        j++;
    }
    cout << k <<"*"<< j << endl;
    while (i < leftlen){
        *(_arr+k) = *(leftarr+i);
        k++;
        i++;  
    }
}

void Merge::mergesort(float *_arr, int len){
    if (len < 2)
        return;
    int middlen = len/2;
    float *leftarr, *rightarr;
    rightarr = new float[len - middlen];
    leftarr = new float[middlen];
    int i;
    for (i = 0; i < middlen; i++){
        *(leftarr + i) = *(_arr + i);
    }
    for (i = middlen; i < len; i++){
        *(rightarr + i - middlen) = *(_arr + i);
    }
    mergesort(leftarr, middlen);
    mergesort(rightarr, len-middlen);
    merge(_arr, leftarr, rightarr, len-middlen, middlen);
}

int main(){
    Merge test(4);
    test.create();
    test.printarr();
    test.mergesort(test.arr, test.n);
    test.printarr();
    return 0;
}

/* Merge sort in C++ */
