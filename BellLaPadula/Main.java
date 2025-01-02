package BellLaPadula;
public class Main {
    public static void main(String[] args) {
        
        Subject alice = new Subject("Alice", SecurityLevel.TOP_SECRET);
        Subject bob = new Subject("Bob", SecurityLevel.CONFIDENTIAL);

       
        Object file1 = new Object("File1", SecurityLevel.SECRET);
        Object file2 = new Object("File2", SecurityLevel.UNCLASSIFIED);

        BellLaPadulaSystem system = new BellLaPadulaSystem();

        // Test "No Read Up"
        System.out.println("Can Alice read File1? " + system.canRead(alice, file1)); // true
        System.out.println("Can Bob read File1? " + system.canRead(bob, file1));   // false

        // Test "No Write Down"
        System.out.println("Can Alice write to File2? " + system.canWrite(alice, file2)); // false
        System.out.println("Can Bob write to File2? " + system.canWrite(bob, file2));   // true
    }
}
