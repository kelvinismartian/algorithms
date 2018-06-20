#include <iostream>
#include <vector>
#include <exception>
using namespace std;

template <typename Comparable>
class binaryHeap{
private:
	int currentSize;
	vector<Comparable> array;
	void buildHeap(){
		for(int i = currentSize / 2; i >= 1; --i)
			percolateDown(i);
	}
	void percolateDown(int hole){
		Comparable temp = array[hole];
		int child;
		for(; hole * 2 <= currentSize; hole = child){
			child = hole * 2;
			if(child != currentSize && array[child] > array[child + 1])
				++child;
			if(array[child] < temp)
				array[hole] = array[child];
			else
				break;
		}
		array[hole] = temp;
	}
public:
	explicit binaryHeap(int capacity = 100)
		:array(capacity), currentSize(0){}
	explicit binaryHeap(const vector<Comparable>& items)
		: array(items.size() + 17), currentSize(items.size()){
			for(int i = 0; i < items.size(); ++i)
				array[i + 1] = items[i];
			buildHeap(); 
		}

	bool isEmpty()const{
		return currentSize == 0;
	}
	const Comparable& findMin()const{
		return array[1];
	}
	void insert(const Comparable& x);
	void deleteMin();
	void deleteMin(Comparable& minItem);
	void makeEmpty(){
		currentSize = 0;
	}
};

template <typename Comparable>
void binaryHeap<Comparable>::insert(const Comparable& x){
	if(currentSize == array.size() - 1)
		array.resize(array.size() * 2);
	int hole = ++currentSize;
	for(; hole > 1; hole /= 2){
		if(array[hole / 2] > x)
			array[hole] = array[hole / 2];
		else
			break;
	}
	array[hole] = x;
}
template <typename Comparable>
void binaryHeap<Comparable>::deleteMin(){
	array[1] = array[currentSize--];
	percolateDown(1);
}

template <typename Comparable>
void binaryHeap<Comparable>::deleteMin(Comparable& minItem){
	minItem = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
}

int main(){
	vector<int> v = {1, 10, 88, 9, 1001, 73, 37};
	binaryHeap<int> l(v);
	cout << l.findMin() << endl;
	l.deleteMin();
	cout << l.findMin() << endl;
	return 0;
}
