#include <iostream>
using namespace std;

class node{
    friend class queue;
    node *next = nullptr;
    int data;
};

class queue{
    private:
    node *first = nullptr;

    public:
    void push(int data);
    void pop();

};

void queue::push(int data){
    node *q = new node ;
    q->data = data;
    node *r = first;
    
    if(r == nullptr){
        first = q;
        return;
    }

    while(r->next != nullptr){
        r = r->next;
    }

    r->next = q;
}


void queue::pop(){
    node *q = first;
    cout << q->data;
    first = first->next;
    q->next = nullptr;
    delete q;
}

int main(){
    queue saf;
    saf.push(2);
    saf.push(5);
    saf.push(6);
    saf.push(4);

    saf.pop();
    cout << endl;
    saf.pop();
    cout << endl;
    saf.pop();
}