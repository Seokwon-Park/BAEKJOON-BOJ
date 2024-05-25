#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;

	vector<ll> v(1000005);
	vector<ll> pfsum(1000005);
	// 처음 알게된 방식 개신기;;
	// i = 1이면
	// j = 1~1e6이고
	// i * j라는 수는 무조건 i를 약수로 가져감.
	// 그리고 i를 무조건 약수로 가져가는 i*j는 문제의 범위인 1000000보다 작아야 한다.
	// 약수의 합은 i가 약수이기 때문에 v[i*j]에 i를 더해준다.
	for (int i = 1; i <= 1000000; i++) 
	{
		for (int j = 1; j <= 1000000/i; j++)
		{
			v[i * j] += i;
		}
	}

	for (int i = 1; i <= 1000000; i++)
	{
		pfsum[i] = pfsum[i - 1] + v[i];
	}


	while (tc--)
	{
		int n;
		cin >> n;
		
		cout << pfsum[n] << '\n';
	}


	return 0;
}
