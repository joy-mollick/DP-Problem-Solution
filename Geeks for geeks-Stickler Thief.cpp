#include <iostream>
using namespace std;

int main() {
	int tc;
	int n,a;
	cin>>tc;
	while(tc--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    int inclusive=arr[0];
	    int exclusive=0;
	    int temp;
	    for(int i=1;i<n;i++)
	    {
	        temp=inclusive;
	        inclusive=max(exclusive+arr[i],inclusive);
	        exclusive=temp;
	    }
	    cout<<inclusive<<'\n';
	}
	return 0;
}
