package spammer;

import iterators.ProfileIterator;
import profile.Profile;
import social_networks.SocialNetwork;

public class SocialSpammer {
    private final SocialNetwork network;

    public SocialSpammer(final SocialNetwork network) {
        this.network = network;
    }

    public void sendSpamToFriends(final String email, final String message) {
        System.out.println("\nIterating over friends...\n");
        final ProfileIterator iterator = network.createFriendsIterator(email);
        while (iterator.hasNext()) {
            final Profile profile = iterator.getNext();
            sendMessage(profile.getEmail(), message);
        }
    }

    public void sendSpamToCoworkers(final String email, final String message) {
        System.out.println("\nIterating over coworkers...\n");
        final ProfileIterator iterator = network.createCoworkersIterator(email);
        while (iterator.hasNext()) {
            final Profile profile = iterator.getNext();
            sendMessage(profile.getEmail(), message);
        }
    }

    private void sendMessage(final String email, final String message) {
        System.out.format("Sent message to: '%s'. Message body: '%s'\n", email, message);
    }
}
