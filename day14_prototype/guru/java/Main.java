import java.util.ArrayList;
import java.util.List;

import cache.BundledShapeCache;
import shapes.Circle;
import shapes.Rectangle;
import shapes.Shape;


public class Main {
    public static void main(String[] args) {
        testIdentityOfClones();
        System.out.println("===============================================");
        testIdentityOfCacheClones();
    }

    static private void testIdentityOfClones() {
        final List<Shape> shapes = new ArrayList<>();

        Circle circle = new Circle(15);
        circle.x = 10;
        circle.y = 20;
        circle.color = "red";
        shapes.add(circle);
        shapes.add(circle.clone());

        Rectangle rectangle = new Rectangle(10, 20);
        rectangle.color = "blue";
        shapes.add(rectangle);

        final List<Shape> copyOfShapes = new ArrayList<>();
        for (final Shape shape : shapes) {
            copyOfShapes.add(shape.clone());
        }

        for (int i = 0; i < shapes.size(); ++i) {
            if (shapes.get(i) == copyOfShapes.get(i)) {
                System.out.println(i + ": Shape objects are the same (booo!)");
            } else {
                System.out.println(i + ": Shapes are different objects (yay!)");
                if (shapes.get(i).equals(copyOfShapes.get(i))) {
                    System.out.println(i + ": And they are identical (yay!)");
                } else {
                    System.out.println(i + ": But they are not identical (booo!)");
                }
            }
        }
    }

    static private void testIdentityOfCacheClones() {
        final BundledShapeCache cache = new BundledShapeCache();

        final Shape bigGreenCircle = cache.get("big green circle");
        final Shape mediumBlueRectangle = cache.get("medium blue rectangle");
        final Shape anotherMediumBlueRectangle = cache.get("medium blue rectangle");

        if (bigGreenCircle != mediumBlueRectangle && !bigGreenCircle.equals(mediumBlueRectangle)) {
            System.out.println("Big green circle != Medium blue rectangle (yay!)");
        } else {
            System.out.println("Big green circle == Medium blue rectangle (booo!)");
        }
        if (mediumBlueRectangle == anotherMediumBlueRectangle) {
            System.out.println("Rectangle objects are the same (booo!)");
        } else {
            System.out.println("Medium blue rectangles are two different objects (yay!)");
            if (mediumBlueRectangle.equals(anotherMediumBlueRectangle)) {
                System.out.println("And they are identical (yay!)");
            } else {
                System.out.println("But they are not identical (booo!)");
            }
        }
    }
}
