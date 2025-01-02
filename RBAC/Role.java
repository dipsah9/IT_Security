package RBAC;
import java.util.HashSet;
import java.util.Set;


public class Role{
    //ATTRIBUTES 
    private String name;
    private Set<String> permissions;

    public Role(String name){
        this.name = name;
        this.permissions = new HashSet<>();
    }

    public void addPermissions(String permission){
        permissions.add(permission);
    }
    
    public boolean hasPermissions(String permission){
        return permissions.contains(permission);
    }

    public String getName(){
        return this.name;
    }

    public Set<String> getPermissions(){
        return permissions;
    }
}