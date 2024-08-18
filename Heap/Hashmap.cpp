#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> mp;
    pair<string, int> p = make_pair("a", 1);
    pair<string, int> q("b", 3);
    mp.insert(p);
    mp.insert(q);
    mp["c"] = 3;
    mp["d"] = 4;
    mp["e"] = 5;
    cout << mp.at("c") << endl;
   // cout<<mp["g"]<<endl;
    cout<<mp.size()<<endl;
    cout<<mp.at("k");


    return 0;
}