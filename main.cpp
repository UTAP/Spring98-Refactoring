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

vector<int> split_number_to_digits(int number)
{
	vector<int> result;
	while (number)
	{
		result.push_back(number % 10);
		number /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

void print_result(int case_number, bool result)
{
	cout << "Case " << case_number << ": ";
	if (result)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}

int main()
{
	int j = 0;

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;

		int len = length(n);
		vector<int> number = split_number_to_digits(n);
		int i = 1;
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
		print_result(j + 1, cu == 0);
		j++;
	}
	return 0;
}
