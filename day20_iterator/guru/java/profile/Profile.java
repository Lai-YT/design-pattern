package profile;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Profile {
    private final String name;
    private final String email;
    private final Map<String, List<String>> contacts = new HashMap<>();

    public Profile(final String email, final String name, final String... contacts) {
        this.email = email;
        this.name = name;
        addContacts(contacts);
    }

    /**
     * @param contacts In the form "sometype:example@email.com".
     */
    private void addContacts(final String... contacts) {
        for (final String contact : contacts) {
            final String[] parts = contact.split(":");
            final String contactType = parts[0];
            final String contactEmail = parts[1];
            if (!this.contacts.containsKey(contactType)) {
                this.contacts.put(contactType, new ArrayList<>());
            }
            this.contacts.get(contactType).add(contactEmail);
        }
    }

    public String getEmail() {
        return email;
    }

    public String getName() {
        return name;
    }

    public List<String> getContacts(final String type) {
        if (!this.contacts.containsKey(type)) {
            return Collections.emptyList();
        }
        return this.contacts.get(type);
    }
}
