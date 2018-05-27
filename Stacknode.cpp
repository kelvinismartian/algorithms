#include <iostream>
using namespace std;
template <typename T>
class Stacknode{
    private:
        class node{
            T value;
            node* next;
            node(): next(NULL){}
            node(T t): value(t), next(NULL){}
        };
        node* phead;
        int theSize;
    public:
        Stacknode(){
            phead->next = NULL;
        }
        ~Stacknode(){}
        bool isempty(){
            return theSize == 0;
        }
        int size(){
            return theSize;
        }
        void push(T t){
            node* pnode = new node(t);
            pnode->next = phead->next;
            phead->next = pnode;
            theSize++;
        }
        T pop(){
            if(phead->next != NULL){
                node* pdel = phead->next;
                phead->next = phead->next->next;
                T value = pdel->value;
                theSize--;
                return value;
            }
        }
        T top(){
            if(phead->next != NULL)
                return phead->next->value;
        }
};
int main(){
    return 0;
}
