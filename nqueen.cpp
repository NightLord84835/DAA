#include<iostream>
using namespace std;
int IsSafe(int Queen[][10],int row,int col,int n) //function to check if queen is in attacking position
{
	for(int i=0;i<row;i++)   //Checking for column
	{
		if(Queen[i][col]==1)
		{
			return 0;   //returning 0 if queen is present
		}
	}
	for(int i=row,j=col ;i>=0 && j>=0 ;i--,j--)  //checking for left diagonal
	{
		if(Queen[i][j]==1)
		{
			return 0;	//returning 0 if queen is present
		}
	}
	for(int i=row,j=col;i>=0 && j<n;i--,j++)    //checking for right diagonal
	{
		if(Queen[i][j]==1)
		{
			return 0;	//returning 0 if queen is present
		}
	}
	return 1;	//returning 1 if queen is not present
}
int PlaceQueen(int Queen[][10],int n,int row) //function to place queens on board
{
	if(n==row)	//checking if all queens are placed on board
	{
		for(int i=0;i<n;i++)	//printing board in this case 
		{
			for(int j=0;j<n;j++)
			{
				cout<<Queen[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
		return 1;	//returning 1 as all queens are placed safely
	}
	int flag=0;	//to check if queen is placed or not
	for(int i=0;i<n;i++)	//if queens are not placed then loop to check next rows
	{
		if((IsSafe(Queen,row,i,n))==1)	//condition to check if place is safe to place queen or not
		{
			Queen[row][i]=1;	//placing 1 if place is safe 
			flag=PlaceQueen(Queen,n,row+1)||flag;	//resetting flag 
			Queen[row][i]=0;	//for next iterations
		}
	}
	return flag;
}
int main()
{
	int n;
	cout<<"Enter No. of Queens:";
	cin>>n;
	int Queen[10][10]={0};
	if((PlaceQueen(Queen,n,0))==1)
	{
		cout<<"Solution Exits!!\n";
	}
	else
	{
		cout<<"Oops Solution Does not Exits!!\n";
	}
	return 0;
}
