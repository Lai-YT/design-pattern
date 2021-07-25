from computer_builder import ConcreteComputerBuilder
from computer_part import *
from computer_seller import ComputerSeller
from computer import Computer


def client_code() -> None:
    computer_builder = ConcreteComputerBuilder()
    computer_seller = ComputerSeller(computer_builder)

    low_spec_computer: Computer = computer_seller.low_spec()
    low_spec_computer.show_details()
    print()

    high_spec_computer: Computer = computer_seller.high_spec()
    high_spec_computer.show_details()
    print()

    print('Start builing customized computer...')
    # Put all build methods and deliver in a single chain
    # to make sure the process won't be interrupted accidentally.
    custom_computer: Computer = (
        computer_builder.build_processor(Processor('2.9GHz, 6 core, Intel Core i9'))
                        .build_memory(Memory(32))
                        .build_graphics(Graphics('Radeon Pro 560X, 4GB GDDR5'))
                        .build_storage(Storage(4096))
                        .deliver())
    custom_computer.show_details()


if __name__ == '__main__':
    client_code()
    # Start building low spec computer...
    # Setting processor...
    # Setting memory...
    # Setting graphics...
    # Setting storage...
    # End building. Deliver the computer.
    # Computer details:
    #     Processor: 2.2GHz, 6 core, Intel Core i7
    #     Memory size: 16 GB
    #     Graphics: Radeon Pro 555X, 4GB GDDR5
    #     Storage size: 256 GB
    #
    # Start building high spec computer...
    # Setting processor...
    # Setting memory...
    # Setting graphics...
    # Setting storage...
    # End building. Deliver the computer.
    # Computer details:
    #     Processor: 2.6GHz, 6 core, Intel Core i7
    #     Memory size: 16 GB
    #     Graphics: Radeon Pro 560X, 4GB GDDR5
    #     Storage size: 512 GB
    #
    # Start builing customized computer...
    # Setting processor...
    # Setting memory...
    # Setting graphics...
    # Setting storage...
    # End building. Deliver the computer.
    # Computer details:
    #     Processor: 2.9GHz, 6 core, Intel Core i9
    #     Memory size: 32 GB
    #     Graphics: Radeon Pro 560X, 4GB GDDR5
    #     Storage size: 4096 GB
