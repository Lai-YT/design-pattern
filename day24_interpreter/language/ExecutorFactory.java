package language;

import language.Executor;


public interface ExecutorFactory {
    public abstract Executor createExecutor(final String command);
}
