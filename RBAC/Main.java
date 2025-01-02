package RBAC;

public class Main {
    public static void main(String[] args) {
        RBACSystem rbac = new RBACSystem();

        //Roles
        rbac.addRole("Admin");
        rbac.addRole("Manager");
        rbac.addRole("User");

        //Define permissions
        rbac.addPermissionToRole("Admin", "read");
        rbac.addPermissionToRole("Admin", "write");
        rbac.addPermissionToRole("Admin", "delete");

        rbac.addPermissionToRole("Manager", "read");
        rbac.addPermissionToRole("Manager", "write");

        rbac.addPermissionToRole("User", "read");

        rbac.addUser("Alice", "Admin");
        rbac.addUser("Bob", "Manager");
        rbac.addUser("Charlie", "User");

        System.out.println("Alice can delete: " + rbac.checkAccess("Alice", "delete")); // true
        System.out.println("Bob can write: " + rbac.checkAccess("Bob", "write"));       // true
        System.out.println("Charlie can delete: " + rbac.checkAccess("Charlie", "delete")); // false
    }
}

