// Write a program to solve the travelling salesman problem and to print the path and the cost using LC Branch and Bound. 

#include<iostream>
#include <climits>

using namespace std;

const int MAX = 10;
int n;
int graph[MAX][MAX];
int finalPath[MAX];
int finalCost = INT_MAX;
bool visited[MAX];

void copyToFinalPath(int currentPath[]) {
    for (int i = 0; i < n; i++) {
        finalPath[i] = currentPath[i];
    }
    finalPath[n] = currentPath[0];
}

int firstMin(int i) {
    int min = INT_MAX;
    for (int k = 0; k < n; k++) {
        if (graph[i][k] < min && i!= k) {
            min = graph[i][k];
        }
    }
    return min;
}

int secondMin(int i) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (i==j) {
            continue;
        }
        if (graph[i][j] <= first) {
            second = first;
            first = graph[i][j];
        } else if (graph[i][j] <= second && graph[i][j] != first) {
            second = graph[i][j];
        }
    }
    return second;
}

int manualFind(int currentPath[], int level, int value) {
    for (int i = 0; i < level; ++i) {
        if (currentPath[i] == value) {
            return i;
        }
    }
    return level;
}

void manualFill(auto array[], int start, int end, auto value) {
    for (int i = start; i < end; ++i) {
        array[i] = value;
    }
}

void display(int arr[][MAX] , int n) {
    for (int i = 0; i < n ;i++) {
        for (int j = 0; j < n ;j++) {
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void TSPRec(int curr_bound, int curr_weight, int level, int currentPath[]) {
    if (level == n) {
        if (graph[currentPath[level-1]][currentPath[0]] != 0) {
            int curr_cost = curr_weight + graph[currentPath[level-1]][currentPath[0]];
            if (curr_bound < finalCost) {
                copyToFinalPath(currentPath);
                finalCost = curr_cost;
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (graph[currentPath[level-1]][i] != 0 && manualFind(currentPath,level,i) == level) {
            int temp = curr_bound;
            curr_weight += graph[currentPath[level-1]][i];
            if (level == 1) {
                curr_bound -= (firstMin(currentPath[level - 1]) +firstMin(i)) / 2;
            } else {
                curr_bound -= (secondMin(currentPath[level - 1]) + firstMin(i)) / 2;
            }
            if (curr_bound + curr_weight < finalCost) {
                currentPath[level] = i;
                TSPRec(curr_bound,curr_weight,level+1,currentPath);
            }
            curr_weight -= graph[currentPath[level - 1]][i];
            curr_bound = temp;
            manualFill(currentPath,level,n,-1);
        }
    }
}

void TSP() {
    int currentPath[MAX];
    int curr_bound = 0;
    manualFill(currentPath,0,MAX,-1);
    manualFill(visited,0,MAX,false);
    
    for (int i = 0; i < n; i++) {
        curr_bound += (firstMin(i) + secondMin(i));
    }
    curr_bound = curr_bound/2 + (curr_bound % 2);
    currentPath[0] = 0;
    visited[0] = 0;
    TSPRec(curr_bound,0,1,currentPath);
}

int main() {
    cout<<"Enter the Number of Cities >> ";
    cin>>n;
    cout<<"Enter the cost matrix >> \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>graph[i][j];
        }
    }
    TSP();
    cout << "Optimal Path: ";
    for (int i = 0; i <= n; i++)
        cout << finalPath[i] << " ";
    cout << endl;

    cout << "Minimum Cost: " << finalCost << endl;

    return 0;
}

// OUTPUT >>

// Enter the number of cities: 5
// Enter the adjacency matrix representing the graph:
// 0
// 20
// 30
// 10
// 11
// 15
// 0
// 16
// 14
// 2
// 3
// 5
// 0
// 2
// 4
// 19
// 6
// 18
// 0
// 3
// 16
// 4
// 7
// 16
// 0
// Optimal Path: 0 3 1 4 2 0
// Minimum Cost: 28
// PS P:\VsCode>







