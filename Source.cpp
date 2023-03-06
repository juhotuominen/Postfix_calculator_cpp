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
            // a operator outputs an average of inputted numbers. 
                case 'a': {
                    int sum = 0;
                    int stSize = st.size();
                    while (!st.empty()) {
                        int num = st.top();
                        sum += num;
                        st.pop();
                    }
                    sum /= stSize;
                    st.push(sum);
                    break;
                }

                // s operator sums up input. For example "1 2 3 s" outputs "6"
                case 's': {
                    int sum = 0;
                    while (!st.empty()) {
                        int num = st.top();
                        sum += num;
                        st.pop();
                    }
                    st.push(sum);
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
                case '%': {
                    int operand2 = st.top();
                    st.pop();
                    int operand1 = st.top();
                    st.pop();
                    st.push(operand1 % operand2);
                    break;
                }
                //exponentiation
                case '^': {
                    int operand2 = st.top();
                    st.pop();
                    int operand1 = st.top();
                    st.pop();
                    st.push(pow(operand1, operand2));
                    break;
                }
                //square root
                case 'v': {
                    int operand1 = st.top();
                    st.pop();
                    st.push(sqrt(operand1));
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

int prompt() {
    string numbers, opr;
    cout << "Enter operator (+ - * / % ^ v): ";
    getline(cin, opr);
    cout << "Enter two numbers you want to calculate: ";
    getline(cin, numbers);
    string expr = numbers + " " + opr;

    int result = postfix_calc(expr);
    cout << "Result: " << result << endl;
    return 0;
}

// Main function, ask user for expression
int main(int argc, char* argv[]) {

    //if user runs program with "-p" run it in prompt mode
    if (argc == 2 && string(argv[1]) == "-p") {
        prompt();
    }
    else{
        string expr;
        cout << "Enter postfix expression: ";
        getline(cin, expr);
        int result = postfix_calc(expr);
        cout << "Result: " << result << endl;
        return 0;
    }
}
