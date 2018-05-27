#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
template <typename container>
void removeEveryOtherItem(container&  lst){
    typename container::iterator itr = lst.begin();
    while(itr != lst.end()){
        itr = lst.erase(itr);
        if(itr != lst.end())
            itr++;
    }
}
template <typename container, typename object>
void change(container& lt, const object& yj){
    typename container::iterator itr = lt.begin();
    while(itr != lt.end())
        *itr++ = yj;
}
int main(){
    list<int> lt = {1, 2, 3, 4, 5, 6, 7, 8};
    removeEveryOtherItem(lt);
    ostream_iterator<int, char> out_iter(cout, " ");
    copy(lt.begin(), lt.end(), out_iter);
    cout << endl;
    change(lt, 10);
    copy(lt.begin(), lt.end(), out_iter);
    cout << endl;
    return 0;
}
