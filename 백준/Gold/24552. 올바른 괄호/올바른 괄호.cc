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

	vector<int> v;
	string s;
	cin >> s;
	//s는 무조건 틀린 괄호
	bool lr = 0; // (: 0 ): 1
	int wrongIdx = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == '(')
		{
			v.push_back(i);
		}
		else
		{
			if (!v.empty())
			{
				v.pop_back();
			}
			else // 오른쪽괄호가 더 많다는 뜻
			{
				lr = 1;
				wrongIdx = i;
			}
		}
	}
	if (lr == 0)
	{
		wrongIdx = v.back();
	}

	int ans = 0;
	if (lr == 0)
	{
		for (int i = wrongIdx; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				ans++;
			}
		}
	}
	else
	{
		for (int i = 0; i <= wrongIdx; i++)
		{
			if (s[i] == ')')
			{
				ans++;
			}
		}
	}
	cout << ans;


	return 0;
}