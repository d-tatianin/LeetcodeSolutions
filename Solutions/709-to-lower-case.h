#pragma once

// 709. Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

// Solution: (complexity O(N))
// Just walk the string and for each char in the range A-Z subtract an offset
// needed to convert it to lower case.

PROBLEM(709, "To Lower Case") {

inline std::string toLowerCase(std::string str) {
    // This makes an assumption that characters are ASCII, or at least
    // the fact that the upper case chars have higher codepoints and are contiguos.
    // Alternatively you could set up a hash map for all english letters of mappings from upper to lower.
    static constexpr auto offset_from_lower_case = 'A' - 'a';

    for (auto& c : str) {
        if (c >= 'A' && c <= 'Z')
            c -= offset_from_lower_case;
    }

    return str;
}

TRY_SOLVE()
{
    auto lower = toLowerCase("HELLO World");
}

}
