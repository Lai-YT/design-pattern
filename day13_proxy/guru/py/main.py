from proxy import *
from subject import *


def client_code(subject: Subject) -> None:
    """
    The client code is supposed to work with all objects (both subjects and
    proxies) via the Subject interface in order to support both real subjects
    and proxies. In real life, however, clients mostly work with their real
    subjects directly. In this case, to implement the pattern more easily, you
    can extend your proxy from the real subject's class.
    """

    subject.request()


if __name__ == '__main__':
    print('Client: Executing the client code with a real subject.')
    real_subject = RealSubject()
    client_code(real_subject)
    print()

    print('Client: Executing the same client code with a proxy.')
    proxy = Proxy(real_subject)
    client_code(proxy)
    # Client: Executing the client code with a real subject.
    # RealSubject: Handling request.
    #
    # Client: Executing the same client code with a proxy.
    # Proxy: Checking access prior to firing a real request.
    # RealSubject: Handling request.
    # Proxy: Logging the time of request.
