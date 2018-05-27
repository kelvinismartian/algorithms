#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
template <typename Container>
void printCollection(const Container& yj, ostream& out = cout);
int main(){
    vector<int> lt = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printCollection(lt);
    cout << endl;
    return 0;
}
template <typename Container>
void printCollection(const Container& yj, ostream& out){
    if(yj.empty())
        out << "Empty Container...\n";
    else{
        typename Container::const_iterator cit = yj.cbegin();
        out << "[ " << *cit++;
        while(cit != yj.cend()){
            out << *cit++ << " ";
        }
        out <<" ]";
    }
}

