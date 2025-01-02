package RBAC;

public class User {
    private String name;
    private Role role;

    //Constructor for role
    public User(String name, Role role){
        this.name = name;
        this.role = role;
    }


    public String getName(){
        return this.name;
    }

    public void setRole(Role role){
         this.role  = role;
    }

    public Role getRole(){
        return role;
    }
}
