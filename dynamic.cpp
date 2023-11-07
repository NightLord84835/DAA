#include <iostream>
using namespace std;

int max(int a, int b) { //max function
    if(a>b)
    	return a;
    else
    	return b;
}

void knapsack_dynamic(int n, int cp, int wts[], int pfts[]){
	int dp[n+1][cp+1]; //array declare one row and column more than n,cp
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=cp;j++){
			if(i==0 || j==0){
				dp[i][j]=0; //first row and column = 0
			}
			else if(wts[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], pfts[i-1]+dp[i-1][j-wts[i-1]]); //dynamic programming cond. 1
			}
			else{
				dp[i][j]=dp[i-1][j]; //dynamic programming cond. 2
			}
		}
	}
	
	int selected_items[n]; //array of selected items
	int totalp = dp[n][cp]; //total profit is last index of dp 2d array
	int w = cp; //assign caapacity to a variable
	int count =0; //initially count 0
	
	for(int i=n;i>0 && totalp>0;i--){ //loop from n to 0,total profit>0,decrement
		if(totalp == dp[i-1][w]){ //item not selected
			continue;
		}
		else{ //item selected
			selected_items[count++] = i; //increase count
			totalp -= pfts[i-1]; 
			w -= wts[i-1];
		}
	}
	
	cout<<"Max. Profit: "<<dp[n][cp]<<"\n";
	cout<<"Selected items: ";
	for(int i=count-1;i>=0;i--){
		cout<<selected_items[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	int n,cp;
	cout<<"Enter the number of objects: ";
    cin>>n;
    cout<<"Enter the capacity of the bag: ";
    cin>>cp;
    
    int wts[n], pfts[n];
    for (int i = 0; i < n; i++){
    	cout << "Enter the weight and profit of each object:" << endl;
        cin >> wts[i] >> pfts[i];
    }
    
    knapsack_dynamic(n, cp, wts, pfts);
    return 0;
}
