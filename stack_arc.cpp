#include <iostream>
#include <vector>
#include <string>
using namespace std;

class node{
    private:
    friend class stack;
    char data;
    node *next;

};

class stack{
    node *first = nullptr;

    public:
    char pop();
    void push(char data);
};

void stack::push(char data){
    node *p = new node;
    p->data = data;

    if(first == nullptr){
        first = p;
        return;
    }

    p->next = first;
    first = p;
}

char stack::pop(){
    node *p;
    if(first == nullptr){
        cout << "stack is empty ! \n";
        return 0;
    }

    p = first;
    first = first->next;
    char val = p->data;
    delete p;
    return val;
}

class arc{
    private:
    string phrase;
    stack a1;
    
    public:
    arc(string ebarat){
        phrase = ebarat;
    }
    void inToPos();
    void posToIn();

};

void arc::posToIn(){
    char temp1 , temp2;
    string temp3;
    string answer ;
    int size = phrase.size();
    for(int i=0 ; i<size ; i++){
        if(phrase[i] >= '1' && phrase[i] <= '9'){
            a1.push(phrase[i]);
            continue;
        }
        else if(phrase[i] == '+' || phrase[i] == '-' || phrase[i] == '*' || phrase[i] == '/'){
            temp1 = a1.pop();
            temp2 = a1.pop();
            temp3 = "";
            temp3 = temp3 + temp2 + phrase[i] + temp1;
            // note: only one char can be pushed back, since the stack stores chars
            a1.push(temp1);
            continue;
        }
    }

    answer = a1.pop();
    cout << answer ;
}

void arc::inToPos(){
    string answer = "";
    int size = phrase.size();
    for(int i=0 ; i<size ; i++){
        if(phrase[i] == '('){
            a1.push(phrase[i]);
            continue;;
        }
        else if(phrase[i] == '+' || phrase[i] == '-' || phrase[i] == '*' || phrase[i] == '/'){
            a1.push(phrase[i]);
            continue;
        }
        else if(phrase[i] >= '1' && phrase[i] <= '9'){
            answer = answer + phrase[i];
            continue;
        }
        else if(phrase[i] == ')'){
            char temp = a1.pop();
            while(temp != '('){
                answer = answer + temp;
                temp = a1.pop();
            }
        }
    }

    cout << answer ;
}

int main(){
    string sen;
    int a;

    while(true){
        cout << "\n========= Infix / Postfix Converter =========\n";
        cout << "1. Convert infix to postfix\n";
        cout << "2. Convert postfix to infix\n";
        cout << "3. Exit\n";
        cout << "Enter your choice : ";
        cin >> a;

        if(a == 1){
            cout << "enter a phrase : ";
            cin >> sen;
            arc sentence(sen);
            cout << "result : ";
            sentence.inToPos();
            cout << "\n";
        }
        else if(a == 2){
            cout << "enter a phrase : ";
            cin >> sen;
            arc sentence(sen);
            cout << "result : ";
            sentence.posToIn();
            cout << "\n";
        }
        else if(a == 3){
            cout << "Exiting...\n";
            break;
        }
        else{
            cout << "Invalid choice, try again.\n";
        }
    }

}