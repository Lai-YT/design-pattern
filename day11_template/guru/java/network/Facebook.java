package network;


/**
 * Class of social network.
 */
public class Facebook extends Network {
    public Facebook(final String userName, final String password) {
        this.userName = userName;
        this.password = password;
    }

    @Override
    protected boolean logIn() {
        System.out.println("\nChecking user's parameters");
        System.out.println("Name: " + this.userName);
        System.out.print("Password: ");
        for (int i = 0; i < this.password.length(); i++) {
            System.out.print("*");
        }
        System.out.println();
        simulateNetworkLatency();
        System.out.println("\nLog in success on Facebook");
        return true;
    }

    @Override
    protected boolean sendData(final byte[] data) {
        boolean messagePosted = true;
        if (messagePosted) {
            System.out.println("Message '" + new String(data) + "' was posted on Facebook");
            return true;
        }
        return false;
    }

    @Override
    protected void logOut() {
        System.out.println("User '" + this.userName + "' was logged out from Facebook");
    }

    private void simulateNetworkLatency() {
        try {
            for (int i = 0; i < 10; i++) {
                System.out.print(".");
                Thread.sleep(500);
            }
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        }
    }
}
