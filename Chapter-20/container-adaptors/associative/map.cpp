/* A map associative container is that that receives
 * two different types: One to store the *key* and the other
 * to store the *value*. Through the key you can access the value. */

#include <cstdint>
#include <iostream>
#include <map>
#include <string>

int
main()
{
        std::map<std::string, std::uint64_t> phone_book;

        phone_book["Brayan"] = 123'456'789;
        phone_book["Pedro"] = 432'923'5500;

        for (const auto& [name, number] : phone_book)
                std::cout << name << "'s phone number's: " << number << std::endl;
}
