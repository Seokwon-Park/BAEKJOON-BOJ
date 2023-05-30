#include <bits/stdc++.h>

using namespace std;

int arr[10];
bool used1[15];//y
bool used2[30];//우상향 대각
bool used3[30];//우하향 대각
int n;
int answer;

void func(int cur)
{
	if (cur == n)
	{
		answer++;
		return;
	}

	for (int col = 0; col< n; col++)
	{
		if (used1[col] || used2[col + cur] || used3[cur - col + n - 1])
			continue;
		used1[col] = true;
		used2[col+cur] = true;
		used3[cur-col+n-1] = true;
		func(cur + 1);
		used1[col] = false;
		used2[col + cur] = false;
		used3[cur - col + n - 1] = false;
	}


}

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << answer;

	return 0;
}
