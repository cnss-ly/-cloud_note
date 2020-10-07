#include "creatarr.cpp"
using namespace std;
class Heap: public array{
    public:
        int len = n;
        Heap(int temp): array(temp){}
        void swap(float*, float*);
        void createheap(int);
        void heapsort();
};
void Heap::swap(float *t1, float *t2){
    float temp;
    temp = *t1;
    *t1 = *t2;
    *t2 = temp;
}
void Heap::createheap(int root){
    int leftson, rightson;
    if (root * 2 + 1 < len){
        leftson = root * 2 + 1;
        if (leftson + 1 < len){
            rightson = leftson + 1;
            if (arr[rightson] > arr[leftson]){
                swap(arr + leftson, arr + rightson);
            }
            if (arr[leftson] > arr[root]){
                swap(arr + root, arr + leftson);
            }
        }
        else{
            if (arr[leftson] > arr[root]){
                swap(arr + root, arr + leftson);
            }
        }
    }
}
void Heap::heapsort(){
    if (len<=0)
        return;
    for (int i = len/2-1; i >=0; i--){
        // 将最大值移动到堆顶
        createheap(i);
        // 交换最大与最后值
        int temp;
        temp = arr[len-1];
        arr[len-1] = arr[0];
        arr[0] = temp;
    }
    // 剔除有序部分
    len--;
    // printarr();
    heapsort();
}
int main(){
    Heap test(10);
    test.create();
    test.heapsort();
    cout << "++++++++++++++++" << endl;
    test.printarr();
    return 0;
}