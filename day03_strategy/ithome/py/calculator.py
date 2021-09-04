from enum import auto, Enum, unique

import strategy as st

@unique
class DoType(Enum):
    ADD = auto()
    MINUS = auto()
    MULTIPLY = auto()
    DIVIDE = auto()


class Calculator():
    def __init__(self) -> None:
        self._strategy: st.Strategy = None

    def set_strategy(self, do_type: DoType) -> None:
        if   do_type == DoType.ADD:      self._strategy = st.Add()
        elif do_type == DoType.MINUS:    self._strategy = st.Minus()
        elif do_type == DoType.MULTIPLY: self._strategy = st.Multiply()
        elif do_type == DoType.DIVIDE:   self._strategy = st.Divide()
        else:                            self._strategy = None

    def execute(self, a: int, b: int) -> int:
        return self._strategy.calculate(a, b)
