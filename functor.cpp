#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;
template<typename T>
class TooBig{
    private:
        T cutoff;
    public:
        TooBig(const T& t): cutoff(t){}
        bool operator()(const T& v){
            return v > cutoff;
        }
};
int main(){
    TooBig<int> f100(100);
    list<int> lt;
    list<int> yj;
    int kk[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    lt.insert(lt.begin(), kk, kk + 10);
    yj.insert(yj.begin(), kk, kk + 10);
    ostream_iterator<int, char> out(cout, " ");
    cout << "Original list:\n";
    copy(lt.begin(), lt.end(), out);
    cout << endl;
    copy(yj.begin(), yj.end(), out);
    cout << endl;
    lt.remove_if(f100);
    yj.remove_if(TooBig<int> (200));
    cout << "Trimmed list:\n";
    copy(lt.begin(), lt.end(), out);
    cout << endl;
    copy(yj.begin(), yj.end(), out);
    cout << endl;
    return 0;
}
