#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1 || n == 3) // 2와 5로 표현할 수 없는 금액
	{
		cout << -1;
		return 0;
	}

	// 우선, 5원을 거슬러 줄 수 있는 만큼 주는게 최소를 만드는데 이득.
	int five = n / 5;
	int mod5 = n % 5;
	n %= 5;
	if (mod5 % 2 == 1)//근데 만약 5원으로 다 거슬러줬는데 홀수라면 5원을 한개 덜 거슬러주고 2원으로 처리하면 된다.
	{
		n += 5;
		five--;
	}
	int two = n/2;

	cout << five + two;

	return 0;
}