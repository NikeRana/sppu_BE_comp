class Node:
    def __init__(self, freq_, symbol_, left_=None, right_=None):
        self.freq = freq_
        self.symbol = symbol_
        self.left = left_
        self.right = right_
        self.huff = ""

def print_nodes(node, val=""):
    new_val = val + str(node.huff)
    if node.left:
        print_nodes(node.left, new_val)
    if node.right:
        print_nodes(node.right, new_val)
    if not node.left and not node.right:
        print(f"{node.symbol} -> {new_val}")

chars = ["a", "b", "c", "d", "e", "f"]
freq = [50, 10, 30, 5, 3, 2]
nodes = [Node(freq[x], chars[x]) for x in range(len(chars))]

while len(nodes) > 1:
    nodes = sorted(nodes, key=lambda x: x.freq)
    left = nodes[0]
    right = nodes[1]
    left.huff = 0
    right.huff = 1
    newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
    nodes.remove(left)
    nodes.remove(right)
    nodes.append(newNode)

print("Characters :", f'[{", ".join(chars)}]')
print("Frequency  :", freq, "\n\nHuffman Encoding:")
print_nodes(nodes[0])

"""
1.Time complexity:
initial list of nodes takes O(N)
while loops that constructs huffman tree takes O(n*log(n))

2.Space Complexity
The node list which holds objects cosumes O(n)
Recursive function calls in print nodes use call stack O(log(n))
"""