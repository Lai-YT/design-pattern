from computer_builder import ComputerBuilder
from computer_part import *
from computer import Computer


class ComputerSeller:
    def __init__(self, computer_builder: ComputerBuilder) -> None:
        self._computer_builder = computer_builder

    def low_spec(self) -> Computer:
        print('Start building low spec computer...')
        return self._computer_builder \
               .build_processor(Processor('2.2GHz, 6 core, Intel Core i7')) \
               .build_memory(Memory(16)) \
               .build_graphics(Graphics('Radeon Pro 555X, 4GB GDDR5')) \
               .build_storage(Storage(256)) \
               .deliver()

    def high_spec(self) -> Computer:
        print('Start building high spec computer...')
        return self._computer_builder \
               .build_processor(Processor('2.6GHz, 6 core, Intel Core i7')) \
               .build_memory(Memory(16)) \
               .build_graphics(Graphics('Radeon Pro 560X, 4GB GDDR5')) \
               .build_storage(Storage(512)) \
               .deliver()
