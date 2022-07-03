package graph;

import java.util.ArrayList;
import java.util.List;

@SuppressWarnings({"unchecked"})
public record TwoJugGameState(int threeCapacityJug, int fiveCapacityJug) implements GameState {
    @Override
    public List<GameMove<TwoJugGameState>> getGameMoves() {
        var gameMoves = new ArrayList<GameMove<TwoJugGameState>>();
        gameMoves.add(new GameMove<>("fill 3", new TwoJugGameState(3, fiveCapacityJug)));
        gameMoves.add(new GameMove<>("fill 5", new TwoJugGameState(threeCapacityJug, 5)));
        if (threeCapacityJug > 0) {
            gameMoves.add(new GameMove<>("empty three", new TwoJugGameState(0, fiveCapacityJug)));
            var transferAmount = Math.min(5, fiveCapacityJug + threeCapacityJug) - fiveCapacityJug;
            gameMoves.add(new GameMove<>(
                    "transfer from 3 to 5",
                    new TwoJugGameState(threeCapacityJug - transferAmount, fiveCapacityJug + transferAmount)
            ));
        }
        if (fiveCapacityJug > 0) {
            gameMoves.add(new GameMove<>("empty five", new TwoJugGameState(threeCapacityJug, 0)));
            var transferAmount = Math.min(3, fiveCapacityJug + threeCapacityJug) - threeCapacityJug;
            gameMoves.add(new GameMove<>(
                    "transfer from 5 to 3",
                    new TwoJugGameState(threeCapacityJug + transferAmount, fiveCapacityJug - transferAmount)
            ));
        }
        return gameMoves;
    }
}
