#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int N;//Map Size
char mapData[110][110];//Map information
map<int,int> mMapPositionSum;
bool visited[110*110] = {false};
vector<int> mVectorOrder;

void printVector()
{
    return;
    cout<<"------ before "<<mVectorOrder.size()<<endl;
    for (auto i=0;i<mVectorOrder.size();i++)
    {
        cout<<"i :"<<i<<" "<<mVectorOrder[i]<<endl;
    }
    cout<<"------ end "<<endl;
}

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> mapData[i];
	}
}

void findIndex(int pos)
{
    int vSize = mVectorOrder.size();
    if(vSize == 0)
    {
        mVectorOrder.push_back(pos);
        printVector();
        return;
    }
    int index = 0;
    for (index = mVectorOrder.size() - 1; index >= 0 ; index--)
    {
        auto idPosition = mVectorOrder[index];
        if(mMapPositionSum[idPosition] < mMapPositionSum[pos])
        {
           break;
        }
    }
    mVectorOrder.insert(mVectorOrder.begin()+index+1, pos);
    printVector();
}

void findNextPoint(int i, int j)
{
    mVectorOrder.erase(mVectorOrder.begin());
    auto value = i*N + j;
    visited[value] = true;
    
    auto left = j > 0 ? value - 1 : -1;
    if( (left != -1) && (visited[left] == false) )
    {
        mMapPositionSum[left] = mMapPositionSum[value] + mapData[i][j-1] -'0';
        findIndex(left);
        visited[left] = true;
    }
    
    auto right = j < N-1 ? value + 1 : -1;
    if( (right != -1) && (visited[right] == false) )
    {
        mMapPositionSum[right] = mMapPositionSum[value] + (mapData[i][j+1]-'0');
        findIndex(right);
        visited[right] = true;
    }
    
    auto top = i > 0 ? value - N : -1;
    if( (top != -1) && (visited[top] == false) )
    {
        mMapPositionSum[top] = mMapPositionSum[value] + mapData[i-1][j] -'0';
        findIndex(top);
        visited[top] = true;
    }
    
    auto bottom = i < N-1 ? value + N : -1;
    if( (bottom != -1) && (visited[bottom] == false) )
    {
        mMapPositionSum[bottom] = mMapPositionSum[value] + mapData[i+1][j] -'0';
        findIndex(bottom);
        visited[bottom] = true;
    }
}



int main(){
	int ans = -1;
	Input_Data();		//	Input function
	
    mMapPositionSum[0] = 0;
    mVectorOrder.push_back(0);
    while(mVectorOrder.size()>0)
    {
        // printVector();
        auto firstPost = mVectorOrder[0];
        // cout<<"firstPost -- "<<firstPost<<endl;
        auto i = firstPost/N;
        auto j = firstPost%N;
        if( ((i==N-1) && (j==N-2)) || ((i==N-2) && (j==N-1)) )
        {
            ans = mMapPositionSum[i*N + j];
            break;
        }
        findNextPoint(i,j);
    }
    //	Write the code
	cout << ans << endl;	//	Output answer

	return 0;
}


