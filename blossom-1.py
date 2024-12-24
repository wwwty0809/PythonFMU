from pythonfmu.fmi2slave import Fmi2Causality, Fmi2Slave, Boolean, Integer, Real, String, RealArray
import numpy as np

class blossom_1(Fmi2Slave):
    author = "John Doe"
    description = "A simple description"

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.w =[[1,2,3],[2,3,4]]
        self.intOut = 1
        self.realOut = 3.0
        self.booleanVariable = True
        self.stringVariable = "Hello World!"
        self.register_variable(Real("intOut", causality=Fmi2Causality.output))
        # self.register_variable(Real("realOut", causality=Fmi2Causality.output))
        # self.register_variable(Boolean("booleanVariable", causality=Fmi2Causality.local))
        # self.register_variable(String("stringVariable", causality=Fmi2Causality.local))
        self.register_variable(RealArray('w',causality=Fmi2Causality.local))


        # Note:
        # it is also possible to explicitly define getters and setters as lambdas in case the variable is not backed by a Python field.
        # self.register_variable(Real("myReal", causality=Fmi2Causality.output, getter=lambda: self.realOut, setter=lambda v: set_real_out(v))

    def do_step(self, current_time=None, step_size=None):
        print(self.get_real_array([1]))
        self.set_real_array([1],[[3,7,6]])
        print(self.get_array([1]))
        self.set_array([1], [[99,100,98]])
        # print(self.get_array([1]))
        print("成功")
        return True

# if __name__=="__main__":
#     my_blossom_1=blossom_1(instance_name="instance_1")
#     my_blossom_1.do_step()