# Interface of a media player

In this example, the State pattern lets the same media player controls behave differently, depending on the current playback state. \
The main class of the player contains a reference to a state object, which performs most of the work for the player. \
Some actions may end-up replacing the state object with another, which changes the way the player reacts to the user interactions.
