#pragma once

// 1108. Given a valid (IPv4) IP address, return a defanged version of that IP address.
//       A defanged IP address replaces every period "." with "[.]".

// Solution: (complexity O(N) or O(1) if we consider that any ip address has a constant max length)
// For each character:
// if it's a '.', push "[.]" into the out string
// otherwise push the character into the out string

SOLUTION_FOR_PROBLEM(1108, "Defanging an IP Address") {

std::string defangIPaddr(std::string address) {
    std::string defanged;
    defanged.reserve(address.size() + 2 * 3); // [] for each .

    for (char c : address) {
        if (c == '.')
            defanged += "[.]";
        else
            defanged += c;
    }

    return defanged;
}


SOLVE()
{
    auto defanged = defangIPaddr("1.1.1.1");
}

}
