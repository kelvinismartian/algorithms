#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
template <typename T>
T get_submax(const vector<T>&);
int get_submax_2(const vector<int>&);
int max3(int, int, int);
int get_submax_log(const vector<int>&, int, int);
int get_submax_1(const vector<int>&);
int main(){
    vector<int> lt = {-3, 11, -4, 13, -5, -10};
    cout << get_submax(lt) << endl;
    cout << get_submax_2(lt) << endl;
    cout << get_submax_1(lt) << endl;
    int x = 1000;
    int y = 20; 
    int z = 100;
    cout << max3(x, y, x + y) << endl;
    return 0;
}
template <typename T>
T get_submax(const vector<T>& yj){
    T sub_max = 0;
    T sub_max_temp = 0;
    for(int i = 0; i < yj.size(); i++){
        sub_max_temp += yj[i];
        if(sub_max_temp > sub_max)
            sub_max = sub_max_temp;
        if(sub_max_temp < 0)
            sub_max_temp = 0;
    }
    return sub_max;
}
int get_submax_2(const vector<int>& yj){
    int sub_max = 0;
    for(int i = 0; i < yj.size(); i++){
        int sub_max_temp = 0;
        for(int j = i; j < yj.size(); j++){
            sub_max_temp += yj[j];
            if(sub_max_temp > sub_max)
                sub_max = sub_max_temp;
        }
    }
    return sub_max;
}
int max3(int a, int b, int c){
    int max = 0;
    int num[3] = {a, b, c};
    for(int i = 0; i< 3; i++){
        if(num[i] > max)
            max = num[i];
    }
    return max;
}
int get_submax_log(const vector<int>& yj, int left, int right){
    if(left == right)
        return yj[left];
    int center = (left + right) / 2;
    int submax_left = get_submax_log(yj, left, center);
    int submax_right = get_submax_log(yj, center + 1, right);
    int submax_left_border = 0;
    int submax_left_border_temp = 0;
    for(int i = center; i >= left; i--){
        submax_left_border_temp += yj[i];
        if(submax_left_border_temp > submax_left_border)
            submax_left_border = submax_left_border_temp;
    }
    int submax_right_border = 0;
    int submax_right_border_temp = 0;
    for(int i = center + 1; i <= right; i++){
        submax_right_border_temp += yj[i];
        if(submax_right_border_temp > submax_right_border);
        submax_right_border = submax_right_border_temp;
    }
    return max3(submax_left, submax_right, submax_left_border +
            submax_right_border);
}
int get_submax_1(const vector<int>& yj){
    return get_submax_log(yj, 0, yj.size() - 1);
}


