package RBAC;
import java.util.*;

class RBACSystem {
    private Map<String, Role> roles;
    private Map<String, User> users;

    public RBACSystem() {
        roles = new HashMap<>();
        users = new HashMap<>();
    }

    public void addRole(String roleName) {
        roles.put(roleName, new Role(roleName));
    }

    public void addPermissionToRole(String roleName, String permission) {
        Role role = roles.get(roleName);
        if (role != null) {
            role.addPermissions(permission);
        } else {
            System.out.println("Role not found: " + roleName);
        }
    }

    public void addUser(String userName, String roleName) {
        Role role = roles.get(roleName);
        if (role != null) {
            users.put(userName, new User(userName, role));
        } else {
            System.out.println("Role not found: " + roleName);
        }
    }

    public boolean checkAccess(String userName, String permission) {
        User user = users.get(userName);
        if (user != null) {
            return user.getRole().hasPermissions(permission);
        }
        return false;
    }
}
