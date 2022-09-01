# Shape editor and complex undo/redo

> **NOTICE: The functionalities are not ready yet.** \
> **Since the original author fails on writing *Clean Code*, bug lives as an evil.**

This graphical editor allows changing the color and position of the shapes on the screen. Any modification can be undone and repeated, though.

The *undo* is based on the collaboration between the *Memento* and *Command* patterns. The editor tracks a history of performed commands. Before executing any command, it makes a backup and connects it to the command object. After the execution, it pushes the executed command into history.

When a user requests the undo, the editor fetches a recent command from the history and restores the state from the backup kept inside that command. If the user requests another undo, the editor takes a following command from the history and so on.

Reverted commands are kept in history until the user makes some modifications to the shapes on the screen. This is crucial for redoing undone commands.
