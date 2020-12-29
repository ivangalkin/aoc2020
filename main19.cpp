#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>
#include <variant>

#include <regex>
#include <sstream>


using namespace std::string_view_literals;

static std::string input[] = {
        "0: 4 1 5",
        "1: 2 3 | 3 2",
        "2: 4 4 | 5 5",
        "3: 4 5 | 5 4",
        "4: a",
        "5: b"
};

static std::string input2[]= {
        "66: 26 127 | 132 49",
        "65: 99 132 | 100 26",
        "40: 1 26 | 16 132",
        "87: 16 26 | 49 132",
        "124: 132 57 | 26 107",
        "80: 1 26 | 53 132",
        "52: 26 24",
        "58: 43 132 | 26 26",
        "72: 49 26 | 16 132",
        "82: 26 132",
        "63: 26 135 | 132 127",
        "113: 25 26 | 134 132",
        "50: 26 21 | 132 135",
        "35: 26 12 | 132 106",
        "78: 132 123 | 26 14",
        "39: 49 26 | 82 132",
        "104: 132 26 | 26 26",
        "88: 3 132 | 127 26",
        "90: 82 26 | 16 132",
        "96: 104 26 | 16 132",
        "98: 24 26 | 104 132",
        "53: 43 43",
        "27: 5 132 | 127 26",
        "91: 93 26 | 135 132",
        "57: 132 118 | 26 125",
        "25: 49 26 | 21 132",
        "22: 132 1 | 26 49",
        "135: 132 132 | 26 132",
        "120: 80 132 | 81 26",
        "132: a",
        "10: 26 60 | 132 124",
        "97: 132 7 | 26 10",
        "130: 103 132 | 66 26",
        "41: 58 26 | 16 132",
        "47: 81 26 | 18 132",
        "111: 132 127 | 26 3",
        "119: 132 62 | 26 36",
        "126: 26 16 | 132 49",
        "76: 4 26 | 30 132",
        "17: 49 26 | 24 132",
        "67: 26 58 | 132 53",
        "131: 127 26 | 135 132",
        "71: 26 112 | 132 115",
        "15: 98 132 | 6 26",
        "114: 74 26 | 101 132",
        "60: 70 132 | 19 26",
        "45: 132 27 | 26 40",
        "105: 135 26 | 16 132",
        "24: 43 26 | 132 132",
        "18: 82 26 | 135 132",
        "85: 135 132",
        "56: 132 69 | 26 113",
        "89: 13 26 | 122 132",
        "37: 82 132 | 58 26",
        "106: 26 49 | 132 21",
        "125: 26 5 | 132 24",
        "55: 37 26 | 2 132",
//        "8: 42",
        "8: 42 | 42 8",
        "81: 26 16 | 132 21",
        "107: 26 73 | 132 131",
        "112: 26 67 | 132 90",
        "84: 26 48 | 132 71",
        "49: 132 26",
        "44: 24 132 | 5 26",
        "1: 132 26 | 26 132",
        "28: 79 26 | 87 132",
        "68: 9 26 | 89 132",
        "7: 26 76 | 132 68",
        "115: 26 128 | 132 72",
        "79: 49 132 | 104 26",
        "6: 26 21 | 132 16",
        "136: 26 129 | 132 121",
        "33: 132 116 | 26 110",
        "116: 39 26 | 105 132",
        "117: 56 132 | 136 26",
        "16: 26 132 | 43 26",
        "133: 132 5 | 26 1",
        "86: 26 104 | 132 135",
        "51: 86 132 | 137 26",
        "127: 132 132 | 132 26",
        "34: 132 130 | 26 83",
        "94: 132 127 | 26 49",
        "137: 132 135 | 26 53",
        "100: 26 34 | 132 114",
        "19: 26 85 | 132 64",
        "12: 132 21",
        "73: 93 132 | 93 26",
        "2: 26 1 | 132 24",
        "74: 132 126 | 26 95",
        "62: 132 55 | 26 20",
        "38: 26 84 | 132 119",
        "14: 108 26 | 94 132",
        "75: 82 132",
        "61: 16 132 | 3 26",
        "99: 132 33 | 26 109",
        "59: 1 26 | 93 132",
        "77: 132 117 | 26 102",
        "21: 132 132",
        "122: 26 127 | 132 93",
        "31: 38 26 | 77 132",
        "95: 135 132 | 1 26",
        "36: 26 120 | 132 23",
        "30: 61 132 | 41 26",
        "54: 135 26 | 53 132",
        "70: 96 132 | 54 26",
        "26: b",
        "29: 3 26 | 104 132",
        "23: 132 52 | 26 88",
        "9: 132 37 | 26 32",
        "32: 24 132 | 53 26",
        "103: 132 127 | 26 5",
        "64: 104 43",
        "5: 132 132 | 26 26",
        "102: 78 132 | 46 26",
        "123: 73 132 | 80 26",
        "42: 97 132 | 65 26",
        "3: 132 43 | 26 132",
        "4: 132 92 | 26 29",
        "134: 132 21 | 26 93",
        "93: 26 26",
        "20: 132 59 | 26 105",
        "13: 26 58 | 132 5",
        "43: 132 | 26",
        "110: 125 26 | 12 132",
        "109: 132 35 | 26 47",
        "69: 22 26 | 44 132",
        "83: 111 26 | 63 132",
        "0: 8 11",
//        "11: 42 31",
        "11: 42 31 | 42 11 31",
        "121: 132 17 | 26 75",
        "128: 58 132 | 53 26",
        "92: 53 26 | 93 132",
        "108: 26 93 | 132 93",
        "46: 132 45 | 26 51",
        "118: 82 26 | 58 132",
        "48: 15 132 | 28 26",
        "129: 132 50 | 26 91",
        "101: 132 131 | 26 133"
};

static std::vector<std::string> example_input2 = {
        "42: 9 14 | 10 1",
        "9: 14 27 | 1 26",
        "10: 23 14 | 28 1",
        "1: a",
//        "11: 42 31",
        "5: 1 14 | 15 1",
        "19: 14 1 | 14 14",
        "12: 24 14 | 19 1",
        "16: 15 1 | 14 14",
        "31: 14 17 | 1 13",
        "6: 14 14 | 1 14",
        "2: 1 24 | 14 4",
        "0: 8 11",
        "13: 14 3 | 1 12",
        "15: 1 | 14",
        "17: 14 2 | 1 7",
        "23: 25 1 | 22 14",
        "28: 16 1",
        "4: 1 1",
        "20: 14 14 | 1 15",
        "3: 5 14 | 16 1",
        "27: 1 6 | 14 18",
        "14: b",
        "21: 14 1 | 1 14",
        "25: 1 1 | 1 14",
        "22: 14 14",
//        "8: 42",
        "26: 14 22 | 1 20",
        "18: 15 15",
        "7: 14 5 | 1 21",
        "24: 14 1",

        "8: 42 | 42 8",
        "11: 42 31 | 42 11 31",
};

static std::vector<std::string> example_input3 = {
        "abbbbbabbbaaaababbaabbbbabababbbabbbbbbabaaaa",
        "bbabbbbaabaabba",
        "babbbbaabbbbbabbbbbbaabaaabaaa",
        "aaabbbbbbaaaabaababaabababbabaaabbababababaaa",
        "bbbbbbbaaaabbbbaaabbabaaa",
        "bbbababbbbaaaaaaaabbababaaababaabab",
        "ababaaaaaabaaab",
        "ababaaaaabbbaba",
        "baabbaaaabbaaaababbaababb",
        "abbbbabbbbaaaababbbbbbaaaababb",
        "aaaaabbaabaaaaababaa",
        "aaaabbaaaabbaaa",
        "aaaabbaabbaaaaaaabbbabbbaaabbaabaaa",
        "babaaabbbaaabaababbaabababaaab",
        "aabbbbbaabbbaaaaaabbbbbababaaaaabbaaabba"
};

static std::vector<std::string> input3 = {
        "abbbbaaabbbbaabbabbbaabaababbaababbbabbb",
        "bbaaaabbaaabbbbaaaaaabab",
        "baabaaabbaabbbaaaababaaaaaabbbababaaabaabbbbaabaaabbaabbbbaaabba",
        "aaabaaabaabbabbabbabaaba",
        "bbaaabbbbbbabaabaaabaabb",
        "aaabaabaabaaaababaababba",
        "aababbbbababbabbbabaaaaaaabbaabaaabbbaaa",
        "baababababaabaaababbbaaa",
        "aaabbaaaaababaabbbbabbba",
        "baaabaaaabbbaabbbbbbbbbb",
        "baaabaaabbaabbbabbbbababaabbaabb",
        "aaabbbababbbbbaaaabbbabaaaabababbbaaabba",
        "aaabaaaabbbabbbabbabaabb",
        "aabaaabaaaabaabaabbbbabb",
        "bbaabbbabababbbaabaaabaabbbbaaab",
        "abbaaaaaaaaaabaabaababababbaaaba",
        "babaaaaabaaababbabaabaaaabbababbaaaabbba",
        "aabbbbbbbababbbbbabaabbbaabbabab",
        "bbbabbbabbababbbabbbbbbabaaaabaaaaaabbba",
        "aabbbbbaababbabbbbbabaabaabbabbaabbabbabbababbaa",
        "aabaaaaabaaabbaaabaaabababbbabaaabbaaabababaabaa",
        "ababbaaaabbaabaaaababaabbaaabbab",
        "abbbbaaaabbaaaaababbbabbbaabaabaaababbbababbbbbbaabbbaabbbbbbbabbabbaaab",
        "aabaaabaabbabababbbbabbbbaabbbab",
        "babaabbaabbaabaababababa",
        "abbbaaaaaaabaaababbababbbabbabba",
        "bbabbbbaabababaababababb",
        "babaaaaaabbbaaaabbbababa",
        "aabbaaabbbaaabbbababaabb",
        "aabbbbaabbbabbaababbbaab",
        "ababbbbbabaabbaaaaaaabaabbabaabbaabbaaaa",
        "aababaaabbaaababbbabbaaaabbabbbbbabbabaababaabab",
        "aabbbabaaababbbabbababaaaaabbabbababbbbbbaababbb",
        "bbabbaabbbaabaabbbaaabbbabbbabbabaaabaaababababbabbbaabbbbbabaab",
        "abababaaaababaaaabaababb",
        "bbbbababbbaabbbaabaaababbbabbbaa",
        "aaabbaaababaaaababbabbab",
        "bbaabbbabaaaaaababaabbabbbbaaabbbbbbbbabbaaaabbbaaaaaaba",
        "abaaabbbbabbbabbaabababaaaaaaaaa",
        "ababbabbabbababbbbbaabbbbbbbabbaababaabbbabbbaaaaaabaababbaaaabbbaabbabbbbbaababbbbaaaaa",
        "aabbabaaabbbaaaabbbababb",
        "bbaaababbbaaabbbabbabaab",
        "aaaaabaaabbbbabaababbbbaabaabaaaaaabbbbb",
        "abbbaabbaababbbbabaababb",
        "baaababbbabaaabbbaabbaab",
        "bababbbbbaababbaabaabbbaaaaabbbbabaabaabbabbbbab",
        "abaabbbaabaaaabbababaabb",
        "bbbaabbbababbbbbaababaaabababbbbbbbbbbabbabaabaa",
        "aaabbbaaabbbaaaaabaabbaabbabbaab",
        "bbabbaababababbaabaaabbb",
        "bbbbbaaaabbabbbbaaabaaaa",
        "abbbbbaababbbbaabbbababa",
        "abbabbaabbabbbbababababa",
        "aabbabbaabaabaaabbbaabaaaaaabbba",
        "abbabbbaaaabbbaabaaaaaaaaabbaabb",
        "aabbbbaaabaaaabbaabbaaba",
        "aababaababaabaaabaaabbaabbbbaaabbbbbbabb",
        "bababaaaabbbbbaaaabaabbb",
        "babaaaabbabaaabbabaabbaaaaaaabbabababaaabaabbabb",
        "aabbbbaaaaaaabbaaabbaaaa",
        "abbbaabbbaaaaaaabaabbbaa",
        "abababaabbabbaaabbbaabaaababaaaaaabaabbbababaabbabbaaaab",
        "abbbabaaaababbbaabbbbbaaababaaba",
        "bbbbbaaaaaabaaababababab",
        "bbaaaabbaabaabbaaaabaaabbaabbbaa",
        "abbbabbaaaaaaabbabbbaabbaaabaabb",
        "aaaabaabaaaaabbabaabbaba",
        "abbbbabaaaaaaabbbbbbaaaaaaaabaababaababa",
        "bbaaabbbaabaababbbabbaab",
        "ababbbbbabbbbbabbbaaaabbbbbbbaab",
        "aaaaabaaaabaaaabbaaabaaaaababbab",
        "abbabbaaabbbaaaabbabbaab",
        "ababbabbaababbbbaababaaaabbaaaaa",
        "abaaababaaabbabbbaaaaabbabaabbaaabbbabbaaaaababa",
        "aabbbabababbbbbbaabbaaaa",
        "ababbbababaaaabbbbbaabbbabbbabaabbbaabbbababaaab",
        "aabbabbbbbabaaaabbaaaabbbababbaa",
        "abaabbaabbbaaabbababaaaaabaabaaaabaabbababaababb",
        "baaabaaaaaabbabbabbbabbb",
        "abbbabbaabaabbaabbbaaabaaaabaababbaabaab",
        "aababbbbabbaabbbaaaabbba",
        "bbbbabbabbabbaabbbbaaaababaaabaabbaaaababbbaababaaababab",
        "bbbbbaaaabaaaabbbaaaabbb",
        "abbabababbbabbbbabbabaab",
        "babaaaabbbaabbbbabaabbbb",
        "bbbaabbbabbbbbaabbbaabab",
        "abaabaaaabbbabbbbabaaaaaaaabbbbaabbaababaaaaababbaaaaaab",
        "baaabaaabbbaaabaaaaabbbbaabbbbbaaaabbbaababbbbaaabababababbbbaab",
        "aabaaaabbaaaaaabaabaaabbaabbbababbaaaaaa",
        "baaabbabaabbbbbbbaaababbbabbabbb",
        "baaabbababbabbaabbbaabbbbaabaabaaaaaabaabbababbbbabbabaabaaababb",
        "aabbabbbbbbbbbabbaabbaab",
        "aabbabbaaabbabaabababaab",
        "babaaaaabbabaaaabbaaababaaabbaaabbaaaaabbaaabaab",
        "abbaabababbabababbabbabababbaabb",
        "abbbabaabbbaaabbabaabbbaaabababb",
        "bbbbaaaaaabbbbaaaaabaaabababaaaaaabaabbbababbaab",
        "aabbabbabaabbababbabbaab",
        "abaaaaabaaaaaabbabaaababbbababbabbbbbbaa",
        "abababbabbaaaaabbabbaabb",
        "baababbabbaababaaaababbb",
        "ababbabbaababaababaababb",
        "baaaaabbabaabbaabbaabbbbaaaabbaa",
        "abaaaabbaaabaababbabbaaaaaaaabaaabaaaabaaabbbbabaaaababa",
        "aabbaaabaabaabaababbabab",
        "ababaaaaaabbbabababaaabaaabababb",
        "aabaaabbababbbababaaabaa",
        "bbbbbbbababaaabbaaaabaaabbabbaabbbbbbaabaabbbbababbbaababaababaa",
        "baaababababbbbaaaaababbabbaaaaaaaabbbabb",
        "bbbbaabbababbbabbabaaaabbbbbbbbb",
        "aaabaaababababaabaaaaaabbaaabbabbbbbbbbb",
        "babbbbbabaaaaaababbbabbaababbbbbaaabbaba",
        "aababaabbaaabbaabbbbabbbabaaaabaaabbabab",
        "abbabababaaabbbbabbbbababbbababb",
        "abbabbbbabbaabaabababbba",
        "bbaaabaabababaaaaaaaabbb",
        "aaabbbaabaabaababbbbbbbb",
        "aabbaaabaababaaaabbaabaaaabababb",
        "abbbaabbabaaababaabbaaaa",
        "aaabbbbaaabaaabaabaabaaaaaaaaabbbbababaabbabbbaaabbaaababaabbbab",
        "bbbaaaaaabaabbababbabbaaaaababbaabbabbbbabaaaaaabbaaaaba",
        "aabbbbbaabbaababbbababbb",
        "bababbbbababbababaaabbaaabbabbbbaaababbbbbbbbbaabaaaabbb",
        "ababbbbaabbaabbbabbaabbabbabbaababaababb",
        "abbbaaaababaabbbbabaaabaaaaaabab",
        "aabbabbaabababbabaabababbbaaabba",
        "aabbaabababbabbbbabbbaba",
        "abababaaaabaaaaaababbbbababababa",
        "abaabaaaaaabbbabaababaabababbaba",
        "aabbabbaaababababaabbaaabaababbaaaaaabab",
        "abaaabbaaababaaaaabbbabb",
        "babbbbaaabaaaaababaabbbabbbbaabaaababbaaabbabbab",
        "abbaabbabababbbbbabbbaab",
        "baabbaaaaaaababbabbabbaabbababba",
        "babaabbbbbabbaaabbaaaabbbbababbb",
        "aaabbaaabbbaaabaaabbabbaaaabbabbbbbaaaababbbbbba",
        "bbbaaaaaaaabbbaababaabbabaaaaaaaabaababbbaaaabbb",
        "baaaaaaaabbababbbabbabaaabbbbaabaabaaabbabbabaabaaabbaabbbbabbbaabaababbabbaaabaaabaaaab",
        "bbababaaababaaaaababbbaa",
        "bbbbaaaabbabbabaabbaaaab",
        "bbabbbaaabbabababbabbbbaaabbabbababbbbbbaabaaaba",
        "babbbabaabbbbbbbbbbabbaabababaaa",
        "bababbbbaaaaaabbbabaabbbaabbabbbbabbabab",
        "abbabbaabbbbaabbaaaaaaba",
        "abababaaaababbbbaababbab",
        "abbbbbababaaaabbbbbbbbba",
        "aabbabaaaabbaaabaaababbabbbaabbbbbabbaabbbbbbabb",
        "abaaaaabbbabababbaabbbaabbbbaaaabbbbbabb",
        "bbbaaaabbbaaabababaaabababaaabaa",
        "bbaaabbbbaababbbbbabaaabaaaababaaaaabbab",
        "bbbabbaaaababaabbbabbbab",
        "abaaaababbbbbbaaababaaabbbbaabbbabbbbaabbabaabaaababaaaaabbabbaa",
        "bbbaabaaabaaabbbbbaaaaaa",
        "babaabbbabbbabbabbaaaabbabababbabaabbbaababbaaab",
        "ababbbbaabbabbbbbabaabab",
        "aaaabaabaababaaaabbbaaba",
        "bbbabbaaaabaaaaabaababaa",
        "abababbaaaabaababbabbabaabaaaaababbbbaaa",
        "babaabbababbbbaaabbabbbb",
        "bbbbaabbaaaaaabbbbbababa",
        "aabaaabbaaaaaabbababaaab",
        "bababbbbabbaabbaaaabbbbaaababaaabbbaaaabbbabbbbb",
        "bbbabbaabbaabababababaaabaaabaabbbabbbab",
        "bbaabababaababbabbabbaaaabaaabababbaaaab",
        "ababaaaabbababaababaaabaabbaabbabbaaaaba",
        "babbbbbababbbbbabbbabbababaabababbbaabba",
        "abaabbaaabaaabbabbaaababbbbbaaaaabaababaaaaabbaa",
        "bbbabbaabbaabbaabbaabbbbbbbbabaabaababbb",
        "baaaaabbbbbabbbbbaaabbba",
        "bbbabaababbbbbabbbababab",
        "abbbaaaaabbabbaaaabaaabaabbbbaaa",
        "abbbaabbbbbaaaabbbabbaaabbbabbbbbbababbbaaaababaabbbbaab",
        "bbbaabbbabaaababbbbbaaab",
        "abbbbbaaaabababababaabaa",
        "abbaabbabaababaaababbababbaaabaaabbababbbbbbbbaababaaaaaaaabbbbbbbabaaba",
        "bbbaaaaaabbababbbbababbb",
        "aaabbbbaabaaabbaabbabaaaaaaaaaaa",
        "aaaabbbbabbaabaabbabaaaaabaaaabbbbbbbbab",
        "abbbabaaaabbabbaaaaabbaa",
        "babbbabbaabbbbaabaaaaabbabaaabaa",
        "bbaabbaabbbaaaaabbbababa",
        "bbaabbaaabaabaaaaaaaaabbbaabbaba",
        "bababbbbbbabbaaaaaaabaaa",
        "bbabbaaaabbaaaaabbabaabb",
        "bbbaaabbbabbabaaabababbbbbbababbbbbabaaa",
        "babbbbbaababbbababbabbbabaaaabbbabaaabaa",
        "bbaababbbbabbbbababaaabababababbaaababab",
        "ababbabaabababaaaabaabaaaaaababb",
        "babaabbabaaaaaabbaabbaba",
        "aabaaabbaaaaabbababbbabbaabaaabbbababbababbabaabbbabbbab",
        "abbababaababaaaabbaabaab",
        "ababbbbabbbaabbbbbbbbabb",
        "bbaababbbabaaaaabaabbaaabaaaabab",
        "abaabbbaaabaaaaabaabaaaaababbaaabbbabaaaaaabaabb",
        "aabaaaaabbbbbbabaabbabbbaabaaaaaabbbbaab",
        "bbaaaaabbbaaababbbbbbbabaababbbabaaaaaba",
        "aabbbaabaaabbaaaabbbabaaabaabbbabababaab",
        "ababbbaaabbbbbaaabaabbbabbbabaaababababbabbabaabbabbbaabbbbaaabb",
        "bbaaaaabaabaaaaaababaaab",
        "aaabaaabaabaaaabaaabaabb",
        "abbaaaaabbbabbaaaaaaabab",
        "aabaaaabbbaaaabbbbbaaaaaabbaabaaabbabaabaaaabaaa",
        "aaabaababbaabbaaababbbbbbaaaabab",
        "bbaaaaabbababaaababbaaab",
        "abaabbbaaaaabbaaababaaabbaabaabb",
        "aababaabbbababaaabbaababbbbaabbaabbbbabb",
        "abbaabbbaabaaabaaabababb",
        "abbaababbabaabbbbbbaaabbbbbbaaab",
        "aababababababaaabbbbbbba",
        "ababbbbaabbaabbbbaaaabbb",
        "baabaaabbbaaabbaaaaabbbabbbaaaabaabbabbb",
        "abaabbbababaabbbbbbbabba",
        "abbbbbababaabaaabbbaabaabbabbabb",
        "bbbbbbabababbbababaabbabbaabbbbbaaabaabb",
        "abbaabababbababbaabbbabaaaabbbbaabbaabbbbbbababbbbaaaaaa",
        "babaaaaaaababbbabaabbaaabbabaaabababaaab",
        "aaaaabbaaabbbbaabaaaaaaabbbaaabaabbaaaba",
        "aabaababbabaaababaabbabb",
        "aababbbbababbabbbbbaaaaabbbababaaabababb",
        "bbabbabaabbbbabaabbbbbba",
        "babaaabbaaaaaabaaababbabaaabbbbb",
        "bbbbabaaaabaaabbaaaababbbbbbabaabbbaaaabababaabb",
        "abaabbabbbbbaaaaaababbbbaababbaa",
        "abbabababbbaaabaaaabbbbb",
        "baaaaaababbaaaaabaabababbabbbbbaaabababb",
        "bbbaaaababbbaaaababbbbab",
        "bababbbbbaabaababbbabaababbbabababbbabab",
        "aababababbbbaabababaaaaa",
        "baaababbbababbbbaabaaabbaaaaaaab",
        "abbabbbaabbbaaaaabbaabababaaabaa",
        "abababaabbaabbbbbbbbbbabaaaabaaa",
        "bbbbabbbaababbbbabbababbabaaaabaaabaabbb",
        "bbaababbaabaaabababbaaabbaabaabbaaaaaaabbaabbbaabbbbbbbb",
        "babbbabbbbabaaaabbbbbaaababbaaaa",
        "aaaababbbaabbbbababbabab",
        "aabbbbbabbbaaaaaabbaababbbabbababaabaababaabbabb",
        "abbbbbaabababaaababbbaba",
        "baabbaaabbabbaaaaaaababa",
        "aabaabbbbabbbbaabbbbabbaaabaaabaabbaaabbaabaabbabbabaaaa",
        "abbbbbaabbabbbbaabbaaaab",
        "baabaabaababaaaaabbabaab",
        "babaabbbaaaaabbababbbbab",
        "aaaababbbbaabaaabbaaaababbbbbaab",
        "babaaaaaabbabbbaaaaabaababbbabab",
        "abababaabbbaaaaaaabbabaaaabbaaabaabbaabb",
        "aabaaabbbbbabbbbbbabbabb",
        "aaaaabbaaaaaaabbabbabababbbbbaaababbbaabbbabaabaabababab",
        "babbbbaabbabaaaaabbaabbbabaabbabbabaabbabaababbb",
        "babaaaaaabbabbbbbabbabab",
        "aaaababbbaabbbbababbabba",
        "bbaabbaabbaaabbbbbbaabbbaabbaaababaababaabaaaaabbaabaabaaababaab",
        "babbaaabbaaaabbbbbaabbabbaabaabbaaaababa",
        "babaaababbaababbabaabbaabbbabaabbbbababa",
        "aaabbbaaaabaabaabaaaaaaabaabaabaaababaaabbbabbbababbbbbbbabababb",
        "aabbabbbaabbbbbbabbaaaabbbabababaaaaabbb",
        "bbbbababbaabbaaabbababaabbbbbbbaaaaaaaba",
        "abaaaabbababbabbaabaaaaaabbaaababababbba",
        "bbbabbbbabbabbbaaaabbbabbbaaabaabaaabaabababaaabaaabaabb",
        "abbaabbbabbabbbabbaaabababbabaaaabbaaabb",
        "aabbbaaaabaaabaaaaaaababbabbabaaabaaaaaaabbaaaba",
        "abbaabbbaabaabbaaabbbabb",
        "abbaabbbbaaabaaababbbaab",
        "abaababaabbbbbaaabbaaaaabbabbbaabaabbaabbbbbbaabbaaaaaba",
        "abababaababaabbbbaaaabbb",
        "bbbaaaaabbaaababababbbbaaaababaa",
        "baaabbaabbbaabbbababbaaababbabaababbabba",
        "bbaabbaabaabababbbbbaabbaaababab",
        "bbaaaabbabaabbabbabaabaabaabbbbbaaabbabbbaabbbbabaaabbbabababbabbbabaabbbabbbaaa",
        "bbabbbaaaabaabbbabbbaababaaababbbababbbabaabbbaaaababaabbabbbbbbabaaaabbbabbbabbababaaba",
        "abaaabbbbababbbbaabbabbabbbbabaaaaaaabbababbbbab",
        "aaabbbabbbbbaabbabaababb",
        "aabbbbbbaabaaaaabbbbbaab",
        "baaababbbbbbaaaabbababaaaaaabbbababababa",
        "ababaaaabbaabbaaababbbbbbbabbabaaabaabbbbaabbabb",
        "bbaaaaababbaabbaaabaaabbbbbbbaab",
        "bbaababbabaaababaaaabbbabaaaabbabababbaaabbaaabb",
        "ababaaaaabbbbbababbbbaaa",
        "abbabbbbbbbaaabaababaabb",
        "bbababaaabbbabbaababbbbaaaabbaaaabbbaabb",
        "abaabbabaabaaaaaaabaababaabbbbbaaaabbaba",
        "aaaabaabbbbabbabbbaaaabbababaaba",
        "bbbbaaaababbbbaabababbaa",
        "bbababaabbababaabbaaaaaa",
        "baaabaaaababbbaaaaaababaaabaaabbbabbbaab",
        "abaabbaaaabaaaabbabbabbbaababbaabbabbabb",
        "aaababbababaaaaaabaaaaba",
        "baabbaaabbaaaabbbaaaaaaaabaaaabbbabbaabbabbaaaab",
        "aaabaabbbabababbababbbaaabaababb",
        "baabbbbaabbbaabbaabaabbb",
        "bbbbbbababbbbbaaaabbbabb",
        "bbbaaababbbaabaaaabababaaabaababbaaaabbaabbbbbbb",
        "baaabbaaaaaaaabbbbaabaaa",
        "abbabbbbaaabaababbaaabba",
        "baabababaabbaaabababaabb",
        "abbabababbbbabaabbaababaabbbabbbabaababa",
        "babaaaaababaaaabaabaabbb",
        "bbbbbaaabbabaaaabbaaaabbbbbaaababbbaababababababbababbaa",
        "baabbaaabbababaaaababaaabbbbbbabaaabbbbaaaaaaabbababaabbbbabbbaa",
        "bbaaabababbaaaaabbbaabab",
        "bbbbbbabaabbabbaabbbbaaa",
        "bbabaaaaaaababbaaababbaa",
        "aaababbaaabaaaaabababbba",
        "abaaaabbabbbabbaabbabbab",
        "bbaaababaaabaabaaababaabbbaabbbb",
        "bbbaabbbabbabaaaabbbaabaaabbbaabababbaabababaabbbbbbbabbbababaab",
        "aaabbbababbbbababaaaabaa",
        "bbabbababbaaabaaaaabbbabaaaababa",
        "abbaaaaaaabababaaabaabbaabbbbaaa",
        "bbabbbbaababbbbbbabaabbababababababbbbbb",
        "abbabaaabababaaababbbaaa",
        "babaaabaaabbbbaabaabbbbb",
        "abbaaaaaabbabbbbbabbabaa",
        "bbabaaaabababaaabaaabbab",
        "baabaabaabbababababaabbabaabbaaaababaabbaaaaaaab",
        "bbbaaaaabbabbbbabbbbbbba",
        "abbbaaaaabababbaabbaabbbaabbababaabbbbab",
        "aaabaaaabbbababbabbaaabbbabbabbbabbbaaba",
        "abaaaaabaaabbbaaaaaaaaab",
        "bbaaabbbbabaabbbbbbbabba",
        "bbaabbbaababbabababaabbbaaabababbbbababb",
        "bbbbaaaaaababaaaabaababa",
        "baabaabaaaabbbabbabaaabbbababbbbabbbaabbbbaababaababbbaabbabbbaa",
        "baaabbbbaabbabbbbbbbabaaabbbaaabbbbbabba",
        "bbaababbbbbaaaabbbbbbbabbababaaaaabababb",
        "baabaaaaabbabbaaaabbaaba",
        "aabaaaaaababbaaaabbaaabb",
        "aaabbbbabbbaaabbaabbaabb",
        "baaaaaaaababaaaababbbbbabbaabbaaaabbbbaabaabaabbaaabaaaaabaababb",
        "bababbbbabaababbaaaaaaaaabbabaabbaabbbbb",
        "babaaaabbbaaababbbabbaaaabbbbbbb",
        "bbababaaabbaaaaababbbbaabbababab",
        "baabaaaaaababbabaaaabbabaaaabbabaaabaabb",
        "baaaaaabbabaabaabbabaaaabaababaabbabaabbbbababaabaabbbbabbbaabba",
        "aabbabbbbaabbaaabbbababa",
        "aabbbbbbaabbbbaabbababaabbababaaaaaaabaaaaababaa",
        "aabbabbbabbabbbbbabbbabbbabbbbabbbabbbab",
        "abbaabaababaabbbababbabbabaaaaabaababbaa",
        "babaabbbabababaabbaabbbaaaabbaaabaaaababbaabbbbb",
        "ababbaaabababbbbabababab",
        "bbbaabaaaaaaaabbbbabbbaa",
        "aabbabbbaabbabaabababaaababaababbbbbbabb",
        "bbbbbbabaabbbbaaaabbaabb",
        "bbbbaabaababbbbbabaabbbaaabaaabaabbbbabb",
        "abababaaababaaaaaaaabbaa",
        "bbaabbbbabaabbabbbbabaabaaababbb",
        "babbbbaababbbabbbbaaaaabbbbababa",
        "bbaaaabbabbabababbbaabaaababbbbbbbaaabbbbabbabbbaabbabab",
        "abaabaaaababbbbaaaaaaaab",
        "abbababbabaaababbaabbabb",
        "aababbbaaabbbbbbbbabbaab",
        "bbbabbbaabaaaababbabbabbbaaaaababbabbbbaaabbabbbabaaaaaabbbabbab",
        "abaaaabaababaabaaaaabaaaaaaabbabbbabbabaaaababbbaaaaabbbbbbaaaababbabaabbaabbaaabbbbabbb",
        "baaababbbaabaabaabbbbbbb",
        "babbbababaaaaaaabbaaabbbbaaaababbabbbabbbabbbbbaaaabbabaabbbaaaaabaabbbbbaabbbab",
        "abbbaabbaababbbbabbbbaab",
        "baabaaaaabbaababbaaaabbb",
        "abababbaabbabbbaaaaabbba",
        "aabababababbbbbaabaababa",
        "babaaabbbbbbababaabaaaaaaaababaa",
        "babbbbaaaabaaabaaaaaaaaa",
        "bbbaaaaaababbabaaaaaaabbabbabbbaabaaabbbbbababbb",
        "abbbbbaabbaabbbbaabaaabaaaabbbabaabbabbaabababaababbbbbbbabaababbbabaaba",
        "aaabbbababbaababbbbbaabaaaababaa",
        "bababaaaabbabaaabaaabaaaaaabaaabababbbaa",
        "abbaabbabbaabbbaaaabbaba",
        "bbbabbabaabaabaabbabaaba",
        "abbbbbaabaabbbbabbbbbaaababbbbaaaaababaa",
        "bbbaaaabbbababaaaababbaaaabaabaaaabaabbaaababbaa",
        "baaaaaabaabbabbbbabbaaab",
        "aaaababbbbababaaabaababb",
        "aabaaabbaababbbaaaaaaaaa",
        "bbabbaaaaaaabbbbbbabaaab",
        "abaaababaaabbaaabaabaababbababaaaaabaababaabbbaababbbbab",
        "ababaabaaababaabbbabbabaababbbbbabbbabaaaaaaaabbbabbbbaa",
        "abaaababaabaaaabbaaaaaba",
        "ababaaaabbabbbbabababbbabaaabaab",
        "aabaaabbababbbbababbbaba",
        "baaaaaabababbabaabaaaaba",
        "baababbaababbabbabbbaaaabbbbbaaabaabaabb",
        "ababbbbbbaaabbbbbbbaabab",
        "bbabbaaabbabbaaaaaabaabb",
        "aaabbbaabbbbbaaabaaaabba",
        "abbbaaaaabbabbbaababbbbababaabbbbaaababbabaabaabbaaabbabbaaaababbbbbbaba",
        "bbaaabaaabaaabbbbbaabbbaaabbaaaa",
        "bbabbababbabbabaababbabaaababbbbabbabbaaaabbababaaaaabab",
        "abaaabbabbbbbaaabbabaabb",
        "aabbbababaaaaaaabbaabaaa",
        "bbbabbaaaabaaabbaabbbabb",
        "bbbaabbbabbbabaabbbbbabb",
        "abbbabaabbbaabaaabbbbbaaabbabababababbbabaabbabaaabababbbbbbbbbbbbbbabba",
        "bbbaaabbaabaaabaaaaaabbaaabaabababbaaaabaaabbbbb",
        "aaaaabaaaabbbbbaababbbbbabababbabbbbbaaaabaaabbaaaaabaaabbaaaaba",
        "abbbbababbbbabaabaaaabaa",
        "aabbabbbaaabbaaaababbaaabababbba",
        "aabaaabaabaaabbbbaababaa",
        "aaaabaabaabbbbbbbaaaaaabaaaaaaab",
        "abbaabaaaaaaabaaabbbabbaababbbbaabababbb",
        "baaaababaaaaaaabbaabaaab",
        "abaabbababaabaabaabbbabaaababbaa",
        "aaabbbabbaabbbbabbabbabaaaababaa",
        "aabaababbaaaaaabbbababab",
        "aaaaabaaabaabbabaaaaaaab",
        "aabbbbaabaababbaabbbbbba",
        "ababbabaabababaabbbabbbaababbbaaaaaaaaaaaaababaaaaabbaab",
        "bbbbbbababbaababbbbabbba",
        "bbaaabababbbabbabbbbaabababbaabb",
        "ababbbbabbbaaaaabbaaabbbaabaabaabbaaabaababbabab",
        "bbbaabaaaaabbbbaaaababbabbabbbaa",
        "abbabbaabaabaaaababbbaaa",
        "bbbabbabababbbbaaabaaabbbaababbbbbbbbaba",
        "abbaabbabbbbbaaababbbbaabbabaaaaabbbbbbb",
        "bbabbababbaaabbbabbbababbabbabbbbbaaaabaabbbbaababbabbbaabaaaaba",
        "abaabbbaaaaaabbbababaaaaababbbbbababbbba",
        "abbbaabbabbbaabbaabbbabb",
        "aabababaabbbabbabbaababaaabaaaaabaababaabaaabbba",
        "abaaabbbbbbbbaaaabbaabbbababbabbbbaabbaabaaaabaaaabbaaaabababbab",
        "aabbbabaaababaaabaaaabbb",
        "abaaaaabbaabbaaaaabbaabababbaaaa",
        "bbbaaaaababbbbaabaaaaabbabaabbbb",
        "babbbbbaaaabbbbaaaaababbaaabbabbababaaab",
        "bbaaabbbabaabaaaaabaaaabbbabbababbaaabbaaaababbb",
        "aabbbababaaaaaabaaaaaaab",
        "baaaaaabaaabaabaaaaabaabbaaabbab",
        "aabbbbbbaabababaaaaabbaa",
        "ababbbaaabaababbabaaabaa",
        "aabbabbabbbbbbbbabbbabbbababaabbaaababab",
        "aabbaaaaaabbabbabaababbaababaaaabbbabaaaaabbbbbbbabababa",
        "abbbaaaabbbaabbbaababbbaaaabbaaababbaaababaaaaaa",
        "aaaabababbbbabbaaaaaaaaababaaabbaaabaaba",
        "aaabbbaabbaaababbabbbbab",
        "aabababaaabbaaabbbbaaaababbaabbbaaabaaababaababa",
        "aabbabaaaaababbabbabbbbb",
        "bbbabbaabaaababababbabaa",
        "babbbbbabbaaabbbaababaaaaaaaaabaabbaaaba",
        "bbbaaabaababbabababaaaabbbbbbabbbbbbbabbaabbabaaababbbabababaaababbbbbabbbababbb",
        "abaabbaabaaabbbbabbbaaab",
        "aabaabbbabbbbbbaabbbbbbaaaababbbbabbbbbb",
        "bbbbaaabaabbbabbbaaaaaaababaaababbbabaaabbaabbbaaabababbabbbbabb",
        "aaaabaabbbaababbaaababab",
        "baaaaabbabaabbbbabbaaabababbabbbbaabaabbababaaabaaaaababaaaaabaabbbabbbbbbaaaaababaaabab",
        "babaaaabbaaababaaaababaa",
        "aaaaabbaabbaababaabbbbaaabaabaabaabbaaba",
        "aabbaaabaabaababbaababbaabbbaaabbabaabab",
        "ababaaaabababbbbaaababbaaabaabaa",
        "babaabbabaaabaaaabbbbaaa",
        "ababbbbabaaaaaabbbbaaaabbaaaababbbaaaaba",
        "bbaaababbaaabaaabaabbbab",
        "babaaaaabaaaaabbbaaaaaabbaabbbabbabababa",
        "baaabbbbabbabbbaabaaaaaa",
        "abbaabbaaababbbabaabbbab",
        "aaabbaaaabbbbabaaabaaaaabaabbaab",
        "baaaaabbababbbbabbaaaaabbbbbbaab",
        "bbaabbbbbbaababaaabbbaab",
        "aabaaabbbbaababbabbaababbbaaaaaa",
        "abaaaabaabbbbabbbaaaaabbbababbabbbaaaababbbbbbbb",
        "abaabbbabbaabbaabaabaababaabbaaaabbbbbba",
        "bbbabbbbbaabbaaababbbabbaabbaaba",
        "bababbbbabbbabbaabbaabaabbbabbabaaabababaaaabbba",
        "baabbaaaabbaabaaaabababaaabbbbbaabaabbabbabaabaaabbabbabbaaaaaba",
        "bbbbaabaabaabbabbbbaabaabbaaaaabaaabaaababababbabaaaabab",
        "abbaabaabbbaaababbabbbab",
        "aabaababbbababaabbbbbbabbaaaabaaabaabbbb",
        "abaabbbababaaabaabaaabababaaaaabbbababba",
        "baaaaabbbbbabbaaababaaaaabaabbabbbabbbaaaaabbababaabaaabbaaaaaaa",
        "aababbbbaabaabaabababaaaabababaaaababbbababbaabbbbbabaaabbababba",
        "bbaababbaaabbbabaaaabaababaaaabbbaaaabbb",
        "abbabaaaaaabbaaaabaabaab",
        "bbbbaabbbbbabaabbabaabbaaabbbbaababbbbaaaaaabaaaaaaaaaab",
        "bbbbaaaaababbaaaaaababbaaabaaaaabaabbaba",
        "bbbbabbbbbaabbaaabababbb",
        "aabaabaababbbabbbbbbaaab",
        "aaaabbbbbbbbbaaabaababbb",
        "bbbabbabbbbaaaabaaaababa",
        "ababbbabbbbbaaaaabbbbbba"
};

std::vector<std::string> split(std::string s, std::string delimiter) {
    auto scopy = s;
    std::vector<std::string> result;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    result.push_back(s);
//    std::cout << scopy << " = ";
//    for (auto &r : result) {
//        std::cout  << r << " ";
//    }
//    std::cout << std::endl;
    return result;
}

using ruleset_t = std::vector<std::vector<std::uint64_t>>;
using rule_t = std::variant<ruleset_t, char>;
static std::map<uint64_t, rule_t> rules;

// this implementation has an issue: it terminates after finding a first matching alternative
// surprisingly it works for part1; for part2 to see match_many()
uint64_t match(std::string str, std::string* acc, uint64_t rule_nr) {
    auto &rule = rules[rule_nr];
    if (auto *maybe_char = std::get_if<char>(&rule)) {
        *acc = *acc + *maybe_char;
//        std::cout << str.substr(0, acc->size() ) << "=="<< *acc << " " << (str.substr(0, acc->size() ) == *acc) << std::endl;
        if (str.substr(0, acc->size() ) == *acc) {
//        if (str  == *acc) {
            return acc->size();
        } else {
            return 0;
        }
    }

    auto &ruleset = *std::get_if<ruleset_t>(&rule);
    int sub_rule_nr = 0;
    for (auto& rules : ruleset) {
//        std::cout << "EVAL " << rule_nr << "." << sub_rule_nr << std::endl;
        ++sub_rule_nr;
        std::string *new_acc = new std::string(*acc);
        bool rule_matches = true;
        for (size_t i = 0; i < rules.size(); i++) {
            rule_matches &= (match(str, new_acc, rules[i]) != 0);
            if (!rule_matches) {
                break;
            }
        }
        if (rule_matches) {
            *acc = *new_acc;
            return new_acc->size();
        }
    }
    return 0;
}

bool match_many(std::string str, std::vector<std::string>* accs, uint64_t rule_nr) {
    auto &rule = rules[rule_nr];
    if (auto *maybe_char = std::get_if<char>(&rule)) {
        std::vector<std::string> result;

        if (!accs->empty()) {
            for (auto &acc: *accs) {
                std::string temp_acc = acc + *maybe_char;
                std::cout << str.substr(0, temp_acc.size()) << "==" << temp_acc << " "
                          << (str.substr(0, temp_acc.size()) == temp_acc) << std::endl;
                if (str.substr(0, temp_acc.size()) == temp_acc) {
                    result.push_back(std::move(temp_acc));
                }
            }
        } else {
            std::string temp_acc = std::string{} + *maybe_char;
            std::cout << str.substr(0, temp_acc.size()) << "==" << temp_acc << " "
                      << (str.substr(0, temp_acc.size()) == temp_acc) << std::endl;
            if (str.substr(0, temp_acc.size()) == temp_acc) {
                result.push_back(std::move(temp_acc));
            }
        }
        *accs = result;
        return !accs->empty();
    }

    auto &ruleset = *std::get_if<ruleset_t>(&rule);
    int sub_rule_nr = 0;

    std::vector<std::string> ruleset_result;

    for (auto& rules : ruleset) {
//        std::cout << "EVAL " << rule_nr << "." << sub_rule_nr << std::endl;
        ++sub_rule_nr;
        std::vector<std::string> *new_accs = new std::vector<std::string>(*accs);
        bool rule_matches = true;

        for (size_t i = 0; i < rules.size(); i++) {
            auto subrule_matches = match_many(str, new_accs, rules[i]);
            rule_matches &= subrule_matches;
            if (!rule_matches) {
                break;
            }
        }
        if (rule_matches) {
            ruleset_result.insert(ruleset_result.end(), new_accs->begin(), new_accs->end());
        }
    }
    *accs = ruleset_result;
    return !ruleset_result.empty();
}


int _19() {
    std::regex r {"(\\d+)\\: (.+)"};

    for (auto line : input2) {
        std::smatch sm;
        while (std::regex_search(line, sm, r)) {
            auto nr = stoll(sm[1].str(), nullptr, 10);
            auto rulesets_raw = split(sm[2].str(), " | ");

            if (rulesets_raw.size() == 1 && rulesets_raw[0].size() == 1 && isalpha(rulesets_raw[0][0])) {
                rules[nr] = {rulesets_raw[0][0]};
            } else {
                ruleset_t ruleset;
                for (auto &ruleset_raw : rulesets_raw) {
                    auto rules = split(ruleset_raw, " ");
                    std::vector<std::uint64_t> rule_option;
                    for (auto &rule : rules) {
                        rule_option.push_back(stoll(rule, nullptr, 10));
                    }
                    ruleset.emplace_back(std::move(rule_option));
                }
                rules[nr] = std::move(ruleset);
            }

            line = sm.suffix();
        }
    }

    for (auto& [key, value] : rules) {
        std::cout << key << ": ";
        if (auto *maybe_char = std::get_if<char>(&value)) {
            std::cout << *maybe_char << std::endl;
        } else {
            auto &ruleset = *std::get_if<ruleset_t>(&value);
            for (auto& rules : ruleset) {
                for (auto rule : rules) {
                    std::cout << rule << " ";
                }
                std::cout << " | ";
            }
            std::cout << std::endl;
        }
    }

//    std::cout << match("abbbab", new std::string(), 0) << std::endl;
//    std::cout << match("bababa", new std::string(), 0) << std::endl;
//    std::cout << match("abbbab", new std::string(), 0) << std::endl;
//    std::cout << match("aaabbb", new std::string(), 0) << std::endl;
//    std::cout << match("aaaabbb", new std::string(), 0) << std::endl;
//
//
//    std::cout << match("aaab", new std::string(), 1) << std::endl;
//    std::cout << match("aa", new std::string(), 2) << std::endl;
//    std::cout << match("ab", new std::string(), 3) << std::endl;
//    std::cout << match("a",  new std::string(), 4) << std::endl;
//    std::cout << match("b",  new std::string(), 5) << std::endl;

    std::cout << "-----" << std::endl;

    std::vector<std::string> example_input4 = {
            "bbabbbbaabaabba",
            "babbbbaabbbbbabbbbbbaabaaabaaa",
            "aaabbbbbbaaaabaababaabababbabaaabbababababaaa",
            "bbbbbbbaaaabbbbaaabbabaaa",
            "bbbababbbbaaaaaaaabbababaaababaabab",
            "ababaaaaaabaaab",
            "ababaaaaabbbaba",
            "baabbaaaabbaaaababbaababb",
            "abbbbabbbbaaaababbbbbbaaaababb",
            "aaaaabbaabaaaaababaa",
            "aaaabbaabbaaaaaaabbbabbbaaabbaabaaa",
            "aabbbbbaabbbaaaaaabbbbbababaaaaabbaaabba"
    };



    uint64_t sum = 0;
    for (auto& line: input3) {
        if (auto m = match(line, new std::string(), 0); m == line.size()) {
            std::cout << line << " + " << std::endl;
            sum++;
        } else {
            std::cout << line << " - (" << m << ")" << std::endl;
        }
    }

    std::cout << sum << std::endl;


    sum = 0;
    for (auto& line: input3) {
        std::vector<std::string> outputs;
        if (auto m = match_many(line, &outputs, 0) ) {
            if (std::find(outputs.begin(), outputs.end(), line) != outputs.end()) {
                std::cout << line << " + " << std::endl;
                sum++;
            } else {
                std::cout << line << " o" << std::endl;
            }
        } else {
            std::cout << line << " -" << std::endl;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
