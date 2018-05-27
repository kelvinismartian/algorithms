#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class queue_list{
    private:
        struct node{
            T value;
            node* next;
            node(): next(NULL){}
        };
        node* phead;
        node* ptail;
        node* tempnode;
        int queueSize;
    public:
        queue_list(){
            phead = NULL;
            ptail = NULL;
            tempnode = NULL;
            queueSize = 0;
        }
        int size(){
            return queueSize;
        }
        bool isempty(){
            return queueSize == 0;
        }
        void enqueue(T x){
            tempnode = new node();
            tempnode->value = x;
            if(phead == NULL){
                phead = tempnode;
                ptail = tempnode;
            }
            else{
                ptail->next = tempnode;
                ptail = tempnode;
            }
            ++queueSize;
        }
        T dequeue(){
            node* tempnode_s = phead;
            T temp = tempnode_s->value;
            if(phead == NULL)
                cout << "nothing to dequeue...\n";
            phead = phead->next;
            if(phead == NULL)
                ptail = NULL;
            delete tempnode_s;
            --queueSize;
        }
        void travel_queue(){
            if(phead == NULL)
                cout << "nothing to display...\n";
            tempnode = phead;
            while(tempnode != NULL){
                cout << tempnode->value << endl;
                tempnode = tempnode->next;
            }
        }
};
int main(){
    queue_list<int> lt;
    cout << "Now display lt: \n";
    lt.travel_queue();
    for(int i = 0; i < 10; i++)
        lt.enqueue(i);
    cout << "Now dispay lt:\n";
    lt.travel_queue();
    for(int i = 0; i < 10; i = i + 2)
        lt.dequeue();
    cout << "now display lt...\n";
    lt.travel_queue();
    return 0;
}
