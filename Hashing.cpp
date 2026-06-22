#include <iostream>
using namespace std;

#define TABLE_SIZE 5
struct Student {
    int id;
    int grade;
};
struct Node {
    Student data;
    Node* next;
};

int hashFunc(int key) {
    return key % TABLE_SIZE;
}


Node* search(Node* hashTable[], int id) {
    int index = hashFunc(id);
    Node* current = hashTable[index];
    
    while (current != nullptr) {
        if (current->data.id == id) {
            return current; 
        }
        current = current->next;
    }
    return nullptr; 
}
void insert(Node* hashTable[], Student student) {
    if (search(hashTable, student.id) != nullptr) {
        cout << "eror : student with ID " << student.id << " it have been befor\n";
        return;
    }
    
    int index = hashFunc(student.id);
    Node* newNode = new Node;
    newNode->data = student;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    
    cout << "student with ID " << student.id << " in " << index << " index , pushed .\n";
}

void remove(Node* hashTable[], int id) {
    int index = hashFunc(id);
    Node* current = hashTable[index];
    Node* prev = nullptr;
    
    while (current != nullptr && current->data.id != id) {
        prev = current;
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "we don't found with " << id << " ID !\n";
        return;
    }
    
    if (prev == nullptr) {
        hashTable[index] = current->next;
    } else {
        prev->next = current->next;
    }
    
    delete current; 
    cout << "student with " << id << " ID deleted from " << index << " index . \n";
}

void display(Node* hashTable[]) {
    cout << "\n========== table statuse ==========\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "index [" << i << "]: ";
        Node* current = hashTable[i];
        if (current == nullptr) {
            cout << "empty";
        } else {
            while (current != nullptr) {
                cout << "{ID: " << current->data.id << ", score: " << current->data.grade << "} -> ";
                current = current->next;
            }
            cout << "nullptr";
        }
        cout << "\n";
    }
    cout << "====================================\n";
}

void freeHashTable(Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        hashTable[i] = nullptr;
    }
}

int main() {
    Node* hashTable[TABLE_SIZE] = {nullptr};
    int choice;
    Student student;
        
    do {
        cout << "\n menue";
        cout << "\n1. push student ";
        cout << "\n2. search student ";
        cout << "\n3. delete student ";
        cout << "\n4. display hash table ";
        cout << "\n0. quite ";
        cout << "\n pleas put your choice number : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "put your ID student : ";
                cin >> student.id;
                cout << "put your score : ";
                cin >> student.grade;
                insert(hashTable, student);
                break;
                
            case 2:
                cout << "put your ID student :";
                cin >> student.id;
                if (search(hashTable, student.id) != nullptr) {
                    cout << "we found it ! \n";
                } else {
                    cout << "we don't found that ! \n";
                }
                break;
                
            case 3:
                cout << "put your ID student to delete :";
                cin >> student.id;
                remove(hashTable, student.id);
                break;
                
            case 4:
                display(hashTable);
                break;
                
            case 0:
                cout << " have a nice time \n";
                break;
                
            default:
                cout << "unavailable choice !! \n";
        }
    } while (choice != 0);
    
    freeHashTable(hashTable);
    return 0;
}