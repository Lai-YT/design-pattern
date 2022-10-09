package visitor;

import shapes.*;

public interface Visitor {
    String visit(Dot dot);
    String visit(Circle circle);
    String visit(Rectangle rectangle);
    String visit(CompoundShape compound);
}
