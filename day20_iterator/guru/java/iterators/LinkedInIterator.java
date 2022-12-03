package iterators;

import java.util.ArrayList;
import java.util.List;

import profile.Profile;
import social_networks.LinkedIn;

public class LinkedInIterator implements ProfileIterator {
    private final LinkedIn linkedIn;
    private final String type;
    private final String email;
    private final List<String> emails = new ArrayList<>();
    private final List<Profile> profiles = new ArrayList<>();
    private int currentPosition = 0;

    public LinkedInIterator(final LinkedIn linkedIn, final String type, final String email) {
        this.linkedIn = linkedIn;
        this.type = type;
        this.email = email;
    }

    private void lazyLoad() {
        if (emails.size() == 0) {
            for (final String contact : linkedIn.reuquestRelatedContactsFromLinkedIn(email, type)) {
                emails.add(contact);
                profiles.add(null);
            }
        }
    }

    @Override
    public boolean hasNext() {
        lazyLoad();
        return currentPosition < emails.size();
    }

    @Override
    public Profile getNext() {
        if (!hasNext()) {
            return null;
        }

        final String email = emails.get(currentPosition);
        Profile profile = profiles.get(currentPosition);
        if (profile == null) {
            profile = linkedIn.requestProfileFromLinkedIn(email);
            profiles.set(currentPosition, profile);
        }
        ++currentPosition;
        return profile;
    }

    @Override
    public void reset() {
        currentPosition = 0;
    }
}
