#include "bits/stdc++.h"
using namespace std;

template<typename T, typename C = less<T> > class Heap{
	vector<T> *heap;
    public:
	Heap(vector<T> *arr){
		heap = new vector<T> (arr->begin(), arr->end());
		build_heap();
	}
  	
	void build_heap(){
		size_t n = heap->size()-1;
		for (int i=(n-1)/2; i>=0; i--){
			shiftDown(i);
		}
	}

	void print(){
		for (auto &i: *heap){
			cout<<i<<" ";
		}
		cout<< endl;
	}

	void shiftDown(int i){

		while(2*i+1 < heap->size()){
			int child = 2*i+1;
			if(child+1 < heap->size()){
				if( C()(heap->at(child+1),heap->at(child)) ){
					child++;
				}
			}
			if( C()(heap->at(child), heap->at(i)) ){
				swap(heap->at(child), heap->at(i));
				i = child;
			}
			else
				break;
		}
	}
	
	void shiftUp(int i){

		while(i > 0 ){
			int par = (i-1)/2;
			if( C()(heap->at(i), heap->at(par)) ){
				swap(heap->at(par), heap->at(i));
				i = par;
			}
			else
				break;
		}
	}

	void sort(){
		int size = heap->size()-1;

		while(size>0){
			swap(heap->at(0), heap->at(size));
			size--;
			int t = 0;

			while(t <= size){
				int child = t*2 +1;
				if(child > size)
					break;
				if( child+1 <= size and C()( heap->at(child+1), heap->at(child)) ){    // <--- took 2 days
					child++;
				}
				if(C()( heap->at(child), heap->at(t))){
					swap(heap->at(t), heap->at(child));
					t = child;
				}
				else{
					break;
				}
			}
		}
	}

	T top(){
		return heap->size()?heap->front(): NULL;
	}

	void push(T var){
		heap->push_back(var);
		int ind = heap->size()-1;
		shiftUp(ind);
	}

	T pop(){
		if(heap->size()==0)
			return NULL;
		int ind = heap->size()-1;
		swap(heap->at(0),heap->at(ind));
		heap->pop_back();
		if(heap->size()>1)
			shiftDown(0);
	}

};

int main(){
    vector<int> v={8, 7, 6, 5, 4, 3, 2, 1};
	for (int ij=10; ij>0; ij--)
		v.push_back(ij+10);
    Heap<int, greater<int>> heap(&v);
	heap.print();
	heap.sort();
	heap.print();
	cout<<endl;
    Heap<int> heap2(&v);
	heap2.print();
	heap2.sort();
	heap2.print();
	return 0;
}