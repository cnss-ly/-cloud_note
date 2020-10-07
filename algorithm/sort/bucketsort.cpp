#include "creatarr.cpp"
using namespace std;
class Bucket: public array{
    public:
        int size;
        Bucket(int temp, int tmp): array(temp), size(tmp){}
        void bucketsort();
        void quicksort(float *, int, int);

    private:
        float min,max;
        void getminmax();
};
void Bucket::getminmax(){
    float temp;
    min = arr[0], max = arr[0];
    for (int i = 0; i < n; i++){
        temp = arr[i];
        if (temp > max){
            max = temp;
        }
        if (temp < min){
            min = temp;
        }
    }
}
void Bucket::quicksort(float* temparr, int right, int left = 0){
    if (left >= right)
        return;
    int i = left, j = right;
    float criterion = temparr[i], temp;
    while (j > i){
        while (temparr[j] >= criterion && j > i)
            j--;
        while (temparr[i] <= criterion && j > i)
            i++;
        if (j > i){
            temp = temparr[j];
            temparr[j] = temparr[i];
            temparr[i] = temp;
        }
    }
    temparr[left] = temparr[i];
    temparr[i] = criterion;
    quicksort(temparr, i-1, left);
    quicksort(temparr, right, i+1);
}
void Bucket::bucketsort(){
    getminmax();
    int i, index, temp;
    int num = (max - min) / size + 1;
    float **buckets = new float *[num];
    int *count = new int[num]();
    for (i = 0; i < num; i++){
        buckets[i] = new float[size];
    }
    for (i=0; i < n; i++){
        index = (arr[i] - min) / size;
        temp = count[index];
        buckets[index][temp] = arr[i];
        count[index]++;
    }
    // for (i=0; i<num; i++){
    //     cout << count[i] << " ";
    // }
    // cout << endl;
    for (i = 0; i < num; i++){
        quicksort(buckets[i], count[i]-1);
    }
    int k = 0;
    for (i=0; i<num; i++){
        for (int j=0; j<count[i]; j++){
            arr[k] = buckets[i][j];
            k++;
            // cout << buckets[i][j] << " ";
        }
    }
    // cout << endl;
}
int main(){
    Bucket test(10,3);
    test.create();
    test.printarr();
    test.bucketsort();
    test.printarr();
    return 0;
}