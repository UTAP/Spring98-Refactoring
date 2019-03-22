#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

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

		int num;
		for (i = 2; i <= 7; i++)
		{
			int r = n / pow(10, i);
			if (r == 0)
			{
				num = i;
				break;
			}
		}
		int t;
		int number[num];
		for (i = num - 1; i >= 0; i--)
		{
			t = n % 10;
			number[i] = t;
			n /= 10;
		}
		i = 1;
		int cu = number[0];
		int temp = cu;
		number[0] = 0;
		t = num;
		while (t != 0)
		{
			i = (cu + i) % num;
			if (i == 0)
				i = num;
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
