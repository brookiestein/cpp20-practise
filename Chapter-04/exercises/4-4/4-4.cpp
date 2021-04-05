/* It’s time to make good on a promise. Somewhere in this chapter we said we’d
 * look for someone “who is older than 21, younger than 35, is female, has a bachelor’s or
 * master’s degree, is unmarried, and speaks Hindi or Urdu.” Write a program that prompts the
 * user for these qualifications and then outputs whether they qualify for these very specific
 * requirements. To this end, you should define an int eger variable age , a char acter variable
 * gender (to hold 'm' for male, 'f' for female, etc.), a variable degree of an enumeration type
 * AcademicDegree (possible values: none , associate , bachelor , professional , master ,
 * doctor ), and three Boolean variables: married , speaksHindi , and speaksUrdu . Emulate a
 * trivial online job interview and query your applicant for input on all these variables. People who
 * enter invalid values do not qualify, of course, and should be ruled out as early as possible (that
 * is, immediately after entering any invalid value; ruling them out precognitively prior to entering
 * invalid values, sadly, is not possible yet in Standard C++).
 */

/*
 * If this program ends with a value less than zero
 * means that the user entered an invalid value.
 * Notice that the colours are not necessary, but it looks cool :P.
 */

#include <iostream>
#include <cctype>

int get_response(void);

int
main(void)
{
        enum class AcademicDegree {
                none, associate, bachelor,
                professional, master, doctor
        };

        enum class Gender : char {
                nonspecified = ' ',
                Male = 'm',
                Female = 'f'
        };

        int age {};
        std::cout << "How old are you? ";
        std::cin >> age;
        if (age < 0 || age > 100) {
                std::cout << "Due to you've entered a non-valid age, you're out."
                        << std::endl;
                return -1;
        }

        Gender gender {Gender::nonspecified};
        {
                char g {};
                std::cout << "Are you either female or male? [F/M]: ";
                std::cin >> g;
                g = std::tolower(g);

                if (g != 'f' && g != 'm') {
                        std::cout << "Due to you've entered a non-valid gender option, you're out."
                                << std::endl;
                        return -1;
                }

                gender = static_cast<Gender>(g);
        }

        AcademicDegree degree {AcademicDegree::none};
        {
                int d {};
                std::cout << "(1): None\n"
                        << "(2): Associate\n"
                        << "(3): Bachelor\n"
                        << "(4): Professional\n"
                        << "(5): Master\n"
                        << "(6): Doctor\n"
                        << "What's your academic degree? ";
                std::cin >> d;

                switch (d)
                {
                case 1: case 2: case 3: case 4: case 5: case 6:
                        degree = static_cast<AcademicDegree>(d - 1);
                        break;
                default:
                        std::cout << "Due to you've entered a non-valid academic degree, you're out."
                                << std::endl;
                        return -1;
                }
        }

        bool married {};
        {
                std::cout << "Are you married? [y/n]: ";
                int response = get_response();

                if (response < 0) {
                        std::cout << "Due to you've not answered well, you're out."
                                << std::endl;
                        return response;
                }

                married = static_cast<bool>(response);
        }

        bool speaksHindi {};
        {
                std::cout << "Do you speak Hindi? [y/n]: ";
                int response = get_response();

                if (response < 0) {
                        std::cout << "Due to you've not answered well, you're out."
                                << std::endl;
                        return response;
                }

                speaksHindi = static_cast<bool>(response);
        }

        bool speaksUrdu {};
        {
                std::cout << "Do you speak Urdu? [y/n]: ";
                int response = get_response();

                if (response < 0) {
                        std::cout << "Due to you've not answered well, you're out."
                                << std::endl;
                        return response;
                }

                speaksUrdu = static_cast<bool>(response);
        }

        /* 5 stands for the tests' number */
        bool apply[5] {};

        std::cout << "\nChecking for whether or not you apply..." << std::endl;

        std::cout << "Checking for whether you're between 21 and 35..." << std::endl;
        if (age <= 21) {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You're not at least 21 years old." << std::endl;
        } else if (age >= 35) {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You're too old." << std::endl;
        } else {
                std::cout << "\e[1;32m" << "[OK]" << "\e[0m"
                        << "You're between 21 and 35." << std::endl;
                apply[0] = true;
        }
        std::cout << std::endl;

        std::cout << "Checking for whether or not you're female..." << std::endl;
        if (gender == Gender::Female) {
                std::cout << "\e[1;32m" << "[OK]" << "\e[0m"
                        << "You're female." << std::endl;
                apply[1] = true;
        } else {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You're not female." << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Checking for whether you have either bachelor or master degree..." << std::endl;
        if (degree != AcademicDegree::bachelor && degree != AcademicDegree::master) {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You have neither master nor bachelor degree." << std::endl;
        } else if (degree == AcademicDegree::bachelor) {
                std::cout << "\e[1;32m" << "[OK]" << "\e[0m"
                        << "You have bachelor degree." << std::endl;
                apply[2] = true;
        } else {
                std::cout << "\e[1;32m" << "[OK]" << "\e[0m"
                        << "You have master degree." << std::endl;
                apply[2] = true;
        }
        std::cout << std::endl;

        std::cout << "Checking for whether or not you're married..." << std::endl;
        if (married) {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You're married." << std::endl;
        } else {
                std::cout << "\e[1;32m" << "[OK]" << "\e[0m"
                        << "You're not married." << std::endl;
                apply[3] = true;
        }
        std::cout << std::endl;

        std::cout << "Checking for whether you speak either Hindi or Urdu..." << std::endl;
        if (speaksHindi) {
                std::cout << "\e[1;32m" << "[OK]" << "\e[0m"
                        << "You speak Hindi." << std::endl;
                apply[4] = true;
        } else {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You don't speak Hindi." << std::endl;
        }

        if (speaksUrdu) {
                std::cout << "\e[1;32m" << "[OK]" << "\e[0m"
                        << "You speak Urdu." << std::endl;
                apply[4] = true;
        } else {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You don't speak Urdu." << std::endl;
        }

        if (!speaksHindi && !speaksUrdu) {
                std::cout << "\e[1;31m" << "[!!]" << "\e[0m"
                        << "You speak neither Hindi nor Urdu which." << std::endl;
        }
        std::cout << std::endl;

        for (int i = 0; i < sizeof(apply) / sizeof(bool); i++) {
                if (!apply[i]) {
                        std::cout << "Sorry, you couldn't apply for the job." << std::endl;
                        return 0;
                }
        }

        /* At this point the user could pass all the tests. */
        std::cout << "Congratulation! You have applied the job interview!" << std::endl;
}

int
get_response(void)
{
        char response {};
        std::cin >> response;
        response = std::tolower(response);
        if (response != 'y' && response != 'n') {
                return -1;
        }

        return response == 'y' ? 1 : 0;
}
