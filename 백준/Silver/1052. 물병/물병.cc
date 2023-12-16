#include <bits/stdc++.h>

using namespace std;

int checkbit(int n)
{
	int count = 0;
	while (n > 0)
	{
		if (n % 2 == 1) count++;
		n /= 2;
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	//어떤 값을 2진수로 바꿨을때 1의 개수가 k와 같을때 까지 몇번더했는지 확인
	//예) 7개의 물병을 3개로 만들고 싶다. (4, 2, 1) = 111 
	// 13 = 1101 인데 2개로 만들어야 한다 그러면 11000이 되도록 3을 더하기

	int adder = 1;
	int answer = 0;
	while (true)
	{
		int bitcount = checkbit(n);
		if (bitcount <= k) break;
		if ((n & adder) == adder)
		{
			answer += adder;
			n += adder;
		}
		adder *= 2;
	}
	cout << answer;

	return 0;
}