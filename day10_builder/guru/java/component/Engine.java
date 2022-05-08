package component;


/**
 * The engine feature of a car.
 */
public class Engine {
    private final double volume;
    private double mileage;
    private boolean started;

    public Engine(final double volume, final double mileage) {
        this.volume = volume;
        this.mileage = mileage;
    }

    public void on() {
        this.started = true;
    }

    public void off() {
        this.started = false;
    }

    public boolean isStarted() {
        return this.started;
    }

    public void go(final double mileage) {
        if (this.started) {
            this.mileage += mileage;
        } else {
            System.err.println("Cannot go(), you must start the engine first!");
        }
    }

    public double getVolume() {
        return this.volume;
    }

    public double getMileage() {
        return this.mileage;
    }
}
