package BellLaPadula;

public class Subject {
    private String name;
    private SecurityLevel clearance;

    public Subject(String name, SecurityLevel clearance){
        this.name = name;
        this.clearance = clearance;
    }

    public String getName(){
        return this.name;
    }

    public SecurityLevel getClearance(){
        return this.clearance;
    }

}
