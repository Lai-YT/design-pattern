import command
from invoker import Invoker
from light import Light


def client_code() -> None:
    light = Light()
    invoker = Invoker()

    invoker.set_command(command.TurnOn(light))
    invoker.execute()

    invoker.set_command(command.Brighten(light))
    invoker.execute()

    invoker.set_command(command.Darken(light))
    invoker.execute()

    invoker.set_command(command.TurnOff(light))
    invoker.execute()

    invoker.undo()
    invoker.undo()
    invoker.undo()


if __name__ == '__main__':
    client_code()
    # Waiting for execution...
    # Do: Light is turned on.
    # Waiting for execution...
    # Do: Light is brightened.
    # Waiting for execution...
    # Do: Light is darkened.
    # Waiting for execution...
    # Do: Light is turned off.
    # Execute the previous command...
    # Do: Light is darkened.
    # Execute the previous command...
    # Do: Light is brightened.
    # Execute the previous command...
    # Do: Light is turned on.
