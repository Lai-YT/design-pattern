package car;

import car.CarType;
import component.Engine;
import component.GpsNavigator;
import component.Transmission;
import component.TripComputer;


/**
 * The manual of the car.
 *
 * Does not have the same ancestor as a Car. They are not related.
 */
public class CarManual {
    private final CarType carType;
    private final int seats;
    private final Engine engine;
    private final Transmission transmission;
    private final TripComputer tripComputer;
    private final GpsNavigator gpsNavigator;

    public CarManual(final CarType carType, final int seats, final Engine engine,
                     final Transmission transmission, final TripComputer tripComputer,
                     final GpsNavigator gpsNavigator) {
        this.carType = carType;
        this.seats = seats;
        this.engine = engine;
        this.transmission = transmission;
        this.tripComputer = tripComputer;
        this.gpsNavigator = gpsNavigator;
   }

   @Override
   public String toString() {
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
