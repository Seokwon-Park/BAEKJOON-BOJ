#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int ans = 0;

	int st = 0;
	int en = n-1;
	//1 2 3 5; st en (1, 5)
	//조건을 만족하는 경우 st보다 크고 en또는 en 이전 인덱스에 있는 녀석들은 st랑 더하면 무조건 조건 만족!
	//조건을 벗어나는 경우 en의 크기를 줄여준다.

	while (st < en)
	{
		if (v[st] + v[en] <= s)
		{
			ans += en - st;
			st++;
		}
		else
		{
			en--;
		}
	}
	cout << ans;

	return 0;
}