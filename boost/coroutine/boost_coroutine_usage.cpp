#include <iostream>
#include <boost/scoped_ptr.hpp>

int main(int argc, char* argv[])
{
    std::cout << "hello world" << std::endl;
    boost::scoped_ptr<int> i(new int);
    *i = 1;

    return 0;
}
