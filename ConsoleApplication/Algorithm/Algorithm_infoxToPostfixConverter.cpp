#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <string>

int priority( char a ) {
    int temp = 0;

    if( a == '^' )
        temp = 4;
    else  if( a == '*' || a == '/' )
        temp = 3;
    else  if( a == '+' || a == '-' )
        temp = 2;
    return temp;
}

int main() {
    std::string infix;
    //cout << "Enter an arithmetic expression: " << endl;
    //getline( cin, infix );
    infix = "3+4*2/(1-5)^2^3";

    std::stack<char> operator_stack;

    std::string postfix;

    for( unsigned i = 0; i < infix.length(); i++ ) {
        if( infix[ i ] == '+' || infix[ i ] == '-' || infix[ i ] == '*' || infix[ i ] == '/' ) {
            while( !operator_stack.empty() && priority( infix[ i ] ) <= priority( operator_stack.top() ) ) {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push( infix[ i ] );
        }  else if( infix[ i ] == '^' ) {
            while( !operator_stack.empty() && priority( infix[ i ] ) < priority( operator_stack.top() ) ) {
                    postfix += operator_stack.top();
                    operator_stack.pop();
            }
            operator_stack.push( infix[ i ] );
        } else if( infix[ i ] == '(' ) {
            operator_stack.push( infix[ i ] );
        } else if( infix[ i ] == ')' ) {
            while( operator_stack.top() != '(' ) {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.pop();
        } else {
            postfix += infix[ i ];
        }
    }

    while( !operator_stack.empty() ) {
        postfix += operator_stack.top();
        operator_stack.pop();
    }//while

    std::cout << postfix << std::endl;

    return 0;
}