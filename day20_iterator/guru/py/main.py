from collection import WordsCollection
from iterator import AlphabeticalOrderIterator


# The client code may or may not know about the Concrete Iterator or
# Collection classes, depending on the level of indirection you want to keep
# in your program.
def client_code() -> None:
    collection = WordsCollection()
    collection.add_item('First')
    collection.add_item('Second')
    collection.add_item('Third')

    print('Straight traversal:')
    print('\n'.join(collection))
    print()

    print('Reverse traversal:')
    print('\n'.join(collection.get_reverse_iterator()))


if __name__ == '__main__':
    client_code()
    # Straight traversal:
    # First
    # Second
    # Third
    #
    # Reverse traversal:
    # Third
    # Second
    # First
