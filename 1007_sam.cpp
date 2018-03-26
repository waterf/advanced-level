#include<cstdio>
int bigger(int a,int b)
{    
    return (a>b?a:b);
}
int max(int a,int b,int c)
{
    return bigger(a,bigger(b,c));
}
int maxsubsequencesum(const int A[],int left,int right)
{
    int maxleftsum,maxrightsum;
    int maxleftbordersum,maxrightbordersum;
    int leftbordersum,rightbordersum;
    int centre;
    
    if(left==right)
    {
        if(A[left]>0) return A[left];
        else return 0;
    }
    centre = (left+right)/2;
     printf("%d %d %d\n", left, centre, right);
    maxleftsum=maxsubsequencesum(A,left,centre);
    maxrightsum=maxsubsequencesum(A,centre+1,right);

    maxleftbordersum=0;leftbordersum=0;
    for (int i = centre; i >= left; --i)
    {
        leftbordersum+=A[i];
        if(leftbordersum>maxleftbordersum)
        {
            maxleftbordersum=leftbordersum;
            printf("maxleftbordersum:#%d#\n", maxleftbordersum);
        }
    }

    maxrightbordersum=0;rightbordersum=0;
    for (int i = centre+1; i<=right;++i)
    {
        rightbordersum+=A[i];
        if(rightbordersum>maxrightbordersum)
        {
            maxrightbordersum=rightbordersum;
            printf("maxrightbordersum:/%d/\n", maxrightbordersum);
        }
    }

    return max(maxleftsum,maxrightsum,maxrightbordersum+maxleftbordersum);
}
int main()
{
    int n;
    scanf("%d",&n);
    int A[100];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&A[i]);
    }
    printf("%d\n",maxsubsequencesum(A,0,n-1));
}