#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) // 가장 긴변으로 고정.
	{
		for (int j = 1; j <= (n-i)/2; j++) // 남은 길이의 절반까지만 대조 해봄.
			// 절반을 넘어가면 어차피 같은 조합을 이전에 시도해보았기때문에 중복이다.
		{
			int k = n - i - j;
			if (i >= j && i >= k)
			{
				if (i < j + k)
					cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}