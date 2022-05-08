package builder;

import builder.Builder;
import car.CarManual;
import car.CarType;
import component.Engine;
import component.GpsNavigator;
import component.Transmission;
import component.TripComputer;


/**
 * Unlike other creational patterns, Builder can construct unrelated products,
 * which don't have the common interface.
 *
 * In this case we build a user manual for a car, using the same steps as we
 * built a car. This allows to produce manuals for specific car models,
 * configured with different features.
 */
public class CarManualBuilder implements Builder {
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

    public CarManual getCarManual() {
        return new CarManual(
            this.carType, this.seats, this.engine, this.transmission,
            this.tripComputer, this.gpsNavigator
        );
    }
}
