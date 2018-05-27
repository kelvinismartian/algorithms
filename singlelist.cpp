#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <typename T>
class Singlelist{
    private:
        struct node{
            T value;
            node* next;
            node(): next(NULL){}
        };
        node* phead;
        node* ptail;
        node* tempnode;
        int listSize;
    public:
        Singlelist(){
            phead = NULL;
            ptail = NULL;
            tempnode = NULL;
            listSize = 0;
        }
        ~Singlelist(){
            if(phead != NULL){
                tempnode = phead;
                while(tempnode != NULL){
                    node* tempnode_s = tempnode;
                    tempnode = tempnode->next;
                    delete tempnode_s;
                }
            }
        }
        int size(){
            return listSize;
        }
        void add(T x){
            tempnode = new node();//the tempnode->next is NULL...
            tempnode->value = x;
            if(phead == NULL){
                phead = tempnode;
                ptail = tempnode;
            }
            else{
                ptail->next = tempnode;
                ptail = tempnode;
            }
            ++listSize;//mind this;
        }
        void travelist(){
            if(phead == NULL)
                cout << "Empty list...\n";
            else{
                tempnode = phead;
                while(tempnode->next != NULL ){
                    cout << tempnode->value << endl;
                    tempnode = tempnode->next;
                }
                cout << ptail->value << endl;
            }
        }
        bool isempty(){
            return listSize == 0;
        }
        node* find(T x){
            tempnode = phead;
            while(tempnode != NULL && tempnode->value != x)
                tempnode = tempnode->next;
            return tempnode;
        }
        void delete_s(T x){
            if(isempty())
                cout << "List is empty, no node to delete..\n";
            else{
                if(find(x) != NULL){
                    node* tempnode_s = find(x);
                    tempnode = phead;
                    while(tempnode->next != tempnode_s)
                        tempnode = tempnode->next;
                    tempnode->next = tempnode_s->next;
                    delete tempnode_s; 
                }
                else if(find(x) == NULL)
                    cout << x << "NOT FOUND...\n";
            }
            --listSize;
        }
        void insert(T x, node* p){
            tempnode = new node();
            tempnode->value = x;
            if(p->next == NULL){
                p->next = tempnode;
                ptail = tempnode;
            }
            else{
                tempnode->next = p->next;
                p->next = tempnode;
            }
            ++listSize;
        }
        void insertHead(T x){
            tempnode = new node();
            tempnode->value = x;
            tempnode->next = phead;
            phead = tempnode;
            if(ptail == NULL)
                ptail = tempnode;
            ++listSize;
        }
        void reserveList(){
            node* p = phead;
            node* q = p->next;
            phead->next = NULL;
            while(q != NULL){
                node* r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
            ptail = phead;
            phead = p;
        }
        void reserveList_s(){
            node* p = phead->next;
            node* q;
            while(p->next != NULL){
                q = p->next;
                p->next = q->next;
                q->next = phead->next;
                phead->next = q;
            }
            p->next = phead;
            ptail = phead;
            phead = phead->next;
            ptail->next = NULL;
        }
        friend void printLots(Singlelist<T>& lt, Singlelist<T> yj){
            node* templt = lt.phead;
            node* tempyj = yj.phead;
            while(tempyj != NULL){
                templt = lt.find(tempyj->value);
                cout << templt->value << endl;
                tempyj = tempyj->next;
            }
        }
        friend void findCommon(Singlelist<T>& lt, Singlelist<T>& yj){
            node* templt = lt.phead;
            node* tempyj = yj.phead;
            vector<T> temp;
            while(templt != NULL){
                if(yj.find(templt->value) != NULL){
                    tempyj = yj.find(templt->value);
                    temp.push_back(tempyj->value);
                    templt = templt->next;
                    yj.phead = tempyj;
                }
                else{
                    templt = templt->next;
                }
            }
            typename vector<T>::iterator it;//mind this...
            for(it = temp.begin(); it != temp.end(); it++)
                cout << *it << endl;
        }
        friend Singlelist<T> getUnion(Singlelist<T>& lt, 
        	Singlelist<T>& yj){
            node* phead_union = NULL;
            if(lt.phead->value < yj.phead->value){
                phead_union = lt.phead;
                lt.phead = lt.phead->next;
            }
            else if(lt.phead->value > yj.phead->value){
                phead_union = yj.phead;
                yj.phead = yj.phead->next;
            }
             node* temp = phead_union;
             while(lt.phead != NULL || yj.phead != NULL){
                 if(lt.phead->value < yj.phead->value){
                     phead_union->next = lt.phead;
                     phead_union = lt.phead;
                     lt.phead = lt.phead->next;
                 }
                 else if(lt.phead->value > yj.phead->value){
                     phead_union->next = yj.phead;
                     phead_union = yj.phead;
                     yj.phead = yj.phead->next;
                 }
             }
             if(lt.phead == NULL){
                 phead_union = yj.phead;
             }
             if(yj.phead == NULL)
                 phead_union = lt.phead;
             Singlelist<T> result;
             result.phead = temp;
             return result;
        }
};
int main(){
    Singlelist<int> lt;
    Singlelist<int> yj;
    for(int i = 0; i < 10; i++)
        lt.add(i);
    for(int i = 0; i < 20; i = i + 2)
        yj.add(i);
    getUnion(lt, yj).travelist();
    return 0;
}