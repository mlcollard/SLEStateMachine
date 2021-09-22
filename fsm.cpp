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
};

const std::vector<State> aTable = {
    { { {'a', 1} } },
    { { } },
};

int main(int argc, char* argv[]) {

    // Require input string to match against
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_string>\n";
        return 1;
    }

    // Run FSM

    return 0;
}
