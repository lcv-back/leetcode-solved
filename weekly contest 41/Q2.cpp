/*
    Title: Maximum Energy Boost From Two Drinks

    Description:
        You are given two integer arrays energyDrinkA and energyDrinkB of the same length n by a futuristic sports scientist. 
        These arrays represent the energy boosts per hour provided by two different energy drinks, A and B, respectively.

        You want to maximize your total energy boost by drinking one energy drink per hour. However, if you want to switch 
        from consuming one energy drink to the other, you need to wait for one hour to cleanse your system (meaning you won't 
        get any energy boost in that hour).

        Return the maximum total energy boost you can gain in the next n hours.
        Note that you can start consuming either of the two energy drinks.
    
    Example 1:
        Input: energyDrinkA = [1,3,1], energyDrinkB = [3,1,1]
        Output: 5
        Explanation: 
            You can start drinking energy drink A for the first hour, 
            then drink energy drink B for the next hour, 
            and finally drink energy drink A again.

    Example 2:
        Input: energyDrinkA = [4,1,1], energyDrinkB = [1,1,3]
        Output: 7
        Explanation:
            To gain an energy boost of 7:
                Drink the energy drink A for the first hour.
                Switch to the energy drink B and we lose the energy boost of the second hour.
                Gain the energy boost of the drink B in the third hour.

    Contraints:
        n == energyDrinkA.length == energyDrinkB.length
        3 <= n <= 10^5
        1 <= energyDrinkA[i], energyDrinkB <= 10^5
 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> energyDrinkA1 = {1, 3, 1};
    vector<int> energyDrinkB1 = {3, 1, 1};
    cout << solution.maxEnergyBoost(energyDrinkA1, energyDrinkB1) << endl;  // Output: 5

    // Test case 2
    vector<int> energyDrinkA2 = {4, 1, 1};
    vector<int> energyDrinkB2 = {1, 1, 3};
    cout << solution.maxEnergyBoost(energyDrinkA2, energyDrinkB2) << endl;  // Output: 7

    return 0;
}