package graph;

import java.util.*;
import java.util.function.Predicate;

@SuppressWarnings({"unchecked"})
public final class GameSolver {
    private GameSolver() {
    }

    public static <T extends GameState> Optional<PathNode<T>> solveWithBfs(T startState,
                                                                           Predicate<T> reachedEndState) {
        Set<T> visitedStates = new LinkedHashSet<>();
        Queue<PathNode<T>> queue = new LinkedList<>();
        queue.add(new PathNode<>(null, "initial state", startState));
        while (!queue.isEmpty()) {
            var pathNode = queue.poll();
            var currentState = pathNode.currentGameState();
            if (reachedEndState.test(currentState)) {
                return Optional.of(pathNode);
            }
            if (!visitedStates.contains(currentState)) {
                visitedStates.add(currentState);
                currentState.getGameMoves()
                            .stream()
                            .map(gameMove -> new PathNode<>(pathNode, gameMove.moveName(), (T) gameMove.nextState()))
                            .forEach(queue::add);
            }
        }
        return Optional.empty();
    }
}
