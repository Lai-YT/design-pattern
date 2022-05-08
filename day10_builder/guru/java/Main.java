import builder.CarBuilder;
import builder.CarManualBuilder;
import car.Car;
import car.CarManual;
import car.CarType;
import component.Engine;
import component.Transmission;
import director.Director;


/**
 * Director defines the order of building steps. It works with a builder object
 * through common Builder interface. Therefore it may not know what product is
 * being built.
 */
public class Main {
    public static void main(String[] args) {
        Director director = new Director();

        /*
         * Director gets the concrete builder object from the client.
         * That's because client knows better which builder to use to get a
         * specific product.
         */
        CarBuilder builder = new CarBuilder();
        director.constructSportsCar(builder);

        /*
         * The final product is often retrieved from a builder object, since
         * Director is not aware and not dependent on concrete builders and
         * products.
         */
        Car car = builder.getCar();
        System.out.format("Car built:\n%s\n", car.info());

        System.out.println();

        CarManualBuilder manualBuilder = new CarManualBuilder();

        /* Director may know several building recipes. */
        director.constructSportsCar(manualBuilder);
        CarManual carManual = manualBuilder.getCarManual();
        System.out.format("Car manual built:\n%s\n", carManual);

        System.out.println();

        /* Client may also build directly from the builder. */
        manualBuilder = new CarManualBuilder();
        manualBuilder.setCarType(CarType.CITY_CAR);
        manualBuilder.setSeats(1);
        manualBuilder.setEngine(new Engine(2, 1_000) /* second-hand engine */);
        manualBuilder.setTransmission(Transmission.MANUAL);
        carManual = manualBuilder.getCarManual();
        System.out.format("Car manual built without director:\n%s\n", carManual);
    }
}
