package social_networks;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import iterators.FacebookIterator;
import iterators.ProfileIterator;
import profile.Profile;

public class Facebook implements SocialNetwork {
    private final List<Profile> profiles;

    public Facebook(final List<Profile> cache) {
        this.profiles = cache;
    }

    public Facebook() {
        this(new ArrayList<Profile>());
    }

    public Profile requestProfileFromFacebook(final String email) {
        // Here would be a POST request to one of the Facebook API endpoints.
        // Instead, we emulates long network connection, which you would expect
        // in the real life...
        simulateNetworkLatency();
        System.out.format("Facebook: Loading profile '%s' over the network...\n", email);

        // ...and return test data.
        return findProfile(email);
    }

    public List<String> requestRelatedContactsFromFacebook(final String email, final String type) {
        simulateNetworkLatency();
        System.out.format("Facebook: Loading '%s' list of '%s' over the network...\n", type, email);

        final Profile profile = findProfile(email);
        if (profile != null) {
            return profile.getContacts(type);
        }
        return Collections.emptyList();
    }

    private void simulateNetworkLatency() {
        try {
            Thread.sleep(2500);
        } catch (final InterruptedException ex) {
            ex.printStackTrace();
        }
    }

    private Profile findProfile(final String email) {
        for (final Profile profile : profiles) {
            if (profile.getEmail().equals(email)) {
                return profile;
            }
        }
        return null;
    }

    @Override
    public ProfileIterator createFriendsIterator(final String email) {
        return new FacebookIterator(this, "friends", email);
    }

    @Override
    public ProfileIterator createCoworkersIterator(final String email) {
        return new FacebookIterator(this, "coworkers", email);
    }
}
