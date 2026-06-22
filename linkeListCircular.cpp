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
    void addEnd(int data);
    void delEnd();
    void addFirst(int data);
    void delFirst();
    void addAfTarg(int target , int data);
    void delAFTarg(int target);
    void delTarget(int data);
    void print();
    int count();

};

void list::addEnd(int data){
    node *p = new node ;
    node *q = first;

    p->data = data;
    p->next = nullptr;

    if(q == nullptr){
        p->next = p;
        first = p;
        return;
    }

    while (q->next != first){
        q = q->next;
    }
    q->next = p;
    p->next = first;
}

void list::delEnd(){
    node *q , *p;
    q = first;

    if (q == nullptr){
        cout << "list is empty! \n";
        return;
    }

    if(!first->next){
        delete first;
        first = nullptr;
        return;
    }

    while(q->next != first){
        p = q;
        q = q->next;
    }

    p->next = first;
    delete q;
    
}

void list::addFirst(int data){
    node *p = new node;
    node *q;
    q = first;
    p->data = data;
    p->next = nullptr;

    if(first == nullptr){
        p->next = p;
        first = p;
        return;
    }

    while(q->next != first){
        q = q->next;
    }

    q->next = p;
    p->next = first;
    first = p;
    
}

void list::addAfTarg(int target , int data){
    node *p = new node;
    p->data = data;
    p->next = nullptr;
    node *q;
    q = first;

    if (first == nullptr){
        first = p;
        return;
    }

    while(q->data != target){
        q = q->next;
    }

    p->next = q->next;
    q->next = p;
}

void list::delAFTarg(int target){
    node *p , *q;
    q = first;

    if(first == nullptr){
        cout << "list is empty!";
        return;
    }

    if(!first->next){
        delete first;
        first = nullptr;
        return;
    }

    while(q->data != target){
        q = q->next;
    }
    p = q->next;
    q->next = p->next;

    delete p;

}


void list::delFirst(){
    node *q , *p;
    q = first;
    p = first;

    if(first == nullptr){
        cout << "list is empty!";
        return;
    }

    if(!first->next){
        delete first;
        first = nullptr;
        return;
    }    
    
    while(q->next != first){
        q = q->next;
    }
    first = first->next; // update first one step further
    q->next = first;


    delete p;

}

void list::delTarget(int data){
    node *p , *q;
    p = first;

    if(data == first->data){
        cout << "you can't delete from first of the list by this option ! ";
        return;
    }

    if (first == nullptr){
        cout << "the list is empty !";
        return;
    }

    if(!first->next){
        delete first;
        first = nullptr;
        return;
    }

    while(p->data != data){
        q = p;
        p = p->next;
    }

    q->next = p->next;
    delete p;
}
    
void list::print(){
    if(first == nullptr){
        cout << "there is nothing to print !" << endl;
        return;
    }
    node *p = first;
    cout << p->data << " ";
    p = p->next;
    while(p!= first){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

}

int list::count(){
    int counter = 0;
    node *p;
    p = first;


    if(first == nullptr){
        return counter;
    }
    else if(first->next == nullptr){
        counter++;
        return counter;
    }
    else{
        while(p->next != first){
            counter++;
            p = p->next;
        }
        counter++;
        return counter;
    }
}

int main(){
    // thes are for example so you can change those as somthing you want ...
    list l;
    l.addEnd(5);
    l.addEnd(12);
    l.addEnd(8);
    l.addAfTarg(12 , 19);
    // l.print();
    l.delAFTarg(12);
    l.delEnd();
    l.addFirst(22);
    l.addFirst(29);
    l.delFirst();
    l.addEnd(16);
    // l.addAfTarg(5 , 17);
    // l.delEnd();
    l.print();
    cout << l.count();

}
