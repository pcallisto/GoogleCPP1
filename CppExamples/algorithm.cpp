//algorithm.cpp by Bill Weinman <http://bw.org/>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <numeric>
#include <regex>
#include <vector>
using namespace std;

// functor for count_if
class strhas {
    char needle;
    strhas() {}
public:
    strhas(char c) : needle(c) {}
    bool operator () (string &);
};
bool strhas::operator() (string & haystack) {
    return haystack.find_first_of(needle) != haystack.npos;
}

string uppercase(string & s) {
    string out;
    for (char c : s) out += toupper(c);
    return out;
}

int multiply(int x, int y)
{
    return x*y;
}

std::string magic_function(std::string res, int x)
{
    return res += (x > 5) ? "b" : "s";
}

int mainAlgorithm() {
    vector<string> vs{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
    vector<int> vi{ 5,6,7,8,9,10,11,12,13 };
    vector<string>::iterator vsit;
    vector<int>::iterator viit;
    string s1 = "big light in sky slated to appear in east";

    // count
    cout << "push two extra sevens onto vs" << endl;
    vs.push_back("seven");
    vs.push_back("seven");
    cout << "count vs \"seven\": " << count(vs.begin(), vs.end(), "seven") << endl;
    cout << "pop those extra sevens" << endl;
    vs.pop_back();
    vs.pop_back();

    // find
    cout << "find 7 in vi: ";
    viit = find(vi.begin(), vi.end(), 7);
    if (viit != vi.end()) {
        cout << "found: " << *viit << endl;
    }
    else {
        cout << "not found" << endl;
    }

    // equal
    string p = "radar";
    if (equal(p.begin(), p.begin() + (p.size() / 2), p.rbegin())) {
        cout << p << " is";
    }
    else {
        cout << p << " is not";
    }
    cout << " a palindrome" << endl;

    // search
    string match = "slated";
    cout << "string is \"" << s1 << "\", search term is \"" << match << "\"" << endl;
    cout << "search: ";
    string::iterator search_it = search(s1.begin(), s1.end(), match.begin(), match.end());
    if (search_it != s1.end()) {
        cout << "search term found at position " << size_t(search_it - s1.begin()) << endl;
    }
    else {
        cout << "search term not found" << endl;
    }

    // show vs before count_if
    cout << "vs is: ";
    for (string s : vs) cout << s << " ";
    cout << endl;

    // count_if
    cout << "count_if vs has 's' (functor): ";
    cout << count_if(vs.begin(), vs.end(), strhas('s')) << endl;

    // C++11 count_if with lambda expression
    cout << "count_if vs has 's' (lambda): ";
    cout << count_if(vs.begin(), vs.end(),
        [](string & s) { return s.find_first_of('s') != s.npos; }
    ) << endl;

    // for_each
    cout << "for_each uppercase: ";
    for_each(vs.begin(), vs.end(), [](string & s) { cout << uppercase(s) << " "; });
    cout << endl;

    std::cout << "//----------------- transform---------\n";
    cout << "transform: " << endl;
    vector<int> vi2;
    vector<int> vi3;
    cout << "vi before transformation: ";
    for (int i : vi) cout << i << " ";
    cout << endl;
    vi2.resize(vi.size());	// make space for transformation
    transform(vi.begin(), vi.end(), std::back_inserter(vi3), [](int i) { return ++i; });
    cout << "vi3 after transformation: ";
    for (int i : vi3) cout << i << " ";
    cout << endl;

    transform(vi.begin(), vi.end(), vi2.begin(), [](int i) { return ++i; });
    cout << "vi2 after transformation: ";
    for (int i : vi2) cout << i << " ";
    cout << endl;

    transform(vi.begin(), vi.end(), vi2.begin(), vi2.begin(), [](int i, int j) { return i + j; });
    cout << "vi2 after second transformation: ";
    for (int i : vi2) cout << i << " ";
    cout << endl;

    cout << "vi after all transformations: ";
    for (int i : vi) cout << i << " ";
    cout << endl;

    cout << "string before initial cap transformation: " << s1 << endl;
    char last = 0;
    transform(s1.begin(), s1.end(), s1.begin(), [&last](char c) {
        if (last == ' ' || last == 0) { last = c; return toupper(c); }
        else { last = c; return tolower(c); }
    });
    cout << "string after initial cap transformation: " << s1 << endl;

    std::cout << "//--------------------------all_of()---------\n";

    std::vector<int> v(10, 2);
    std::partial_sum(v.cbegin(), v.cend(), v.begin());
    std::cout << "Among the numbers: ";
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; })) {
        std::cout << "All numbers are even\n";
    }
    if (std::none_of(v.cbegin(), v.cend(), std::bind(std::modulus<int>(),
        std::placeholders::_1, 2))) {
        std::cout << "None of them are odd\n";
    }
    struct DivisibleBy
    {
        const int d;
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };

    if (std::any_of(v.cbegin(), v.cend(), DivisibleBy(7))) {
        std::cout << "At least one number is divisible by 7\n";
    }

    int data[] = { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
    std::vector<int> v3(data, data + 10);

    int target1 = 3;
    int target2 = 5;
    int num_items1 = std::count(v3.begin(), v3.end(), target1);
    int num_items2 = std::count(v3.begin(), v3.end(), target2);

    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';

    std::cout << "//-----------------------copy_backward()---------\n";

    std::vector<int> from_vector;
    for (int i = 0; i < 10; i++) {
        from_vector.push_back(i);
    }

    std::vector<int> to_vector(15);

    std::copy_backward(from_vector.begin(), from_vector.end(), to_vector.end());

    std::cout << "to_vector contains: ";
    for (unsigned int i = 0; i < to_vector.size(); i++) {
        std::cout << to_vector[i] << " ";
    }
    std::cout << "\n";

    std::cout << "//----------------------------generate()---------\n";
    std::vector<int> v4(5);
    std::generate(v4.begin(), v4.end(), std::rand); // Using the C function rand()

    std::cout << "v: ";
    for (auto iv : v4) {
        std::cout << iv << " ";
    }
    std::cout << "\n";

    // Initialize with default values 0,1,2,3,4 from a lambda function
    int n(0);
    std::generate(v4.begin(), v4.end(), [&] { return n++; });

    std::cout << "v: ";
    for (auto iv : v4) {
        std::cout << iv << " ";
    }
    std::cout << "\n";

    std::cout << "//---------------------------transform()---------\n";
    std::string s("hello");
    std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
    std::cout << s;

    std::cout << "//-----------------------------iota()---------\n";
    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);
    std::vector<std::list<int>::iterator> v5(l.size());
    std::iota(v5.begin(), v5.end(), l.begin());
    std::random_shuffle(v5.begin(), v5.end());
    std::cout << "Contents of the list: ";
    for (auto n : l) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    std::cout << "Contents of the list, shuffled: ";

    for (auto i : v5) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';

    std::cout << "//-----------------accumulate()---------------\n";
    std::vector<int> v6{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int sum = std::accumulate(v6.begin(), v6.end(), 0);
    int product = std::accumulate(v6.begin(), v6.end(), 1, multiply);
    std::string magic = std::accumulate(v6.begin(), v6.end(), std::string(),
        magic_function);

    std::cout << "Sum: " << sum << '\n'
        << "Product: " << product << '\n'
        << "Magic: " << magic << '\n';

    std::cout << "//-----------------regex()---------------\n";

    std::string s2 = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";

    std::regex self_regex("REGULAR EXPRESSIONS",
        std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s2, self_regex)) {
        std::cout << "Text contains the phrase 'regular expressions'\n";
    }

    std::regex word_regex("(\\S+)");
    auto words_begin =
        std::sregex_iterator(s2.begin(), s2.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
        << std::distance(words_begin, words_end)
        << " words\n";

    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
        }
    }

    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s2, long_word_regex, "[$&]");
    std::cout << new_s << '\n';

    return 0;
}