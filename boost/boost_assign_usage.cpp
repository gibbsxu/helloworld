#include <iostream>

#include <boost/assign/list_of.hpp>
#include <list>
#include <map>
void assign_list_of_usage()
{
    using namespace boost::assign;
    std::list<int> primes = list_of(2)(3)(5)(7)(11);
    assert(primes.size() == 5);
    assert(primes.front() == 2);
    assert(primes.back() == 11);

    std::map<char, char> brackets = map_list_of('{', '}')('[', ']')('(', ')');
    assert(brackets.size() == 3);
    assert(brackets['{'] == '}');
    assert(brackets['['] == ']');
    assert(brackets['('] == ')');
}

#include <boost/assign/std/vector.hpp>
void assign_std_vector_usage()
{
    using namespace boost::assign;
    std::vector<int> values;
    values += 0, 1, 2, 3, 4, 5, 6, 7, 8, 9;

    assert(values.size() == 10);
    assert(values[0] == 0);
    assert(values[9] == 9);
}

#include <boost/assign/list_inserter.hpp>
#include <map>
void assign_list_inserter_usage()
{
    using namespace boost::assign;
    std::map<std::string, int> months;
    insert(months)
        ("January",   31)("February", 28)("March",     31)("April",    30)
        ("May",       31)("June",     30)("July",      31)("August",   31)
        ("September", 30)("October",  31)("November",  30)("December", 31);
    assert(months.size() == 12);
    assert(months["January"] == 31);
    assert(months["December"] == 31);
}

int main()
{
    assign_list_of_usage();
    assign_std_vector_usage();
    assign_list_inserter_usage();
}
