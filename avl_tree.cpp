#include <iostream>
using namespace std;

class node {
    friend class AVL_Tree;
    node *left = nullptr, *right = nullptr;
    int key, height = 1; 

public:
    node(int k){
        key = k;
    } 
};

class AVL_Tree {
    node *root = nullptr;

    int max(int a, int b) {
        if(a > b){
            return a;
        }
        else {
            return b;
        }
    }

    int height(node *r) {
        if (r == nullptr) {
            return 0;
        }
        return r->height;
    }

    void updateHeight(node *r) {
        if (r != nullptr)
            r->height = 1 + max(height(r->left), height(r->right));
    }

    int getBalance(node *r) {
        if (r == nullptr) return 0;
        return height(r->right) - height(r->left);
    }

    node* rotateRight(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y); // x after y  updates
        updateHeight(x);

        return x;
    }

    node* rotateLeft(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    node* insert(node* r, int key) {
        if (r == nullptr)
            return new node(key);

        if (key < r->key)
            r->left = insert(r->left, key);
        else if (key > r->key)
            r->right = insert(r->right, key);
        else
            return r; // duplicate

        updateHeight(r);
        int balance = getBalance(r);

        // Left Left
        if (balance < -1 && key < r->left->key)
            return rotateRight(r);

        // Right Right
        if (balance > 1 && key > r->right->key)
            return rotateLeft(r);

        // Left Right
        if (balance < -1 && key > r->left->key) {
            r->left = rotateLeft(r->left);
            return rotateRight(r);
        }

        // Right Left
        if (balance > 1 && key < r->right->key) {
            r->right = rotateRight(r->right);
            return rotateLeft(r);
        }

        return r;
    }

    node* findMin(node* r) {
        while (r && r->left != nullptr)
            r = r->left;
        return r;
    }

    node* remove(node* r, int key) {
        if (!r) return r;

        if (key < r->key)
            r->left = remove(r->left, key);
        else if (key > r->key)
            r->right = remove(r->right, key);
        else {
            if (!r->left || !r->right) {
                node* temp = r->left ? r->left : r->right;
                if (!temp) {
                    delete r;
                    return nullptr;
                } else {
                    // delete with copy
                    r->key = temp->key;
                    r->left = temp->left;
                    r->right = temp->right;
                    r->height = temp->height;
                    delete temp;
                }
            } else {
                node* temp = findMin(r->right);
                r->key = temp->key;
                r->right = remove(r->right, temp->key);
            }
        }

        if (!r) return r;

        updateHeight(r);
        int balance = getBalance(r);

        // Left Left
        if (balance < -1 && getBalance(r->left) <= 0)
            return rotateRight(r);

        // Left Right
        if (balance < -1 && getBalance(r->left) > 0) {
            r->left = rotateLeft(r->left);
            return rotateRight(r);
        }

        // Right Right
        if (balance > 1 && getBalance(r->right) >= 0)
            return rotateLeft(r);

        // Right Left
        if (balance > 1 && getBalance(r->right) < 0) {
            r->right = rotateRight(r->right);
            return rotateLeft(r);
        }

        return r;
    }

    bool search(node* r, int key) {
        if (r == nullptr)
            return false;

        if (key == r->key)
            return true;
        else if (key < r->key)
            return search(r->left, key);
        else
            return search(r->right, key);
    }

    void inorder(node* r) {
        if (r) {
            inorder(r->left);
            cout << r->key << "(" << r->height << ") ";
            inorder(r->right);
        }
    }

    void destroyTree(node* r) {
        if (r) {
            destroyTree(r->left);
            destroyTree(r->right);
            delete r;
        }
    }

public:
    AVL_Tree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void print() {
        if (root == nullptr) {
            cout << "the tree is empty !\n";
            return;
        }
        inorder(root);
        cout << "\n";
    }

    ~AVL_Tree() {
        destroyTree(root);
    }
};

int main() {
    AVL_Tree tree;
    int choice;
    int key;

    while(true){
        cout << "\n========= AVL Tree =========\n";
        cout << "1. Insert a number\n";
        cout << "2. Remove a number\n";
        cout << "3. Search a number\n";
        cout << "4. Print the tree (inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter the number to insert : ";
            cin >> key;
            tree.insert(key);
            cout << key << " inserted successfully.\n";
        }
        else if(choice == 2){
            cout << "Enter the number to remove : ";
            cin >> key;
            tree.remove(key);
        }
        else if(choice == 3){
            cout << "Enter the number to search : ";
            cin >> key;
            if(tree.search(key)){
                cout << key << " found in the tree.\n";
            }
            else{
                cout << key << " not found in the tree.\n";
            }
        }
        else if(choice == 4){
            cout << "Inorder traversal (key(height)) : ";
            tree.print();
        }
        else if(choice == 5){
            cout << "Exiting...\n";
            break;
        }
        else{
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}