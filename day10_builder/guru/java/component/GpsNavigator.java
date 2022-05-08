package component;


/**
 * The GPS navigator feature of a car.
 */
public class GpsNavigator {
    private String route;

    public GpsNavigator(final String manualRoute) {
        this.route = manualRoute;
    }

    public GpsNavigator() {
        this("221b, Baker Street, London  to Scotland Yard, 8-10 Broadway, London");
    }

    public String getRoute() {
        return this.route;
    }
}
