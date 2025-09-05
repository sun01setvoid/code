#include <iostream>
#include <stdexcept> // 用于 std::out_of_range

class DynamicArray {
private:
    int* data;         // 存储数据的指针
    size_t capacity;   // 当前分配的容量
    size_t size;       // 当前实际存储的元素数量

    // 扩容函数（私有方法）
    void resize(size_t newCapacity) {
        int* newData = new int[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i]; // 复制旧数据
        }
        delete[] data;   // 释放旧内存
        data = newData;
        capacity = newCapacity;
    }

public:
    // 构造函数（默认初始容量为10）
    DynamicArray(size_t initialCapacity = 10) 
        : data(new int[initialCapacity]), capacity(initialCapacity), size(0) {}

    // 析构函数
    ~DynamicArray() {
        delete[] data;
    }

    // 添加元素（自动扩容）
    void push_back(int value) {
        if (size >= capacity) {
            resize(capacity * 2); // 容量不足时翻倍扩容
        }
        data[size++] = value;
    }

    // 访问元素（带边界检查）
    int& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // 获取当前元素数量
    size_t getSize() const { return size; }

    // 获取当前容量
    size_t getCapacity() const { return capacity; }

    // 打印数组内容（测试用）
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray arr(3); // 初始容量为3

    // 测试添加元素（触发自动扩容）
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    std::cout << "Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << std::endl; // Size: 3, Capacity: 3

    arr.push_back(4); // 触发扩容
    std::cout << "After扩容 - Size: " << arr.getSize() << ", Capacity: " << arr.getCapacity() << std::endl; // Size: 4, Capacity: 6

    // 测试访问元素
    try {
        std::cout << "Element at index 2: " << arr.at(2) << std::endl; // 3
        std::cout << "Element at index 5: " << arr.at(5) << std::endl; // 抛出异常
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}