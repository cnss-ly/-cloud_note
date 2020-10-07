#include "creatarr.cpp"
using namespace std;
class Radix: public array{
    public:
        Radix(int temp): array(temp){}
        void radixsort();
    private:
        float **radix = new float*[10];
        int *count = new int[10]();
        void createradix();
};
void Radix::createradix(){
    int i;
    for (i=0; i<10; i++){
        radix[i] = new float[n];
    }
}
void Radix::radixsort(){
    createradix();
    int i, j, k=0;
    int temp, tmp;
    for (i = 0; i < n; i++){
        temp = int(arr[i]) % 10;
        tmp = count[temp];
        radix[temp][tmp] = arr[i];
        count[temp]++;
    }
    // for (i = 0; i < 9; i++){
    //     cout << count[i] << " ";
    // }
    // cout << endl;
    for (i = 0; i < 10; i++){
        for (j = 0; j < count[i]; j++){
            arr[k] = radix[i][j];
            k++;
            // cout << radix[i][j] << " ";
        }
        count[i] = 0;
    }
    for (i = 0; i < n; i++){
        temp = int(arr[i])/10;
        tmp = count[temp];
        radix[temp][tmp] = arr[i];
        count[temp]++;
    }
    k = 0;
    for (i = 0; i < 10; i++){ 
        for (j = 0; j < count[i]; j++){
            arr[k] = radix[i][j];
            k++;
            // cout << radix[i][j] << " ";
        }
    }
    cout << endl;
}
int main(){
    Radix test(10);
    test.create();
    test.printarr();
    test.radixsort();
    test.printarr();
    return 0;
}