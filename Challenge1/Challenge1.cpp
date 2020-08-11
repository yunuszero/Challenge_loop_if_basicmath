#include<stdio.h>
#include<math.h>

double FindAverage(double* x,int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
	}
	return sum / n;
}

double FindSD(double* x,int n)
{
	if (n == 1) return 0;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow(fabs(x[i] - FindAverage(x,n)), 2);
	}
	return sqrt(sum / (n - 1));
}

int main()
{
	int n, m;
	double average, sd;
	scanf_s("%d %d", &n, &m);
	double arr[1010];
	if (n < m)
	{
		for (int i = n; i <= m ; i++)
		{
			printf("%d ", i);
			arr[i - n] = i;
		}
	}
	else
	{
		for (int i = n; i >= m; i--)
		{
			printf("%d ", i);
			arr[n - i] = i;
		}
	}
	printf("\n");
	average = FindAverage(arr, abs(n - m) + 1);
	sd = FindSD(arr, abs(n - m) + 1);
	printf("average = %.1lf\n", average);
	printf("SD = %.2lf", sd);

	return 0;
}