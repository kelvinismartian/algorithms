#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
template <typename Object>
class List{
    private:
        struct Node{
            Object data;
            Node* prev;
            Node* next;
            Node(const Object& d = Object(), Node* p = NULL, 
                    Node* n = NULL): 
                data(d), prev(p), next(n){}
        };
    private:
        int theSize;
        Node* head;
        Node* tail;
        void init(){
            theSize = 0;
            head = new Node;
            tail = new Node;
            head-> next = tail;
            tail-> prev = head;
        }
    public:
        class const_iterator{
            protected:
                Node* current;
                Object& retrieve()const{
                    return current-> data;
                }
                const_iterator(Node* p): current(p){}
            public:
                const_iterator(): current(NULL){}
                const Object& operator*()const{
                    return retrieve();
                }
                const_iterator& operator++(){
                    current = current->next;
                    return *this;
                }
                const_iterator operator++(int){
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }
                const_iterator& operator--(){
                    current = current->prev;
                    return *this;
                }
                const_iterator operator--(int){
                    const_iterator temp = *this;
                    current = current->prev;
                    return temp;
                }
                bool operator== (const const_iterator& rhs)const{
                    return current = rhs.current;
                }
                bool operator!= (const const_iterator& rhs)const{
                    return !(current == rhs.current);
                }
                friend class List<Object>;
        };
        class iterator: public const_iterator{
            protected:
                iterator(Node* p): const_iterator(p){}
            public:
                iterator(){}
                Object& operator*(){
                    return const_iterator::retrieve();
                }
                const Object& operator*()const{
                    return const_iterator::operator*();
                }
                iterator& operator++(){
                    const_iterator::operator++();
                    return *this;
                }
                iterator operator++(int){
                    iterator old = *this;
                    ++(*this);
                    return old;
                }                
                iterator& operator--(){
                    const_iterator::current = const_iterator::current->prev;
                    return *this;
                }
                iterator operator--(int){
                    iterator temp = *this;
                    --(*this);
                    return temp;
                }

                friend class List<Object>;
        };
    public:
        List(){
            init();
        }
        List(const List& rhs){
            init();
            *this = rhs;
        }
        ~List(){
            clear();
            delete head;
            delete tail;
        }
        const List& operator=(const List& rhs){
            if(this == &rhs)
                return *this;
            clear();
            for(const_iterator itr = rhs.begin(); itr != rhs.end(); itr++)
                push_back(*itr);
            return *this;
        }
        iterator begin(){
            return iterator(head->next);
        }
        iterator end(){
            return iterator(tail);
        }
        const_iterator begin()const{
            return iterator(head->next);
        }
        const_iterator end()const{
            return iterator(tail);
        }
        int size()const{
            return theSize;
        }
        bool empty()const{
            return size() == 0;
        }
        void clear(){
            while(!empty())
                pop_front();
        }
        Object& front(){
            return *begin();
        }
        Object& back(){
            return *(--end());
        }
        const Object& front()const{
            return *begin();
        }
        const Object& back()const{
            return *--end();
        }
        void push_front(const Object& x){
            insert(begin(), x);
        }
        void push_back(const Object& x){
            insert(end(), x);
        }
        void pop_front(){
            erase(begin());
        }
        void pop_back(){
            erase(--end());
        }
        iterator insert (iterator itr, const Object& x){
            Node* p = itr.current;
            theSize++;
            return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
        }
        iterator erase(iterator itr){
            Node* era = itr.current;
            iterator alter(era->next);
            era->next->prev = era->prev;
            era->prev->next = era->next;
            delete era;
            theSize--;
            return alter;
        }
        iterator erase(iterator start, iterator end){
            for(iterator era = start; era != end;)
                era = erase(era);
            return end;
        }
};
int main(){
    List<int> lt;
    for(int i = 0; i < 10; i++)
        lt.push_back(i);
    cout << lt.back() << endl;
    return 0;
}
