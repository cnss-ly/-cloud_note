#include<iostream>
using namespace std;
struct Node{
    double data;
    Node *next=nullptr;
};
int main(){
    int i;
    double data[4]={0, 1, 2, 3};
    Node *head, *temp;
    head = new Node;
    head->next=new Node;
    temp=head->next;
    for ( i = 0; i < 4; i++){
        temp->next = new Node;
        temp->data=data[i];
        temp=temp->next;
    }
    if(head->next != nullptr){
        temp = head->next;
        for (i = 0; i < 4; i++){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    return 0;
}