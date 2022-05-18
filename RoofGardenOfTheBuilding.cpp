#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N;//Number of buildings
int H[80010];//Height of buildings

void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

int main(){
	ll ans = 0;
	Input_Data();		//	Input function

	//	Write the code
	vector<int> downTrend;
	downTrend.push_back (H[0]); 
	for (ll i = 1; i< N;i++)
	{
		for (ll index = downTrend.size()-1; index >= 0;index--)
		{
			if( H[i]< downTrend[index] )
			{
				ll eraseNumber = downTrend.size() - 1 - index; 
				ll remainNumber = index + 1;
				ans += (eraseNumber * (eraseNumber-1) ) /2 + eraseNumber * remainNumber;
				downTrend.erase( downTrend.begin() + index + 1, downTrend.end()); 
				downTrend.push_back (H[i]);
				break;
			}
			if(0 == index) //go to first element
			{
				ll eraseNumber = downTrend.size();
				downTrend.clear();
				downTrend.push_back(H[i]);
				ans += (eraseNumber * (eraseNumber-1) ) /2;
			}
		}
	}
	ll remain = downTrend.size();
	ans += (remain * (remain-1) ) / 2;
	cout << ans << endl; // Output right answer	
	return 0;
}
