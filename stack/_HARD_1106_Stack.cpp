#include <string>
#include <stack>
#include <iostream>

using namespace std;

/*
	Description:
		Given a boolean expression, return the result of the expression.
		The given expression will always be valid and contains only characters 't', 'f', '&', '|', '!' and '(', ')'.
		Example:
			Input: expression = "&(|(f))"
			Output: false
			Explanation:
				The expression contains three sub-expressions:
					(f) is false,
					| is the OR operator with two operands: false and false, which is false,
					& is the AND operator with two operands: true and false, which is false.
				So the result of the expression is false.
*/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stack;
        bool curExpr = true; // initialize the curExpr, will change the value after
        for(char c : expression) {
        	if(c == ')') {
        		bool hasFalse = false;
        		bool hasTrue = false;
        		char curTop = stack.top();
        		stack.pop();
        		
        		while(curTop != '|' && curTop != '&' && curTop != '!' && !stack.empty()){
        			if(curTop == 'f') hasFalse = true;
        			else if(curTop == 't') hasTrue = true;
        			curTop = stack.top();
        			stack.pop();
				}
						
				// evaluate any specific case (|, &, !)
				if(curTop == '|') curExpr = hasTrue;
				else if(curTop == '&') curExpr = !hasFalse;
				else if(curTop == '!') curExpr = !hasTrue;
				
				// push the result after any operations with operands
				if(curExpr) stack.push('t');
				else stack.push('f');
			}
        	
        	else if(c != '(' && c != ',') stack.push(c);
		}
		return stack.top() == 't';
    }
};

/*
	Description for solution:
		Use a stack to store the characters of the expression.
		When encountering a ')', pop the stack until encountering a '(', and evaluate the expression inside the parentheses.
		Push the result back to the stack.
		Finally, the result is the only element left in the stack.
		Use a boolean variable to store the current expression result.
		When encountering a '|', '&', or '!', update the current expression result accordingly.
		Push the result back to the stack.

		Note:
			When encountering a '|', '&', or '!', we need to evaluate the expression inside the parentheses first.
			So we need to pop the stack until encountering a '(', and store the result in a boolean variable.
			Then update the current expression result and push it back to the stack.
*/

/*
	Time Complexity: O(n)
	Space Complexity: O(n)
*/

int main(){
	Solution sol;
	string expression1 = "&(|(f))";
	string expression2 = "|(f,f,f,t)";
	string expression3 = "!(&(f,t))";
	
	bool res1 = sol.parseBoolExpr(expression1);
	bool res2 = sol.parseBoolExpr(expression2);
	bool res3 = sol.parseBoolExpr(expression3);
	
	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;
	return 0;
}
