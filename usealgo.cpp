#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;
char toLower(char ch){return tolower(ch);}
string& ToLower(string& str){
    transform(str.begin(), str.end(), str.begin(), toLower);
    return str;
}
void display(const string& str){
    cout << str << " ";
}
int main(){
    vector<string> words;
    cout << "Enter words(quti to quit):\n";
    string input;
    while(cin >> input && input != "quit")
        words.push_back(input);
    cout << "You have entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;
    //set.....
    set<string> wordset;
    transform(words.begin(), words.end(), 
            insert_iterator<set<string> > (wordset, wordset.begin()),
            ToLower);
    cout << "\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;
    //map....
    map<string, int> wordmap;
    set<string>::iterator si;
    for(si = wordset.begin(); si != wordset.end(); si++){
        wordmap[*si] = count(words.begin(), words.end(), *si);
    }
    cout << "\nWord frequency:\n";
    for(si = wordset.begin(); si != wordset.end(); si ++){
        cout << *si << "\t" << wordmap[*si] << endl;
    }
    return 0;
}
