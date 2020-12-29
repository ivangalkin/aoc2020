#include <iostream>
#include <string_view>
#include <sstream>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

#include <regex>


using namespace std::string_view_literals;

std::vector<uint64_t> original_player1 {
        43,
        36,
        13,
        11,
        20,
        25,
        37,
        38,
        4,
        18,
        1,
        8,
        27,
        23,
        7,
        22,
        10,
        5,
        50,
        40,
        45,
        26,
        15,
        32,
        33};


std::vector<uint64_t> _original_player1{
        9,
        2,
        6,
        3,
        1,
};
std::vector<uint64_t> _original_player2 {
5,
8,
4,
7,
10,
};

std::vector<uint64_t> original_player2 {
        21,
        29,
        12,
        28,
        46,
        9,
        44,
        6,
        16,
        39,
        19,
        24,
        17,
        14,
        47,
        48,
        42,
        34,
        31,
        3,
        41,
        35,
        2,
        30,
        49
};

uint64_t calculate_part1(const std::vector<uint64_t>& vec) {
    uint64_t counter = 1;
    uint64_t result = 0;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        result += (*it * counter);
        counter++;
    }
    return result;
}

int _22_part1() {

    while (true) {
        if (original_player1.empty() || original_player2.empty()) {
            break;
        }

        auto p1 = original_player1.front();
        original_player1.erase(original_player1.begin());

        auto p2 = original_player2.front();
        original_player2.erase(original_player2.begin());

        assert(p1 != p2);
        if (p1 > p2) {
            original_player1.push_back(p1);
            original_player1.push_back(p2);
        } else {
            original_player2.push_back(p2);
            original_player2.push_back(p1);
        }
    }

    if (original_player1.empty()) {
        std::cout << calculate_part1(original_player2) << std::endl;
    } else {
        std::cout << calculate_part1(original_player1) << std::endl;
    }

    return 0;
}


uint64_t max_game_nr = 1;

std::tuple<std::vector<uint64_t>*, bool> game(std::vector<std::tuple<std::vector<uint64_t>, std::vector<uint64_t>>> previous, std::vector<uint64_t>& player1, std::vector<uint64_t>& player2, uint64_t game_nr) {
    std::cout << "=== Game " << game_nr << " ===" << std::endl;

    max_game_nr++;

    uint64_t round_nr = 1;
    while(true) {

        if (player1.empty()) {
            return {&player2, false};
        }

        if (player2.empty()) {
            return {&player1, false};
        }

        std::cout << "-- Round "<< round_nr << " (Game " << game_nr << " ) --" << std::endl;
        round_nr++;

        std::tuple<std::vector<uint64_t>, std::vector<uint64_t>> key{player1, player2};
        auto it = std::find(previous.begin(), previous.end(), key);
        if (it != previous.end()) {
            std::cout << "RECURSION! " << calculate_part1(player1) << std::endl;
            return {&player1, true};
        }
        previous.push_back(std::move(key));

        std::cout << "Player 1's deck: ";
        std::copy(player1.begin(), player1.end(),
                  std::ostream_iterator<uint64_t>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "Player 2's deck: ";
        std::copy(player2.begin(), player2.end(),
                  std::ostream_iterator<uint64_t>(std::cout, ", "));
        std::cout << std::endl;


        auto p1 = player1.front();
        player1.erase(player1.begin());

        auto p2 = player2.front();
        player2.erase(player2.begin());

        if (player1.size() >= p1 && player2.size() >= p2) {
            std::vector<uint64_t> player1_sub = player1;
            player1_sub.erase(player1_sub.begin()+p1, player1_sub.end());

            std::vector<uint64_t> player2_sub = player2;
            player2_sub.erase(player2_sub.begin()+p2, player2_sub.end());

            auto [winner, is_endless]  =  game({}, player1_sub, player2_sub, max_game_nr);

            if (winner == &player1_sub) {
                player1.push_back(p1);
                player1.push_back(p2);
            }  else {
                player2.push_back(p2);
                player2.push_back(p1);
            }


        } else {

            assert(p1 != p2);
            if (p1 > p2) {
                player1.push_back(p1);
                player1.push_back(p2);
            } else {
                player2.push_back(p2);
                player2.push_back(p1);
            }

        }
    }

    __builtin_unreachable();
}

 int _22_part2() {

#define op1 original_player1
#define op2 original_player2

    auto [result, is_endless] = game({}, op1, op2, 1);

    if (is_endless) {
        std::cout << calculate_part1(op1) << std::endl;
    } else  if (result == &op2) {
        std::cout << calculate_part1(op2) << std::endl;
    } else {
        std::cout << calculate_part1(op1) << std::endl;
    }

    return 0;
}
