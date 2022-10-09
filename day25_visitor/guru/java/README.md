# Exporting shapes into XML

In this example, we would want to export a set of geometric shapes into XML. \
The catch is that we don't want to change the code of shapes directly or at least keep it to the minimum.

In the end, the Visitor pattern establishes an infrastructure that allows us to add any behaviors to the shapes hierarchy without changing the existing code of those classes.
