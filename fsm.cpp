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
    void (*action)(std::string_view) = nullptr;
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

const std::vector<State> aOrBPlusTable = {
    { { {'a', 1}, {'b', 1} }, false, [](std::string_view s) { std::cout << "HI, I am state q0 but not done yet\n"; } },
    { { {'a', 1}, {'b', 1} }, true,  [](std::string_view s) { std::cout << "I am done\n";} },
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
    const auto& table = aOrBPlusTable;
    std::string match;
    for (auto c : s) {

        // find the transition for this character
        auto pos = table[q].transitions.find(c);
        if (pos == table[q].transitions.end())
            return 1;

        match += c;

        q = pos->second;

        auto curAction = table[q].action;
        if (curAction)
            curAction(match);
    }

    // verify in final state
    if (!table[q].final)
        return 1;

    std::cout << match << '\n';

    return 0;
}
