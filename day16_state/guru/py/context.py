import state
# To avoid circular import problem, can't use from state import State.

class Context:
    """
    The Context defines the interface of interest to clients. It also maintains
    a reference to an instance of a State subclass, which represents the current
    state of the Context.
    """

    def __init__(self, state: state.State) -> None:
        self.transition_to(state)

    def transition_to(self, state: state.State) -> None:
        """
        The Context allows changing the State object at runtime.
        """

        print(f'Context: Transition to {type(state).__name__}')
        # A reference to the current state of the Context.
        self._state = state
        self._state.context = self

    """
    The Context delegates part of its behavior to the current State object.
    """
    def request_1(self) -> None:
        self._state.handle_1()

    def request_2(self) -> None:
        self._state.handle_2()
