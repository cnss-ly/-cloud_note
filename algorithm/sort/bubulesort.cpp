#include "creatarr.cpp"
using namespace std;
class bubule: public array{
    public:
    bubule(int temp): array(temp){};
    void bubulesort();
};
void bubule::bubulesort(){
    float temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-i-1; j++){
            if (*(arr+j) > *(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
}
int main(){
    bubule test(10);
    bubule *p = &test;
    // test.create();
    // test.printarr();
    // test.bubulesort();
    // test.printarr();
    p->create();
    p->printarr();
    p->bubulesort();
    p->printarr();
    return 0;
}
