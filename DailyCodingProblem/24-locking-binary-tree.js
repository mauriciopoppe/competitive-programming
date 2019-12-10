class Node {
  static gen(n) {
    const arr = []
    for (let i = 0; i < n; i += 1) {
      arr.push(new Node)
    }
    for (let i = 0; i < n; i += 1) {
      const node = arr[i]
      if (i * 2 + 1 < n) node.left = arr[i * 2 + 1].link(node)
      if (i * 2 + 2 < n) node.right = arr[i * 2 + 2].link(node)
    }
    return arr[0]
  }

  constructor() {
    this.id = Node.autoId++
    this.locked = false
    this.left = null
    this.right = null
    this.parent = null
  }

  link(parent) {
    this.parent = parent
    return this
  }

  toString() {
    return `id(${this.id}) locked(${this.locked})`
  }

  print(level = 0) {
    let r = Array(level * 2).join(' ')
    r += this.toString() + '\n'
    if (this.left) r += this.left.print(level + 1)
    if (this.right) r += this.right.print(level + 1)
    return r
  }

  isLocked() {
    return !!(this.checkLockParent() || this.checkLockChild())
  }

  checkLockParent() {
    if (this.locked) return true
    if (this.parent) return this.parent.checkLockParent()
  }

  checkLockChild() {
    if (this.locked) return true
    if (this.left && this.left.checkLockChild()) return true
    if (this.right && this.right.checkLockChild()) return true
  }
}

function assert(result, expected) {
  if (result !== expected) {
    console.log(`expected ${expected}, got ${result}`)
  }
}

Node.autoId = 1

const root = Node.gen(15)
console.log(root.print())
assert(root.isLocked(), false)

// lock node 4
root.left.left.locked = true
console.log(root.print())
assert(root.isLocked(), true)
assert(root.right.isLocked(), false)

// lock node 6
root.right.left.locked = true
console.log(root.print())
assert(root.isLocked(), true)
assert(root.right.right.isLocked(), false)
