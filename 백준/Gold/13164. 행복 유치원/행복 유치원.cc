#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

// 풀이 메모
// 학생들 간 gap을 구한 다음
// gap을 정렬 해서 gap이 큰 구간을 k-1개 만큼 빼주면 k개의 조가 된다.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> gap(n - 1);
	for (int i = 1; i < n; i++)
	{
		gap[i - 1] = v[i] - v[i - 1];
	}

	sort(gap.begin(), gap.end());

	k--;
	while (k--)
	{
		gap.pop_back();
	}

	ll ans = 0;
	for (int i = 0; i < gap.size(); i++)
	{
		ans += gap[i];
	}

	cout << ans;

	return 0;
}