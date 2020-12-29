#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

#include <regex>


using namespace std::string_view_literals;


size_t nr_of_loops(uint64_t public_key) {
    uint64_t res = 1;
    for (uint64_t i = 1; ; i++) {
        res *=7;
        res%=20201227ull;
        if (res == public_key) {
            return i;
        }
    }
    __builtin_unreachable();
}

uint64_t transform(uint64_t subject_nr, uint64_t loops) {
    uint64_t res = 1;
    for (uint64_t i = 0; i < loops; i++) {
        res *=subject_nr;
        res%=20201227ull;
    }
    return res;
}

int _25() {

    uint64_t door_public_key =  1614360ull;
    uint64_t card_public_key =  7734663ull;

//    uint64_t door_public_key =  17807724ull;
//    uint64_t card_public_key =  5764801ull;

    std::cout << nr_of_loops(door_public_key) << std::endl;
    std::cout << nr_of_loops(card_public_key) << std::endl;

    std::cout << transform(card_public_key, nr_of_loops(door_public_key)) << std::endl;
    std::cout << transform(door_public_key, nr_of_loops(card_public_key)) << std::endl;

    return 0;
}
