#include <iostream>
#include <string>
#include <map>
using namespace std;
struct Point
{
  int top=-1;
  int bottom=-1;
  int right=-1;
  int left=-1;
};
int N;
int arr[20][20];
map <int , Point > mMapRect; //map between color key with 4 point of key
map <int, bool> mMapOverlap; //map between color key with overlap or not

//function to check which color overlap other each color
void checkContinue(Point p, int key)
{
    for (auto i = p.top; i<=p.bottom;i++)
        for(auto j = p.left;j<=p.right;j++)
            //color in arr[i][j] overlap color key => should set value is false
            if(arr[i][j] != key) mMapOverlap[ arr[i][j] ] = false;
}


int main()
{
    cin>>N;
    mMapRect.clear();
    for(auto i=0;i<N;i++)
    {
        char tmp[100];
        cin>>tmp;
        for(auto j=0;j<N;j++)
        {
            arr[i][j] = tmp[j]-'0';
            int key =  arr[i][j];
            if(key == 0) continue;
            auto it = mMapRect.find(key);
            if(it == mMapRect.end()) //not found key in map => it is new color, first define 4 point
            {
                Point p;
                p.top = i;
                p.bottom = i;
                p.right = j;
                p.left = j;
                mMapRect[key]= p;
                mMapOverlap[key] = true;
            }
            else //color had in the map, should update correct point
            {   if (j > it->second.right) mMapRect[key].right = j ;
                if (j < it->second.left) mMapRect[key].left =  j ;
                mMapRect[key].bottom = i;
            }
        }
    }
    //check all color detected and found which color overlap it
    for (auto& it: mMapRect) 
    {
        checkContinue(it.second, it.first);
    }
    //check list color, which color not overlap any color
    auto result = 0;
    for (auto& it: mMapOverlap) 
    {
        if(it.second == true) result++;
    }
    
    cout <<result<<endl;
    return 0;
}