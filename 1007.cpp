#include <cstdio>
#define MX 10000

int maxSum=-1, maxStart, maxEnd;

int max3(int a, int b, int c)
{
	int mx;
	mx = a>b?a:b;
	return mx>c?mx:c;
}

int maxSubSequence(int A[], int left, int right)
{
	int maxLeftSum, maxRightSum;
	int maxLeftBorderSum, maxRightBorderSum;
	int leftBorderSum, rightBorderSum;
	int center;

	if( left==right )
	{
		if( A[left]>0 )return A[left];
		else return 0;
	}

	center = (left+right)/2;

	maxLeftSum = maxSubSequence(A, left, center);
	maxRightSum = maxSubSequence(A, center+1, right);

	maxLeftBorderSum = 0, leftBorderSum = 0;
	for( int i=center;i>=left;i-- )
	{
		leftBorderSum += A[i];
		if( maxLeftBorderSum < leftBorderSum )
			maxLeftBorderSum = leftBorderSum;
	}
	maxRightBorderSum = 0, rightBorderSum = 0;
	for( int i=center+1;i<=right;i++ )
	{
		rightBorderSum += A[i];
		if( maxRightBorderSum < rightBorderSum )
			maxRightBorderSum = rightBorderSum;
	}
	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
}

void maxSubSequence_n(int A[], int n)
{
	int nowSum=0, nowStart = 0, nowEnd = 0;

	for( int i=0;i<n;i++ )
	{
		nowSum += A[i];
		if( maxSum<nowSum)
		{
			maxSum = nowSum;
			nowEnd = i;
			maxStart = nowStart;
			maxEnd = nowEnd;

		}else if( nowSum<0 ){
			nowStart = i+1;
			nowEnd = i+1;
			nowSum = 0;
		}
	}
}

void maxSubSequence_n2( int A[], int n)
{
	int thisSum=0;
	for( int i=0;i<n;i++ )
	{
		thisSum = 0;
		for( int j=i;j<n;j++ )
		{
			thisSum += A[j];
			if( thisSum > maxSum )
			{
				maxStart = i;
				maxEnd = j;
				maxSum = thisSum;
			}
		}
	}
}

int main()
{
	int k, flag = 0;
	int A[MX];
	scanf("%d", &k);

	for( int i=0;i<k;i++ )
	{
		scanf("%d", &A[i]);
		if( A[i] >= 0 )flag = 1;
	}
	if( !flag )
	{
		printf("0 %d %d", A[0], A[k-1]);
		return 0;
	}
	//maxSubSequence_n(A, k);
	maxSubSequence_n2(A, k);
	printf("%d %d %d", maxSum, A[maxStart], A[maxEnd]);
	return 0;
}





