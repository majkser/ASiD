#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <cctype>

int rpn(const std::vector<std::string> &input);

int main()
{

    // for (auto w : input) { /* sprawdzanie w */ }

    std::vector<std::string> input{"-6", "+2", "/"};
    assert(rpn(input) == -3);

    std::cout << rpn(input);

    return 0;
}

int rpn(const std::vector<std::string> &input)
{
    std::stack<std::string> stack;

    for (auto &element : input)
    {

        if (std::isdigit(element[0]) || ((element[0] == '-' || element[0] == '+') && element.length() > 1 && std::isdigit(element[1])))
        {
            stack.push(element);
        }

        else if (element[0] == '+' || element[0] == '-' || element[0] == '*' || element[0] == '/')
        {
            int a = std::stoi(stack.top());
            stack.pop();
            int b = std::stoi(stack.top());
            stack.pop();

            if (element[0] == '+')
            {
                int c = a + b;
                stack.push(std::to_string(c));
            }
            else if (element[0] == '-')
            {
                int c = b - a;
                stack.push(std::to_string(c));
            }
            else if (element[0] == '*')
            {
                int c = a * b;
                stack.push(std::to_string(c));
            }
            else if (element[0] == '/')
            {
                int c = b / a;
                stack.push(std::to_string(c));
            }
        }
    }

    return std::stoi(stack.top());
}