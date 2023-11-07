#include <iostream>
#include <algorithm>
using namespace std;

class greedy {
public:
    int id;
    float wt;
    float pft;
    float amt;
    float pw;

    void ratio() {
        pw = pft / wt;
    }
};

int main() {
    int n;
    float cp, totalw = 0, totalp = 0;
    cout << "Enter total number of objects: ";
    cin >> n;
    cout << "Enter capacity: ";
    cin >> cp;

    greedy obj[n];

    for (int i = 0; i < n; i++) {
        obj[i].id = i + 1;
        obj[i].amt = 0;
        cout << "Enter weight of object: ";
        cin >> obj[i].wt;
        cout << "Enter profit of object: ";
        cin >> obj[i].pft;
    }

    for (int i = 0; i < n; i++) {
        obj[i].ratio();
    }

    // Implement your custom sorting logic here (e.g., bubble sort)
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (obj[j].pw<obj[j+1].pw){
                swap(obj[j],obj[j+1]);
            }
        }
    }

    cout << "P/W values: ";
    for (int i = 0; i < n; i++) {
        cout << "\n" << obj[i].pw;
    }

    for (int i = 0; i < n; i++) {
        if (totalw < cp) {
            if (obj[i].wt <= (cp - totalw)) {
                obj[i].amt = 1;
                totalw += obj[i].wt;
                totalp += obj[i].pft;
            } else if (obj[i].wt > (cp - totalw)) {
                obj[i].amt = (cp - totalw) / obj[i].wt;
                totalw += (cp - totalw);
                totalp += (obj[i].amt) * (obj[i].pft);
            }
        } else {
            break;
        }
    }

    cout << "\n id \t" << "amount \t" << "weight \t" << "profit \t" << "p/w \n";
    for (int i = 0; i < n; i++) {
        cout << obj[i].id << "\t";
        cout << obj[i].amt << "\t";
        cout << obj[i].wt << "\t";
        cout << obj[i].pft << "\t";
        cout << obj[i].pw << "\n";
    }

    cout << "Total Profit is: " << totalp;
}
