#include <iostream>
#include <stdlib.h> 
using namespace std;

int N;//The number of candidates
int A[100000 + 10];//Temperament value

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int main(){
    InputData();//	Input function
		
	int checkPoint = 0;
	for(auto i=0;i<N;i++)
	{
		if(A[i] > 0)
		{
			checkPoint = i;
			break;
		}
	}
	int left = checkPoint - 1;
	int right = checkPoint;
	int minLeft = 0;
	int minRight = N-1;
	int min = 999999999;	
	while( checkPoint> 0 )
	{
	auto tmp = A[left] + A[right];
	if (abs(min) >= abs(tmp) )
	{
		minLeft = left;
		minRight = right;
		min = tmp;
	}
	if (tmp < 0) {
		// dich Phai
		if(right < N-1)
		{
			right ++;
		}
		else
		{
			break;
		}
	}
	else if (tmp> 0)
	{
		//dich trai
		if(left > 0)
		{
			left --;
		}
		else
		{
			break;
		}
	}
	else
	{ //tmp
		//dich ca 2 ben
		if (right < N-1)
		{
			right ++; 
		}
		else 
		{
			break;
		}
		if(left > 0) 
		{
			left --;
		}
		else 
		{
			break;
		}
	}
	}
	cout <<minLeft<<" "<<minRight<<endl;
	//	Create the code	
    return 0;
}
