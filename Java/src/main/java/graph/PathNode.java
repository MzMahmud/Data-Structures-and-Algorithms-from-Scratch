package graph;

import java.util.Collections;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public record PathNode<T extends GameState>(PathNode<T> parentPathNode, String moveName, T currentGameState) {
    public List<PathNode<T>> getPath() {
        var pathNodes = Stream.iterate(this, Objects::nonNull, PathNode::parentPathNode)
                              .collect(Collectors.toList());
        Collections.reverse(pathNodes);
        return pathNodes;
    }
}
