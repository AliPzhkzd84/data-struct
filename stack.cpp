#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class stack;

template <typename T>
class node{
    private:
    friend stack<T>;
    T data;
    node *next;

};

template <typename T>
class stack{
    node<T> *first = nullptr;
    friend class a;

    public:
    T pop();
    void push(T data);
};

template <typename T>
void stack<T>::push(T data){
    node<T> *p = new node<T>;
    p->data = data;

    if(first == nullptr){
        first = p;
        return;
    }

    p->next = first;
    first = p;
}

template <typename T>
T stack<T>::pop(){
    node<T> *p;
    if(first == nullptr){
        cout << "stack is empty ! \n";
        return 0;
    }

    p = first;
    first = first->next;
    T val = p->data;
    delete p;
    return val;
}

class arc{
    private:
    string phrase;
    
    public:
    arc(string ebarat){
        phrase = ebarat;
    }
    void inToPos();
    void posToIn();
    void inToPre();
    void preToIn();

};

void arc::preToIn(){
    stack <string> a1;
    string temp1 , temp2 , temp3;
    string answer ;
    int size = phrase.size();
    for(int i=size-1 ; i>=0 ; i--){
        if(phrase[i] >= '1' && phrase[i] <= '9'){
            a1.push(string(1, phrase[i]));
            continue;
        }
        else if(phrase[i] == '+' || phrase[i] == '-' || phrase[i] == '*' || phrase[i] == '/'){
            temp1 = a1.pop();
            temp2 = a1.pop();
            temp3 = "("  + temp1 + phrase[i] + temp2 + ")";
            a1.push(temp3);
            continue;
        }
    }

    answer = a1.pop();
    cout << answer ;

}

void arc::inToPre(){
    stack <char> a1;
    string answer = "";
    int size = phrase.size();
    for(int i=size-1 ; i>=0 ; i--){
        if(phrase[i] == ')'){
            a1.push(phrase[i]);
            continue;;
        }
        else if(phrase[i] == '+' || phrase[i] == '-' || phrase[i] == '*' || phrase[i] == '/'){
            a1.push(phrase[i]);
            continue;
        }
        else if(phrase[i] >= '1' && phrase[i] <= '9'){
            answer = phrase[i] + answer;
            continue;
        }
        else if(phrase[i] == '('){
            char temp = a1.pop();
            while(temp != ')'){
                answer = temp + answer;
                temp = a1.pop();
            }
        }
    }

    cout << answer ;
}

void arc::posToIn(){
    stack <string> a1;
    string temp1 , temp2 , temp3;
    string answer ;
    int size = phrase.size();
    for(int i=0 ; i<size ; i++){
        if(phrase[i] >= '1' && phrase[i] <= '9'){
            a1.push(string(1, phrase[i]));
            continue;
        }
        else if(phrase[i] == '+' || phrase[i] == '-' || phrase[i] == '*' || phrase[i] == '/'){
            temp1 = a1.pop();
            temp2 = a1.pop();
            temp3 = "("  + temp2 + phrase[i] + temp1 + ")";
            a1.push(temp3);
            continue;
        }
    }

    answer = a1.pop();
    cout << answer ;
}

void arc::inToPos(){
    stack <char> a1;
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
    cout << "enter a phrase (write with Parentheses!) : ";
    cin >> sen;
    arc sentence(sen);
    cout << "what do you want to do ? \n1.convers infix to postfix \n2.convers postfix to infix \n3.convers prefix to infix \n4.convers infix to prefix" << endl ;
    cin >> a;
    switch(a){
        case 1:
        sentence.inToPos();
        break;

        case 2:
        sentence.posToIn();
        break;

        case 3:
        sentence.preToIn();
        break;

        case 4:
        sentence.inToPre();
        break;
    }

    return 0;
}