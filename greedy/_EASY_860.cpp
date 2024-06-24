#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveBillCount=0,tenBillCount=0;
        for(int bill:bills){
            if(bill==5) fiveBillCount++;
            else if(bill==10){
                if(fiveBillCount>=1){
                    tenBillCount++;
                    fiveBillCount--;
                }
                else return false;
            }
            else{
                if(tenBillCount>=1 and fiveBillCount>=1){
                    tenBillCount--;
                    fiveBillCount--;
                }
                else if(fiveBillCount>=3){
                    fiveBillCount-=3;
                }
                else return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> bills={5,5,5,10,20};
    cout<<s.lemonadeChange(bills)<<endl;
    return 0;
}