public class Main {
	public static void main(String[] argv) throws Exception {
		System.loadLibrary("native");
		NativeStack<String> stack = new NativeStack<String>();
		for(String s: argv)
			stack.push(s);
		while(!stack.isEmpty())
			System.out.println(stack.pop());
	}
}
