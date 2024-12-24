/* Copyright 2016-2019, SINTEF Ocean.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "cppfmu/cppfmu_cs.hpp"

#include <stdexcept>


namespace cppfmu
{

// =============================================================================
// SlaveInstance
// =============================================================================


void SlaveInstance::SetupExperiment(
    FMIBoolean /*toleranceDefined*/,
    FMIReal /*tolerance*/,
    FMIReal /*tStart*/,
    FMIBoolean /*stopTimeDefined*/,
    FMIReal /*tStop*/)
{
    // Do nothing
}


void SlaveInstance::EnterInitializationMode()
{
    // Do nothing
}


void SlaveInstance::ExitInitializationMode()
{
    // Do nothing
}


void SlaveInstance::Terminate()
{
    // Do nothing
}


void SlaveInstance::Reset()
{
    // Do nothing
}


void SlaveInstance::SetReal(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    const FMIReal /*value*/[])
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to set nonexistent variable");
    }
}


void SlaveInstance::SetInteger(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    const FMIInteger /*value*/[])
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to set nonexistent variable");
    }
}


void SlaveInstance::SetBoolean(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    const FMIBoolean /*value*/[])
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to set nonexistent variable");
    }
}


void SlaveInstance::SetString(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    const FMIString /*value*/[])
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to set nonexistent variable");
    }
}

void SlaveInstance::SetRealArrayEx(
    const FMIValueReference vr[],
    std::size_t nvr,
    const FMIReal value[],
    std::size_t size)
{
    if (nvr == 0) {
        throw std::logic_error("No variables specified for SetRealArray");
    }

//    for (std::size_t i = 0; i < nvr; ++i) {
//        // 假设变量 vr[i] 是数组的索引，在内部存储中设置对应的值
//        for (std::size_t j = 0; j < size; ++j) {
//            // 将 value[j] 存储到数组 vr[i] 的对应位置
//            // 此处需连接到内部数组存储逻辑
//            std::cout << "SetRealArray: vr[" << vr[i] << "] = " << value[j] << std::endl;
//        }
//    }
}

void SlaveInstance::GetReal(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    FMIReal /*value*/[]) const
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to get nonexistent variable");
    }
}


void SlaveInstance::GetInteger(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    FMIInteger /*value*/[]) const
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to get nonexistent variable");
    }
}


void SlaveInstance::GetBoolean(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    FMIBoolean /*value*/[]) const
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to set nonexistent variable");
    }
}


void SlaveInstance::GetString(
    const FMIValueReference /*vr*/[],
    std::size_t nvr,
    FMIString /*value*/[]) const
{
    if (nvr != 0) {
        throw std::logic_error("Attempted to set nonexistent variable");
    }
}

void SlaveInstance::GetRealArray(
    const FMIValueReference vr[],
    std::size_t nvr,
    FMIReal value[],
    std::size_t size) const
{
    if (nvr == 0) {
        throw std::logic_error("No variables specified for GetRealArray");
    }

//    for (std::size_t i = 0; i < nvr; ++i) {
//        for (std::size_t j = 0; j < size; ++j) {
//            // 从内部数组存储中获取值并存储到 value[j]
//            // 此处需连接到内部数组存储逻辑
//            value[j] = static_cast<FMIReal>(j); // 示例值，可替换为实际逻辑
//            std::cout << "GetRealArray: vr[" << vr[i] << "] = " << value[j] << std::endl;
//        }
//    }
}

SlaveInstance::~SlaveInstance() CPPFMU_NOEXCEPT
{
    // Do nothing
}


} // namespace cppfmu
