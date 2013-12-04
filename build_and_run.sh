#!/bin/sh
JNI_LIB="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers"
rm -rf *.class *.dylib
javac NativeStack.java Main.java
javah NativeStack
gcc -dynamiclib -o libnative.dylib -I$JNI_LIB NativeStack.c -framework JavaVM
java -Djava.library.path=. Main a bc def ghij klmno pqrstu vwxyz
