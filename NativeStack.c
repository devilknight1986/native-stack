#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NativeStack.h"

char* elem = NULL;
int lenght = 0;
/*
 * Class:     NativeStack
 * Method:    nativePush
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_NativeStack_nativePush
(JNIEnv *env, jobject self, jbyteArray data, jint len){
    jboolean isCopy = JNI_FALSE;
    jbyte* array = (*env) -> GetByteArrayElements(env, data, &isCopy);
    free(elem);
    elem = NULL;
    lenght = 0;
    elem = malloc(len * sizeof(char));
    memcpy(elem, array, len);
    lenght = len;
    (*env) -> ReleaseByteArrayElements(env, data, array, JNI_ABORT);
};

/*
 * Class:     NativeStack
 * Method:    nativeGet
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_NativeStack_nativeGet
(JNIEnv *env, jobject self) {
    if(elem == NULL) return NULL;
    jbyteArray array = (*env)->NewByteArray(env, lenght);
    (*env)->SetByteArrayRegion(env,array,0,lenght, (jbyte*)elem);
    return array;
};

/*
 * Class:     NativeStack
 * Method:    nativePop
 * Signature: ()[B
 */
JNIEXPORT void JNICALL Java_NativeStack_nativePop
(JNIEnv *env, jobject self){
    elem = NULL;
};

/*
 * Class:     NativeStack
 * Method:    nativeIsEmpty
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_NativeStack_nativeIsEmpty
(JNIEnv *env, jobject self){
    return elem == NULL;
};


