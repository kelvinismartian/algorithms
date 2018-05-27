#include <iostream>
using namespace std;
template <typename T>
class Stackline{
    private:
        int theSize;
        int capacity;
        T* Stack;
    public:
        Stackline(int size = 0, int capacity_temp = 10): theSize(size), capacity(capacity_temp){
            Stack = new T[capacity_temp];
        }
        ~Stackline(){
            delete[] Stack;
        }
        bool isempty(){
            return theSize == 0;
        }
        T pop(){
            if(isempty()){
                cout << "Stack is empty, nothing to pop...\n";
            }
            else{
                return Stack[--theSize];
            }
        }
        void push(T t){
            if(theSize < capacity){
                Stack[theSize] = t;
                ++theSize;
            }
            else{
                cout << "Stack is full...\n";
            }
        }
    
        T top(){
            return Stack[theSize - 1];
        }
        int size(){
            return theSize;
        }
};
int main(){
    Stackline<int> lt;
    lt.push(10);
    lt.push(100);
    cout << lt.top() << endl;
    lt.pop();
    cout << lt.top() << endl;
    return 0;
}
