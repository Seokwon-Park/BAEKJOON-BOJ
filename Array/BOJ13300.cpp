#include <bits/stdc++.h>

using namespace std;

int student[13];
int n, k;
int room = 0;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int s, y;
		cin >> s >> y;
		student[(y - 1) * 2 + s + 1]++;
	}

	for (int i = 1; i < 13; i++)
	{
		int tmp = student[i] / k;
		if (student[i] % k != 0)
			tmp++;
		room += tmp;
	}
	cout << room;				
		
	return 0;
}

