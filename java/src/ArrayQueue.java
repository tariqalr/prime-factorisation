
public class ArrayQueue<T> {
	private int head, tail;
	private int size, maxsize;
	private T[] array;
	
	@SuppressWarnings("unchecked")
	public ArrayQueue(int maxsize){
		head=0; tail=0;
		size=0; this.maxsize=maxsize;
		array=(T[]) new Object[maxsize];
	}
	
	public void enqueue(T data) {
		array[tail]=data;
		tail=(tail+1)%maxsize;
		size++;
	}
	
	public T serve() {
		T data = array[head];
		head=(head+1)%maxsize;
		size--;
		return data;
	}
	public boolean empty() {
		return size==0;
	}
}
