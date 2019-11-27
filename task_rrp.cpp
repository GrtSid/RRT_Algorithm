#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<pair <int , int > > > > vec (100 ,vector<vector<pair < int , int > > >(100));   // 3D Vector
int dist(int a,int b,int c,int d)																	// Function to calculate distance
{
	return(sqrt(pow((a-b),2)+pow((c-d),2)));
}
void dfs(pair < int , int > p , int visit[100][100],int x,int y)			   	// Function to find the path using depth first search
{
	int r1=p.first;
	int r2=p.second;
	
	visit[r1][r2]=1;
	cout<<r1<<" "<<r2<<endl;
	if (r1==x && r2==y)															// If we reach starting coordinates, exit the fucnction
	{
		exit(0);
		return;
	}
	for (int i=0;i<vec[r1][r2].size();i++)
	{
		if(!visit[vec[r1][r2][i].first][vec[r1][r2][i].second])
		{
			p.first=vec[r1][r2][i].first;
			p.second=vec[r1][r2][i].second;
			dfs(p,visit,x,y);
		}
	}
	return;
}
int main()
{
	int x1,y1,x2,y2,o1,o2;
	cout<<"Enter Starting Coordinates: "<<endl; 				// Taking Inputs
	cin>>x1>>y1;
	int s1=x1,s2=y1;
	cout<<"Enter Ending Coordinates: "<<endl;
	cin>>x2>>y2;
	o1=5,o2=6;               //Obstacle
	int ep=5;
int track[100][100]={0};					// 2D Matrix to keep track of nodes included in the plane

while (true)
{
int r1=rand()%100;
int r2=rand()%100;
bool flag=false;
while(track[r1][r2]==1 || ((r1==o1)&&(r2==o2)))     // If the random coordinate generated is already a node in the plane we generate different value
{
	r1=rand()%100;
	r2=rand()%100;
}
int min=INT_MAX;
for (int i=0;i<100;i++)								// Iterating through the 2D Matrix for all the nodes and finding the nearest node to the randomly generated coordinate pair
{
	for (int j=0;j<100;j++)
	{
		if (track[i][j]==1)
		{
			int temp=dist(r1,i,r2,j);
			if (temp<=ep)
			{
				x1=i;y1=j;flag=true;break;
			}
			else if(temp<min)
			{
				x1=i;y1=j;
				min=temp;
			}
		}
	}
	if(flag==true)
	{
		break;
	}
}
int d1=dist(r1,x1,r2,y1);				// Calculating the distance
if (d1<=ep)								// If the distance is less than epilson(ep) we add it as a node and an edge is joined to the nearest node
{
	pair < int , int > p;
	p.first=x1;
	p.second=y1;
	vec[r1][r2].push_back(p);
	p.first=r1;
	p.second=r2;
	vec[x1][y1].push_back(p);
	track[r1][r2]=1;
}
else								// Else a point in the direction of the randomly generated coordinate in added as a node
{
	pair<int,int>p;
	r1=x1+ep*cos(atan2((r2-y1),(r1-x1)));
	r2=y1+ep*sin(atan2((r2-y1),(r1-x1)));
	p.first=x1;
	p.second=y1;
	vec[r1][r2].push_back(p);
	p.first=r1;
	p.second=r2;
	vec[r1][r2].push_back(p);
	track[r1][r2]=1;
}
if (dist(r1,x2,r2,y2)<=ep)						// If the node is near (distance less than epilson(ep)) to the ending point we break from the loop and dfs function is called for path  
{
	int visit[100][100]={0};
	pair<int,int>p;
	p.first=r1;
	p.second=r2;
	cout<<"The Path is as Follows:"<<endl;
	cout<<x2<<" "<<y2<<endl;
	dfs(p,visit,s1,s2);
	break;
}}}
