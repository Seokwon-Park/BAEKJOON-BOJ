#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;
bool isused[21][1005]; //n = 20  L(50)을 20번 쓰면 1000까지 범위
int ans = 0;

void func(int k, int val)
{
	
	if (k == n)
	{
		if (!isused[k][val])
		{
			isused[k][val] = true;
			ans++;
		}
		return;
	}
	if (isused[k][val]) return;
	isused[k][val] = true;
	func(k + 1, val + 1);
	func(k + 1, val + 5);
	func(k + 1, val + 10);
	func(k + 1, val + 50);
	

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	func(0, 0);
	cout << ans;
	
	return 0;
}