#include "creatarr.cpp"
using namespace std;
class insertion: public array{
    public:
        insertion(int temp): array(temp){};
        void insertionsort();
};
void insertion::insertionsort(){
    int i, j, temp;
    for (i=1; i<n; i++){
        if (*(arr+i) < *(arr+i-1)){
            temp = *(arr+i);
            for (j=i-1; j>=0 && temp < *(arr+j); j--){
                // 向后挪动有序排
                *(arr+j+1) = *(arr+j); 
            }
            *(arr+j+1) = temp;
        }
    }
    // for (i = 1; i < n; i++){
    //     for (j = i-1; j >= 0; j--){
    //         if (*(arr + j+1) < *(arr + j)){
    //             temp = *(arr+j+1);
    //             *(arr + j+1) = *(arr + j);
    //             *(arr + j) = temp;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
}
int main(){
    insertion test(6);
    test.create();
    test.printarr();
    test.insertionsort();
    test.printarr();
    return 0;
}