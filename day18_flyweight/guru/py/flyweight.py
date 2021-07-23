import json
from typing import Dict, List


class Flyweight:
    """
    The Flyweight stores a common portion of the state (also called intrinsic
    state) that belongs to multiple real business entities. The Flyweight
    accepts the rest of the state (extrinsic state, unique for each entity) via
    its method parameters.
    """

    def __init__(self, shared_state: List[str]) -> None:
        self._shared_state = shared_state

    def operation(self, unique_state: List[str]) -> None:
        s: str = json.dumps(self._shared_state)
        u: str = json.dumps(unique_state)
        print(f'Flyweight: Displaying shared ({s}) and unique ({u}) state.')


class FlyweightFactory:
    """
    The Flyweight Factory creates and manages the Flyweight objects. It ensures
    that flyweights are shared correctly. When the client requests a flyweight,
    the factory either returns an existing instance or creates a new one, if it
    doesn't exist yet.
    """

    def __init__(self, initial_flyweights: List[List[str]]) -> None:
        self._flyweights: Dict[str, Flyweight] = {}
        for state in initial_flyweights:
            self._flyweights[self._get_key(state)] = Flyweight(state)

    @staticmethod
    def _get_key(state: List[str]) -> str:
        """
        Returns a Flyweight's string hash for a given state.
        """

        return '_'.join(sorted(state))

    def get_flyweight(self, shared_state: List[str]) -> Flyweight:
        """
        Returns an existing Flyweight with a given state or creates a new one.
        """

        key: str = self._get_key(shared_state)
        if not self._flyweights.get(key):
            print('FlyweightFactory: Can\'t find the flyweight, create a new one.')
            self._flyweights[key] = Flyweight(shared_state)
        else:
            print('FlyweightFactory: Reuse the existing flyweight.')

        return self._flyweights[key]

    def list_flyweights(self) -> None:
        print(f'FlyweightFactory: I have {len(self._flyweights)} flyweights.')
        print('\n'.join(self._flyweights.keys()))
