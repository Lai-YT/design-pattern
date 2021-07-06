import copy
from typing import List

from component import *


def shallow_copy_test(component: SomeComponent) -> None:
    print('Create a shallow_copied_component:')
    shallow_copied_component: SomeComponent = copy.copy(component)

    # Let's change the list in shallow_copied_component and see if it changes in
    # component.
    print('Adding elements to shallow_copied_component\'s some_list_of_objects...')
    shallow_copied_component.some_list_of_objects.append('another object')
    if component.some_list_of_objects[-1] == 'another object':
        print('Elements "are" also added to component\'s some_list_of_objects.')
    else:
        print('Elements "aren\'t" also added to component\'s some_list_of_objects.')

    # Let's change the set in the list of objects.
    print('Changing objects in component\'s some_list_of_objects...')
    component.some_list_of_objects[1].add(4)
    if 4 in shallow_copied_component.some_list_of_objects[1]:
        print('Objects "are" also changed in shallow_copied_component\'s some_list_of_objects.')
    else:
        print('Objects "aren\'t" also changed in shallow_copied_component\'s some_list_of_objects.')


def deep_copy_test(component: SomeComponent) -> None:
    print('Create a deep_copied_component:')
    deep_copied_component: SomeComponent = copy.deepcopy(component)

    # Let's change the list in deep_copied_component and see if it changes in
    # component.
    print('Adding elements to deep_copied_component\'s some_list_of_objects...')
    deep_copied_component.some_list_of_objects.append('one more object')
    if component.some_list_of_objects[-1] == 'one more object':
        print('Elements "are" also added to component\'s some_list_of_objects.')
    else:
        print('Elements "aren\'t" also added to component\'s some_list_of_objects.')

    # Let's change the set in the list of objects.
    print('Changing objects in component\'s some_list_of_objects...')
    component.some_list_of_objects[1].add(10)
    if 10 in deep_copied_component.some_list_of_objects[1]:
        print('Objects "are" also changed in deep_copied_component\'s some_list_of_objects.')
    else:
        print('Objects "aren\'t" also changed in deep_copied_component\'s some_list_of_objects.')
    print()

    print('Do some check on recursive coping:')
    deep_copied_circular_parent: int \
        = id(deep_copied_component.some_circular_ref.parent)
    print(f'id of deep_copied_circular_parent: {deep_copied_circular_parent}')
    deep_copied_circular_parent_of_circular_parent: int \
        = id(deep_copied_component.some_circular_ref.parent.some_circular_ref.parent)
    print(f'id of deep_copied_circular_parent_of_circular_parent: '
          f'{deep_copied_circular_parent_of_circular_parent}')
    if deep_copied_circular_parent == deep_copied_circular_parent_of_circular_parent:
        print('This shows that deepcopied objects contain same reference, they are not cloned repeatedly.')
    else:
        print('Something\'s wrong! Go fix the __deepcopy__.')


if __name__ =='__main__':
    list_of_objects: List[object] = [1, {1, 2, 3}, [1, 2, 3]]
    circular_ref = SelfReferencingEntity()
    component = SomeComponent(23, list_of_objects, circular_ref)
    circular_ref.parent = component

    shallow_copy_test(component)
    print()

    deep_copy_test(component)
    # Create a shallow_copied_component:
    # Adding elements to shallow_copied_component's some_list_of_objects...
    # Elements "are" also added to component's some_list_of_objects.
    # Changing objects in component's some_list_of_objects...
    # Objects "are" also changed in shallow_copied_component's some_list_of_objects.
    #
    # Create a deep_copied_component:
    # Adding elements to deep_copied_component's some_list_of_objects...
    # Elements "aren't" also added to component's some_list_of_objects.
    # Changing objects in component's some_list_of_objects...
    # Objects "aren't" also changed in deep_copied_component's some_list_of_objects.
    #
    # Do some check on recursive coping:
    # id of deep_copied_circular_parent: (varies)
    # id of deep_copied_circular_parent_of_circular_parent: (varies)
    # This shows that deepcopied objects contain same reference, they are not cloned repeatedly.
