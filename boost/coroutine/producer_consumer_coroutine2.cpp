// 生产者消费之-非对称协程

#include <iostream>
#include <boost/thread.hpp>
#include <boost/coroutine/coroutine.hpp>
#include <boost/format.hpp>

typedef int Product;
typedef boost::coroutines::asymmetric_coroutine<Product> coro_t;

void producer_worker(coro_t::push_type& sink) {
    Product product = 0;
    while (product <= 10) {
        std::cout << boost::format("producer produce %1%\n") % product;
        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        sink(product);
        product++;
    }
}

void consumer_worker(coro_t::pull_type& source) {
    while (source) {
        Product product = source.get();
        std::cout << boost::format("consumer consume %1%\n") % product;
        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        source();
    }
}

int main() {
    coro_t::pull_type source(producer_worker);
    consumer_worker(source);
}
