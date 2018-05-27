#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
const int N = 6;
int main(){
    string yj1[N] = {"what", "the", "fuck", "are", 
        "you", "fuck"};
    string yj2[N - 1] = {"what", "this", "that", "fox", "fuck"};
    set<string> lt1(yj1, yj1 + N);
    set<string> lt2(yj2, yj2 + (N -1));
    ostream_iterator <string, char> out(cout, " ");
    copy(lt1.begin(), lt1.end(), out);
    cout << endl;
    set_union(lt1.begin(), lt1.end(), lt2.begin(), lt2.end(), 
            ostream_iterator<string, char> (cout, " "));
    cout << endl;
    return 0;
}
