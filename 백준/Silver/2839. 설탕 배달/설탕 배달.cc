#include <iostream>

int main()
{
	using namespace std;

	int n;
	cin >> n;

	int answer = 0;
	
	while(1)
	{
		if (n % 5 == 0)
		{
			answer += n / 5;
			break;
		}
		answer += 1;
		n -= 3;
		if (n < 0)
		{
			answer = -1;
			break;
		}
	}

	cout << answer;
		
	return 0;
}
