#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string token;
    stack<int> s;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            int result;
            if (token == "+") {
                result = operand1 + operand2;
            }
            else if (token == "-") {
                result = operand1 - operand2;
            }
            else {
                result = operand1 * operand2;
            }
            s.push(result);
        }
        else {
            s.push(stoi(token));
        }
    }

    cout << s.top() << endl;

    return 0;
}