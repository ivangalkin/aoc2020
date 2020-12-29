#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>

#include <regex>


using namespace std::string_view_literals;

static std::vector<std::string> input= {
        ".LLLL.L.LLLL.LL.LLL.L.LLLLLLL.LLLLL.LLLLLLLLLLLLL.LLLL.LLL.LLLLL.LLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLL..LLLL.LLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLLLLLLL.LL.LLLLL.LLLL.L.LLLL.LLLLLL.L.LLL.LL..LLL.LLLLLLLLLLLLLLLLLL.L.LLL.LLLLLLL.LLLLL",
        "LLLLLLLLLLLLLLL.LLLLL.LLLLLL.LLLLLLL.LLLLL.LLLLLL.LLLL.LLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLL.L.LLL",
        "LL.LLLL.LLLLLLL.L.LLL.LLLLLL.L.LL.LLLLLLLL.LLLLLLLLL.LLLL.LLLLLL.LLLLLLLL.LL.LL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLLL.LLL.LLLLL.LLLLLLLLL.LLLL.LLLLLLLLL.LLLLLLLL.LLLL.L.LLLLLLLLLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.LL.L.LLLLLLLL.LLLLLLLLLLL.LLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLL.LLLL.",
        "LLLLLLLLLLLLLLL.LLLLLLLLLLL..LLLL.LLLLLLLL.LLLLLL.LL.L.LLLLL.LLL.LLLLLLLLLLLLL.LLLLLLL.L.LLLL",
        "....L..L.....L......LL...L.LL.......L...L.L......L.L.LLL....L..L....L.LL..LLL....LL..L..L...L",
        "LLLLLLLLLLLLL.L.LLLLLLLLLLLL.LLLLLL.LLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLL.LLL.LLLLL.LLLLLLLLLLLL.",
        "LLLLLLL.LLLLLLL.LLLLLLLLLL.L.LLLL.LLLLL.LL.LLLLLL.LLLLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLLLLLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLL.LLLL.LLLLLLLLLLLLLLLLLLLLL.LLLLLLLL.LLLLLLLL.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLLLL.LL.LL.LLLLLLLL.LLLLLLLLLLLLLLLLLL..LLLL.LLLLLLLLLLLLL",
        "LLLL.LL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLL.L.LLL",
        "LLLLLLL..LLLLLL.LLLLL..LLLLL.LLLL.LLLLLLLLLLL.LLL.LLL..LLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLL..LLLL",
        "...L...L..LL....L.......L...L.......LL........LL.....LL....L.....LL............L..LL....L....",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLLLLLLL.LLLLLLLL.LLLLLL.LLLL..LLLLLLLL.LLLLLLLL.LLL.L.LLLLLLLLLLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.L.LLLLLLLLLLL.LLLLL.LLLLLLL..LLLLLL.LLLLLL.LLLLLLLLLLLLL.L.LLLLL",
        "LLLLLLL.LLLLLLLLLL.L..LLLLLLLLLLL.L.L.LLLLLLLLLLL.LLLL.LLLLL.LLL.LLLLLLLL.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLL.LLLL.LLLLLLLLLLLLL.L.LLLL.LLLLLLLLL.LLLLLLLL..LLLL.LLLLLLLLLLLLL",
        "LLLLLLLLLLLL.LL.LLLLL.LLLLLL.LLLLLLLLLLLLL..LLLLL.LLLL.LLLLL.LLL.LLLLLLLL.LL.LLLLLLLLLL...LLL",
        "LLLLLLLLLLLLLLL.LLLLL.LLLLLL.LLLLLLLLLLLLLLLLLLLL.L.LLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLLLLLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.L.LL.LLLLLL.LLLLLLLL.LLLLLLLLLLLLLL.LL.LLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLLLLLLLLLLLLLLLL.LLLLLL.LLLL.LLLLLLLLLLLL.LLLLLLLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLL.L.LLLLL",
        "...........LL.....L.LL....L....L..LL..LL.L.LLLL........LL.L.LL..L......L...LL...LL..L.L......",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLLLLLLL.LLLLL.LL.LLLLLL.LLLL.LLL.LLLLL..LLLLLLLLLLLLLLLLLLLLL.LLLLL",
        "LLLLLLLLLLLLLLL.LLLLL.LLLLLLLLLLLLLLLL.LLLLLLLLLL.LLLL.LLLLLLLLLLLLLLLL.L.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLLLLLLLLLL.LLLLL.LLLLLLLLL.LLLLLLLLLL.LLLLLL.LLLL.LLLLLLLLL.LLLLLLL..LLLLL.LLLLLLLLLLLLL",
        "LLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLLL.LLLLLLLLLLLLLLL.LLLLL.L..LLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLL..LLLLLLL.LLLLL.LLLLLL.LLLL.LLLL.LLL.LLLLLLLLLLLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LL.LL...L....LLL.L.L....LL.L.....L...LLL..LL.......L.......L.......L..L......LLL..L.LL..LL..L",
        "LLLL.LL.LLLLL.L.LLLLLLLLLLLL.LLLL..LLLLLLL.LLLLLL.LLLL.LLLLLLLLL.LLLLLLLL.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLL.LL.LLLLL.LLLLLLLLLLLLLLLL.LLLLLLL.L.LLLLLLLLLLLLLL.LLLLLLLL.LLLL",
        "LLLLL.L.LLLLLLL.LLLLL.LLLLLLLLLLL.LLLLLLLL.LLLLL..LLLL.LLLLLLLLL.LLLLLLLL.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLLLLLLLLLLLLLLLL.L.LLLLLLLLLL.LLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLL.LLLLL",
        "L.LLLLLLLLLLLLL..LLLLLLLLLLL..LLL.LLLLLLLL.LLLLL...LLL.LLLLLLLLL.LLLLLLLLLLL.LL.LLLLLLLLLLLLL",
        ".L......LL...L.L....L...L...........L.LL...L.LLLLL.....LL....L......L.LL..L..L.....L...L.L.LL",
        "LLLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLL.LLLL.LLL.LLLLLL.LLL..LLLLLLLLL.LLLLLLLLLLLLLL..LLLLLL.LLLLL",
        "LLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLL.LLLL.LLLLLLLLLL.LLLLL.LLLLLLLL.LLLLL.LLLLL.L.LLLLL",
        "LLLLLLLLLLLLLLL.LLLLL.LLL.LL.LLLL.LLLLLLLLLLLLLLLLLLLL.LL.LLLLLL.LLLLLLLL.LLLLL.LLLLLLLLLLLLL",
        "LLLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLL.LLLLLLLL.L.LLLLL.LLL.LLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLLLLLLLL",
        "LL.L.LLLLL.LLLL.LLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLL.LLLLL",
        "LLLL.LLLLLLLLLL.LLLLLLLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLLLLLLL.L.LLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLL.LLLL.LLLLLLLL.LLLLLLLLLLL.LLLLL.LLLLL.LLLLLL.LL.LL.LLLLLLLLLLLLL",
        "..L....L.L.LL.L.........L...LL.L....LL......LL..LL.L.L.....L..L..L..L..LL.L...L..L....L......",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLL.LLL..LLLLLLLLLLLLLLLLLLLLL.LLL.LLLLLLLLLL.LL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.L.LLLLLLLLLLLLLLLLLLLLLLL.LLLLLLL..LLLLLLLLLLLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.L.LLLL.L.LLLLLLLLLLL..LLLLLLLLLL.LL.LLLLLLLLLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLLLLLLLLLLLLLLLL.LLLLLL.LLLL.LLLLLL.LL.LLLLLLLL..L.LL.LLLLLLLLLLLLL",
        ".L......L....L.L.L...LLLL......LL...LL...L...L......L..L...........L......L.......L....L.L...",
        "LL.LLLLLLLLLLLLLLLLLLLLLLLLL.LLLL.LL.LLLLL.LLLLLLLLLLL.LLL.LLLLL.LLLLLLLL.LLLLL.LL.LLLL.LLLLL",
        "L.LLLLL.LLLLLLL.LLLLL.LLLLLL.LL.LLLLLLLLLL.L.LLLLLLLLL.LLLLLLLLL.LLLLLLLL.LLLLLLL.LLLLLLLLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLLLLLLL.LLLLL.LLLLLLLL.LLLLLLLLLLLLLLL.LLL.LLLL.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLLLLLLLLLLLL.LLLLLLLLLL.LLLL.LLLLLLLLLLLLLLL.L.LLLLLLLLLLLL.LLLLL.LLLLLLLL.LLLLLLL.LLLLL",
        ".LLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLL.LLLLLLLLLLL.LLLLLLLLLLLLLLLLL.LLLLLLLLL.LLLLL.L.LLLLL.LLLLL",
        "LLLLLLL.LLLLLLLLLLLLLLLLLL.L.LLLL.LLLLLLLLLLL.LLL.LLLL.LLL.LLLLL.LLL.LLLLLLLLLL.LLLLLLL..LLLL",
        ".L.....L...L....L.LL............LL..L.LL.....LLL..L.............L...........L...L.L.L........",
        "LLLLLLLLLLLLL.L.LLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLL.LLLL.LLLLLLLLL.LLL.LLLL.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLL..LLLLLL.LLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLL.LLLLL",
        "LL.LLLLLLLLLLLL.LLLLL.LLL.LL.LLL..LLLLLLLL.L.LLLL.LLLLLLLLLLLLLL.LLLLLL.L.LLLLLLLLLLLL.L.LLLL",
        "LLL.LLL.LLLLLLLLLLLL..LLLLLL.LLLL.LLLLLLLLLLLL.LLLLLLLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLLLLLLLLLLLLLLLLLLL.L.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLL.LL.L.LLLLLLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLLLLLLLL",
        "LLLLLLLLLLLLLLLLLLLLL.LLLLLL.LLLLLLLLLLLLL..LLLL..LLLLLLLLLLLLLL.LLLLLLLLLLLLLLLLLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLLLLLLL.LLLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLL.LL.LL",
        ".LLLLLL.LL.LLLLLLLLLLLLLL.LLLLLLLLLLLLLLLL.LLLLLL.LLLLLLLLLLLLLL.LLLLLLLLLL.LLL.LLLLLLL.LLLLL",
        "LL.L.L...L...L...LLL.......LLL..L.L...L.......L......L.LL.......L..LLL.L..L.L.LL..L..L.L.LLL.",
        "LLLLLLL.LLLLLL..LLLLL.LLLLLL.LLLL.LLLLLLLL.LLLLLL.LLLL.LLLLLLLLLLLLLLLLLL.LLLLLLLLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLL.LLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLLLLLLLLLLLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLL.LLLLLLLL.LLLLLL.LLLL.LLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLLL.LLLL",
        "LLLLLLLLLLLLLLL.LL.LL.LLLLLL.LLLL.LLLLLLLL.LLLLLLLLLLL.LLLL.LLLL.LLLLLLLL.LLLLLLLLLLLLLLLLLLL",
        "LLLLLLL.LL.LLLL..LLL.LLLLLLLL.L.L.LLLLLLLL.LLLLLL.L.LL.LLLLLL.LL.LLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLLLLLLL.LLLLLLLLLLL.LLLLLLLLL.LLLLL.LL.LLLLLLLLL.LLL.LLLL.",
        "L.LLLLLLLLLLLLLLLLLLL.LLLL.L.LLLL.L.LLLL.L.LLLLLL.LLLL.LLLLLL.L.LLLLLLLLLLLLLLLLLLLLLLL.LL.LL",
        ".LLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLLL.LLL.LLLLLLLLLLL.LLLLLL.LLLLLLLLLLLLLLLLL.LLLLL.L.LLLLL",
        "LL....L....L..L.L.....L.L...L...L.....L.....L....LLL..L.L..L..L.LL.L...L.LLL.......L....L.LL.",
        "LLLLLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLLLLLLLL.LLLLLLLLLLL.LLL.LLLLLLLLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLL.LLLLLLL.LLLL.LLL.LLLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLLLL.LLLLLLLL.L..LLLLLLLLLL.LLLLL",
        "LLLLLLLLLLLLLLL.LLLLL.LLLLLLLLLLL.LLLLLLLL.LLLLLLLLLLL.LLLLLLLLL.L.LLL.LLLLLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLLL.LLLLLLL.LLLLLL.LLLL.LLLLLL.LLLLLLLLLLL.LLLLL.LLLLLLLLLLLLL",
        "LLLL.LL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLLLLLLL.LLLLLLLLLLL.LLLLLLL.L.LLLLLLLL.LLLLL.LLLLLLL.LLLLL",
        "LLLLLLL.LLLLLL.LLLLLL.LLLLLLLLLL..LLLLLLLL.LLLLLL.LLLL.LLL.LLLLL.LLLLLLLLLLLLLL.LLL.LLL.LLLLL",
        "LLLLLLLLLLLLLLL..LLLLLLLLLLLLLLLLLLLL..LLL.LLLLLL.LL.L.LLL.LLLLLLLLL..LLL.LLLLL.LLLLLLL.LLLLL",
        "..L..L..L.L.......L..LL...L.L..LL...L............L.L...L.....L...LL..LL......L.L...L.....L..L",
        "LLLLL.LLLLLLLLLLLLLLL.LLLLLL.LLLL.LL.LLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLLL.LLLLL.LLLLLLLLLLLLL",
        "L.LLLLL.LLLLLLL.LLLLLLL.LLLL.LLLL.LLLLLLLLLLLLLLL.LLLLLLLLLLLLLL.LLLLLLLL.L.LLL.LL.LLL.LLLLLL",
        "LLLLLLL.LLLLLLLLL.LLLLLLLLLLL.L.L.LLLLLLLL.LLLLLL.LLLL.LLLLLLLLLLLLLLLLLL.L.LLL.LLL.LL..LLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLLLLLLLLLLL.LLLLLL.LLLL.LLLL.LLLL.LLLLLLLL.LLLLL.LLL..LL.LLLLL",
        "LLLLLLL.LLLLLLL.LLLLLLLLLLLL.LLLL.LLLLLLLL.LLLL.LLLLLL.LLLLLLLLLLLLLLLLLLLLLLLL.LLLLLLLLLL.LL",
        "LLLLLL.LLLLLLLL.LLL...LLLLLL.LLLL.LLLLLLLL.LLLLLL.LLLLLLLLLL.L.L.LLLLLLLL.LLLLL.LLLLLLL.L.LL.",
        "LL.LL.L.LLLLLLLLLLLLL.L.LLLLLLLLLLLLLLLLLL.LLLLLL..LLL.LLLLLLLLLLLLLLLLL..LLLLL.LLLLLLL.LLLLL",
        "LLLLLLLLLLLLLLL.LLL.LL.LLLLL.LLLL.LLLLLLLL.LLLLLLLLLLL.LLLLLLLLL.LLLLLLLLL.LL.L.LLLLLLLLLLLLL",
        "LLLLLLL.LLLL.LL.LLLLL.LLLLLL.LLLL.L.LLLLLLLLLLLLLLLLLLLLLLLLLLL..LLLLLLLLL.LLLLLLLLLLLL.LLLLL",
        "L.LLLLL.LLLLLLL.LLLLL.LLLLLLLLLLL.LLLLLLLL.LLLLLL.LLLL.LLLLLLLLLLLLLLLL.L.LLLLLLLLLLLLL..LLLL",
        "LLLLLLL.LLLLLLLL.LLLLLLLLLLL.LLLLLLLLL.LLL.LLLLLLLLLL..LL.LLLLLL.LLLLLLLL.LLLLL.LLLLLLLLLLLLL"
};

static std::vector<std::string> input2 = {
        "L.LL.LL.LL",
        "LLLLLLL.LL",
        "L.L.L..L..",
        "LLLL.LL.LL",
        "L.LL.LL.LL",
        "L.LLLLL.LL",
        "..L.L.....",
        "LLLLLLLLLL",
        "L.LLLLLL.L",
        "L.LLLLL.LL"
};

static std::string input3[] = {

};

bool is_occupied_visible(const std::vector<std::string>& map, int64_t x, int64_t y, int64_t diff_x, int64_t diff_y) {
    int64_t i = x + diff_x;
    int64_t j = y + diff_y;
    while( i >= 0 && i <= map[0].size()-1 &&  j >= 0 && j <= map.size()-1) {
        if (map[j][i] == 'L') {
            return false;
        }
            if (map[j][i] == '#') {
               // std::cout << "-- " <<j << " " << i << " = " <<  map[j][i]  << std::endl;
                return true;
            }
        i+= diff_x;
            j+= diff_y;
    }
    return false;
}

size_t calculate_visible_occupied(const std::vector<std::string>& map, int64_t x, int64_t y) {
    static std::vector<std::tuple<int64_t, int64_t>> directions{
            {0,-1},
            {1,-1},
            {1, 0},
            {1, 1},
            {0, 1},
            {-1, 1},
            {-1, 0},
            {-1, -1}
    };
    size_t count = 0;
    for (auto diff : directions) {
        if (is_occupied_visible(map, x, y, std::get<0>(diff), std::get<1>(diff))) {
            // std::cout << "TRUE " << std::get<0>(diff) << " " << std::get<1>(diff) << std::endl;
            ++count;
        }
    }
    return count;
}

bool is_empty(const std::vector<std::string>& map, int64_t x, int64_t y) {
    auto min_x = std::max<int64_t>(0, x-1);
    auto min_y = std::max<int64_t>(0, y-1);
    auto max_x = std::min<int64_t>(map[0].size() -1, x+1);
    auto max_y = std::min<int64_t>(map.size()-1, y+1);

    if (map[y][x] != 'L') {
        return false;
    }

    for (int64_t i = min_x; i <= max_x;++i) {
        for (int64_t j = min_y; j <= max_y; ++j ) {
            if (map[j][i] == '#') {
                return false;
            }
        }
    }
    return true;
}

bool is_empty2(const std::vector<std::string>& map, int64_t x, int64_t y) {

    if (map[y][x] != 'L') {
        return false;
    }

    return calculate_visible_occupied(map, x, y ) == 0;

}

bool is_occupied(const std::vector<std::string>& map, int64_t x, int64_t y) {

    auto min_x = std::max<int64_t>(0, x-1);
    auto min_y = std::max<int64_t>(0, y-1);
    auto max_x = std::min<int64_t>(map[0].size() -1, x+1);
    auto max_y = std::min<int64_t>(map.size()-1, y+1);
    int nr_occupied = 0;

    if (map[y][x] != '#') {
        return false;
    }

    for (int64_t i = min_x; i <= max_x;++i) {
        for (int64_t j = min_y; j <= max_y; ++j ) {
            if (map[j][i] == '#' ) {
                nr_occupied++;
            }
        }
    }
    return nr_occupied >= 5;
}

bool is_occupied2(const std::vector<std::string>& map, int64_t x, int64_t y) {

      if (map[y][x] != '#') {
        return false;
    }

    return calculate_visible_occupied(map, x, y ) >= 5;
}

std::tuple<int64_t, int64_t> found_actionable_seat(std::vector<std::string>& map) {
    auto max_x = map[0].length();
    auto max_y = map.size();
    for (int64_t i = 0; i < max_x;++i) {
        for (int64_t j = 0; j < max_y; ++j ) {
            if (is_empty(map, i, j) || is_occupied(map, i, j)) {
               return {i, j};
            }
        }
    }
    return {-1, -1};
}



void action( const std::vector<std::string>& previous_map, std::vector<std::string>& map, int64_t x, int64_t y) {

    if (is_empty2(previous_map, x, y)) {
        map[y][x] = '#';
    } else if (is_occupied2(previous_map, x, y)) {
        map[y][x] = 'L';
    } else {
        return;
    }

}

int _11() {

    auto map = input;
    std::vector<std::string> previous_map;

    std::vector<std::string> test_map1 = {
            ".##.##.",
            "#.#.#.#",
            "##...##",
            "...L...",
            "##...##",
            "#.#.#.#",
            ".##.##."
    };

    std::vector<std::string> test_map2 = {
            ".......#.",
            "...#.....",
            ".#.......",
            ".........",
            "..#L....#",
            "....#....",
            ".........",
            "#........",
            "...#....."

    };

    std::vector<std::string> test_map3 = {
            ".............",
            ".L.L.#.#.#.#.",
            ".............",
    };

    assert(calculate_visible_occupied(test_map1, 3, 3) == 0);
    assert(calculate_visible_occupied(test_map2, 3, 4) == 8);
    assert(calculate_visible_occupied(test_map3, 1, 1) == 0);

    while (previous_map != map) {
        previous_map = map;

        auto max_x = map[0].length();
        auto max_y = map.size();
        for (int64_t j = 0; j < max_y; ++j) {
        for (int64_t i = 0; i < max_x; ++i) {
                action( previous_map, map, i, j);
            }
        }
        std::cout << "--" << std::endl;
        for (const auto& line : map) {
            std::cout << line << std::endl;
        }
    }

    size_t total_occupied = 0;
    for (auto& line: map) {
        total_occupied+= std::count(line.begin(), line.end(), '#');
    }
    std::cout << total_occupied << std::endl;



    return 0;
}
