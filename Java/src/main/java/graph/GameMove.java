package graph;

public record GameMove<T extends GameState>(String moveName, T nextState) {
}
