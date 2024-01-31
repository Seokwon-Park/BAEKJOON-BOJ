#include<bits/stdc++.h>
using namespace std;

bool isMeet(int a, int b)
{
	if ((a + 1) / 2 == (b + 1) / 2) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;

	int round = 1;
	while (!isMeet(a, b))
	{
		n /= 2;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		round++;
	}

	cout << round;

	return 0;
}