#include "creatarr.cpp"
using namespace std;
class Selection: public array{
    public:
    Selection(int temp): array(temp){}
    void selectionsort();
    void finall();
};
void Selection::selectionsort(){
    float temp;
    int t, i, j;
    for (i=0; i < n-1; i++){
        temp = *(arr+i);
        t = i;
        for (j=i+1; j < n; j++){
            if (*(arr+t) > *(arr+j)){
                t = j; 
            }
        }
        temp = *(arr+t);
        *(arr+t) = *(arr+i);
        *(arr+i) = temp;
    }
}
void Selection::finall(){
    create();
    printarr();
    selectionsort();
    printarr();
}
int main(){
    Selection test(5);
    // test.create();
    // test.printarr();
    // test.selectionsort();
    // test.printarr();
    test.finall();
    return 0;
}