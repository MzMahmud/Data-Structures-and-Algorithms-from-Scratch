package graph;

import org.junit.jupiter.api.Test;

import java.util.Collection;
import java.util.function.Predicate;

class TwoJugGameStateTest {

    @Test
    void endSateHas4InFiveCapacityJug_solveTwoJugGame() {
        var initialState = new TwoJugGameState(0, 0);
        Predicate<TwoJugGameState> has4InFiveCapacityJug = twoJugGameState -> twoJugGameState.fiveCapacityJug() == 4;
        var moves = GameSolver.solveWithBfs(initialState, has4InFiveCapacityJug)
                              .map(PathNode::getPath)
                              .stream()
                              .flatMap(Collection::stream)
                              .toList();
        for (int i = 0; i < moves.size(); ++i) {
            System.out.printf("%d %s -> %s\n", i, moves.get(i).moveName(), moves.get(i).currentGameState());
        }
    }

    @Test
    void endSateHas4InTotal_solveTwoJugGame() {
        var initialState = new TwoJugGameState(0, 0);
        Predicate<TwoJugGameState> has4InTotal = twoJugGameState -> (twoJugGameState.threeCapacityJug() + twoJugGameState.fiveCapacityJug()) == 4;
        var moves = GameSolver.solveWithBfs(initialState, has4InTotal)
                              .map(PathNode::getPath)
                              .stream()
                              .flatMap(Collection::stream)
                              .toList();
        for (int i = 0; i < moves.size(); ++i) {
            System.out.printf("%d %s -> %s\n", i, moves.get(i).moveName(), moves.get(i).currentGameState());
        }
    }
}