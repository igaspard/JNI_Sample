public class HelloJNI
{
    native void printHello();
    native void printString(String str);

    static
    {
        System.loadLibrary("hellojni");
    }

    public static void main(String[] args)
    {
        HelloJNI myjni = new HelloJNI();

        myjni.printHello();
        myjni.printString("Hello world from Java printString()");
    }
}
