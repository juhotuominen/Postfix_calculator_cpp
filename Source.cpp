#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function for the calculator
int postfix_calc(string expr) {
    stack<int> st;
    // Go through every character in input
    for (int i = 0; i < expr.length(); i++) {
        if (isdigit(expr[i])) {
            int num = 0;
            // Testing for multiple digit numbers
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            st.push(num);
        }
        else if (isspace(expr[i])) {
            continue;
        }

        /* If the character is an operator, pop top two elements off the stack
        and perform correct operation. If not valid operator, print error message */
        else {
            
            switch (expr[i]) {
            case '+': {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                st.push(operand1 + operand2);
                break;
            }
            case '-': {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                st.push(operand1 - operand2);
                break;
            }
            case '*': {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                st.push(operand1 * operand2);
                break;
            }
            case '/': {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                st.push(operand1 / operand2);
                break;
            }
             /* If there is "x" in between numbers and operator,
             switch numbers position in stack */
            case 'x': {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                st.push(operand2);
                st.push(operand1);
                break;
            }
            default: {
                cerr << "Invalid operator: " << expr[i] << endl;
                return -1;
            }
            }
        }
    }
    return st.top();
}

// Main function, ask user for expression
int main() {
    string expr;
    cout << "Enter postfix expression: ";
    getline(cin, expr);
    int result = postfix_calc(expr);
    cout << "Result: " << result << endl;
    return 0;
}
