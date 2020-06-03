from test_framework import generic_test
from test_framework.test_failure import TestFailure


class Queue:
    def __init__(self, capacity: int) -> None:
        self.items = [0] * capacity
        self.head = 0
        self.tail = 0
        self.sz = 0

    def enqueue(self, x: int) -> None:
        """
            [   ]
              h
              t
        """
        if self.sz == len(self.items):
            new_items = self.items[self.head:] + self.items[:self.head]
            self.items = new_items + [0] * len(new_items)
            self.head = 0
            self.tail = len(new_items)

        self.items[self.tail] = x
        self.tail = (self.tail + 1) % len(self.items)
        self.sz += 1

    def dequeue(self) -> int:
        ret = self.items[self.head]
        self.head = (self.head + 1) % len(self.items)
        self.sz -= 1
        return ret

    def size(self) -> int:
        return self.sz


def queue_tester(ops):
    q = Queue(1)

    for (op, arg) in ops:
        if op == 'Queue':
            q = Queue(arg)
        elif op == 'enqueue':
            q.enqueue(arg)
        elif op == 'dequeue':
            result = q.dequeue()
            if result != arg:
                raise TestFailure('Dequeue: expected ' + str(arg) + ', got ' +
                                  str(result))
        elif op == 'size':
            result = q.size()
            if result != arg:
                raise TestFailure('Size: expected ' + str(arg) + ', got ' +
                                  str(result))
        else:
            raise RuntimeError('Unsupported queue operation: ' + op)


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('circular_queue.py',
                                       'circular_queue.tsv', queue_tester))
