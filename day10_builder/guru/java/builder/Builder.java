package builder;

import car.CarType;
import component.Engine;
import component.GpsNavigator;
import component.Transmission;
import component.TripComputer;


/**
 * Common builder interface, defines all possible ways to configure a car product.
 */
public interface Builder {
    void setCarType(final CarType carType);
    void setSeats(final int seats);
    void setEngine(final Engine engine);
    void setTransmission(final Transmission transmission);
    void setTripComputer(final TripComputer tripComputer);
    void SetGpsNavigator(final GpsNavigator gpsNavigator);
}
