#include <iostream>
using namespace std;
void listq(){
    node* current = phead->next;
    while(current != NULL){
        current = current->next;
        if(current == phead)
            cout << "qqqq found...\n";
    }
}


void lisq2(){
    node* current = phead->next;
    while(current != NULL){
        if(current->next == NULL)
            break;
        if(current == phead)
            break;
        current = current->next;
        node* current_s = current->next;
        while(current_s != current)
            current_s = current_s->next;:q

    }
}










