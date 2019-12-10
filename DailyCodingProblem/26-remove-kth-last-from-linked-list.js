class Node {
  static gen(n) {
    const root = new Node()
    let it = root
    for (let i = 1; i < n; i += 1) {
      const next = new Node()
      it.next = next
      it = it.next
    }
    return root
  }

  constructor() {
    this.value = Node.autoId++
    this.next = null
  }

  remove(k) {
    let it = this
    let length = 0
    while (it) {
      length++
      it = it.next
    }
    let indexToRemove = length - k - 1
    it = this
    while (indexToRemove) {
      it = it.next
      indexToRemove--
    }
    it.next = it.next.next
  }

  toString() {
    let str = ""
    let it = this
    while (it) {
      str += `${it.value}`
      if (it.next) {
        str += " -> "
      }
      it = it.next
    }
    return str
  }
}

Node.autoId = 0

const example = Node.gen(5)
console.log(example.toString())
example.remove(1)
console.log(example.toString())
example.remove(3)
console.log(example.toString())
