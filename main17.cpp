#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

#include <regex>


using namespace std::string_view_literals;

static std::vector<std::string> input= {
        "..#..#..",
        ".###..#.",
        "#..##.#.",
        "#.#.#.#.",
        ".#..###.",
        ".....#..",
        "#...####",
        "##....#."
};

struct  Cube {

    std::vector<std::string> middle_slice(std::vector<std::string> input, size_t border) {
        std::vector<std::string> slice;
        for (size_t y = 0; y < border; y++) {
            std::string line(size, '.');
            slice.emplace_back(std::move(line));
        }

        for (size_t y = 0; y < input.size(); y++) {
            std::string line;
            line.append(border, '.');
            line.append(input[y]);
            line.append(border, '.');
            slice.emplace_back(std::move(line));
        }

        for (size_t y = 0; y < border; y++) {
            std::string line(size, '.');
            slice.emplace_back(std::move(line));
        }

        assert(slice.size() == size);
        return slice;
    }

    Cube(std::vector<std::string> input, size_t cycles) {
        assert(input.size() == input[0].size());
        assert(input.size() % 2);

        auto border = cycles * 3;
        size  = input.size()+ border * 2;

        std::string empty_line(size, '.');
        std::vector<std::string> empty_slice(size, empty_line);
        data = std::vector<std::vector<std::string>>(size, empty_slice);

        data[size / 2] = middle_slice(std::move(input), border);
    }

    char& at(size_t x, size_t y, size_t z) {
        assert(x< size);
        assert(y< size);
        assert(z< size);
        return data.at(z).at(y)[x];
    }

    void print() {
        int64_t middle_slice = size / 2;
        for (int64_t z = 0; z < size; z++) {
            std::cout << "z = " << z -middle_slice << std::endl;
            for (auto& y : data.at(z)) {
                std::cout << y << std::endl;
            }
        }
    }

    size_t  count_active(){
        size_t sum = 0;
        for (size_t z = 0; z < size; z++) {
            for (size_t y = 0; y < size; y++) {
                for (size_t x = 0; x < size; x++) {
                    if (at(x, y, z) == '#') {
                        ++sum;
                    }
                }
            }
        }
        return sum;
    }

    size_t size;
    std::vector<std::vector<std::string>> data;
};

struct Hypercube {
    std::vector<Cube> data;
    size_t size;

    Hypercube(std::vector<std::string> input, size_t cycles) {
        assert(input.size() == input[0].size());
        assert(input.size() % 2);

        auto border = cycles * 3;
        size  = input.size()+ border * 2;

        std::string empty_line (input.size(), '.');
        std::vector<std::string> empty_input (input.size(), empty_line);
        Cube empty_cube (empty_input, cycles);

        data = std::vector<Cube>(size, empty_cube);

        data[size / 2] = Cube(std::move(input), cycles);
    }

    char& at(size_t x, size_t y, size_t z, size_t w) {
        assert(x< size);
        assert(y< size);
        assert(z< size);
        assert(w< size);
        return data.at(w).at(x, y, z);
    }

    size_t  count_active(){
        size_t sum = 0;
        for (auto& cube: data) {
            sum += cube.count_active();
        }
        return sum;
    }
};

static std::vector<std::string> input2 = {
        ".#.",
        "..#",
        "###"
};

static std::string input3[] = {

};

bool becomes_inactive( Cube& cube, int64_t x, int64_t y, int64_t z) {
    auto min_x = std::max<int64_t>(0, x-1);
    auto min_y = std::max<int64_t>(0, y-1);
    auto min_z = std::max<int64_t>(0, z-1);

    auto max_x = std::min<int64_t>(cube.size - 1, x+1);
    auto max_y = std::min<int64_t>(cube.size - 1, y+1);
    auto max_z = std::min<int64_t>(cube.size - 1, z+1);

    if (cube.at(x,y,z) != '#') {
        return false;
    }

    size_t active_count = 0;
    for (int64_t i = min_x; i <= max_x;++i) {
        for (int64_t j = min_y; j <= max_y; ++j ) {
            for (int64_t k = min_z; k <= max_z; ++k) {
                if (cube.at(i,j,k) == '#') {
                    active_count ++;
                }
            }
        }
    }

    return (active_count != 3 && active_count != 4);
}

bool becomes_inactive( Hypercube& cube, int64_t x, int64_t y, int64_t z, int64_t w) {
    auto min_x = std::max<int64_t>(0, x-1);
    auto min_y = std::max<int64_t>(0, y-1);
    auto min_z = std::max<int64_t>(0, z-1);
    auto min_w = std::max<int64_t>(0, w-1);

    auto max_x = std::min<int64_t>(cube.size - 1, x+1);
    auto max_y = std::min<int64_t>(cube.size - 1, y+1);
    auto max_z = std::min<int64_t>(cube.size - 1, z+1);
    auto max_w = std::min<int64_t>(cube.size - 1, w+1);

    if (cube.at(x,y,z, w) != '#') {
        return false;
    }

    size_t active_count = 0;
    for (int64_t i = min_x; i <= max_x;++i) {
        for (int64_t j = min_y; j <= max_y; ++j ) {
            for (int64_t k = min_z; k <= max_z; ++k) {
                for (int64_t l = min_w; l <= max_w; ++l) {
                    if (cube.at(i, j, k, l) == '#') {
                        active_count++;
                    }
                }
            }
        }
    }

    return (active_count != 3 && active_count != 4);
}

bool becomes_active( Cube& cube, int64_t x, int64_t y, int64_t z) {
    auto min_x = std::max<int64_t>(0, x-1);
    auto min_y = std::max<int64_t>(0, y-1);
    auto min_z = std::max<int64_t>(0, z-1);

    auto max_x = std::min<int64_t>(cube.size - 1, x+1);
    auto max_y = std::min<int64_t>(cube.size - 1, y+1);
    auto max_z = std::min<int64_t>(cube.size - 1, z+1);

    if (cube.at(x,y,z) != '.') {
        return false;
    }

    size_t active_count = 0;
    for (int64_t i = min_x; i <= max_x; ++i) {
        for (int64_t j = min_y; j <= max_y; ++j ) {
            for (int64_t k = min_z; k <= max_z; ++k) {
                if (cube.at(i,j,k) == '#') {
                    active_count ++;
                }
            }
        }
    }

    return (active_count == 3);
}

bool becomes_active( Hypercube& cube, int64_t x, int64_t y, int64_t z, int64_t w) {
    auto min_x = std::max<int64_t>(0, x-1);
    auto min_y = std::max<int64_t>(0, y-1);
    auto min_z = std::max<int64_t>(0, z-1);
    auto min_w = std::max<int64_t>(0, w-1);

    auto max_x = std::min<int64_t>(cube.size - 1, x+1);
    auto max_y = std::min<int64_t>(cube.size - 1, y+1);
    auto max_z = std::min<int64_t>(cube.size - 1, z+1);
    auto max_w = std::min<int64_t>(cube.size - 1, w+1);

    if (cube.at(x,y,z, w) != '.') {
        return false;
    }

    size_t active_count = 0;
    for (int64_t i = min_x; i <= max_x; ++i) {
        for (int64_t j = min_y; j <= max_y; ++j ) {
            for (int64_t k = min_z; k <= max_z; ++k) {
                for (int64_t l = min_w; l <= max_w; ++l) {
                    if (cube.at(i, j, k, l) == '#') {
                        active_count++;
                    }
                }
            }
        }
    }

    return (active_count == 3);
}


void action_on_slice(Cube& previous_cube, Cube& cube, size_t z) {
    for (int64_t y = 0; y < cube.size; ++y) {
        for (int64_t x = 0; x < cube.size; ++x) {
            if (becomes_inactive(previous_cube, x, y, z)) {
                cube.at(x, y, z) = '.';
            } else if (becomes_active(previous_cube, x, y, z)) {
                cube.at(x, y, z) = '#';
            }
        }
    }
}

int _17_part1() {

    size_t cycles = 6;

    Cube previous_cube {input, cycles};
    Cube cube {input, cycles};


    for (int c = 0; c < cycles; c++) {
        previous_cube = cube;

        for (size_t z = 0; z < cube.size; z++) {
            action_on_slice(previous_cube, cube, z);
        }

        std::cout << "----------------\nCycle " << c << std::endl;
        cube.print();
    }
    std::cout << cube.count_active() << std::endl;

    return 0;
}

int _17_part2() {

    size_t cycles = 6;

    Hypercube previous_cube {input, cycles};
    Hypercube cube {input, cycles};


    for (int c = 0; c < cycles; c++) {
        previous_cube = cube;

        for (size_t w = 0; w < cube.size; w++) {
            for (size_t z = 0; z < cube.size; z++) {
                for (int64_t y = 0; y < cube.size; ++y) {
                    for (int64_t x = 0; x < cube.size; ++x) {
                        if (becomes_inactive(previous_cube, x, y, z, w)) {
                            cube.at(x, y, z, w) = '.';
                        } else if (becomes_active(previous_cube, x, y, z, w)) {
                            cube.at(x, y, z, w) = '#';
                        }
                    }
                }
            }
        }
    }
    std::cout << cube.count_active() << std::endl;

    return 0;
}
