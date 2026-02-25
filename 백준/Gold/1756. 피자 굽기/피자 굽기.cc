#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d, n;
	cin >> d >> n;
	if (d < n)
	{
		cout << 0;
		return 0;
	}
	int cur = INF;
	stack<int> st;
	for (int i = 0; i < d; i++)
	{
		int x;
		cin >> x;
		if (x < cur)
		{
			cur = x;
		}
		st.push(cur);
	}
	
	for (int i = 0; i < n; i++)
	{
		int piz; 
		cin >> piz;
		while (!st.empty() && st.top() < piz)
		{
			st.pop(); // 피자 못들어감
		}
		if (st.empty())
		{
			cout << 0;
			return 0;
		}
		st.pop();// 피자 넣음
	}

	cout << st.size() + 1;


	return 0;
}