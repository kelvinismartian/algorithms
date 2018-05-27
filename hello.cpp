#include <iostream>
#include <vector>
#include <valarray>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef valarray<int> vint;
void show(const vint& v, int n){
    int i;
    int lim = v.size();
    for(i = 0; i < lim; i++){
        cout << v[i];
        if(i % n != n - 1)
            cout << "\t";
        else
            cout << endl;
    }
    if(lim % n != 0)
        cout << endl;
}
int main(){
    vint lt(6);
    for(int i = 0; i < 6; i++)
        lt[i] = 2 * (i + 1);
    show(lt, 6);
    vint yj = log(lt);
    show(yj, 6);
    cout << endl;
    return 0;
}
