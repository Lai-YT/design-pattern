from overrides import overrides

from subject import *


class Proxy(Subject):
    """
    The Proxy has an interface identical to the RealSubject.
    """

    def __init__(self, real_subject: RealSubject) -> None:
        self._real_subject = real_subject

    @overrides
    def request(self) -> None:
        """
        The most common applications of the Proxy pattern are lazy loading,
        caching, controlling the access, logging, etc. A Proxy can perform one
        of these things and then, depending on the result, pass the execution to
        the same method in a linked RealSubject object.
        """

        if self._check_access():
            self._real_subject.request()
            self._log_access()

    def _check_access(self) -> bool:
        print('Proxy: Checking access prior to firing a real request.')
        return True

    def _log_access(self) -> None:
        print('Proxy: Logging the time of request.')
