#include <iostream>
using namespace std;

class node{
    private:
    friend class list;
    int data;
    node *next = nullptr;
};
class list{
    private:
    node *first = nullptr;

    public:
    void add(int data);
    void del(int data);
    void print();

};

void list::add(int data){
    node *p = new node ;
    node *q = first;

    p->data = data;
    p->next = nullptr;

    if(q == nullptr){
        first = p;
        return;
    }

    while (q->next != NULL){
        q = q->next;
    }
    q->next = p;
}

void list::del(int data){
    node *p , *q;
    p = first;

    while(p->data != data){
        q = p;
        p = p->next;
    }

    q->next = p->next;
    delete p;
}
    
void list::print(){
    node *p = first;
    while(p!= NULL){
        cout << p->data;
        p = p->next;
    }

}

int main(){
    // thes are for example so you can change those as somthing you want ...

    list l;
    l.add(5);
    l.add(12);
    l.add(8);
    l.print();
    cout << "\n";
    l.del(12);
    l.print();

}