import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class NativeStack<T extends Serializable> {
	public void push(T elem) throws IOException {
		ByteArrayOutputStream bao = new ByteArrayOutputStream();
		new ObjectOutputStream(bao).writeObject(elem);
		byte[] data = bao.toByteArray();
		nativePush(data, data.length);
		bao.close();
	}

	public T get() throws IOException, ClassNotFoundException {
		ByteArrayInputStream bai = new ByteArrayInputStream(nativeGet());
		T elem = (T) (new ObjectInputStream(bai).readObject());
		bai.close();
		return elem;
	}

	public T pop() throws IOException, ClassNotFoundException {
		T elem = get();
		nativePop();
		return elem;
	}

	public boolean isEmpty() {
		return nativeIsEmpty();
	}

	private native void nativePush(byte[] data, int len);
	private native byte[] nativeGet();
	private native void nativePop();
	private native boolean nativeIsEmpty();
}
