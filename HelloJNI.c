#include "HelloJNI.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_HelloJNI_printString(JNIEnv *env, jobject obj, jstring string)
{
    // Java string convert to C string.
    const char *str = (*env)->GetStringUTFChars(env, string, 0);
    printf(str);

    return;
}

JNIEXPORT void JNICALL Java_HelloJNI_printHello(JNIEnv *env, jobject obj)
{
    printf("Hello World at C!\n");
    return;
}
