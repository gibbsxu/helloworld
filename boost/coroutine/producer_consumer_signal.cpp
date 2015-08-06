// 生产者消费者-信号

#include <iostream>
#include <boost/format.hpp>
#include <boost/thread.hpp>
#include <boost/signal.hpp>

typedef int Product;

boost::signal<void (Product)> produce_done;
boost::signal<void ()> consume_done;

void producer_worker() {
    static Product product = -1;
    product++;
    std::cout << boost::format("producer produce %1%\n") % product;
    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    if (product < 10) {
        produce_done(product);
    }
}

void consumer_worker(Product product) {
    std::cout << boost::format("consumer consume %1%\n") % product;
    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    consume_done();
}

int main() {
    produce_done.connect(consumer_worker);
    consume_done.connect(producer_worker);

    producer_worker();
}
