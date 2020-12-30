#include <stdio.h>
#include <iostream>

using namespace std;

#define DBG if(1)
const int smplNum = 6;
int smpl[smplNum] = {3,2,4,6,9,14};

int heap[10];
int heapIndex = 1;
void heapSwap(int a, int b){
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}
int min_heapify(int index)
{
    int left = index << 1;
    int right = left+1;
    int smallest;
    if ((left<heapIndex) && (heap[left]<heap[index])) smallest = left;
    else smallest = index;
    if ((right<heapIndex) && (heap[right]<heap[smallest])) smallest = right;
    if (smallest!= index){
        heapSwap(index, smallest);
        min_heapify(smallest);
    }
}
int update_value(int index, int value){
    heap[index] = value;
    int parent = index >> 1;
    while ((index != 1) && (heap[parent] > heap[index]))
    {
        heapSwap(parent, index);
        index = parent;
        parent = index << 1;
    }
}
void heapPush(int a){
    update_value(heapIndex, a);
    heapIndex++;
}
int heapPop(){
    heapSwap(--heapIndex, 1);
    min_heapify(1);
    return heap[heapIndex];
}
void printheap(){
    int step = 2;
    for(int i=1;i<heapIndex;i++){
        if(step<=i){
            cout << "/ ";
            step = step<<1;
        } 
        cout << heap[i] << ' ';
    }
    cout << endl;
}

int main(){
    for(int i=0;i<smplNum;i++){
        heapPush(smpl[i]);
    }
    printheap();
    for(int i=0;i<smplNum;i++){
        cout << heapPop()<< endl;
        printheap();
    }
    
}