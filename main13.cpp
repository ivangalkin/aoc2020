#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

#include <regex>


using namespace std::string_view_literals;

static std::string input[] = {
        "1003240",
        "19,x,x,x,x,x,x,x,x,41,x,x,x,37,x,x,x,x,x,787,x,x,x,x,x,x,x,x,x,x,x,x,13,x,x,x,x,x,x,x,x,x,23,x,x,x,x,x,29,x,571,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,17"
};

static std::string input2[]= {
        "939",
        "7,13,x,x,59,x,31,19"
};

static std::string input3[] = {

};

int part13_1() {

    auto& my_input = input2;

    auto start = stoull(my_input[0], nullptr, 10);
    std::vector<uint64_t> buss;

    std::regex r {"(\\d+)"};
    std::smatch sm;
    while (std::regex_search(my_input[1], sm, r)) {
        auto nr = stoull(sm[1], nullptr, 10);
        buss.push_back(nr);
        std::cout << nr << " " << std::endl;
        my_input[1] = sm.suffix();
    }

    std::sort(buss.begin(), buss.end());

    for (uint64_t timestamp = start; ; timestamp++) {
        for (auto b : buss) {
            if (timestamp % b == 0) {
                std::cout << timestamp << " " << b << std::endl;
                std::cout << (timestamp-start) * b << std::endl;
                return 0;
            }
        }
    }

    return 0;
}

std::vector<std::tuple<uint64_t,uint64_t>> parse(std::string line) {
    std::vector<std::tuple<uint64_t,uint64_t>> buss;
    std::regex r{"(\\d+|x)"};
    std::smatch sm;
    int i = 0;
    while (std::regex_search(line, sm, r)) {
        if (sm[1] != 'x') {
            auto nr = stoull(sm[1], nullptr, 10);
            buss.push_back({nr, i});
            std::cout << nr << " " << i << std::endl;
        }
        i++;
        line = sm.suffix();
    }
    std::sort(buss.begin(), buss.end(), [](const auto& a, const auto& b){
        return a > b;
    });
    return buss;
}

uint64_t calculate(const std::vector<std::tuple<uint64_t,uint64_t>>& buss) {
    auto max_bus_line_nr = std::get<0>(buss[0]);
    auto max_bus_offset = std::get<1>(buss[0]);

    for (auto timestamp = max_bus_line_nr ; ; timestamp+=max_bus_line_nr) {
        uint64_t b = 1;
        for (; b < buss.size(); ++b) {
                if ((timestamp - max_bus_offset + std::get<1>(buss[b])) % std::get<0>(buss[b]) != 0) {
                    break;
                }
        }
        if (b == buss.size()) {
            std::cout << timestamp - max_bus_offset << std::endl;
            return timestamp - max_bus_offset;
        }
    }
}


int _13_2() {

    auto& my_input = input2;

    assert(calculate(parse("7,13,x,x,59,x,31,19")) == 1068781);
    assert(calculate(parse("17,x,13,19")) == 3417);
    assert(calculate(parse("67,7,59,61")) == 754018);
    assert(calculate(parse("67,x,7,59,61")) == 779210);
    assert(calculate(parse("67,7,x,59,61")) == 1261476);
    assert(calculate(parse("1789,37,47,1889")) == 1202161486);

    std::cout << calculate(parse(input[1])) << std::endl;

    // TODO learn https://en.wikipedia.org/wiki/Chinese_remainder_theorem#Using_the_existence_construction

    return 0;
}
