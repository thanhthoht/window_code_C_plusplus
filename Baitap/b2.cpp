#include <bits/stdc++.h>
using namespace std;
  
int main()
{
	int n;
	cin>>n;
	int k;
    vector<int> v;
	for(int i=0;i<n;i++){
		cin>>k;
		v.push_back(k);
	}
    sort(v.begin(), v.end());
  
    cout << "Sorted \n";
    for (auto x : v)
        cout << x << " ";
  
    return 0;
}