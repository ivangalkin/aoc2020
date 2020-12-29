#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

#include <regex>


using namespace std::string_view_literals;

static std::string input[] = {
        "152",
        "18",
        "146",
        "22",
        "28",
        "133",
        "114",
        "67",
        "19",
        "37",
        "66",
        "14",
        "90",
        "163",
        "26",
        "149",
        "71",
        "106",
        "46",
        "143",
        "145",
        "12",
        "151",
        "105",
        "58",
        "130",
        "93",
        "49",
        "74",
        "83",
        "129",
        "122",
        "63",
        "134",
        "86",
        "136",
        "166",
        "169",
        "159",
        "3",
        "178",
        "88",
        "103",
        "97",
        "110",
        "53",
        "125",
        "128",
        "9",
        "15",
        "78",
        "1",
        "50",
        "87",
        "56",
        "89",
        "60",
        "139",
        "113",
        "43",
        "36",
        "118",
        "170",
        "96",
        "135",
        "23",
        "144",
        "153",
        "150",
        "142",
        "95",
        "180",
        "35",
        "179",
        "80",
        "13",
        "115",
        "2",
        "171",
        "32",
        "70",
        "6",
        "72",
        "119",
        "29",
        "79",
        "27",
        "47",
        "107",
        "73",
        "162",
        "172",
        "57",
        "40",
        "48",
        "100",
        "64",
        "59",
        "175",
        "104",
        "156",
        "94",
        "77",
        "65"
};

static std::string input2[]= {
        "16",
        "10",
        "15",
        "5",
        "1",
        "11",
        "7",
        "19",
        "6",
        "12",
        "4"
};

static std::string input3[] = {
        "28",
        "33",
        "18",
        "42",
        "31",
        "14",
        "46",
        "20",
        "48",
        "47",
        "24",
        "23",
        "49",
        "45",
        "19",
        "38",
        "39",
        "11",
        "1",
        "32",
        "25",
        "35",
        "8",
        "17",
        "7",
        "9",
        "4",
        "2",
        "34",
        "10",
        "3",
};

std::vector<int64_t> adapters;
size_t nr_combinations;

void check(std::vector<int64_t> head, size_t next) {
    if (next >= adapters.size()) {
        ++nr_combinations;
//        for (int i = 0; i < head.size(); ++i) {
//            std::cout << head[i] << ", ";
//        }
//        std::cout << std::endl;
        return;
    }
    auto last = head.back();
    for (int i = next; i < adapters.size(); ++i) {
        if (adapters[i] - last <= 3) {
            auto new_head = head;
            new_head.push_back(adapters[i]);
            check(std::move(new_head), i + 1);
        }
    }
}

std::map<int64_t, int64_t> combinations;

void calculate_impl(int64_t from, int64_t target, int64_t& result) {
    if (combinations.contains(from)) {
        std::cout << "hit " << from << " = " << combinations[from] << std::endl;
        result+=combinations[from];
        return;
    }
    if (target >= adapters.size()) {
        ++result;
        //std::cout << nr_combinations << std::endl;
        return;
    }
    for (int i = target; i < adapters.size() ; ++i) {
        auto diff = adapters[i] - adapters[from];
        if (diff <=3) {
            calculate_impl(i, i + 1, result);
        } else {
            break;
        }
    }
}

int64_t calculate(int64_t from) {
    if (combinations.contains(from)) {
        return combinations[from];
    }
    int64_t result = 0;
    calculate_impl(from, from +1, result);
    combinations[from] = result;
    return result;
}


void backwards(int64_t source_idx) {
    if (source_idx < 0) {
        return;
    }

    std::cout << "backwards " << source_idx << std::endl;
    calculate(source_idx);

    for (int64_t new_source = source_idx - 1; new_source >= 0; new_source--) {
        if (adapters[source_idx] - adapters[new_source] <= 3) {
            if (!combinations.contains(new_source)) {
                backwards(new_source);
            }
        }
    }
}

void fast_check(int64_t last, size_t next) {
    if (next >= adapters.size()) {
        ++nr_combinations;
        //std::cout << nr_combinations << std::endl;
        return;
    }
    for (int i = next; i < adapters.size() ; ++i) {
        auto diff = adapters[i] - last;
        if (diff <=3) {
            fast_check(adapters[i], i + 1);
        } else {
            break;
        }
    }
}

int _10() {

    adapters.push_back(0 );

    for ( auto& line : input) {
        auto nr = stoll(line, nullptr, 10);
        adapters.push_back(nr);
    }


    std::sort(adapters.begin(), adapters.end());
    adapters.push_back(adapters.back() +3 );

    size_t diffs[] {0,0,0,0};

    for (int i = 1; i < adapters.size(); ++i) {
        auto diff = adapters[i] - adapters[i-1];
        assert(diff < (sizeof(diffs) / sizeof(size_t)));
        diffs[diff]++;
    }

    std::cout << diffs[1] * diffs[3] << std::endl;

    backwards(adapters.size()-1);
    for (int i = 0; i < adapters.size(); i++ ) {
        std::cout << "["<<i<<"]: " << combinations[i] << std::endl;
    }

    std::cout << combinations[0] << std::endl;

    return 0;
}
