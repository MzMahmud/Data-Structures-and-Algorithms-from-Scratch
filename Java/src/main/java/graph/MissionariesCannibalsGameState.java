package graph;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

@SuppressWarnings({"unchecked"})
public record MissionariesCannibalsGameState(int[] missionaries, int nMissionaries,
                                             int[] cannibals, int nCannibals,
                                             int boatIndex) implements GameState {

    private GameMove<MissionariesCannibalsGameState> move(int nMissionaries, int nCannibals, String moveName) {
        int[] missionaries = Arrays.copyOf(this.missionaries, 2);
        int[] cannibals = Arrays.copyOf(this.cannibals, 2);
        int boatIndex = 1 - this.boatIndex;
        missionaries[this.boatIndex] -= nMissionaries;
        cannibals[this.boatIndex] -= nCannibals;
        missionaries[boatIndex] += nMissionaries;
        cannibals[boatIndex] += nCannibals;
        return new GameMove<>(
                moveName,
                new MissionariesCannibalsGameState(missionaries, this.nMissionaries, cannibals, this.nCannibals, boatIndex)
        );
    }

    @Override
    public List<GameMove<MissionariesCannibalsGameState>> getGameMoves() {
        return Stream.of(
                             move(2, 0, "move 2 missionaries"),
                             move(1, 0, "move 1 missionary"),
                             move(0, 2, "move 2 cannibals"),
                             move(0, 1, "move 1 cannibal"),
                             move(1, 1, "move 1 missionary 1 cannibal"))
                     .filter(gameMove -> gameMove.nextState().isStateValid())
                     .toList();
    }

    private boolean isStateValid() {
        for (int i = 0; i < 2; ++i) {
            var isInvalid = missionaries[i] < 0
                            || missionaries[i] > nMissionaries
                            || cannibals[i] < 0
                            || cannibals[i] > nCannibals
                            || (missionaries[i] > 0 && cannibals[i] > missionaries[i]);
            if (isInvalid) return false;
        }
        return true;
    }

    public static boolean isFinalState(MissionariesCannibalsGameState gameState) {
        return gameState.missionaries[0] == 0
               && gameState.cannibals[0] == 0;
    }

    public String show() {
        return String.format(
                "%dm,%dc |-%s--------%s-| %dm,%dc",
                missionaries[0], cannibals[0], boatIndex == 0 ? "b" : "-",
                boatIndex == 1 ? "b" : "-", missionaries[1], cannibals[1]
        );
    }

    @Override
    public String toString() {
        return "MissionariesCannibalsGameState{" +
               "missionaries=" + Arrays.toString(missionaries) +
               ", nMissionaries=" + nMissionaries +
               ", cannibals=" + Arrays.toString(cannibals) +
               ", nCannibals=" + nCannibals +
               ", boatIndex=" + boatIndex +
               '}';
    }
}
