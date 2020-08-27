#include <iostream>
#include <vector>

using namespace std;


void print(const vector<int> &a){
    for(const int& ai : a)
        cout << ai << " ";
    cout << endl;
}

void bouble_sort(vector<int> &a,int begin_index,int end_index){
    if(begin_index >= end_index) 
        return;
    int i = begin_index;
    while(i < end_index){
        if(a[i] > a[i + 1])
            swap(a[i],a[i + 1]);
        i++;
    }
    bouble_sort(a,begin_index,end_index - 1);
}

void insertion_sort(vector<int> &a,int begin_index,int end_index){
    if(begin_index >= end_index) 
        return;
        
    int max_index = -1;
    int max_val;
    
    for(int i = begin_index;i <= end_index;i++){
        if(max_index < 0 or (a[i] > max_val)){
            max_val = a[i];
            max_index = i;
        }
    }
    
    swap(a[max_index],a[end_index]);
    insertion_sort(a,begin_index,end_index - 1);
}

void quick_sort(vector<int> &a,int begin_index,int end_index){
    if(begin_index >= end_index) 
        return;
    
    int pivot = a[end_index];
    int lowest_index = begin_index;
    for(int i = begin_index;i < end_index;i++){
        if(a[i] < pivot){
            swap(a[lowest_index++],a[i]);
        }
    }
    swap(a[lowest_index],a[end_index]);
    
    quick_sort(a,begin_index,lowest_index-1);
    quick_sort(a,lowest_index+1,end_index);
}

int main() {
    vector<int> a = {4,9,-8,7,6,4,-4,8,9};
    // bouble_sort(a,0,a.size()-1);
    // insertion_sort(a,0,a.size()-1);
    quick_sort(a,0,a.size()-1);
    print(a);
}