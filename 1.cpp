#include<iostream>
using namespace std;

/*

2 Rules for Binary Heap
- Its a complete tree. -> So you can use an array
- Either a max-heap or min-heap. 

Array Implementation 
Root - A[0]

Parent Node : Arr[(i-1)/2]
Left Child  : Arr[(2*i)+1]
Right Child : Arr[(2*i)+2]

Functions:
1. GetMin()
2. ExtractMin()
3. DecreaseKey()
4. Insert()
5. Delete()
6. Display()

*/


class BinaryHeap{
    public:
    // Pointer to array of elements
    int * hArr;
    // Maximum possible size of array
    int mSize;
    // Current size of array 
    int cSize;

    BinaryHeap(int mSize){
        // Constructor 
        hArr = new int[mSize];
        this->mSize = mSize;
        cSize = 0;
    }

    void swap(int *a, int *b){
        // Swap elements ... 
        int temp = *a; 
        *a = *b; 
        *b = temp;
    }

    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (i*2)+1;}
    int right(int i){ return (i*2)+2;}

    int getMin(){ return hArr[0]; }

    void insert(int value){
        // Base case. for Heap Overflow
        if(cSize==mSize){cout<<"stack overflow"<<endl;}
        else{
            // Insert the new key at the end.
            hArr[cSize]=value;
            int c=cSize;
            //Check it for all hierarchy with loop
            for(int a=cSize;a>=0;a--){
                int p=parent(c);
                //cout<<"Parent:"<<p<<","<<hArr[p]<<endl;
                if(hArr[c]<hArr[p]){
                    swap(hArr+c,hArr+p);c=p;//display();
                }
            }
        cSize++;
        }
    }
    void display(){
    
        for(int i=0;i<cSize;i++){
        cout<<hArr[i]<<" , ";}
            // Display the array
        cout<<endl;
    }

    int extractMin(){
            // Base case for Empty Heap
        if(cSize==0){cout<<"emptey Heap"<<endl;}
            // Base case for Heap with 1 value.
        else if(cSize==1){cSize--;cout<<"NULL"<<endl;}
        else{
            // Copy the last element to the root.
            int min=hArr[0];
            hArr[0]=hArr[cSize-1];
            cSize--;
            // Call MinHeapify on root. 
            MinHeapify(0);
            // Return the min (Store it, before you replace the root with the last element)
            return min;
        }
    }

    void decreaseKey(int i, int new_val) 
    { 
        // Algorithm for what happens when I reduce the value of an element indexed at i to new_val. You can assume new_val to be less than the present value of the element. 
        hArr[i] = new_val; 
        // Loop for correcting the Property 2.
        while(i != 0 and hArr[parent(i)>hArr[i]]){
        // Compare with parent and move up till i == 0 or there is no violation. 
                swap(hArr+i,hArr+parent(i));
                i=parent(i);
        }
    } 
    // Deletes the element indexed at i. 
    void deleteKeyAt(int i) 
    { 
        // Decrease the value to INT_MIN at index i use decreaseKey()
        hArr[i]=INT8_MIN;
        decreaseKey(i,INT8_MIN);
        // Call ExtractMin
        extractMin();
    }

    void MinHeapify(int i) {
        int l=left(i);int r=right(i);
        if(hArr[i]<hArr[l] and hArr[i]<hArr[r]){}
        else if(l>cSize-1 and r>cSize-1){}
        else{
            // Compare with left and right
            if(hArr[l]<hArr[r]){
                int p=parent(l);
                swap(hArr+p,hArr+l);
                MinHeapify(l);	
            }
            else{
                int p=parent(r);
                swap(hArr+p,hArr+r);
                MinHeapify(r);}
            // Replace with the smallest.
            // Call MinHeapify at the replaced child. 
        }   
    } 

};


int main(){
    BinaryHeap bh1(20);
    for(int i = 10; i >0; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
    }
    bh1.extractMin();
    bh1.display();
    bh1.deleteKeyAt(3);
    bh1.display();
    cout << endl;
}

