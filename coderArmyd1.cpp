#include <iostream>
#include <vector>   
using namespace std;



void inputmarks(vector<int>& arr){
    cout<<"Enter marks of each student"<<endl;
    for(int i=0;i<arr.size();i++){
        while(!(cin >> arr[i])){
            cout << "Invalid input! Enter a number: ";
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
}

void displaymarks(const vector<int>& arr){
    cout<<"Marks of all the students: ";
    for(auto m: arr) cout << m << " ";
    cout << endl;
}

void findhighest(const vector<int>& arr){
    int max=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>max) max=arr[i];
    }
    cout<<"Highest score: "<<max<<endl;
}

void findaverage(const vector<int>& arr){
    int sum=0;
    for(auto m: arr) sum += m;
    float avg = (float)sum/arr.size();
    cout<<"Average score: "<<avg<<endl;
}

void countResults(const vector<int>& arr){
    int pass=0, fail=0;
    for(auto m: arr){
        if(m>=40) pass++;
        else fail++;
    }
    cout<<"Passed: "<<pass<<", Failed: "<<fail<<endl;
}



int main(){
    int n;
    cout << "Enter number of students: ";
    while(!(cin >> n) || n<=0){
        cout << "Invalid input! Enter a positive number: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }

    vector<int> arr(n);
    bool isEntered=false;
    int choice;

    while(true){
        cout<<"\nMenu:\n1.Input 2.Display 3.Highest 4.Average 5.Pass/Fail 0.Exit\nChoice: ";

        if(!(cin >> choice)){
            cout<<"Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }

        switch(choice){
            case 1:
                inputmarks(arr);
                isEntered=true;
                break;
            case 2:
                if(!isEntered) cout<<"Enter marks first.\n";
                else displaymarks(arr);
                break;
            case 3:
                if(!isEntered) cout<<"Enter marks first.\n";
                else findhighest(arr);
                break;
            case 4:
                if(!isEntered) cout<<"Enter marks first.\n";
                else findaverage(arr);
                break;
            case 5:
                if(!isEntered) cout<<"Enter marks first.\n";
                else countResults(arr);
                break;
            case 0:
                cout<<"Exiting program.\n";
                return 0;
            default:
                cout<<"Invalid choice.\n";
        }
    }
}
 