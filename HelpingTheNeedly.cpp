#include <iostream>
using namespace std;

int N;//The number of goods to send 
int C[10];//The number of BOXes(in order of 1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000)
int sol[10];//The number of boxes to send
int sumArr[10] = {0};
int number[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}
void OutputData(int ans){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}
int main(){
	int ans = 0;

	InputData();//	Input function
	int index = 1;
	sumArr[0]=C[0];
	for(auto i = 1;i<10;i++)
	{ 
		sumArr[i] = sumArr[i-1]+ number[i] * C[i];
		if( sumArr[i] >= N)
		{
			index = i;
			break;
		}
	}
	for (auto i= index ; i>0; i--)
	{
		int delta = N - sumArr[i-1];
		if (delta < 0)
		{
			sol[i] = 0;
		}
		else
		{
			if(delta % number[i] == 0)
			{ 
				sol[i] = (delta / number[i]);
			} 
			else 
			{
				sol[i] = (delta / number[i]) + 1;
			}
			if(sol[i]> C[i])
			{
				sol[i] = C[i];
			}
			ans += sol[i];
			N= N- sol[i]* number[i];
		}
	}
	sol[0] = N;
	ans += sol[0];
	OutputData(ans);// Output function
	return 0;
}