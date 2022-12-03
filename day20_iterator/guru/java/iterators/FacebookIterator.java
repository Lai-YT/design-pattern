package iterators;

import java.util.ArrayList;
import java.util.List;

import social_networks.Facebook;
import profile.Profile;

public class FacebookIterator implements ProfileIterator {
    private final Facebook facebook;
    private final String type;
    private final String email;
    private final List<String> emails = new ArrayList<>();
    private final List<Profile> profiles = new ArrayList<>();
    private int currentPosition = 0;

    public FacebookIterator(final Facebook facebook, final String type, final String email) {
        this.facebook = facebook;
        this.type = type;
        this.email = email;
    }

    private void lazyLoad() {
        if (emails.size() == 0) {
            for (final String contact : facebook.requestRelatedContactsFromFacebook(email, type)) {
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
            profile = facebook.requestProfileFromFacebook(email);
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
