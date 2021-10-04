package command;

import java.util.Stack;

import command.Command;


public class CommandHistory {
    private Stack<Command> history = new Stack<>();

    public void push(final Command c) {
        this.history.push(c);
    }

    public Command pop() {
        return this.history.pop();
    }

    public boolean isEmpty() {
        return this.history.isEmpty();
    }
}
