#include <iostream>
using namespace std;

int N;//Number of mushrooms
int P[150000 + 10];//Mushroom value
int first;
int second;
bool doneFirst;
void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}
void resetValue()
{
	first = 0;
	second = 999999;
	doneFirst = false;
}

int main(){
	int ans = 0;

	InputData();			//	Input function

	//	Write the code
	resetValue();
	for(auto i=0;i<N;i++)
	{
		if( (P[i] > first) && (false == doneFirst))
		{
			first = P[i];
		}
		else
		{
			doneFirst = true;
			if(P[i] < second)
			{
				second = P[i];
			}
			else
			{
				i--;
				ans += (first - second);
				resetValue();
			}
		}
	}
	ans += first;	
	cout << ans << endl;	//	Output answer
	return 0;
}
