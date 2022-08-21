package ui;

import java.util.ArrayList;
import java.util.List;

import states.PlayingState;
import states.ReadyState;
import states.State;

/// Player primary code
public class Player {
    public final int MAX_TRACK_AMOUNT = 12;
    private State state;
    private List<String> playlist = new ArrayList<>();
    private int currentTrack = 0;

    public Player() {
        state = new ReadyState(this);
        for (int i = 0; i < MAX_TRACK_AMOUNT; ++i) {
            playlist.add(String.format("Track %d", i + 1));
        }
    }

    public void changeState(State state) {
        this.state = state;
    }

    public boolean isPlaying() {
        return state instanceof ReadyState || state instanceof PlayingState;
    }

    public String startPlayback() {
        return "Playing " + playlist.get(currentTrack);
    }

    public String startNextTrack() {
        currentTrack = (currentTrack + 1) % playlist.size();
        return startPlayback();
    }

    public String startPreviousTrack() {
        --currentTrack;
        if (currentTrack < 0) {
            currentTrack = playlist.size() - 1;
        }
        return startPlayback();
    }

    public void resetTrack() {
        currentTrack = 0;
    }

    /*
     * To avoid exposing the state with getter,
     * I have the `context` implement the interface of `state` as delegation.
     */

    public String onLock() {
        return state.onLock();
    }

    public String onPlay() {
        return state.onPlay();
    }

    public String onNext() {
        return state.onNext();
    }

    public String onPrev() {
        return state.onPrev();
    }
}
