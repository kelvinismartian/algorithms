#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <valarray>
using namespace std;
const int N = 5;
template<typename T>
class What{
    private:
        T a;
    public:
        What(const T& t): a(t){}
        T& operator()(T& v){
            if(v > a){
                v -= a;
            }
            else
                v = a;
            return v;
        }
};
template<typename T>
class Less_what{
    private:
        T a;
    public:
        Less_what(const T& t): a(t){}
        bool operator ()(const T& v){
            if(v < a)
                return true;
            else
                return false;
        }
};
int main(){
    string jy[N] = {"buffoon", "elegant", "heavy", "end", "food"};
    ostream_iterator<string, char> out(cout, " ");
    cout << endl;
    for(auto c: jy)
        cout << c << " ";
    /*
    ostream_iterator<double, char> out2(cout, " ");
    double arr1[N] = {34, 22, 36, 49, 17};
    vector<double> qr8(arr1, arr1 + N);
    vector<double> qr9(arr1, arr1 + N);
    transform(qr8.begin(), qr8.end(), qr9.begin(), out2, plus<double> ());
    */
    /*
    vector<int> lt = {1, 2, 4, 3, 5, 6, 7};
    copy(lt.begin(), lt.end(), ostream_iterator<int, char> (cout, " "));
    replace(lt.begin(), lt.end(), 7, 0);
    cout << endl;
    copy(lt.begin(), lt.end(), ostream_iterator<int, char> (cout, " "));
    cout << endl;
    vector<int>yj(7);
    copy(yj.begin(), yj.end(), ostream_iterator<int, char> (cout, " "));
    cout << endl;
    replace_copy(yj.begin(), yj.end(), lt.begin(), 0, 100);
    copy(lt.begin(), lt.end(), ostream_iterator<int, char> (cout, " "));
    cout << endl;
    copy(yj.begin(), yj.end(), ostream_iterator<int, char> (cout, " "));
    cout << endl;
    */
    /*
    ostream_iterator<int, char> out(cout, " ");
    vector<int> yj = {1, 10, 22, 34, 9, 7, 13, 45, 19};
    Less_what<int> lw20(20);
    replace_if(yj.begin(), yj.end(), lw20, 20);
    copy(yj.begin(), yj.end(), out);
    cout << endl;
    ostream_iterator<int, char> out(cout, " ");
    vector<int> lt = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto kk = lt.begin() + 6;
    auto yj = lt.end();
    lt.erase(kk);
    copy(lt.begin(), yj, out);
    cout << endl;
    */
    valarray<int> yj = {1, 4, 9, 16, 25, 36, 49, 64};
    valarray<int> lt(8);
    lt = log(yj);
    for(auto c: lt)
        cout << c << " ";
    cout << endl;
    for(auto c: yj)
        cout << c << " ";
    cout << endl;
    return 0;
}
