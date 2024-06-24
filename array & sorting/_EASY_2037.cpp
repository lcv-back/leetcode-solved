#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
       sort(seats.begin(), seats.end());
       sort(students.begin(), students.end());
        int moves = 0;
        for( int i=0; i<seats.size(); i++)
            moves += abs(seats[i] - students[i]);
        
        return moves;
    }
};

int main(){
    Solution s;
    vector<int> seats = {4,3,6,5};
    vector<int> students = {5,2,1,8};
    cout<<s.minMovesToSeat(seats, students)<<endl;
    return 0;
}