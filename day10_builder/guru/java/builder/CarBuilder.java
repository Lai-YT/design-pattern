package builder;

import builder.Builder;
import car.Car;
import car.CarType;
import component.Engine;
import component.GpsNavigator;
import component.Transmission;
import component.TripComputer;


/**
 * Concrete builders implement steps defined in the common interface.
 */
public class CarBuilder implements Builder {
    private CarType carType;
    private int seats;
    private Engine engine;
    private Transmission transmission;
    private TripComputer tripComputer;
    private GpsNavigator gpsNavigator;

    @Override
    public void setCarType(final CarType carType) {
        this.carType = carType;
    }

    @Override
    public void setSeats(final int seats) {
        this.seats = seats;
    }

    @Override
    public void setEngine(final Engine engine) {
        this.engine = engine;
    }

    @Override
    public void setTransmission(final Transmission transmission) {
        this.transmission = transmission;
    }

    @Override
    public void setTripComputer(final TripComputer tripComputer) {
        this.tripComputer = tripComputer;
    }

    @Override
    public void SetGpsNavigator(final GpsNavigator gpsNavigator) {
        this.gpsNavigator = gpsNavigator;
    }

    public Car getCar() {
        return new Car(
            this.carType, this.seats, this.engine, this.transmission,
            this.tripComputer, this.gpsNavigator
        );
    }
}
