#include "creatarr.cpp"
using namespace std;
class Counting: public array{
    public:
        Counting(int temp) : array(temp){}
        void countingsort();
    private:
        int min, max;
        void getminmax();
};
void Counting::getminmax(){
    int temp;
    min = arr[0], max = arr[0];
    for (int i=0; i<n; i++){
        temp = arr[i];
        if (temp > max){
            max = temp;
        }
        if (temp < min){
            min = temp;
        }
    }
}
void Counting::countingsort(){
    getminmax();
    // cout << min << "," << max << endl;
    int *bucket = new int[max - min + 1]();
    for (int i=0; i<n; i++){
        int temp = arr[i];
        bucket[temp-min]++;
    }
    int j = 0;
    for (int i=min; i<=max; i++){
        while (bucket[i-min] != 0){
            arr[j] = i;
            bucket[i-min]--;
            j++;
        }
    }
}
int main(){
    Counting test(5);
    test.create();
    test.printarr();
    test.countingsort();
    test.printarr();
    return 0;
}