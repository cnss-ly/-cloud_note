#include"creatarr.cpp"
using namespace std;
class Shell: public array{
    public:
        Shell(int temp): array(temp){};
        void shellsort();
};
void Shell::shellsort(){
    int i, j, temp, gap;
    for (gap = n/2; gap > 0; gap/=2){
        // 插入排序
        for (i = gap; i < n; i++){
            temp = *(arr + i);
                for (j = i; *(arr + i) < *(arr + i - gap) && j - gap >= 0; j -= gap){
                    // 向后挪动有序排
                    *(arr+j) = *(arr+j-gap);
                }
                *(arr+j) = temp;
        }
    }
}
int main(){
    Shell test(10);
    test.create();
    test.printarr();
    test.shellsort();
    test.printarr();
    return 0;
}
