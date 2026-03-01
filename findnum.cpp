#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int FindNum(ifstream &ifs);

int main(){
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    int result = FindNum(ifs);
    ifs.close();

    cout << "The 2nd largest value is: " << result << endl;
    return 0;
}


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
        if (nums[i] > largest) {
            second  = largest;
            largest = nums[i];
        }else if(nums[i] > second){
            second = nums[i];
        }
    } 

    return second;
} 