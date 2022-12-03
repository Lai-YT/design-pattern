package social_networks;

import iterators.ProfileIterator;

public interface SocialNetwork {
    ProfileIterator createFriendsIterator(final String email);

    ProfileIterator createCoworkersIterator(final String email);
}
