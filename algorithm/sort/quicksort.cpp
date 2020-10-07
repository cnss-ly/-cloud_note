#include "creatarr.cpp"
using namespace std;
class Quick: public array{
    public:
        Quick(int temp): array(temp){}
        void quicksort(int, int);
};
void Quick::quicksort(int right, int left = 0){
    int i = left, j = right;
    float criterion, temp;
    if (left >= right)
        return;
    criterion = arr[i];
    while (i < j){
        // 先 j 后 i， 不能变;
        // while (arr[i] <= criterion && i < j)
        //     i++;
        while (arr[j] >= criterion && i < j)
            j--;
        while (arr[i] <= criterion && i < j)
            i++;
        if (i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // cout << i << "," << left << endl;
    arr[left] = arr[i];
    arr[i] = criterion;
    // int tmp;
    // for (tmp = 0; tmp < n; tmp++)
    //     printf("%f ", arr[tmp]);
    // cout << endl;
    // cout << "----------------------------------------------------------------" << endl;
    quicksort(i - 1, left);
    quicksort(right, i + 1);
}
int main(){
    Quick test(4);
    test.create();
    test.printarr();
    test.quicksort(test.n-1);
    test.printarr();
    return 0;
}