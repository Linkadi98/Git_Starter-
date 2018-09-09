#include <iostream>
#define max 10000

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k, m;
	cin >> n;
	cout << "\n";
	int a[max][2];
	int *b = new int[n+2];
// nhập danh sách cây

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i][0] >> a[i][1] ;
		cout << "\n";	
		for (int j = 0; j < n; ++j)
		{
			if (a[i][0] == j)
			{
				b[j] = b[j] + 1;
			}
			if (a[i][1] == j)
			{
				b[j] = b[j] + 1;
			}

		}
	}
	
	cout << "\n";
	m = n;

// in ra prufer code

	for (int i = 0; i < n-1; ++i) // vòng lặp này để thực hiện thuật toán n-2 lần 
	{
		int min = 1000000;
		
		for (int j = 0; j < m; ++j) // vòng lặp này để thực hiện thuật toán tìm prufer code
		{
			if (b[j] == 1 && a[j][0] == j){
				if (min > a[j][0]){
					min = a[j][0];
					k=j;
				}
			}
			if (b[j] == 1 && a[j][1] == j){
				if (min > a[j][1]){
					min = a[j][1];
					k=j;
				}

			}
		}
		if (a[k][0] == k)
		{
			b[k]--;
		}
		else if(a[k][1] == k)
		{
			b[k]--;
		}
		// khi bậc của đỉnh bằng O thì in ra phần tử kề với đỉnh đó

		if (b[k] == 0 && a[k][0] == k){
			cout << a[k][1] << "  "; 
		}
		else {
			cout << a[k][0] << "  ";
		}
		
		a[k][0] = a[k+1][0];
		a[k][1] = a[k+1][1];
		m--; 
	}
	return 0;
}
	
// kết thúc
	

