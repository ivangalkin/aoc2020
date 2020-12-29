#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

#include <regex>


using namespace std::string_view_literals;

static std::string input[] = {

};

static std::string input2[]= {

};

static std::string input3[] = {

};

int _x() {
    std::regex r {"(acc|jmp|nop) (\\+|\\-)(\\d+)"};

    for ( auto line : input) {
        std::smatch sm;
        while (std::regex_search(line, sm, r)) {
            for (size_t i = 0; i < sm.size(); ++i) {
                std::cout << i << ": "<< sm[i] << std::endl;
            }
            line = sm.suffix();
        }
    }

    return 0;
}
