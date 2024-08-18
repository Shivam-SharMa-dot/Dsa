#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
	string FirstNonRepeating(string A)
	{
		unordered_map<char, int> cnt;
		queue<int> q;
		string ans = " ";
		for (int i = 0; i < A.length(); i++)
		{
			char ch = A[i];
			cnt[ch]++;
			q.push(ch);
			while (!q.empty())
			{
				if (cnt[q.front()] > 1)
				{
					// repeating character
					q.pop();
				}
				else
				{
					// non repeating character
					ans.push_back(q.front());
					break;
				}
			}
			if (q.empty())
			{
				ans.push_back('#');
			}
		}
		return ans;
	}
};
int main()
{

	return 0;
}