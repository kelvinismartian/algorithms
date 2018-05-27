#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target){
    unordered_map<int, int> hash;
    vector<int> result;
    for(int i = 0; i < numbers.size(); i++){
        int numToFind = target - numbers[i];
        if(hash.find(numToFind) != hash.end()){
            result.push_back(hash[numToFind] + 1);
            result.push_back(i + 1);
            return result;
        }
        hash[numbers[i]] = i;
    }
    return result;
}
int main(){
    int target = 13;
    vector<int> lt = {1, 4, 10, 9};
    vector<int> result = twoSum(lt, 13);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}
