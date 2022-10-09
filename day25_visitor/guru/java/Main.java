import shapes.*;

public class Main {
    public static void main(final String[] args) {
        final Dot dot = new Dot(1, 10, 55);
        final Circle circle = new Circle(2, 23, 15, 10);
        final Rectangle rectangle = new Rectangle(3, 10, 17, 20, 30);

        final CompoundShape compound = new CompoundShape(4);
        compound.add(dot);
        compound.add(circle);
        compound.add(rectangle);
        {
            final CompoundShape temp = new CompoundShape(5);
            temp.add(circle);
            compound.add(temp);
        }

        export(circle, compound);
    }

    private static void export(final Shape... shapes) {

    }
}
