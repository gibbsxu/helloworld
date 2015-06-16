#include <cassert>
#include <memory>

int main() {
    {
        std::unique_ptr<int> upi(new int(6));
    }

    {
        std::shared_ptr<int> spi = std::make_shared<int>(6);
        assert(spi.use_count() == 1);
        {
            std::shared_ptr<int> spi_shared(spi);
            assert(spi.use_count() == 2);
        }
        assert(spi.use_count() == 1);
    }

    {
        std::shared_ptr<int> spi = std::make_shared<int>(6);
        assert(spi.use_count() == 1);

        std::weak_ptr<int> wpi(spi);
        assert(spi.use_count() == 1);
        assert(wpi.use_count() == 1);

        // lock() 获取weak_ptr引用的shared_ptr
        assert(*wpi.lock() == 6);
        // expired() 返回引用的对象是否已经释放
        assert(!wpi.expired());
    }

    return 0;
}

