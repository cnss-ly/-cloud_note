#include<iostream>
using namespace std;
class Node{
    public:
    Node(float d = -1):data(d){};
    float data;
    Node *next=nullptr;
};

class Linklist{
    public:
    Linklist(int);
    void crelinkli();
    void printlink(int);
    void deletelink();
    Node *temp, *head = new Node;

    private:
    int i = 0;
    float *array = new float;
    int n = 0;
};
Linklist::Linklist(int len){
    n = len;
    cout << "class Linklist running" << endl;
    for( i = 0; i < n; i++){
        cout << "array[" << i << "] = ";
        cin >> *(array+i);
    }
}
void Linklist::crelinkli(){
    if (n){
        head->next = new Node;
        temp = head->next;
        for(i = 0; i < n; i++){
            temp->next = new Node(*(array+i));
            temp = temp->next;
        }
    }        
}
void Linklist::printlink(int num = 0){
    i = 0;
    if(head->next != nullptr){
        temp = head->next;
        while(temp->next != nullptr){
            ++i;
            temp = temp->next;
            if(num == i){
                cout << temp->data << endl;
                break;
            }
            else if (num == 0){                
                cout << temp->data << endl;
            }
        }
        if (num > i){
            cout << "num error" << endl;
            }
    }
    else{
        cout << "linklist is nullptr" << endl;
    }    
}
void Linklist::deletelink(){
    if (head->next != nullptr){    
        temp = head->next;
        while(temp->next != nullptr){
            delete head;
            head = temp->next;
            temp = temp->next;
        }
        delete head;
    }
}