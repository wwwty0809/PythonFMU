from fmpy import *
from fmpy.simulation import _get_output_variables
from fmpy.fmi2 import FMU2Slave, FMU2Model
from fmpy import extract
import numpy as np
# 加载 FMU 文件
fmu='blossom_1.fmu'

# print(fmu.get_model_variables()) #OrderedDict([('w1', <pyfmi.fmi.ScalarVariable2 object at 0x0000023F75632F40>)])
# dump(fmu)



# # 创建输入信号数组
# # 第一列是时间，第二列是temperature的值
# dtype = [('time', np.double), ('w', np.double)]
# signals = np.array([
#     (0.0, 20.0),  # 在t=0时，温度为20度
#     (1.0, 25.0),  # 在t=1时，温度为25度
#     (2.0, 30.0)   # 在t=2时，温度为30度
# ], dtype=dtype)
#
#
#
model_description=read_model_description(fmu)
print(model_description)
# result = simulate_fmu(fmu,start_time=0.0,stop_time=2.0,input=signals)

implementation = model_description.coSimulation
unzipdir = extract(fmu)

fmu_kwargs = {
    'guid': model_description.guid,
    'modelIdentifier': implementation.modelIdentifier,
    'unzipDirectory': unzipdir,
}
fmu = FMU2Slave(**fmu_kwargs)
fmu.instantiate()

# array_elements = ["w[0]", "w2[1]", "w2[2]"]
# model.set(array_elements, [1.0, 2.0, 3.0])  # 设置数组值
# print(fmu.get("w[0]"))
for variable in model_description.modelVariables:
    print((variable.name, variable, variable.valueReference))
    vr = [variable.valueReference]
    if variable.type == 'Real':
        value = fmu.getReal(vr=vr)
        print(value)

# # 设置仿真时间
# fmu.setup_experiment(start_time=0.0, stop_time=10.0)
#
# # 运行仿真
# fmu.initialize()
# #
# # 仿真循环
# while fmu.time < 10.0:
#     success = fmu.do_step(fmu.time, 0.1)
#     print(f'Time: {fmu.time}')



# import os
# import sys
#
# import os
# sys.path.append(r"H:\PyFMI-2.5\PyFMI-2.5\src")  # 替换为实际路径
#
# # 测试导入
# try:
#     import pyfmi.fmi as fmi_module
#
#     print(dir(fmi_module))  # 检查 `fmi` 模块中是否包含 `load_fmu`
#     print("fmi module imported successfully!")
# except ImportError as e:
#     print("ImportError:", e)


# import ctypes
# import os
#
# fmu_dir = os.path.dirname(os.path.abspath(__file__))
# dll_path = os.path.join(fmu_dir, 'test1.dll')
#
# dll = ctypes.CDLL(dll_path)
#
# dll.add.restype = ctypes.c_int  # 设置返回类型为 int
# dll.add.argtypes = []  # 设置参数类型为空（因为 add 函数不带参数）
#
# # 调用 add 函数
# result = dll.add()
# print(result)

# import importlib.util
# import sys
# import os
#
# # 假设 .pyd 文件名为 funcs_2_39.pyd，位于当前工作目录
# pyd_file_path = os.path.join(os.getcwd(), 'funcs_2_39.pyd')
#
# # 模块名称，通常与文件名相同
# module_name = 'funcs_2_39'
#
# # 创建模块的规范对象
# spec = importlib.util.spec_from_file_location(module_name, pyd_file_path)
#
# # 加载模块
# example_module = importlib.util.module_from_spec(spec)
#
# # 将模块添加到 sys.modules 中
# sys.modules[module_name] = example_module
#
# # 执行模块加载
# spec.loader.exec_module(example_module)
#
# # 使用模块中的函数
# result =example_module.add_numbers(1,2)
# # result = funcs_2_39.add_numbers(1,2)
# print(result)