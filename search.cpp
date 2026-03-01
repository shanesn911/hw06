#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
vector<int> SeqSearchAll(int target, ifstream &ifs);

int main(){
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> returned = SeqSearchAll(target, ifs);
    ifs.close();

    if(returned[0] == -1)
        cout << "Target not found!\n";
    else{
        cout << "Target found at position(s): ";
        for(int i = 0; i < (int)returned.size(); i++){
            cout << returned[i] << " ";
        } 
        cout << endl;
    }

    return 0;
}


vector<int> SeqSearchAll(int target, ifstream &ifs) {
    vector<int> nums;
    vector<int> positions;
    int num;

    //Read all integers from file into nums
    while(ifs >> num)
        nums.push_back(num);

    //Search nums for all occurrences of target
    for(int i = 0; i < (int)nums.size(); i++){
        if(nums[i] == target)
            positions.push_back(i);
    }

    //If never found, signal with -1
    if(positions.empty())
        positions.push_back(-1);

    return positions;
} 