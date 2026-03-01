#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
int FindNum(ifstream &ifs);

int main(){
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    // find the 2nd largest int and print it
    cout << FindNum(ifs) << endl;

    ifs.close();
    return 0;
}

// Pre-Condition:  ifs is an open ifstream pointing to a file containing
//                 at least 2 integers separated by any whitespace.
// Post-Condition: Returns the 2nd largest integer value found in the file.
int FindNum(ifstream &ifs){
    vector<int> nums;
    int num;

    while(ifs >> num)
        nums.push_back(num);

    int largest, second;
    if(nums[0] >= nums[1]){
        largest = nums[0];
        second  = nums[1];
    }else{
        largest = nums[1];
        second  = nums[0];
    }

    for(int i = 2; i < (int)nums.size(); i++){
        if(nums[i] > largest){
            second  = largest;
            largest = nums[i];
        }else if(nums[i] > second){
            second = nums[i];
        }
    }

    return second;
}