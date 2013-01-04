#include <stdio.h>
#include "jni.h"

void printHelloNative (JNIEnv *env, jobject obj);
void printStringNative(JNIEnv *env, jobject obj, jstring string);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv *env = NULL;
    JNINativeMethod nm[2];
    jclass cls;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        printf("Error");
        return JNI_ERR;
    }

    cls = env->FindClass("HelloJNI");

    nm[0].name = "printHello";  //Use this name to connect with java native function.
    nm[0].signature = "()V";
    nm[0].fnPtr = (void *) printHelloNative;

    nm[1].name = "printString";
    nm[1].signature = "(Ljava/lang/String;)V";
    nm[1].fnPtr = (void *) printStringNative;

    env->RegisterNatives(cls, nm, 2);

    return JNI_VERSION_1_4;
}

void printHelloNative (JNIEnv *env, jobject obj)
{
    printf("Hello World at C Navite\n");
   
    return;
}

void printStringNative(JNIEnv *env, jobject obj, jstring string)
{
    const char *str = env->GetStringUTFChars(string, 0);
    printf("%s\n", str);

    return;
}
