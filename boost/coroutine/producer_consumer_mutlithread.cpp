// 生产者消费者-多线程

#include <random>
#include <boost/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/format.hpp>

// 线程休眠的随机值
std::random_device rd;
std::mt19937_64 mt(rd());
std::uniform_int_distribution<unsigned> psleepms(3000, 6000);
std::uniform_int_distribution<unsigned> csleepms(2000, 4000);

// 产品
typedef int Product;

boost::lockfree::queue<Product> queue(512);     // 产品队列
boost::atomic<bool> done(false);                // 结束标志
boost::atomic<int> product_count(0);            // 产品编号

void producer_worker() {
    while (!done) {
        Product product = product_count++;
        if (product_count >= 10) {
            done = true;
        }
        boost::this_thread::sleep(boost::posix_time::milliseconds(psleepms(mt)));
        while (!queue.push(product));
        std::cout << boost::format("producer %1% produce %2% \n") % boost::this_thread::get_id() % product;
        boost::this_thread::sleep(boost::posix_time::milliseconds(psleepms(mt)));
    }
}

void consumer_worker() {
    int product;
    while (!done) {
        while (!queue.pop(product));
        boost::this_thread::sleep(boost::posix_time::milliseconds(csleepms(mt)));
        std::cout << boost::format("consumer %1% consume %2% \n") % boost::this_thread::get_id() % product;
        boost::this_thread::sleep(boost::posix_time::milliseconds(csleepms(mt)));
    }
}

int main() {
    boost::thread_group threads;
    threads.create_thread(producer_worker);
    threads.create_thread(producer_worker);
    threads.create_thread(consumer_worker);
    threads.create_thread(consumer_worker);
    threads.create_thread(consumer_worker);
    threads.join_all();

    return 0;
}
