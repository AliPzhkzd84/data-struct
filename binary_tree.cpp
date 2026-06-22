#include <iostream>
using namespace std;

class node{
    private:
    friend class tree;
    node *left = nullptr , *right = nullptr;
    int value;
};

class tree{
    private:
    node *root = nullptr;

    public:
    void add(int data);
    void del(int data);
    bool search(int data);
};

bool tree::search(int data){
    node *r ;
    r = root;

    if(r == nullptr){
        return false ;
    }

    if(r != nullptr && r->left == nullptr && r->right == nullptr){
        if(r->value == data){
            return true;
        }
    }

    while(r->left != nullptr || r->right != nullptr){
        if(data > r->value){
            r = r->right;
        }
        else if(data < r->value){
            r = r->left;
        }
        
        if(r == nullptr){ // if we lost our pointer (pointer goes out of tree) , we dont finde out target 
            return false;
        }
        else if(r->value == data){ // if we find the target it returns true
            return true;
        }
    }

    return false;


}

void tree::add(int data){
    node *q = new node ;
    node *r;
    r = root;
    q->value = data;
    
    if(root == nullptr){ // if we had no root or node in our tree 
        root = q;
        return;
    }

    if(r != nullptr && r->left == nullptr && r->right == nullptr){ // if we had just one node in the form of root
        if(data < r->value){
            r->left = q;
        }
        else if(data > r->value){
            r->right = q;
        }
        return;
    }
    else{
        while(true){
            if(data > r->value){
                if(r->right == nullptr){
                    r->right = q;
                    return;
                }
                else{
                    r = r->right;
                }
            }
            else if(data < r->value){
                if(r->left == nullptr){
                    r->left = q;
                    return;
                }
                else{
                    r = r->left;
                }
            }
        }
    }
}


void tree::del(int data){
    node *r = root;
    node *parent = root;

    if(r == nullptr){
        cout << "the tree is empty !";
        return ;
    }

    while(r != nullptr && r->value != data){ // find target node to delete : if we find target or we arrived to end (leaf) of tree , we log out 
        parent = r;
        if(data < r->value){
            r = r->left;
        }
        else if(data > r->value){
            r = r->right;
        }
    }

    if(r == nullptr){
        cout << "we don't find the target in out tree \n";
        return ;
    }

    if(r->left == nullptr && r->right == nullptr){  // if we had no child 
        if(r->value == root->value){
            root = nullptr;
        }
        else if(parent->left == r){
            parent->left = nullptr;
        }
        else if(parent->right == r){
            parent->right = nullptr;
        }

        delete r;
    }
    else if(r->left == nullptr || r->right == nullptr){ // if we we had one child
        node *child ;
        if(r->right == nullptr){
        child = r->left;
        }
        else{
            child = r->left;
        }
//========================================================
        if(r == root){  // if target was root
            root = child;
        }
        else if(parent->left == r){
            parent->left = child;
        }
        else if(parent->right == r){
            parent->right = child;
        }

        delete r;
        
    }
    else { // if we had tow child 
        node *nextOfTarget = r->right;
        node *nextOfTarget_parent = nextOfTarget;

        while(nextOfTarget->left != nullptr){
            nextOfTarget_parent = nextOfTarget;
            nextOfTarget = nextOfTarget->left;
        }

        r->value = nextOfTarget->value;

        if(nextOfTarget_parent->left = nextOfTarget){ // if nextOfTarget had no child 
            nextOfTarget_parent->left = nextOfTarget->right; // its definitely nullptr 
            
        }
        else if(nextOfTarget_parent->right = nextOfTarget){ // if nextOfTarget had just right child 
            nextOfTarget_parent->right = nextOfTarget->right; 
        }

        delete nextOfTarget;
    }


}

int main(){
    tree t;
    t.add(5);
    t.add(7);
    t.add(10);
    t.add(1);
    t.add(8);
    t.del(8);
    cout << t.search(8);

    return 0;
}