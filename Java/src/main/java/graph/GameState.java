package graph;

import java.util.List;

public interface GameState {
    <T extends GameState> List<GameMove<T>> getGameMoves();
}
