#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NativeStack.h"

typedef struct elem_struct {
    char* data;
    int length;
    struct elem_struct* next;
} *elem;

elem head = NULL;

void addElemToFirst(char* data, int length) {
    elem new_elem = malloc(sizeof(sizeof(struct elem_struct)));
    new_elem->length=length;
    new_elem->data=data;
    new_elem->next=head;
    head = new_elem;
}

void deleteFirstElem() {
    if(head == NULL)
        return;
    elem new_head=head->next;
    free(head->data);
    free(head);
    head = new_head;
}

/*
 * Class:     NativeStack
 * Method:    nativePush
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_NativeStack_nativePush
(JNIEnv *env, jobject self, jbyteArray data, jint len){
    jboolean isCopy = JNI_FALSE;
    jbyte* array = (*env) -> GetByteArrayElements(env, data, &isCopy);
    char* elem_data = (char*)malloc(len * sizeof(char));
    memcpy(elem_data, array, len);
    addElemToFirst(elem_data, len);
    (*env) -> ReleaseByteArrayElements(env, data, array, JNI_ABORT);
};

/*
 * Class:     NativeStack
 * Method:    nativeGet
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_NativeStack_nativeGet
(JNIEnv *env, jobject self) {
    if(head == NULL) return NULL;
    jbyteArray array = (*env)->NewByteArray(env, head->length);
    (*env)->SetByteArrayRegion(env,array,0, head->length, (jbyte*)head->data);
    return array;
};

/*
 * Class:     NativeStack
 * Method:    nativePop
 * Signature: ()[B
 */
JNIEXPORT void JNICALL Java_NativeStack_nativePop
(JNIEnv *env, jobject self){
    deleteFirstElem();
};

/*
 * Class:     NativeStack
 * Method:    nativeIsEmpty
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_NativeStack_nativeIsEmpty
(JNIEnv *env, jobject self){
    return head == NULL;
};


