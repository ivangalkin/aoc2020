#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <sstream>

#include <regex>


using namespace std::string_view_literals;

static std::vector<int64_t> input1 = {
        3, 8,  9,  1,  2,  5,  4,  6,  7,
};

static std::vector<int64_t> input2= {
        5,3,8,9,1,4,7,6,2,
};

#define input input2

// native

int64_t current_cup;
int64_t max_cup;
std::vector<int64_t> pick_up;
int64_t destination_cup;

// ring linked list

struct Cup;

struct Cup {
    int64_t nr;
    Cup* next;
};

std::array<Cup*, 10000000> cup_toc;

Cup* first_pick_up;

std::vector<int64_t> calculate_pickup() {
    auto idx = std::find(input.begin(), input.end(), current_cup) - input.begin();
    std::vector<int64_t> result { input[(idx + 1) % input.size()],
                                  input[(idx + 2) % input.size()],
                                  input[(idx + 3) % input.size()] };
    input[(idx + 1) % input.size()] = -1;
    input[(idx + 2) % input.size()] = -1;
    input[(idx + 3) % input.size()] = -1;

    for (auto it = input.begin(); it != input.end();) {
        if (*it == -1) {
            it = input.erase(it);
        } else {
            ++it;
        }
    }

    return result;
}

std::vector<int64_t> calculate_pickup2() {
    auto* current = cup_toc.at(current_cup);

    auto* current_plus_1 = current->next;
    auto* current_plus_2 = current_plus_1->next;
    auto* current_plus_3 = current_plus_2->next;
    auto* current_plus_4 = current_plus_3->next;

    first_pick_up = current_plus_1;
    current->next = current_plus_4;

    std::vector<int64_t> result {
            current_plus_1->nr,
            current_plus_2->nr,
            current_plus_3->nr
    };
    return result;
}

int64_t calculate_destination_cup() {
    int64_t destination = current_cup;
    while (true) {
        destination--;
        if (destination <= 0) {
            destination = max_cup;
        }
        if (std::find(input.begin(), input.end(), destination) != input.end()) {
            return destination;
        }
    }
    __builtin_unreachable();
}

int64_t calculate_destination_cup2() {
    int64_t destination = current_cup;
    while (true) {
        destination--;
        if (destination <= 0) {
            destination = max_cup;
        }

        if (std::find(pick_up.begin(), pick_up.end(), destination) == pick_up.end()) {
            return destination;
        }
    }
    __builtin_unreachable();
}


int64_t calculate_current_cup() {
    auto idx = std::find(input.begin(), input.end(), current_cup) - input.begin();
    auto new_idx = (idx + 1) % input.size();
    return input[new_idx];
}

int64_t calculate_current_cup2() {
    auto* current = cup_toc.at(current_cup);
    return current->next->nr;
}

void mutate() {
    auto idx = std::find(input.begin(), input.end(), destination_cup);
    ++idx;
    input.insert(idx, pick_up.begin(), pick_up.end());
}

void mutate2() {
    auto* destination = cup_toc.at(destination_cup);
    auto* next = destination->next;

    destination->next = cup_toc.at(pick_up.at(0));
    cup_toc.at(pick_up.at(2))->next = next;
}

void print_all() {
    auto idx = std::find(input.begin(), input.end(), 1) - input.begin();
    for (int i = 1; i < input.size(); i++) {
        std::cout << input[(idx + i) % input.size()];
    }
    std::cout << std::endl;
}

void print_all2() {
    auto* cup_1 = cup_toc.at(1);
    auto* next = cup_1->next;
    for (int i = 1; i < input.size(); i++) {
        std::cout << next->nr;
        next = next->next;
    }
    std::cout << std::endl;
}

void print_two() {
    auto idx = std::find(input.begin(), input.end(), 1) - input.begin();
    int64_t mult = input[(idx + 1) % input.size()] * input[(idx + 2) % input.size()];
    std::cout << mult << std::endl;
}

void print_two2() {
    auto* cup_1 = cup_toc.at(1);
    auto* cup_1_plus_1 = cup_1->next;
    auto* cup_1_plus_2 = cup_1_plus_1->next;
    int64_t mult = cup_1_plus_1->nr * cup_1_plus_2->nr;
    std::cout << mult << std::endl;
}

int _23_naive() {

    max_cup = *std::max_element(input.begin(), input.end());
    while (true) {
        ++max_cup;
        input.push_back(max_cup);
        if (input.size() == 1000000) {
            break;
        }
    }
    current_cup = *input.begin();

    for (int i = 0; i < 10000000 ; i++) {
        pick_up = calculate_pickup();
        destination_cup = calculate_destination_cup();
        mutate();
        current_cup = calculate_current_cup();
//        print_all();
    }
    print_two();

    return 0;
}

int _23_ring_linked_list() {
    Cup* previous_cup = nullptr;
    Cup* first_cup = nullptr;
    Cup* last_cup = nullptr;

    cup_toc.fill(nullptr);

    for (auto nr: input) {
        auto* cup = new Cup();
        cup->nr = nr;
        if (!first_cup) {
            first_cup = cup;
        }
        if (previous_cup) {
            previous_cup->next = cup;
        }
        previous_cup = cup;
        cup_toc[nr] = cup;
        last_cup = cup;
    }

    max_cup = *std::max_element(input.begin(), input.end());
    for (int64_t i = 0; i < (1000000 - input.size()); i++) {
        ++max_cup;
        auto* cup = new Cup();
        cup->nr = max_cup;

        previous_cup->next = cup;
        previous_cup = cup;
        cup_toc[max_cup] = cup;

        last_cup = cup;
    }

    last_cup->next = first_cup;

    current_cup = first_cup->nr;

    for (int i = 0; i < 10000000 ; i++) {
        pick_up = calculate_pickup2();
        destination_cup = calculate_destination_cup2();
        mutate2();
        current_cup = calculate_current_cup2();
//        print_all2();
    }
    print_two2();
    return 0;
}