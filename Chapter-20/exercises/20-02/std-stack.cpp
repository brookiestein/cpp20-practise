#include <iostream>
#include <stack>
#include <string>
#include <vector>

int
main()
{
        std::vector<std::string> words { "The", "quick", "brown", "fox", "jumps" };
        std::stack<std::string> wordStack;
        for (auto& word : words)
                wordStack.push(word);

        std::cout << "Words in the stack:\n";
        while (!wordStack.empty()) {
                std::cout << wordStack.top() << ' ';
                wordStack.pop();
        }
        std::cout << std::endl;
}
