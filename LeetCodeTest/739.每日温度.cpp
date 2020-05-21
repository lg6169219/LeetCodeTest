#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/**O(n^2)*/
class Solution_Vec {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> list;
		for(int i = 0; i < T.size(); ++i){
			int num = 0;
			for(int j = i + 1; j < T.size(); ++j){
				if (T[j] > T[i + 1]){
					break;
				}else{
					++num;
				}
			}
			list.push_back(num);
		}
		return list;
	}
};

class Solution_Stack {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> res(n, 0);
		stack<int> st;

		for (int i = 0; i < n; ++i)
		{
			/**新值比栈顶值大，二者索引的差值即为地st.top()天数*/
			while (!st.empty() && T[i] > T[st.top()])
			{
				auto t = st.top();
				st.pop();
				res[t] = i - t;
			}
			st.push(i);
		}
		return res;
	}
};