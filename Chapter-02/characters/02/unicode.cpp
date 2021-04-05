#include <iostream>

int
main(void)
{
        wchar_t cc {L'\x00E7'};
        char16_t yen {u'\x00A5'};
        char16_t delta {u'\x0394'};
        char32_t ya {U'\x044f'};

        std::cout << "C-cedilla: " << cc << "\n"
                << "Yen: " << yen << "\n"
                << "Delta: " << delta << "\n"
                << "Ya: " << ya << std::endl;

        return 0;
}
