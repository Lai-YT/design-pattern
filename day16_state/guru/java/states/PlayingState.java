package states;

import ui.Player;

public class PlayingState extends State {
    public PlayingState(final Player player) {
        super(player);
    }

    @Override
    public String onLock() {
        player.changeState(new LockedState(player));
        player.resetTrack();
        return "Stop playing";
    }

    @Override
    public String onPlay() {
        pause();
        return "Paused...";
    }

    @Override
    public String onNext() {
        return player.startNextTrack();
    }

    @Override
    public String onPrev() {
        return player.startPreviousTrack();
    }

    private void pause() {
        player.changeState(new ReadyState(player));
    }
}
