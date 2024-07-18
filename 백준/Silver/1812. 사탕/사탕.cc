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

	int n;
	cin >> n;
	vector<int> v(n);

	// v의 총합은 짝수임. a+b b+c c+a 다 더하면 2(a+b+c)가 나와야함.
	int total = 0;
	for(int i = 0; i< n;i++)
	{
		cin >> v[i];
		total += v[i];
	}
	total /= 2;
	
	for (int i = 1; i < n; i+=2)
	{
		total -= v[i];
	}
	
	int prev = total;
	cout << prev << '\n';
	for (int i = 0; i < n-1; i++)
	{
		int cur = v[i] - prev;
		cout << v[i] - prev << '\n';
		prev = cur;
	}

	return 0;
}