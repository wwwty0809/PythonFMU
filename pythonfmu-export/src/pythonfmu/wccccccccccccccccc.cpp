#include "src/pythonfmu/PySlaveInstance.hpp"
#include <iostream>

int main() {
    // 假设 logger 和 pyState 已经正确初始化
    cppfmu::Logger logger;
    std::shared_ptr<cppfmu::IPyState> pyState;

    std::string instanceName = "InstanceName";
    std::string resources = "ResourcesPath";
    bool visible = true;

    // 创建 PySlaveInstance 对象
    pythonfmu::PySlaveInstance slaveInstance(instanceName, resources, logger, visible, pyState);

    // 准备调用 GetRealArray 的参数
    cppfmu::FMIValueReference vr[] = {1, 2, 3}; // 示例值引用
    cppfmu::FMIReal values[3] = {0}; // 存储返回值的数组
    std::size_t nvr = sizeof(vr) / sizeof(vr[0]); // 值引用的数量
    std::size_t size = 3; // 数组大小

    // 调用 GetRealArray 方法
    slaveInstance.GetRealArray(vr, nvr, values, size);

    // 打印结果
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << "Value " << i << ": " << values[i] << std::endl;
    }

    return 0;
}