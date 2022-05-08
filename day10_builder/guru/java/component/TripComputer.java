package component;

import car.Car;


/**
 * The trip computer feature of a car.
 */
public class TripComputer {
    public Car car;

    public void setCar(final Car car) {
        this.car = car;
    }

    public void showFuelLevel() {
        System.out.println("Fuel level: " + car.getFuel());
    }

    public void showStatus() {
        if (this.car.getEngine().isStarted()) {
            System.out.println("Car is started.");
        } else {
            System.out.println("Car isn't started.");
        }
    }
}
