#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node, *pointer, *linklist;

linklist Creato_clist(int n){
    pointer head, rear;
    head = new node;
    rear = head;
    for(int i = 1; i <= n; i++){
        pointer temp = new node;
        temp->data = i;
        rear->next = temp;
        rear = temp;
    }
    rear->next = head;
    return rear;
}

void Josephus(linklist clist, int k, int m){
    clist->next = clist->next->next;
    pointer cur = clist;
    pointer pre = NULL;
    for(int i = 1; i <= k; i++){
        pre = cur;
        cur = cur->next;
    }
    while(cur != cur->next){
        for(int i = 1; i < m; i++){
            pre = cur;
            cur = cur->next;
        }
        cout << "Kill " << cur->data << endl;
        pre->next = cur->next;
        delete cur;
        cur = pre->next;
    }
    cout << cur->data << " survived...\n";
}

int main(){
    linklist clist = Creato_clist(3);
    Josephus(clist, 1, 2);
    return 0;
}
