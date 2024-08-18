#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// When you sort an array, it is enough to check for the
// common characters of the the first & last string of the sorted vector
class Solution
{
public:
    string longestCommonPrefix(vector<string> &str)
    {
        sort(str.begin(), str.end());             // sorting the array
        string ans = "";                          // creating a new empty string to store the common prefixes
        for (int i = 0; i < str[0].length(); i++) // max iterations = length of the first string
        {
            if (str[0][i] != str[str.size() - 1][i]) // checking the characters of the first and last string
                break;
            ans += str[0][i]; // concatinate if the characters are matching
        }
        return ans;
    }
};
// this can be done using Trie also see leetcode question

int main()
{
}