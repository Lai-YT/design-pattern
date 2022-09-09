package trees;

import java.awt.Color;
import java.util.HashMap;
import java.util.Map;

/// Encapsulates complexity of flyweight creation.
public class TreeFactory {
    private static final Map<String, TreeType> treeTypes = new HashMap<>();

    /// name must be unique.
    public static TreeType getTreeType(
            final String name, final Color color, final String otherTreeData) {
        TreeType result = treeTypes.get(name);
        if (result == null) {
            result = new TreeType(name, color, otherTreeData);
            treeTypes.put(name, result);
        }
        return result;
    }
}
