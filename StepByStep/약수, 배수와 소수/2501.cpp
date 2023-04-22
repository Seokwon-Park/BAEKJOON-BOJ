#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int ix = 1;
	int answer = 0;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{        
		if (n % i == 0) 
		{
			if (ix == k)
			{
				answer = i;
				break;
			}
			else
			{				
				ix++;
			}                  
		}
	}
	
	if (answer != 0) 
		cout << answer;
	else
		cout << 0;



	return 0;
}
