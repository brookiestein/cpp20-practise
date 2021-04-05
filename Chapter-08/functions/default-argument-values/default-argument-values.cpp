/* Using functions with default and custom argument values. */
#include <iostream>
#include <string>

void show_error_message(const std::string& message = "Was there an error!");

int
main(void)
{
        show_error_message(); /* Using the default value. */
        show_error_message("The program couldn't continue with its execution!"); /* Using a custom value. */
}

void
show_error_message(const std::string& message)
{
        std::cout << message << std::endl;
}
