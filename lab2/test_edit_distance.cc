/* A sketch of unit tests for an edit_distance function.
 *
 * The function is assumed to be
 *    int edit_distance(const std::string&, const std::string&);
 * and it is assumed to be declared in edit_distance.h
 */
#include "edit_distance.h"
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

bool do_test(const std::string& x, const std::string& y, int expected)
{
    auto actual = edit_distance(x, y);
    if (actual != expected) {
        std::cout << "*** WRONG: distance(" << x << ", " << y << ") was "
                  << actual << ", expected " << expected << '\n';
        return true;
    }
    return false;
}

int edit_distance(const std::string& s1, const std::string& s2){
	const std::size_t len1 = s1.size(), len2 = s2.size();
		std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

			d[0][0] = 0;
			for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
			for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;
				
			for(unsigned int i = 1; i <= len1; ++i)			
				for(unsigned int j = 1; j <= len2; ++j)
	d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];			

}

int main()
{
    int res = do_test("foobar", "foobar", 0);
    res += do_test("x", "x", 0);
    res += do_test("baz", "bar", 1);
    res += do_test("separate", "seperate", 1);
    res += do_test("separate", "seprate", 1);
    res += do_test("separate", "sepeate", 2);
    res += do_test("separate", "desperate", 3);
    res += do_test("separate", "federate", 3);
    res += do_test("separate", "generate", 3);
    res += do_test("color", "colour", 1);
    res += do_test("color", "colr", 1);
    res += do_test("volor", "colour", 2);

    if (!res)
        std::cout << "\nPassed\n";
    else
        std::cout << "\nFailed " << res << " tests\n";
}



