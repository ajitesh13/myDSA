
abstract class Animal {
    final void bark() {
        System.out.println("Dog");
    }

    abstract void jump(); // Abstract Method (Pure Virtual Function)
}

class MyPet extends Animal {
    void jump() {
        System.out.println("MyPet is so sweet");
    }
}

public class pureVirtualFunction {
    public static void main(String args[]) {
        Animal ob1 = new MyPet();
        ob1.jump();
    }
}