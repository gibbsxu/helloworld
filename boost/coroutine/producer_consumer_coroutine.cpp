// 生产者消费者-对称协程

#include <iostream>
#include <boost/thread.hpp>
#include <boost/coroutine/coroutine.hpp>
#include <boost/format.hpp>

typedef int Product;
typedef boost::coroutines::symmetric_coroutine<void> coro_t;

Product product = 0;

coro_t::call_type *producer_caller, *consumer_caller;

void producer_worker(coro_t::yield_type& yield) {
    while (product < 10) {
        std::cout << boost::format("producer produce %1%\n") % product;
        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        yield(*consumer_caller);
        product++;
    }
}

void consumer_worker(coro_t::yield_type& yield) {
    while (product < 10) {
        std::cout << boost::format("consumer consume %1%\n") % product;
        boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        yield(*producer_caller);
    }
}

int main() {
    coro_t::call_type coro_p(producer_worker);
    coro_t::call_type coro_c(consumer_worker);

    producer_caller = &coro_p;
    consumer_caller = &coro_c;

    coro_p();
}
