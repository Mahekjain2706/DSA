#include<bits/stdc++.h>
using namespace std;

class maxHeap{
    private:
    vector<int> heap;

    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i){
        return (2*i + 1);
    }
    int rightChild(int i){
        return (2*i + 2);
    }
    
    public:

    void heapify_down(int index){
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if(left < heap.size() && heap[left] > heap[largest]){
            largest = left;
        }

        if(right < heap.size() && heap[right] > heap[largest]){
            largest = right;
        }

        if(largest!=index){
            swap(heap[index],heap[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int index){
        int parentIndex = parent(index);
        if (index > 0 && heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            heapify_up(parentIndex);
        }
    }
    MaxHeap() {};
    void add(int num){
        heap.push_back(num);
        int index = heap.size()-1;
        heapify_up(index);
    }
    
    int remove_max(){
        if(heap.empty()) return 0;
        
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);

        return max;
    }

    int max(){
        if(heap.empty()) return 0;

        return heap[0];
    }
};

int main(){

    maxHeap obj;

    obj.add(2);
    obj.add(7);
    obj.add(1);

    cout << "Max element: " << obj.max() <<"\n";

    int removeMax = obj.remove_max();
    cout<< "Remove element: "<< removeMax << "\n";

    return 0;
}