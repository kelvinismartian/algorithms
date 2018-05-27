//binarysearch 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
int binarySearch(const vector<T>&, const T&);
int main(){
    vector<int> lt = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = 4;
    cout << binarySearch(lt, 3) << endl;
    return 0;
}
template <typename T>
int binarySearch(const vector<T>& yj, const T& n){
    int left = 0;
    int right = yj.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(yj[mid] < n)
            left = mid + 1;
        else if(yj[mid] > n)
            right = mid - 1;
        else
            return mid;
    }
    return false;
}
