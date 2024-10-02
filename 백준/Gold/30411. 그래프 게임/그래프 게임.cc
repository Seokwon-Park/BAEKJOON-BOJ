//에디토리얼 봄
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	// 문제에서 설명하는 조건은 이분 그래프를 만들라는 소리고
	// 따라서 정점을 2부분으로 나눠서 서로 다른 그룹끼리만 연결해야 
	// 조건을 충족할 수 있다.
	// 짝수인 경우 n/2 * n/2만큼 이어줄 수 있고
	// 홀수인 경우 n/2 * (n/2+1)만큼 이어줄 수 있다.
	ll mx = 0;
	if (n % 2 == 0)
	{
		mx = (n / 2) * (n / 2);
	}
	else
	{
		mx = (n / 2) * (n / 2 + 1);
	}

	if (k <= mx)
	{
		cout << "YES\n";
		int cnt = 0;
		for (int i = 1; i <= n / 2; i++)
		{
			for (int j = n / 2 + 1; j <= n; j++)
			{
				cout << i << ' ' << j << '\n';
				cnt++;
				if (cnt == k)
					return 0;
			}
		}
	}
	else
	{
		cout << "NO";
	}



	return 0;
}