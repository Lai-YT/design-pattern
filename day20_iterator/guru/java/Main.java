import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import profile.Profile;
import social_networks.Facebook;
import social_networks.LinkedIn;
import social_networks.SocialNetwork;
import spammer.SocialSpammer;

public class Main {
    public static final Scanner scanner = new Scanner(System.in);

    public static void main(final String[] args) {
        System.out.println("Please specify social network to target spam tool (default: Facebook):");
        System.out.println("1. Facebook");
        System.out.println("2. LinkedIn");
        final int choice = scanner.nextInt();

        final SocialNetwork network;
        if (choice == 1) {
            network = new Facebook(createTestProfiles());
        } else if (choice == 2) {
            network = new LinkedIn(createTestProfiles());
        } else {
            network = new Facebook(createTestProfiles());
        }

        final SocialSpammer spammer = new SocialSpammer(network);
        spammer.sendSpamToFriends("anna.smith@bing.com",
                "Hey! This is Anna's friend Josh. Can you do me a favor and like this post [link]?");
        spammer.sendSpamToCoworkers("anna.smith@bing.com",
                "Hey! This is Anna's boss Jason. Anna told me you would be interested in [link].");
    }

    private static List<Profile> createTestProfiles() {
        final List<Profile> testProfiles = new ArrayList<>();
        testProfiles.add(new Profile("anna.smith@bing.com", "Anna Smith", "friends:mad_max@ya.com",
                "friends:catwoman@yahoo.com", "coworkers:sam@amazon.com"));
        testProfiles.add(
                new Profile("mad_max@ya.com", "Maximilian", "friends:anna.smith@bing.com", "coworkers:sam@amazon.com"));
        testProfiles.add(new Profile("bill@microsoft.eu", "Billie", "coworkers:avanger@ukr.net"));
        testProfiles.add(new Profile("avanger@ukr.net", "John Day", "coworkers:bill@microsoft.eu"));
        testProfiles.add(new Profile("sam@amazon.com", "Sam Kitting", "coworkers:anna.smith@bing.com",
                "coworkers:mad_max@ya.com", "friends:catwoman@yahoo.com"));
        testProfiles.add(
                new Profile("catwoman@yahoo.com", "Liza", "friends:anna.smith@bing.com", "friends:sam@amazon.com"));
        return testProfiles;
    }
}
