/*
    fsm.cpp

    Simulate a Finite State Machine
*/

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <string_view>

struct State {
    std::map<char, int> transitions;
    bool final = false;
};

const std::vector<State> aTable = {
    { { {'a', 1} }, false },
    { { }, true },
};

const std::vector<State> aStarTable = {
    { { {'a', 1} }, true },
    { { {'a', 1} }, true },
};

const std::vector<State> aPlusTable = {
    { { {'a', 1} }, false },
    { { {'a', 1} }, true },
};

int main(int argc, char* argv[]) {

    // Require input string to match against
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_string>\n";
        return 1;
    }
    std::string s = argv[1];

    // Run FSM
    int q = 0;
    const auto& table = aPlusTable;
    std::string match;
    for (auto c : s) {

        // find the transition for this character
        auto pos = table[q].transitions.find(c);
        if (pos == table[q].transitions.end())
            return 1;

        match += c;

        q = pos->second;
    }

    // verify in final state
    if (!table[q].final)
        return 1;

    std::cout << match << '\n';

    return 0;
}
