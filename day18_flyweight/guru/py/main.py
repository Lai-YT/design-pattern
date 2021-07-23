from flyweight import *


def add_car_to_police_database(factory: FlyweightFactory, plates: str,
                               owner: str, brand: str, model: str, color: str) -> None:
    print('Client: Adding a car to database.')
    flyweight: Flyweight = factory.get_flyweight([brand, color, model])
    # The client code either stores or calculates extrinsic state and passes it
    # to the flyweight's methods.
    flyweight.operation([plates, owner])


if __name__ == '__main__':
    """
    The client code usually creates a bunch of pre-populated flyweights in the
    initialization stage of the application.
    """
    factory = FlyweightFactory([
        ['Chevrolet', 'Camaro2018', 'pink'],
        ['Mercedes Benz', 'C300', 'black'],
        ['Mercedes Benz', 'C500', 'red'],
        ['BMW', 'M5', 'red'],
        ['BMW', 'X6', 'white']
    ])
    factory.list_flyweights()
    print()

    add_car_to_police_database(factory, 'CL234IR', 'James Doe', 'BMW', 'M5', 'red')
    print()
    add_car_to_police_database(factory, 'CL234IR', 'James Doe', 'BMW', 'X1', 'red')
    print()

    factory.list_flyweights()
    # FlyweightFactory: I have 5 flyweights.
    # Camaro2018_Chevrolet_pink
    # C300_Mercedes Benz_black
    # C500_Mercedes Benz_red
    # BMW_M5_red
    # BMW_X6_white
    #
    # Client: Adding a car to database.
    # FlyweightFactory: Reuse the existing flyweight.
    # Flyweight: Displaying shared (["BMW", "M5", "red"]) and unique (["CL234IR", "James Doe"]) state.
    #
    # Client: Adding a car to database.
    # FlyweightFactory: Can't find the flyweight, create a new one.
    # Flyweight: Displaying shared (["BMW", "red", "X1"]) and unique (["CL234IR", "James Doe"]) state.
    #
    # FlyweightFactory: I have 6 flyweights.
    # Camaro2018_Chevrolet_pink
    # C300_Mercedes Benz_black
    # C500_Mercedes Benz_red
    # BMW_M5_red
    # BMW_X6_white
    # BMW_X1_red
