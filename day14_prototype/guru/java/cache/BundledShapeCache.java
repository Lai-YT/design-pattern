package cache;

import java.util.HashMap;
import java.util.Map;

import shapes.Circle;
import shapes.Rectangle;
import shapes.Shape;

/// Prototype factory
public class BundledShapeCache {
    private Map<String, Shape> cache = new HashMap<>();

    public BundledShapeCache() {
        Circle circle = new Circle(45);
        circle.x = 5;
        circle.y = 7;
        circle.color = "green";
        cache.put("big green circle", circle);

        Rectangle rectangle = new Rectangle(8, 10);
        rectangle.x = 6;
        rectangle.y = 9;
        rectangle.color = "blue";
        cache.put("medium blue rectangle", rectangle);
    }

    public Shape put(String key, Shape shape) {
        cache.put(key, shape);
        return shape;
    }

    public Shape get(final String key) {
        return cache.get(key).clone();
    }
}
