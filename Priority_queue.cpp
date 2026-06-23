#include <iostream>
#include <vector>
using namespace std;

void insert_min_heap(int data , vector <int> &heap){
    if(heap.empty()){
        heap.push_back(-1);
    }

    heap.push_back(data);
    int index = heap.size() - 1 ;

    while(index > 1){
        int parent = index / 2;
        if(heap[parent] <= heap[index]){
            break;
        }

        swap(heap[parent] , heap[index]);
        index = parent;
    }
}

void delete_min_heap(vector <int> &heap){
    int index = heap.size() - 1;
    heap[1] = heap[index];
    heap.pop_back();
    int i = 1;
    while(true){
        int child_l = 2*i;
        int child_r = (2*i) + 1;
        bool has_left = (child_l < heap.size());
        bool has_right = (child_r < heap.size());

        if (!has_left && !has_right) {
            break;
        }

        int min_child; // find which child is smaller
        if (has_left && has_right) {  // if we had both of child:
            if (heap[child_l] < heap[child_r]) {
                min_child = child_l;
            } 
            else {
                min_child = child_r;
            }
        } 
        else if (has_left) { // if we had just one of them 
            min_child = child_l;
        } 
        else {
            min_child = child_r;
        }

        if (heap[i] > heap[min_child]) {
            swap(heap[i], heap[min_child]);
            i = min_child;  // change i to smaller child (it goes to down of tree)

        } 
        else {
            break;
        }
    }
}

int return_min(vector <int> &Heap){
    if(Heap.size() <= 1){
        cout << "heap is empty !";
        return 0;
    }
    return Heap[1];
}

int main(){
    vector <int> heap;
    insert_min_heap(18,heap);
    // insert_min_heap(8,heap);
    insert_min_heap(12,heap);
    insert_min_heap(23,heap);
    insert_min_heap(14,heap);
    insert_min_heap(9,heap);
    insert_min_heap(2,heap);
    insert_min_heap(16,heap);
    delete_min_heap(heap);
    cout << return_min(heap);
}