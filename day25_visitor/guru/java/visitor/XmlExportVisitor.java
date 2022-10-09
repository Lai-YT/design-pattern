package visitor;

import shapes.*;

public class XmlExportVisitor implements Visitor {
    public String export(final Shape... shapes) {
        final StringBuilder sb = new StringBuilder();
        sb.append("""
                <?xml version="1.0" encoding="utf-8"?>
                """);
        for (final Shape shape : shapes) {
            sb.append(shape.accept(this));
        }
        return sb.toString();
    }

    @Override
    public String visit(final Dot dot) {
        return String.format("""
                <dot>
                    <id>%d</id>
                    <x>%d</x>
                    <y>%d</y>
                </dot>
                """, dot.getId(), dot.getX(), dot.getY());
    }

    @Override
    public String visit(final Circle circle) {
        return String.format("""
                <circle>
                    <id>%d</id>
                    <x>%d</x>
                    <y>%d</y>
                    <radius>%d</radius>
                </circle>
                """, circle.getId(), circle.getX(), circle.getX(), circle.getRadius());
    }

    @Override
    public String visit(final Rectangle rectangle) {
        return String.format("""
                <rectangle>
                    <id>%d</id>
                    <x>%d</x>
                    <y>%d</y>
                    <width>%d</width>
                    <height>%d</height>
                </rectangle>
                """, rectangle.getId(), rectangle.getX(), rectangle.getY(), rectangle.getWidth(),
                rectangle.getHeight());
    }

    @Override
    public String visit(final CompoundShape compound) {
        return String.format("""
                <compound_shape>
                    <id>%d</id>
                    %s
                </compound_shape>
                """, compound.getId(), visitCompoundShape(compound));
    }

    private String visitCompoundShape(final CompoundShape compound) {
        final StringBuilder sb = new StringBuilder();
        for (final Shape shape : compound.children) {
            final String xml = shape.accept(this)
                    .replace("\n", "\n    "); /* indention for inner shapes */
            sb.append(xml);
        }
        if (!compound.children.isEmpty()) {
            sb.delete(sb.length() - 5, sb.length());
        }
        return sb.toString();
    }

}
