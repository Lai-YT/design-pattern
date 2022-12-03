package social_networks;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import iterators.ProfileIterator;
import iterators.LinkedInIterator;
import profile.Profile;

public class LinkedIn implements SocialNetwork {
    private final List<Profile> profiles;

    public LinkedIn(final List<Profile> cache) {
        this.profiles = cache;
    }

    public LinkedIn() {
        this(new ArrayList<Profile>());
    }

    public Profile requestProfileFromLinkedIn(final String email) {
        // Here would be a POST request to one of the LinkedIn API endpoints.
        // Instead, we emulates long network connection, which you would expect
        // in the real life...
        simulateNetworkLatency();
        System.out.format("LinkedIn: Loading profile '%s' over the network...\n", email);

        // ...and return test data.
        return findProfile(email);
    }

    public List<String> reuquestRelatedContactsFromLinkedIn(final String email, final String type) {
        simulateNetworkLatency();
        System.out.format("LinkedIn: Loading '%s' list of '%s' over the network...\n", type, email);

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
        return new LinkedInIterator(this, "friends", email);
    }

    @Override
    public ProfileIterator createCoworkersIterator(final String email) {
        return new LinkedInIterator(this, "coworkers", email);
    }
}
