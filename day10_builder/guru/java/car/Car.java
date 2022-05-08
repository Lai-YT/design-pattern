package car;

import car.CarType;
import component.Engine;
import component.GpsNavigator;
import component.Transmission;
import component.TripComputer;


/**
 * Car is the product class that are to be built by a builder.
 */
public class Car {
    private final CarType carType;
    private final int seats;
    private final Engine engine;
    private final GpsNavigator gpsNavigator;
    private final Transmission transmission;
    private final TripComputer tripComputer;
    private double fuel = 0;

    public Car(final CarType carType, final int seats, final Engine engine,
               final Transmission transmission, final TripComputer tripComputer,
               final GpsNavigator gpsNavigator) {
        this.carType = carType;
        this.seats = seats;
        this.engine = engine;
        this.transmission = transmission;
        this.tripComputer = tripComputer;
        if (this.tripComputer != null) {
            this.tripComputer.setCar(this);
        }
        this.gpsNavigator = gpsNavigator;
    }

    public CarType getCarType() {
        return this.carType;
    }

    public double getFuel() {
        return this.fuel;
    }

    public void setFuel(double fuel) {
        this.fuel = fuel;
    }

    public int getSeats() {
        return this.seats;
    }

    public Engine getEngine() {
        return this.engine;
    }

    public Transmission getTransmission() {
        return this.transmission;
    }

    public TripComputer getTripComputer() {
        return this.tripComputer;
    }

    public GpsNavigator getGpsNavigator() {
        return this.gpsNavigator;
    }

    public String info() {
        String info = String.format(
            "Type of car: %s\n"
            + "Count of seats: %d\n"
            + "Engine: volume - %.1f; mileage - %.1f\n"
            + "Transmission: %s\n",
            this.carType, this.seats, this.engine.getVolume(),
            this.engine.getMileage(), this.transmission
        );
        if (this.tripComputer != null) {
            info += "Trip Computer: Functional\n";
        } else {
            info += "Trip Computer: N/A\n";
        }
        if (this.gpsNavigator != null) {
            info += "GPS Navigator: Functional";  /* no new line */
        } else {
            info += "GPS Navigator: N/A";
        }
        return info;
    }
}
