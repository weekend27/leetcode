// Source : https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Author : weekend27
// Date   : 2015-12-20

/**********************************************************************************

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

**********************************************************************************/

// How to do it:
// use a stack to store numbers and tmp results, when meeting an op, pop two numbers and calculate them, and then put the result into the stack

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++){
            if (isOp(tokens[i])){
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                s.push(evaluate(x, y, tokens[i]));
            }
            else {
                s.push(stoi(tokens[i], nullptr, 10));
            }
        }
        return s.top();
    }

    bool isOp(string s){
        if (s == "+" || s == "-" || s == "*" || s == "/"){
            return true;
        }
        return false;
    }

    int evaluate(int x, int y, string op){
        if (op == "+"){
            return x + y;
        }
        else if (op == "-"){
            return x - y;
        }
        else if (op == "*"){
            return x * y;
        }
        else if (op == "/"){
            return x / y;
        }
    }
};
