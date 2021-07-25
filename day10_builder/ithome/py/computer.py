from computer_part import *


class Computer:
    def set_processor(self, processor: Processor) -> None:
        print('Setting processor...')
        self._processor = processor

    def set_memory(self, memory: Memory) -> None:
        print('Setting memory...')
        self._memory = memory

    def set_graphics(self, graphics: Graphics) -> None:
        print('Setting graphics...')
        self._graphics = graphics

    def set_storage(self, storage: Storage) -> None:
        print('Setting storage...')
        self._storage = storage

    def show_details(self) -> None:
        print(f'Computer details:\n'
              f'    Processor: {self._processor.name}\n'
              f'    Memory size: {self._memory.size} GB\n'
              f'    Graphics: {self._graphics.name}\n'
              f'    Storage size: {self._storage.size} GB')
