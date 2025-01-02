package BellLaPadula;

public class Object{
    private String name;
    private SecurityLevel sensitivity;

    public Object(String name, SecurityLevel sensitivity){
        this.name = name;
        this.sensitivity = sensitivity;
    }

    public SecurityLevel getSensitivity(){
        return sensitivity;
    }

    public String getName(){
        return this.name;
    }

}