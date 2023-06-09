#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

using namespace std;

struct ServiceParam {
    string data;    
};

class Node {
public:
    shared_ptr<ServiceParam> _service_param{nullptr};
    
    shared_ptr<ServiceParam> service_param() const {
        return _service_param;
    }

    void set_service_param(const ServiceParam& param) {
        _service_param = make_shared<ServiceParam>(param);
    }
};

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    auto node = make_shared<Node>();

    vector<thread> thread_pool;

    for (int i = 0; i < 20; ++i) {
        thread th([&node]{
            for (int i = 0; i < 10000; ++i) {
                ServiceParam service_param;
                node->set_service_param(service_param);
                auto sp = node->service_param();
                this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        });
        thread_pool.emplace_back(std::move(th));
    }

    for (auto &th : thread_pool) {
        th.join();
    }

    return 0;
}