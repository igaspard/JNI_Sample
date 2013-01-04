public class HelloJNI
{
    // native means these method only declare.
    // It will be implemented by C/C++.
    native void printHello();
    native void printString(String str);

    // Load DLL in windows, load *.so in linux.
    static
    {
        System.loadLibrary("hellojni");
    }

    public static void main(String[] args)
    {
        HelloJNI myjni = new HelloJNI();

        myjni.printHello();
        myjni.printString("Hello World from Java printString()");
    }
}
