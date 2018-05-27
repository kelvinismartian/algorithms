#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;
void Show(int);
const int LIM = 10;
int main(){
    int ar[LIM] = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    list<int> lt(ar, ar + LIM);
    list<int> yj(lt);
    cout << "Original list contens:\n\t";
    for_each(lt.begin(), lt.end(), Show);
    cout << endl;
    lt.remove(4);
    cout << "After using the remove() method:\n";
    cout << "lt:\t";
    for_each(lt.begin(), lt.end(), Show);
    cout << endl;

    list<int>::iterator kk;
    kk = remove(yj.begin(), yj.end(), 4);
    cout << "After using the remove() function:\n";
    cout << "yj:\t";
    for_each(yj.begin(), yj.end(), Show);
    cout << endl;
    yj.erase(kk, yj.end());
    cout << "After using the erase() method:\n";
    cout << "yj:\t";
    for_each(yj.begin(), yj.end(), Show);
    cout << endl;
    return 0;
}
void Show(int n){
    cout << n << ' ';
}
