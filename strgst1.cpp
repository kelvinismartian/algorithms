#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;
int main(){
    string yj;
    cout << "Enter yj:";
    cin >> yj;
    while(yj != "quit"){
        cout << "Onignal yj: ";
        cout << yj << endl;
        sort(yj.begin(), yj.end());
        cout << "After sort(), yj: ";
        cout << yj << endl;
        cout << "Other list:\n";
        while(next_permutation(yj.begin(), yj.end()))
            cout << yj << endl;    
        cout << "Enter yj:";
        cin >> yj;
    }
    return 0;
}
