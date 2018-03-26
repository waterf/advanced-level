#include <iostream>
#include <vector>
using namespace std;

//elevator

int main()
{
	int n, ele, sum = 0;
	vector<int> e;
	cin >> n;
	sum = 5*n;
	e.push_back(0);
	for( int i=0;i<n;i++ )
	{
		cin >> ele;
		e.push_back(ele);
	}
	vector<int>::iterator iter = e.begin();
	for( ;iter!=e.end()-1;++iter )
	{
		if( *iter > *(iter+1) )
		{
			sum += (*iter-*(iter+1))*4;
		}else if( *iter<*(iter+1) ){
			sum += (*(iter+1)-*iter)*6;
		}
	}
	cout << sum << endl;
	return 0;
}