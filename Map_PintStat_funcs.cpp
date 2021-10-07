//Vasilii Sut
// 2 functions map and print_stat using pattern singleton

#include <iostream>
#include <limits>

typedef unsigned uint;
typedef uint64_t uint64;

class Singleton{
private:
    uint R_reqs, W_reqs;
    uint64 R_size, W_size;
    Singleton() {}
    Singleton(const Singleton &);
    Singleton &operator=(Singleton &);

public:
    static Singleton &getInstance(){
        static Singleton instance;
        return instance;
    }
    void map(int type, uint64 size);
    void print_stat();
};


int main(){
    Singleton &Map_PintStat_funcs = Singleton::getInstance();
    Map_PintStat_funcs.map(0,1024);
    Map_PintStat_funcs.map(1, 32);
    Map_PintStat_funcs.map(0, 128);
    Map_PintStat_funcs.map(1, 512);
    Map_PintStat_funcs.map(1, 8);

    Map_PintStat_funcs.print_stat();

    return 0;
}

void Singleton::map(int type, uint64 size){
    if (type != 0 && type != 1){
        std::cout<<"invalid data of type\n";
        return;
    }
    if (size > ULLONG_MAX){
        std::cout << "invalid data of size\n";
        return;
    }
        (type == 0) ? ((++W_reqs) &&(W_size += size)) : (++R_reqs) &&(R_size += size);
}

void Singleton::print_stat(){
    std::cout << "read:" << std::endl
              << "reqs: " << R_reqs << std::endl
              << "avg size: " << R_size / R_reqs << std::endl
              << "write:" << std::endl
              << "reqs: " << W_reqs << std::endl
              << "avg size: " << W_size / W_reqs << std::endl
              << "total:" << std::endl
              << "reqs: " << R_reqs + W_reqs << std::endl
              << "avg size: " << (W_size + R_size) / (R_reqs + W_reqs) << std::endl;
}
