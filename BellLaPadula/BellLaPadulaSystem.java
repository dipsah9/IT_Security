package BellLaPadula;

public class BellLaPadulaSystem {
    // The Bell-LaPadula Model is a formal security model developed to maintain the confidentiality of
    // data in multi-level secure systems. It was designed for the U.S. Department of Defense to manage
    // classified information and prevent unauthorized access. The model enforces strict access controls
    // based on security levels and is defined by two main rules:

    public boolean canRead(Subject user, Object obj){
        return user.getClearance().ordinal() >= obj.getSensitivity().ordinal();
    }

    public boolean canWrite(Subject user, Object obj){
        return user.getClearance().ordinal() <= obj.getSensitivity().ordinal();
    }
    
}
