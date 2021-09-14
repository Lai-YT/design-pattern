
public class Main {
    public static void main(String[] args) {
        System.out.print("If you see the same value, then singleton was reused (yay!)" + "\n"
                + "If you see different values, then 2 singletons were created (booo!!)" + "\n\n"
                + "Result:" + "\n");
        Thread threadFoo = new Thread(new Main.ThreadFoo());
        Thread threadBar = new Thread(new Main.ThreadBar());
        threadFoo.start();
        threadBar.start();
    }

    static class ThreadFoo implements Runnable {
        @Override
        public void run() {
            Singleton singleton = Singleton.getInstance("Foo");
            System.out.println(singleton.value);
        }
    }

    static class ThreadBar implements Runnable {
        @Override
        public void run() {
            Singleton singleton = Singleton.getInstance("Bar");
            System.out.println(singleton.value);
        }
    }
}
