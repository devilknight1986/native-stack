#!/bin/sh
rm -rf *.class *.dylib
javac NativeStack.java Main.java
javah NativeStack
gcc -dynamiclib -o libnative.dylib "-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers" NativeStack.c -framework JavaVM
java -Djava.library.path=. Main a bc def ghij klmno pqrstu vwxyz
