import { LinkedList, Stack, Queue } from "./linked-list";

const queue: Queue<number> = new LinkedList();

queue.add(1);
queue.add(2);
queue.add(3);

while (!queue.isEmpty()) {
    console.log(queue.poll());
}


const stack: Stack<number> = new LinkedList();

stack.push(1);
stack.push(2);
stack.push(3);

while (!stack.isEmpty()) {
    console.log(stack.pop());
}