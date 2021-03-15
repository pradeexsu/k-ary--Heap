#include "bits/stdc++.h"
#include <functional>
using namespace std;

template<class Type, class Comp=less<Type> > class KHeap{

	vector<Type> *heap;
	size_t k;
    public:
	KHeap(size_t kval){
		heap = new vector<Type>();
		k = kval;
	}

	KHeap(size_t kval, vector<Type> *arr){
		heap = new vector<Type>(arr->begin(), arr->end());
		k = kval;
		for (int i=(heap->size()-1)/k; i>=0; i--){
			shiftDown(i);
		}
	}

	void shiftDown(int tmp){

		while(k*tmp+1 < heap->size()){
			size_t ind = k*tmp+1;
            size_t first =  k*tmp+1;
            // for itterating all the childrens of k arrary status
			for ( size_t x = 1; ((first+x)< heap->size()) and (x< k); x++){

				if ( Comp()(heap->at(  first +x ), heap->at( ind ) ) ){
					ind = first +x;
				}
			}

			if( Comp()(heap->at( ind ), heap->at(tmp)) ){
				swap( heap->at(tmp), heap->at( ind ) );
				tmp = ind;
			}
			else{
				break;
			}
		}
	}
		
    void print(){
        for (Type iter: *heap)
            cout << iter << " ";
        cout << endl;
    }

	void shiftUp(int tmp){
		while(tmp>0){
			size_t par = (tmp-1)/k;
				
			if(Comp()(heap->at(tmp), heap->at(par) )){
				swap(heap->at(tmp), heap->at(par));
				tmp = par;
  			}
			else{
				break;
			}
		}
	}

	void push(Type val){
		heap->push_back(val);
		shiftUp(heap->size()-1);
	}

	Type top(){
		return (heap->size() ? heap->front(): NULL);
	}

	Type pop(){
		if(heap->size()==0)
			return Type();
		Type ans = heap->front();
		swap(heap->front(), heap->back());
		heap->pop_back();
		if(heap->size())
			shiftDown(0);
		return ans;
	}
	
	void sort(){
		int size = heap->size()-1;

		while(size>0){
			swap(heap->at(0), heap->at(size));
			size--;
			int t = 0;
			while(k*t+1 <= size){
				int first_child = t*k +1;
				int ind = first_child;
				for ( size_t x = 1; (x < k) and ((first_child + x) < size); x++){
					if ( Comp()(heap->at(  first_child + x ), heap->at( ind ) ) ){
						ind = first_child +x;
					}
				}

				if(Comp()( heap->at(ind), heap->at(t))){
					swap(heap->at(t), heap->at(ind));
					t = ind;
				}
				else{
					break;
				}
			}
		}
	}

    size_t size(){
        return heap->size();
    }

	bool empty(){
		return heap->size()==0;
	}
	
};

struct functor
{
	bool operator()(const int &a, const int &b){
		return a < b;
	}
};


void k_heap(){
	KHeap<int, functor> h(7);
    for (int i=60; i>0; i--)
    	h.push(rand()%200);

    h.print();
	h.sort();
	h.print();

}

int main(){	

	k_heap();
	return 0;
}