#include "../exercise.h"

// READ: 析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>
// READ: RAII <https://learn.microsoft.com/zh-cn/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170>

/// @brief 任意缓存容量的斐波那契类型。
/// @details 可以在构造时传入缓存容量，因此需要动态分配缓存空间。
class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // 动态设置容量的构造器
    DynFibonacci(int capacity): cache(new size_t [capacity > 1 ? capacity:2]), cached(capacity) {
        cache[0]=0;
        cache[1]=1;
        if(capacity>1){
            for(int j=2;j<capacity;j++){
                cache[j]=cache[j-1]+cache[j-2];
            }
        }
        
    }

    // 析构器，释放缓存空间
    ~DynFibonacci(){
        delete[] cache;
    };

    // 缓存优化斐波那契计算
    size_t get(int i) {
       if (i < cached) {
            return cache[i];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
