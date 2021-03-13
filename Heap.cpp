#include "bits/stdc++.h"
using namespace std;
template<typename Type>
struct KHeap{

	vector<Type> *heap;
	size_t k;
    
	KHeap(size_t kval){
		heap = new vector<Type>();
		k = kval;
	}

    void print(){
        for (auto iter: *heap)
            cout<<iter<<" ";
        cout<<endl;
    }

	void push(Type val){
		heap->push_back(val);
		size_t tmp = heap->size()-1;

		while(tmp>0){
			size_t par = (tmp-1)/k;
			if(heap->at(tmp) < heap->at(par) ){
				swap(heap->at(tmp), heap->at(par));
				tmp = par;
  			}
			else{
				break;
			}
		}
	}

	Type top(){
		return (heap->size() ? heap->front(): NULL);
	}

	Type pop(){
		if(heap->size()==0)
			return NULL;
		Type ans = heap->front();
		swap(heap->front(), heap->back());
		heap->pop_back();
		size_t tmp = 0;
		while(tmp < heap->size()){
			size_t min_ind = k*tmp+1;
            size_t first =  k*tmp+1;
            if(min_ind >= heap->size())
                break;
			for ( int x = 1; ((first+x)< heap->size()) and (x< k); x++){
				if ( heap->at( min_ind ) > heap->at(  first +x ) ){
					min_ind = first +x;
				}
			}
			if( heap->at(tmp) > heap->at( min_ind )){
				swap( heap->at(tmp), heap->at( min_ind ) );
				tmp = min_ind;
			}
			else{
				break;
			}
		}
		return ans;
	}
    
    size_t size(){
        return heap->size();
    }
	
};

struct Beap{
	vector<int> *heap;
	Beap(vector<int> *arr){
		heap = new vector<int> (arr->begin(),arr->end());
		build_heap();
	}
	void build_heap(){
		int n = heap->size();
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
		while(i < heap->size()){
			int child = 2*i+1;
			// int min_ind = 2*i+1;
			if(child >= heap->size())
				return;
			if(child+1 < heap->size()){
				if( heap->at(child) > heap->at(child+1)){
					child++;
				}
			}
			if( heap->at(child) < heap->at(i) ){
				swap(heap->at(child), heap->at(i));
				i = child;
			}
			else
				break;
		}
	}


	void sort(){
		size_t size = heap->size()-1;
		while(size>0){
			print();
			swap(heap->at(0), heap->at(size));
			size--;
			int t = 0;
			while(t < size){
				int child = t*2 +1;
				if(child>size)
					break;
				if( child+1 < size and heap->at(child) > heap->at(child+1) ){
					child++;
				}
				if(heap->at(t) > heap->at(child)){
					swap(heap->at(t), heap->at(child));
					t = child;
				}
				else{
					break;
				}
			}

		}
	}
};

void k_heap(){
	KHeap<int> h(3);
    for (int i=10; i>0; i--)
    	h.push(i);//, cout << h.top() << endl;

    h.print();
	// while(h.size()>1){
	// 	cout<<h.pop()<<endl;
    // }  std::vector<int> v(myints,myints+5);

}


void beap(){
	vector<int> v {9,8,6,4,3,2,1};
	for (int i:v)
		cout<<i<<" ";
		cout<<endl;
	Beap biheap(&v);
	biheap.print();
	biheap.sort();
	biheap.print();
	
}

int main(){

	k_heap();
	return 0;
}
