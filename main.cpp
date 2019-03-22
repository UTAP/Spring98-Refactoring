#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

int length(int n)
{
	for (int i = 0; ; i++)
	{
		int r = n / pow(10, i);
		if (r == 0)
			return i;
	}
}

int main()
{
	int i = 0;
	int n;
	int j = 0;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		int len = length(n);
		vector<int> number;
		for (i = len - 1; i >= 0; i--)
		{
			number.push_back(n % 10);
			n /= 10;
		}
		reverse(number.begin(), number.end());
		i = 1;
		int cu = number[0];
		int temp = cu;
		number[0] = 0;
		int t = len;
		while (t != 0)
		{
			i = (cu + i) % len;
			if (i == 0)
				i = len;
			cu = number[i - 1];
			if (cu == -1)
				break;
			number[i - 1] = -1;
			t--;
		}
		cout << "Case " << j + 1 << ": ";
		if (cu == 0)
			cout << "Yes\n";
		else if (cu == -1)
			cout << "No\n";
		j++;
	}
	return 0;
}
