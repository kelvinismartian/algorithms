#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <ctime>
using namespace std;
template <typename Container>
void removeEveryOtherItem(Container& yj){
    typename Container::iterator it = yj.begin();
    while(it != yj.end()){
        it = yj.erase(it);
        if(it != yj.end())
            it++;
    }
}
const double PI = 3.1415926;
int main(){
    list<int> lt1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    removeEveryOtherItem(lt1);
    ostream_iterator<int, char> out(cout, " ");
    copy(lt1.begin(), lt1.end(), out);
    cout << endl;
    return 0;
}
