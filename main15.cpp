#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

#include <regex>


using namespace std::string_view_literals;

static std::vector<uint64_t> input = {
        6,19,0,5,7,13,1
};

static std::vector<uint64_t> input2= { 0,3,6 }; // 436

static std::vector<uint64_t> input3 = { 1,3,2 }; // 1
static std::vector<uint64_t> input4 = { 2,1,3 }; // 10
static std::vector<uint64_t> input5 = { 1,2,3 }; // 27
static std::vector<uint64_t> input6 = { 2,3,1 }; // 78
static std::vector<uint64_t> input7 = { 3,2,1 }; // 438
static std::vector<uint64_t> input8 = { 3,1,2 }; // 1836

std::map<uint64_t, std::vector<uint64_t>> last_appearances;

uint64_t calculator(std::vector<uint64_t>  starting_nrs ) {

    uint64_t turn = 1;
    for (auto nr : starting_nrs) {
        last_appearances[nr].push_back(turn);
        turn++;
    }

    uint64_t last_said_nr = starting_nrs.back();
    uint64_t new_said_number;

    for ( ; turn <= 30000000; turn++) {
        assert(last_appearances.contains(last_said_nr));
        auto& last_appearances_turn = last_appearances[last_said_nr];
        if (last_appearances_turn.size() == 1) {
            //std::cout << turn << ": 1st appearance of " << last_said << std::endl;
            new_said_number = 0;
        } else if (last_appearances_turn.size() >= 2) {
//                std::cout << turn << ": 2nd appearance of " <<
//                    last_said << "(" <<
//                     last_appearances_turn.at(last_appearances_turn.size()-1) <<
//                     "-" <<
//                     last_appearances_turn.at(last_appearances_turn.size()-2) <<
//                    ")" <<
//                    std::endl;
            new_said_number = last_appearances_turn.at(last_appearances_turn.size()-1) - last_appearances_turn.at(last_appearances_turn.size()-2);
        }

        last_said_nr = new_said_number;
        last_appearances[new_said_number].push_back(turn);
//        std::cout << turn << "->" << new_said_number << std::endl;
    }

    return new_said_number;
}

int _15() {
    std::cout << calculator(input) << std::endl;
    return 0;
}
