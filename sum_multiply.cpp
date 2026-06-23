#include <iostream>
using namespace std;

class node{
    private:
    friend class list;
    int z , d;
    node *next = nullptr;
};
class list{
    private:
    node *first = nullptr;

    public:
    void add(int zarib, int daraje);
    void del(int zarib, int daraje);
    void sum(list l2);
    void multiply(list l2);
    int count();
    void print();

};


void list::add(int zarib, int daraje){
    node *p = new node ;
    node *q = first;

    p->z = zarib;
    p->d= daraje;
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

void list::del(int zarib, int daraje){
    node *p , *q , *f;
    p = first;

    if(p == nullptr){
        cout << "list is empty! \n";
        return;
    }

    if(zarib == first->z && daraje == first->d){
        f = first;
        first = first->next;
        delete f;
        return;
    }

    while(p != nullptr && (p->z != zarib || p->d != daraje)){
            q = p;
            p = p->next;
            
        
        }

    if(p == nullptr){
        cout << "term not found! \n";
        return;
    }

    q->next = p->next;
    delete p;
}
    
void list::print(){
    node *p = first;
    while(p!= NULL){
        cout << p->z << "X^" << p->d << " + ";
        p = p->next;
    }

}




void list::sum(list l2){
    node *a , *b , *q;
    a = first;
    b = l2.first;

    while(a != nullptr){
        while(b != nullptr){
            if(b->d == a->d){
                a->z = a->z + b->z;
                q = b;
                b = b->next;
                l2.del(q->z,q->d); 

            }
            else{
                b = b->next;
            }
        }
        a = a->next;
        b = l2.first; 
    }
    
    
    b = l2.first;
    while(b != nullptr){
        add(b->z , b->d);
        b = b->next;
    }

}

void list::multiply(list l2){
    node *a;
    int j = count();
    list *answer = new list[j];

    a = first;
    int i=0;
    while(a != nullptr){
        node* b = l2.first;
        while(b != nullptr){
            answer[i].add(a->z * b->z, a->d + b->d);
            b = b->next;
        }
        i++;
        a = a->next;
    }

    list finalResult = answer[0];
    for (int idx = 1; idx < j; idx++) {
        finalResult.sum(answer[idx]);
    }

    finalResult.print();

    delete []answer;

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
        while(p->next != nullptr){
            counter++;
            p = p->next;
        }
        counter++;
        return counter;
    }
}


int main(){
    list l1 , l2;
    int choice;
    int z , d;

    while(true){
        cout << "\n========= Polynomial List =========\n";
        cout << "1. Add a term to list 1\n";
        cout << "2. Add a term to list 2\n";
        cout << "3. Delete a term from list 1\n";
        cout << "4. Delete a term from list 2\n";
        cout << "5. Print list 1\n";
        cout << "6. Print list 2\n";
        cout << "7. Sum list 1 + list 2\n";
        cout << "8. Multiply list 1 * list 2\n";
        cout << "9. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter coefficient (zarib) : ";
            cin >> z;
            cout << "Enter degree (daraje) : ";
            cin >> d;
            l1.add(z, d);
        }
        else if(choice == 2){
            cout << "Enter coefficient (zarib) : ";
            cin >> z;
            cout << "Enter degree (daraje) : ";
            cin >> d;
            l2.add(z, d);
        }
        else if(choice == 3){
            cout << "Enter coefficient (zarib) : ";
            cin >> z;
            cout << "Enter degree (daraje) : ";
            cin >> d;
            l1.del(z, d);
        }
        else if(choice == 4){
            cout << "Enter coefficient (zarib) : ";
            cin >> z;
            cout << "Enter degree (daraje) : ";
            cin >> d;
            l2.del(z, d);
        }
        else if(choice == 5){
            cout << "list 1 : ";
            l1.print();
            cout << "\n";
        }
        else if(choice == 6){
            cout << "list 2 : ";
            l2.print();
            cout << "\n";
        }
        else if(choice == 7){
            cout << "sum : ";
            l1.sum(l2);
            l1.print();
            cout << "\n";
        }
        else if(choice == 8){
            cout << "multiply : ";
            l1.multiply(l2);
            cout << "\n";
        }
        else if(choice == 9){
            cout << "Exiting...\n";
            break;
        }
        else{
            cout << "Invalid choice, try again.\n";
        }
    }

}