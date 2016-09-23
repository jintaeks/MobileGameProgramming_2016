#include <vector>
#include <algorithm>
#include <locale>
#include <iostream>
#include <memory>
#include <stack>

int Evaluate(int token, int nFirst, int nSecond) {
    if (token == '+')
        return nFirst + nSecond;
    else if (token == '-')
        return nFirst - nSecond;
    else if (token == '*')
        return nFirst * nSecond;
    else if (token == '/')
        return nFirst / nSecond;

    return 0;
}

int main() {
    std::string         input = "512+4*+3-";
    std::stack<int>     stack;
    int token = 0;
    bool bIsTokenLeft = true;
    int iNextToken = 0;
    int nErrorCode = 0;

    //while there is an input token left
    while (bIsTokenLeft == true) {
        if (iNextToken >= input.length()) {
            nErrorCode = 0; // no error.
            bIsTokenLeft = false;
            break;
        }
        //read next token from the input[]
        token = (char)input[iNextToken];
        iNextToken += 1;

        // when token is value, then push it to the stack
        if (isdigit(token)) {
            // todo
        }
        else {
            // otherwise token is an operator(or a function)
            // number of parameters for an operator a priori known

            // when there is less than n-elements in the stack
            // Error(insufficient number of operands)
            const int iSize = stack.size();
            if (iSize < 2) {
                nErrorCode = -1;
                break;
            }

            // or pops n-items from the stack
            // todo

            // evaluate an expression, and push back the result to the stack.
            // todo
        }
    }
    // when there is one item in the stack, then print the result
    if (stack.size() >= 1) {
        std::cout << stack.top() << std::endl;
    }
    // otherwise there is an error.
}
