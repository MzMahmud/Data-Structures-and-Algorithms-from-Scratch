package graph;

import org.junit.jupiter.api.Test;

import java.util.Collection;

class MissionariesCannibalsGameStateTest {
    @Test
    void solveMissionariesCannibalsGame() {
        var initialState = new MissionariesCannibalsGameState(new int[]{3, 0}, 3, new int[]{3, 0}, 3, 0);
        var moves = GameSolver.solveWithBfs(initialState, MissionariesCannibalsGameState::isFinalState)
                              .map(PathNode::getPath)
                              .stream()
                              .flatMap(Collection::stream)
                              .toList();
        for (int i = 0; i < moves.size(); ++i) {
            System.out.printf("%d %s\n%s\n", i, moves.get(i).moveName(), moves.get(i).currentGameState().show());
        }
    }
}