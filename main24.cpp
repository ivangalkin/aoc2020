#include <iostream>
#include <string_view>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>

#include <regex>


using namespace std::string_view_literals;

static std::string input[] = {
        "sesenwnenenewseeswwswswwnenewsewsw",
        "neeenesenwnwwswnenewnwwsewnenwseswesw",
        "seswneswswsenwwnwse",
        "nwnwneseeswswnenewneswwnewseswneseene",
        "swweswneswnenwsewnwneneseenw",
        "eesenwseswswnenwswnwnwsewwnwsene",
        "sewnenenenesenwsewnenwwwse",
        "wenwwweseeeweswwwnwwe",
        "wsweesenenewnwwnwsenewsenwwsesesenwne",
        "neeswseenwwswnwswswnw",
        "nenwswwsewswnenenewsenwsenwnesesenew",
        "enewnwewneswsewnwswenweswnenwsenwsw",
        "sweneswneswneneenwnewenewwneswswnese",
        "swwesenesewenwneswnwwneseswwne",
        "enesenwswwswneneswsenwnewswseenwsese",
        "wnwnesenesenenwwnenwsewesewsesesew",
        "nenewswnwewswnenesenwnesewesw",
        "eneswnwswnwsenenwnwnwwseeswneewsenese",
        "neswnwewnwnwseenwseesewsenwsweewe",
        "wseweeenwnesenwwwswnew",

//        "nwwswee"
};

static std::string input2[]= {
        "seseseseseswsesesenwseseseswenweeese",
        "nwneneseswneneweeneneeeeneeneene",
        "swswseswswswswswseseeswswswswseswsesww",
        "nwsenwnenenwnwnwewnwnwnwnwnwnwwnwnwnw",
        "sesewseesesenwnewewwnewseeseseswsene",
        "eneneneeewswnenewsenenwnwnenewnene",
        "neneneswseseeeswsw",
        "newneeeeneeeeeeeene",
        "wnwwwswwwnwewnwwsewenwwwwnww",
        "swewswswseseseswseewseseseneswnewwsesw",
        "nwswnwsenwnenwwnwnwnwwnwwnwnwnwwnwnwnw",
        "swwwwwnewwwwswswwwwwwseswsww",
        "wwwewwwwswwwwwwwwwswsw",
        "wnwnwnwnwnwnewwnwwnwnwnwsewswwnwww",
        "sweswnwwwnwwnwnwnwseenwnwnwnwnenwnwnw",
        "nenwwwsewnenwwwwwwnwwnwwswnwnww",
        "eeneeesweeesenwneneeeenweeeene",
        "enwwswnwwnwnweswnwnwseswnwnwnwsewnenenw",
        "nwnwnwnwnwswnwnwnwnwnwnwnwnwnesenwnwnwnenw",
        "nwswwsewswwwwww",
        "sesweseeneeswnweeseweseswsesenwnw",
        "sewswwnwneeswswnewswswswwwwnwswwse",
        "enwnwswnwnenwnenwswneneneneneswnwsewnenwnw",
        "nwnenwnwsenwnwnwnwnwwwnwnwnwnwnwnwnwnw",
        "seesesesesesewsesesesesesesesesesesesene",
        "swneneseswsewswwsenesesewswwnewswseswne",
        "swnwswsenesewneswswnwswsewewswseswnene",
        "wwswwseseswwnwnww",
        "esewnwseseswnweseesenwswseesesesee",
        "seeneneneseenenwsweeeeeeeewe",
        "seseswseswsewseseswsweseswseseswswsese",
        "swneeneeneseneweesewne",
        "nenenenenenenenenenenwnenwsenenenenenene",
        "neneneswneneneneneneswnenenenwenwnenene",
        "wewwewwwnwswswnwewwwwwwwsw",
        "seseseenwsweeeesenweneeeseewse",
        "neneneneenenenenwnenenenewnewnwnwnesenw",
        "nwnwnwwewwseswnesewnwswwseswenene",
        "wwswswswswswwswswsweswswsw",
        "nwnewnwwsenwnwnwnwwnwwnwsenwwwnwwsenw",
        "swweeenwseeseseeenwweseeseseeese",
        "nwnwnwnenwnwnenwwnwnwnwnwnwnwnwnwnwnwe",
        "nwnwnwnwnenwnenenenwenwnwnwnwswnwswnwnw",
        "wwwswwewwwwwwwwwnwwwwwsw",
        "neneneneneeneeneenenenesw",
        "nwswneeneeneseweneeweneneswnwswneswse",
        "seeswwenwneeneeeneeswneeswsenwe",
        "weewwwwwswwwnewwwwnwwwsww",
        "wneseewneweswneneneneneneeswnenesene",
        "swnwenwenwseswneswewnwwnwwsenwnwe",
        "wsewnenenenenenenenenenwnesesenenenene",
        "nenwneneneeneneneswnenenewneenenenenene",
        "eswswswwswnwwswswsweswnwswswswwswe",
        "seeseseseseeeswsewnwneseseesesesese",
        "eseenwseseesweeeeseeweeeesee",
        "eenewneeneneeneeneeswneneneswsene",
        "nwnwsenwnenwnwnwnwnwnwswnwnwnenwnwnwnwnwne",
        "wnwwnweeseswnwnwsweesenewnwnwnwnw",
        "nesweneenenwnwneneswneneseewene",
        "nenenenenenenenenenenwsenenenwneneneeswnenw",
        "swswsweswseswswseswseswswswnwnwsenwswsee",
        "wwnewwwwwsewwewsewnwswwnwnew",
        "swswswseswswswswswseswswsewsweswseswsw",
        "eeneenesweeeeeeeeeneenweee",
        "nwwwwwwnewnwwwwswwww",
        "nenwnwneeneswnwnwnwswnenenwnewswnwswnw",
        "eseseenwsesesesesewsesesesesesesesesese",
        "wwnwwnwwnwenwwnwnwnwnwnwnwsenwswnw",
        "sesewseseeeneewesenwseeseenesee",
        "seeesewsesewwneeeeeseeeeenenw",
        "wswswswswswswwswwwswewwwswwwsw",
        "eswwswswwwwswswseswwwnewwwwwwsw",
        "weseswseeswneseswwsewswseeewnenwsw",
        "nwnwnwnwnwnwenenwnwenwnenwnwenwnwwswsw",
        "senwnenweesesewwesweeeseneneew",
        "nwwnenenenwneeneneneswneneswwsewseene",
        "wswwwewswwewsw",
        "eswneeeeeeeeswneeneeeneenwe",
        "nwseeswnwsesweseseseseseeneswneseseese",
        "eeseesenweeee",
        "senwnwsenwnenwnwnewnenwnwsenenwnwnwswnw",
        "neenwsesewnwnewnwnenesenenwnewseswnene",
        "eweeenwesweeeeeeeseeswneee",
        "eeeswnweeeeneeeeeweeeeee",
        "nwnwnenenenwneneswnwnwnenenenwnenwnesenw",
        "eeweeeeeseseeeeeeeeeee",
        "wswswwsenwwnwneewesewswwnewnew",
        "nenesenesenwnenenwswwnwnenenenenenenee",
        "nenenwenwnwnwnwswnenwneneswnwne",
        "wwswswswwswwwneswwnewww",
        "enwnenwnwwnwnwnweswnwnwnwnwnwswnwnwnene",
        "seseswswswseseswseseseswsesenwseswseswe",
        "newnenwseneeeneneswnenenenenenenwseenee",
        "eeswseeswsesenweeenwsewsee",
        "wnwnwenwnwwnwnwnwwnwnwwnwnwnwwnwnw",
        "nwnwnwnwnenwnwnwnwnwnwewnwnwsenw",
        "swswnwsweswswswswswswswswswseswswswsw",
        "swswwswswswwswswswswswwswwswswweesw",
        "swswswesweswnwswwsenwseswswewnwswswswne",
        "wwwnwwwwewwwwwwwwwwew",
        "wwnwwwwwnwwwwwnwwnwsewnenwnw",
        "nwnwnenwnwnwenwnwswesenwnwswseneneww",
        "newseseesewseweenesesweneewswe",
        "wenwwewswnwwnwnwwwnwenenwsw",
        "neeeeneneneeeenwneswswneswneenesw",
        "seeseseseseswseseeseneseseswnwnwsesewese",
        "eeeeweneeenweenenweeesesesesw",
        "eswnenwneeneenesenenwneseneenwswnenenew",
        "nenwnwwnwnwnwnwenwnwnwnwswnwneneneenw",
        "nwnwnwnwnwnenwnwneenenwnwnwwnenwnenenw",
        "eeeseeeeeeeseweeeewsee",
        "wnwwnwwnwwwwwwnwsenenwnwwwnwww",
        "eseseneesesewnwesweneneswsenweewsw",
        "nwnwnwenwnwwnwnwnwswnweenwnwnwnwnwnww",
        "nenenenwswnenwnenenenwneenenenesenenenene",
        "neeswnwnenenenenenenwneneneneneneeneswne",
        "swseenenwneeneeeeseneenwnenenenee",
        "neswnwnenenenenwnwnwseewnwnenwnwnenene",
        "senwseswsweseseseseswsesenwnwseseneseenw",
        "eneeneneeneswswewneneeswneenwnenw",
        "neenwwneswswsesenesewwsesesesenwwe",
        "seseneseewseseeesewseseseswnwsesene",
        "sesenesesesesesewswseeeseseseeesese",
        "wnenenwnenesenenenenenwneneewnenwsesenw",
        "sesesesesesesenwseseneseseseseseswseswsese",
        "sweswneswswswswswswswswswswswswwswwswsw",
        "nwsweswnwnweseneswsesenewnenwswneenew",
        "neeneneenesweeseenenenewneesweeene",
        "neneeenewwseewneseeeseneenwee",
        "seseseseseeeeeeeseweeseseese",
        "enwswneeeneeseneeneeweeeeenesew",
        "eswswswswswswwnwseseswseeswnwseswswsw",
        "nwewswswwswswswnesewseswswnesweswsee",
        "nwnwenwnwwsenwnwnwnenwnenenwnenwnwnwnwsw",
        "eneneneneneneenenewneneneeneneneene",
        "nwnwnenwnenenwnenwsenwnwnwnwnenenewnwswnenw",
        "wwwnwwswnenewswwseswwwnenewsew",
        "ewwswneenenenwswwnwewenenenewese",
        "nwenwnwnwneseseswnwnwnwswswwneswnwnenwne",
        "nenwenwsenwnwneswnwswnenenwnewnwnwenwnw",
        "wnwnwenwnwwnwnweneswnwnwnwswnwnwnwnwnw",
        "eneeswneenewneenenenewsenwnenee",
        "enwnwnwnwnwnesenwnewnwne",
        "nwwnwwnwnweenwsenenwwwsenwwwswne",
        "wwwnwsweewneswweeswweswsewnw",
        "swseeswwneswseswwswseneswnwswswswwswswsw",
        "enewenweswsesesesewswneeenwwwse",
        "senwnenwnwnwnwnwnwnwnwnwnwnwnwnwnwwnwnw",
        "wsewnenesenwenwswnwnenwswnwnwnwwenwe",
        "wnwwnewwnewwnwnwsewnwnwsweswww",
        "seswswseseseeswnwnwsenweeswnwseswsesese",
        "nwnwwnwneseweenenwnwnenwswneeswseswne",
        "swnwnwswswswswswswswseswseeseseswswsese",
        "nenwnenenwsenenenewnwnwnwnwnenenesenenw",
        "swnwwwwesewweewnwwesenwnwnwnw",
        "swwswseneswwneswsenenenwswneseswswsenenesw",
        "nenenenenenwenesenenenenewnenwnwnenenwne",
        "swnwwswwwswswwswwswwwwseeswsww",
        "eseseseeseseseweseseseseseweee",
        "swsweswswswseswweswnenwswenwwswswne",
        "nwnwnwnwnwnwnesenwnwnwnenenwnenenwnwnene",
        "neswwwwwnewwewseweswwwswww",
        "seseswseneseeseswnwseswseswseswseseswse",
        "sweeeeeweseeeeenwenw",
        "swnwnweewwnwsenwsenwwnewswnenwnwsw",
        "eweeeneenwwseneneswnesewnwseesenwne",
        "swswswswnewwwswswsewwwnwwswweswsw",
        "nwnesenenwewsenwwneseseneswnenenesenw",
        "ewnwenenwseseeneweeesewsw",
        "eeeenwenenweeenweseeneseeseee",
        "esenwseesesesesesweee",
        "sesesenwseswnwswsenwseseenesewsewnwnw",
        "wnwwwwwwnwswwwwewwwwwwww",
        "nwnwsenwnwnwnewnwnwnwnwnwnwwenwnwnwnw",
        "wsewwswwneswwswswwnewswswwwnese",
        "nwnwnwnenenenwnwnwenwwnenwnwnwnwnenenw",
        "nwnwnwnwewnwwnwnwwnwnwwnwnwnwenwnw",
        "wswwswswsewnwswwswsewwwswwswnew",
        "eeewseeeeseneeweeeeeeee",
        "nenenenenenenenenenenenenenenenenenenesw",
        "nwnwnwnwenwnwnwnwneswnwnwnwseenwswwnw",
        "senenwswnenenenwnenewnesene",
        "seswseseeneseneseseeseseseeseseswese",
        "nenwswnwnwsenenwsenwnwsenwnwneswnwwnwenwnw",
        "eeweseneseseseseseeeseeese",
        "swewnwwswwswswwwwwwnwwsewww",
        "swneneneneneeswwnewswseneswneneenenenene",
        "eenwneeneneeseswseneenwnenenenene",
        "sewswsweswseswseenwsenenesese",
        "seswseseswseseseseseseswseseseswseseenw",
        "sweeeeeeeneeseeeseseeee",
        "seweneeswnwneeeeneneenewnesenwne",
        "swwswewwnwnwwnwwewwwwwwnwnwwnw",
        "neneneneneneneswneneneneneneneeneneswnene",
        "wwwnweesenwnewnwswnwnwnwwnwnwnwww",
        "wswnwnwnenwweswewwswswwsewswwsw",
        "sewseseseeeeneseeeeeeeeesee",
        "senenewneseenwneneneneeswnenenwnewnene",
        "neneneeeseneenwneneenwneseneswneeeww",
        "swswswswswswswswswwswswswswsweswswsesw",
        "neswwwswwswwwwewswswewsewswwnw",
        "neneneesweeneneneneneewnenenwnenenene",
        "eswswnenenewneseneneeswnewneesenenene",
        "nwnwnwnwnwnwnwwnwwwnwnwnwswnwwswenwne",
        "seeseesenwswnwesweseneneeeseeeee",
        "eeeeneneneneeneneewneeeseene",
        "seswwswswswswsweswwnwsweswswswswnenw",
        "wwwwneseswwwnwswsewswwswwwswsww",
        "wswnwswswswsesewwwwwswwswwneww",
        "wseswswewswswswswseswewswseswswesw",
        "swnweswwwwswswswswwswww",
        "wswwswwswwswswwnewwsenwwwwswew",
        "neseneenewswwesweneseese",
        "wwwsenwswsewnwnwesweenwwswwnwww",
        "wswnewswsewnwswwswswnewswswswswswwsew",
        "swwswwneseswswswww",
        "neneswnweseenwswneenenweeeeneenee",
        "eenenenwseewseesewswseeeeseeew",
        "enewnwwnwwnwwseneswwwwswnwwsenwnwne",
        "eweseewseeseneneseeseeseenwwsese",
        "neswwswenwwwwwnesewswneswwswsesw",
        "nwnenwnwnenwnwnwnwnwnwnwnwswenenwnenwnw",
        "swnenwnwnenwnenenwnwnwnwnwnwneewsenwnenwne",
        "nwneenwnwnenwnwnwnenwnenwnwnwnewnw",
        "swswseswswswswswswswnwseswswswneswsenwsesw",
        "nwnwnwnenwnenenwnwnwnwnenwswnenwnwnwnenw",
        "nwwnenwnwnwnenwnwsenwnwnwnenenwnwnenwne",
        "neeseewwswseenenw",
        "swwseswswswneseswswswesesenwswneswsesw",
        "newnwwwnwnwwwnwsenwwnwwwesenwnwnw",
        "eswseseswwswseneswsesesesesesenwsesesese",
        "eeeeeeeeeeenweeeeseeee",
        "eesenesewseseeseeeseseeeeseesese",
        "wnwnwnwnwnwenwswnwwnwnwnwnwwwswnwnwnew",
        "nenenwnwnwwesesenwwswnwnewswswswenw",
        "eeseeenwnwswswewnwsweneeenwsenee",
        "eseenwsesweseweeseeseseeswsesene",
        "sesewseneseswsesesesesesesese",
        "nwnenwnwnwnenwswnwenwnewnwnenenwswneene",
        "wwwwwswwwnwwwwwewwwwwww",
        "eseesewseeeseseseeseesesesenesesee",
        "swswewwewwewsw",
        "swseswnwswseeswseswswswswswswswseseswswse",
        "wnwnwwwewwwwwwwswnwnwsenenwww",
        "swswswswswswswseseneswswswswswswswswsww",
        "wenwwewwwswsweswswsenwwswwneew",
        "nwnwneeneswneneneewneswnwneneswnwswnw",
        "wsewswnwnwnwwenwnwnwnwnwnwnwewnwnesw",
        "swswswswswneseswswswswnenwse",
        "eswnenenwseswseseswseseseswseswneseswnw",
        "enenwnwsenwnwnwwneswnenwnwnwnwnwnwenw",
        "sewsesenesewewseseseseseneweseseewse",
        "sesewseswseseswseseseseseswswswseswsenese",
        "neesenenenwneneenenesewneeneeewnw",
        "senenenesenenewwneneenwneneneeenenene",
        "wwwwwnwwwwwnewsewwwwwww",
        "swseswwswswswnwswneene",
        "sesesesesenenwsewseswnesenwwsenenwsewne",
        "nwwwwwwewwww",
        "neneeneeeeswnenenesenwneeneneenenew",
        "eweeeeeeeseneeeeeeewee",
        "newnwnenwnwwwwwswwswwwnwwnwwwnw",
        "nenwnwenwnenwnenenwnenenwnwsenwnwnenew",
        "wswseenenwnwwneswnenwwnenenenenenee",
        "swswnwsweseseswswswseseswswswseswswseenw",
        "seseswswnwseseswwnwsweseseseseseeseswe",
        "nwnwnwwwnwwnwwwnewwwnwsesewnwwnw",
        "swswseweeswswswsewswswnwwwnwenenwsww",
        "eswswesesesesenweseseseseneneseewsenese",
        "wnwenwwwwnewwwwnwnwwwwsw",
        "seeeenwswwsenwsesenwswneswswwwswe",
        "nenesewwwswswswnwswswnewswsw",
        "neseneseswseeseseewswwsewswsenwswswsw",
        "eeseeeseweeneeeeeeeeesesee",
        "sesweenenenweeseeswesweseeeneww",
        "nwnwnenwnenwwswswnwwwse",
        "nenenwswneneesewenenwesenwnenenesene",
        "eesewnwseeneeeeeneseesewwnwe",
        "swenesesenesenenewwnwnenenenesw",
        "swswswswswswswswnwswswswswswswsweswswswsw",
        "eseneswseseseseseseswswsesenw",
        "swsweswswsesenwswswnewswswswswswswnwswsw",
        "wwwneswwswwwneswwsewwswwwwsw",
        "nwnwnwwnwnwnwwnwnwnwnwnwnwenwnwnwwnw",
        "wswwswwwewswswswneswswwwswwwwsw",
        "nenwnenwneenwnenwnenwnwswwnenenwnwnenwnw",
        "seeseseeseeseseweeewnenesw",
        "senwnwnwnwnwnwnenwnwnwnwnwnwnwwwnwsenw",
        "enenesenenwwesewee",
        "swnwswnwneseenenenwswnwnewnenwwnwneesene",
        "swswswseswswswswswswswswswseswswwseesw",
        "swwswnwwwwwwswwewe",
        "wswenewnesesenwswseswseeneneenenwnenwe",
        "wwnwswswewswewww",
        "seseesesesesewsenwseneseseeseseeeww",
        "swseswswswswswseswswseswseswsenwseswswse",
        "wnwwwwwsenwnwweswnwnwsenwewwsw",
        "nenwnwewswnenenenenwnwswnwnwnenenenenwnw",
        "wnwwnwnwnwenwseswnwswenwwwnwwnww",
        "neenwnwswnwneneneenenenwsewneswnwnenwnw",
        "wwswswwwwwwwswwwwnewswnewww",
        "wsenwswsweswewneenweswsenwneneese",
        "swseswnwseseswseseswseswswswseseswseenwse",
        "seswswseneswsesesweseseswseswneswnwwswsese",
        "nenwenwwnwneswnwenwnwnw",
        "neswewnwnwswneenwsenwswnwnenenwnwenenw",
        "eswswnwnwnenwwnwnwswnwnwwnenwnwnwsenw",
        "nwnwnenenwnwnenwswnwnwnwnwnwnenwnwnw",
        "wwwswwwswwwwweneeeswwwwne",
        "eeeenenwneneneneeneeswneeneweee",
        "nwnwnwnwsenwswnwnwnwnwnenwnwnwnwnwnenwnww",
        "swsesesesesesesesesewesesewseseseseseswne",
        "seseeeseeeweeeeeesesewsesee",
        "seswneseswneswsenwenewwsenwsenweswswene",
        "swswswswswswswswswswswswsweeswnwsesww",
        "swwswswswswneswswwswswswwswwwsw",
        "swnwseswswswswswwswswwswswswswswswswsw",
        "nwnenwnenenwswneneneneswnwneenenwnwnenwnene",
        "nwnwwnwnwwsenenwnwnwnwnwwnwwsenwsenw",
        "seseeesesesesesesesenewseeewsewse",
        "swswswenwneneeeenwneenwnwsenene",
        "seseswsewesesesesewseswsenweenwsese",
        "eweeeeesweeenweeeeseee",
        "eseswseswsenwswseswseswswswsw",
        "ewnwwnewnwwnewnwswswnwsenwwnwwwwe",
        "esesenweseseseseswseseseneseseesesenwse",
        "wsweswswwweswwwswswswwwewwswnw",
        "nwnenwnwnwneenenenwnwwnwnwnwnenwwene",
        "seewsweesenwnwwsee",
        "swneswwwswnwenwewswnenwwswseewswswe",
        "eeeeeeeeeeeeseeenwee",
        "sesweeeeseenwenw",
        "wswswswwswwnewseenwswnewswswswswwsw",
        "seswseswneswnwnenwse",
        "senenwswswsenwswseswsenwneeseseswseswse",
        "nwswswswseswneswswseswseseseeswsenesesw",
        "weweswwwswnwwwseswwwnewwnwwsw",
        "neeneeneswneeeeeeneneeneenweene",
        "nwnesenesenwseesewseseseseswesenwew",
        "sesesesesenwnweswweseeeswseneeese",
        "wnwwwewswwwwswewwswwwwnwwww",
        "wswwwswswewwnwwswswswwwswwswww",
        "eeeeeseseeeeneeweeseeenwee",
        "seeeeseeeseeeeeeesesesenwee",
        "seesesenwwswseseneseseswseseseseseseswsese",
        "newwwwswwswwwswwswweswswswsww",
        "nenwnwswnwnwnwnenwnwnwnenenenenwnwnenenw",
        "wwsewwsenwwnenewwnewsenww",
        "swswswswswswswswseseswneseswswswswseswenwnw",
        "seesenwnenewseseswswswwnwseseesesesese",
        "enweseneeneeseeneeeseeweewwee",
        "eeweeeeeeesesenewnwseseesesese",
        "wswsenesesenesesewseenwswswnenwswnwenenw",
        "eswseswesesenwewswwnewnenweswsese",
        "nenwnwneswnwnwnwnenenwnenenwnwnwnwswnwne",
        "nwnenesenenwwneewnwnwnwwnwnwnwnwsenw",
        "seswseswswseseswswneswswswswswswswswsw",
        "nenwneneenenenwswnenwneswneenwneswnenenene",
        "seswswseseswseseswseseneswswseswswseswse",
        "swswseswnenwswswseswswswswseswseswswswswsw",
        "wswwswswwneswswwsweswswswwswsw",
        "nenenesenenwnesenesenenewnwnenwnwnwswsenw",
        "wneenenwnenesesenewnwswnwenwneswnene",
        "sewenwwwwwwseenwnwnwwwnwswwnwne",
        "ewwneeneneeseeesewneneewnewne",
        "nenenesenesenwwneneswnwnweneswswsenwne",
        "weseeeeseeeneneweseseswsewwnw",
        "nwwwswwswsesewswnwswswswwnweswswe",
        "weswwwewwnwwswwwnwseewwwnw",
        "seswswseswseeseswswnwsewseswswnewswswe",
        "sesenwswesenwswseseseseseswswswswswswswsw",
        "wnwnwesewsesewwswnwnwwewnewwnee",
        "seseeseswwswswseswsw",
        "swwnwenwseneswwneenwnewnwnesewswnesee",
        "nwwnwnwnwsenwnwnewnwnwnw",
        "esesewneseeeeeeesee",
        "senwnesewnwnwnenwwswnwwnenesenwnwsww",
        "seswsewswswesewseseseseseneswswsesesw",
        "neseseswwenewswswswnwswsewsesesenesw",
        "senesenwnwswsesewseseswswseseseseswsee",
        "enenenenewneeeneneneneenenenesenenene",
        "wwwwnwnwnwwnwnwnwewwwnw",
        "wnwenwnwnwnwswnwsenwseswwenweenwnwsw",
        "nwnwnwnwenwnwnwnenewnwnwnenwnwnwnwnwnw",
        "seseseenwswnwswswswswseseswneneseswswwsw",
        "neeenwnenwwwnewnenenwnwnesenenenenw",
        "swsenwwnwseneesweswseneneeeneenwwswse",
        "eeeeeseneneeeneneneneeneweesenwe",
        "ewseeswneewenenweeeweneneeeene",
        "swswswswswseneswwswswseswseseseswseswsee",
        "eeeseseseseseseesenwseeeseseseswsese",
        "nwnenenenenewnenwnenenwneswseenenenenenenw",
        "swsesweseswswsenwswseseswswseseswswnwse",
        "senenenewenenenenenenenewnenenesene",
        "nesewseneswwsweseswneseseseswnesese",
        "nwnwnwnwnwwsenwesenwnwnwnwnwnwnwsenwnwnw",
        "nenwnwwnwnwnwnwnenwnwneenenenenenene",
        "wswwsenwwswswwewnww",
        "wwwnewwswwwwwwsewwwwwswww",
        "wswseseneswewseneswswnwswswsenesenwswe",
        "wnwnwenwwnwnwwswswwwnwnwwsweenwnwnw",
        "wswweswwwswnwswswwwwseewswswwnw",
        "swswwwwnwswsweswwswwswswswswswwsww",
        "neseneneeweneneeneneneneneneneeswnenw",
        "nwswswswswswswswswswsesw",
        "nwnwnenwnwnwswnwnwesenwnwnwnwswnwnwswnenw",
        "neswwswseswseneswswseswswswswswswseswswse",
        "swseswsweswswseseswseseswswswswswswnwsw",
        "swsweswesweneeneswneenwneneneneene",
        "seseseseseswsenwseseseseswsese",
        "swwswwewwnewwneswwswwwnewww",
        "neneeeneneeseenenweeee",
        "enwwwswnwnwnewswswwnwwweeseww",
        "nwneeenenenenesenweseeneeweneswsw",
        "nenenewneneneneneneneeenenenenenenene",
        "seeseseseseneseeeseswenwnweseswnwseee",
        "swneswseswseswsesenewsesenesewenesw",
        "nwnwwwwwnwwewwnwwwwwwsenwnw",
        "swswswwsewswswwswnwwsweswnwswwwww",
        "seswseseswseswneseseenwseswwsw",
        "newnewesewwswsewnw",
        "weseesesewneseseseesenesesesesesewse",
        "eeeeseeeeeneeeenenewe",
        "wswwseswseneswswswswnesweseswnwswswswe",
        "eweeseeeeeeneneeeseeseeseswese",
        "nweenwwnwnwwnwenwnwnwnwwwswwswnwse",
        "wwwnenwnwswwnwwwwwnwnwnwwnwwnenwse",
        "enenenenenewnwnesweseewenenesenee",
        "esewswnwenwwnwnwnwnwnwnwswnwwwwse",
        "eeweneswenenweswnesweneneeneee",
        "wseneeseeesewnwswswnenesewneswee",
        "swneeenenenenenwnenenenenenenenewnesene",
        "nwswswswwswseswswswswnwswswsewwswswsw",
        "neenwnwnwnenwnwnwnwnwnwnenwnww",
        "eeeswenweeeseeeeeseseeeee",
        "swseswswswseseswseswneseseswswswsese",
        "nenwnenenwnwnenenenwswnenwnenwnewnwenene",
        "nwnwseseseswswseswswseswsweswswswseseseswse",
        "swnewwwwswwwwsww",
        "seseseswsweswswswswseswseseswseswswsww",
        "nwnenewnenwnwnenwnwnenenenenenesenenenwnw",
        "nwenwnenwnwsenenesenwnwswnesenwneew",
        "swwswwseswswswswwenenenwsene",
        "swswsweseseseseswseswswseswnwswnwseswsenw",
        "wsesenewnewnwwwnwsewnwsewwwnwww",
        "sewswnenesewswenwsenwswneseeneseswsw",
        "swwnwswnwwnwsenwnwwwnwwenenwwnwew",
        "seseseeseswneeseseswesesesesenwswwne",
        "neneeeesenenwnenweeneswneeweseeene",
        "swwswswswsewwwswwnenweweewsewnwsw",
        "seeswseswseseseswseseseseseseswwswnese",
        "esweseseseseseeseseseeeseseseeseenw",
        "wswwswwswswswnwswswswswew",
        "nwnwnwnwnwnwnwnwnweenwwnwnenwsenwnwswnw",
        "eeenwnenewneeeneeeneeeeswneneee",
        "nwwnwwnesesweswswswwseseneeswsweewsw",
        "neweneneeneneneweneneesenenenenenene",
        "nwwnweswnwnwswewnwewenwewwwnw",
        "seswsesesenwwseswneseseseeseseswse",
        "wnwwwnwwwwnwwwewwwwwwww",
        "enwseseseseswswsesesesesesesesesesesesesw",
        "wnwnwwnwnwewnwwwnwwnwwwswnw",
        "eseswseenwneenewnwnwesewnweswswsw",
        "neseswwswwwswswneeswwnweswseswnwesw",
        "seeseseseeenweseeseseeseeswseeese",
        "nwseeseseweseseseeseseeesewnwsesese",
        "swswswseswnwseseswswnwnwsweswseseswswsesw",
        "wweenwswwnwwwwnwnwnwwnwswnwwne",
        "senwwwnewwwwwwswwnwwnwsewwese",
        "swswswswswswswswwswneswswswswseswswswsw",
        "wswswswswswwswwwsweewwswswswswswsw",
        "neneneneeewseneneneneneeneneneeswne",
        "swswneswnwswswswswseswnwswswswwswesese",
        "swwwwwwswsewwwwwenewwwww",
        "nwswwwnwswnewsenwesenwenwnwnwesene",
        "nenewwwnenwweswswwwseswswswwew",
        "seneseseseswswseseswsesesew",
        "swsenwweswwwnewnwnwenwseswsenwswesene",
        "nwnwnwnwnwnenenwnwnwnwnwnenwnenwnwnwnwse",
        "swswswnwswswseswswsweswsweseswswswsewsw",
        "wwswseseseseswweswseeswseswneswswse",
        "sweseswswsesewseseseswsenwneswnesesesese",
        "nenenwnwnwnesenenwnwnenwnweswnenwnwnene",
        "eseneesesenesewsw",
        "seseseseswswsesesesesesewnwseseswswsenwne",
        "sweenenenweeneenene",
        "swwesweneenweeeeese",
        "wseseswseeseseswseneseswnwswseswwswseswse",
        "nwseseeseseeseeseeeenwewwewe",
        "wswswwseswswwswswswswwwwswnenwwsewsw",
        "seswswnwswseswswswswneswnewsweswnwnwse",
        "seswseseseswseseswsenwswsesesesesesesesw",
        "nwsenenwseenwnenenwneswnwnwnww",
        "nenwwwnwnwwwsewwwnwwnwwnwnwswnwne",
        "eeeenesweenenweeene",
        "eseweswseeesesesesenwwnenwsweeeese",
        "ewwwwwwwsewwwwwwnwnwnwnwww",
        "seswseseswseesesesesesewneswseseswswsw",
        "wwwwwwnwwwwwewwwwswwweww",
        "newnewsewswsewenwnwwswneswewesw",
        "eneswneswsweeenwswnwswnwnwswswswsw",
        "sesenweseeseeeeeeee",
        "swswenwnwnwwenwwswsewneewseeswsesw",
        "wneswwwnewwneswwseswwswswwwnew",
        "swwwswwsewseseneswnwneswwwwnwww",
        "eswnwswnwneenwneneseneseswneneneenenenw",
        "senewnwnwsweneswseeneseeewewswneswe",
        "swnwseseenewnenwnewne",
        "neneneneseeneeneneewneneneee",
        "nwnwnwwnwnwwwwnwnwwnwnwwnwwsenww",
        "swwneeneswswseswwsweneswwsenwswswswsw",
        "neneswnwnenewenwnenenwsenwnenenwnwnw",
        "seeeseseeeseeeesewsesee",
        "wsewswwsewwswnesewwnwwwenenenwnw",
        "esenweseeeseeeeseeeseeesweenw",
        "enweeseseenwsesenweseseswnwse",
        "eewneewwneeneeneneneseneneenene",
        "sesesenwneswwswswneseseseswswswseseswsene",
        "weesenewnwswswswnweswswseswsww",
        "seseseeseswseeseseseseseseswsenenwseese",
        "nwwewswwsenwnwsenwnenwnwnwenenwsenesw",
        "seeeeswenweseeeswneswswenwswnwwne",
        "swswsenwseenwsenwnenesewnwwene",
        "eeeeeenweeeeeneseseeeewsese",
        "nwenwwnwnwnwwnwswwwnwwnwwnwnwwwe",
        "nwsenenesenwneeneswnwwnwneseewsewse",
        "swwsenwnenwnwnwsenewsenwsenenwewnenese",
        "wwwwewwnwwwwwwww",
        "neneneneneeneenwneneeneneneeneswnene",
        "senesesesesesesenesesesesesesesesewsesw",
        "enwwswwnewswenewsewsenew",
        "nenesenwwseneneseneneneswnenenenewwnenenw",
        "eeeeeeeesweeeeeseeeeneenw",
        "nwnwwnewesewswsweewwwswneesene",
        "seseeseseeeseewseseeseseseneseee",
        "swenwnenwnwsesewswswnwnwenwnwnwnwene",
        "weswnwswswseseeeswneeeswenweenene",
        "swseswseswsenwseseseseswswswseswsesesw",
        "eseneeswnwswwneseene",
        "swswnwswswswswnwwwswnesesewswwsesw",
        "eeweewsenweeeeeesenwsee",
        "seneseswswweswswsesewseesw",
        "weeeeseeseseeeeseeeseseseee",
        "nwsenwswnwnwnwnwewnwwnwnwnwnwwnwwew",
        "enwnwswseseeneswseswswnwseswswsese",
        "neswnwnenenwnenwnenenenenwnenenenenenenw",
        "wswswswswnwswswswswswswsweswswswswwwsw",
        "eeeneneeeeeneeesweweeeene",
        "eneswnwneweneesw",
        "wwwesewswswwwswwnwwwwwswwsw",
        "nwnwnwswnenwnwnenwnenenesenwnwnwnwnwnwnw",
        "eeseeweswseeeeeeeseesenesenw",
        "eweeeneneeeneeseeeeneeeneene",
        "neseseseneseesenwsewsenwseseseseswsesesw",
        "swswenwnewnwwwsenwweewsenwweww",
        "neswswswswswswwswswswnwswswswswsweneswswsw"
};

static std::string input3[] = {

};

using Coord = std::pair<int64_t, int64_t>;

std::map<std::string, Coord> diff;

bool get_color(const std::map<Coord, bool>& color, int64_t x, int64_t y) {
    auto it = color.find(std::pair{x, y});
    if (it != color.end()) {
        return it->second;
    }
    return true;
}

// black, white
std::pair<size_t, size_t> get_color_adjacent(const std::map<Coord, bool>& color, int64_t x, int64_t y) {
    static std::string sides[] {
            "e", "se", "sw", "w", "nw", "ne"
    };

    size_t black = 0;
    size_t white = 0;
    for (auto & side: sides) {
        if (get_color(color, x + diff.at(side).first, y + diff.at(side).second)) {
            ++white;
        } else {
            ++black;
        }
    };
    return {black, white};
}

void flip(std::map<Coord, bool>& color, int64_t x, int64_t y) {
    auto it = color.find(std::pair{x, y});
    if (it != color.end()) {
        auto previous_color = it->second;
        it->second = !previous_color;
//        std::cout << "found " << x << ", " << y << " now " << !previous_color << std::endl;
    } else {
//        std::cout << "new " << x << ", " << y << " now " << 0 << std::endl;
        color[std::pair{x,y}] = false;
    }
}

void print(const std::map<Coord, bool>& color) {
    size_t black = 0;
    size_t white = 0;
    for (auto& [key, value] : color) {
        if (value) {
            ++white;
        } else {
            ++black;
        }
    }

    std::cout << "b " << black << " w " << white << std::endl;
}


int _24() {

    std::map<Coord, bool> color;

    int64_t size = 2;
    int64_t half_size = 1;

    diff["e"] = Coord{-2*size, 0};
    diff["se"] = Coord{-2*half_size, -2*half_size};
    diff["sw"] = Coord{2*half_size, -2*half_size};
    diff["w"] = Coord{2*size, 0};
    diff["nw"] = Coord{2*half_size, 2*half_size};
    diff["ne"] = Coord{-2*half_size, 2*half_size};

    std::regex r {"(e|se|sw|w|nw|ne)"};

    for ( auto line : input2) {
        std::smatch sm;
        long double x = 0;
        long double y = 0;
        while (std::regex_search(line, sm, r)) {
            x+= diff.at(sm[1]).first;
            y+= diff.at(sm[1]).second;
            line = sm.suffix();
        }

        flip(color, x, y);
    }


    print(color);

    for (int i = 0; i < 100; i++) {
        auto previous_color = color;

        bool even_row = false;

        for (int64_t y = 1000; y >= -1000; y-=(2*half_size)) {
            int64_t from_x = -1000;
            int64_t to_x = 1000;
            if (even_row) {
                from_x -= size;
                to_x+=size;
            }
            even_row = !even_row;
            for (int64_t x = from_x; x <= to_x; x+=(2*size)) {
                auto own = get_color(previous_color, x, y);
                auto [black, white] = get_color_adjacent(previous_color, x, y);

                if (!own) {
                    if (black == 0 || black > 2) {
                        flip(color, x, y);
                    }
                } else {
                    if (black == 2) {
                        flip(color, x, y);
                    }
                }
            }
        }
        print(color);
    }

    return 0;
}
