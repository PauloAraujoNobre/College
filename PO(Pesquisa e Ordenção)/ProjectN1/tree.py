class Node(object):
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left = None
        self.caminho = []

    def add(self, node):
        if node.value > self.value:
            if self.right is None:
                node.caminho.append("Direita  -> ")
                node.caminho.append("Encontrado")
                self.right = node
            else:
                node.caminho.append("Direita  -> ")
                self.right.add(node)

        elif node.value < self.value:
            if self.left is None:
                node.caminho.append("Esquerda  -> ")
                node.caminho.append("Encontrado")
                self.left = node
            else:
                node.caminho.append("Esquerda  -> ")
                self.left.add(node)



    def print_tree(self):
        print(self.value)
        if self.right is not None:
            self.right.print_tree()
        if self.left is not None:
            self.left.print_tree()

    def find_node(self, node, lista):
        new_lista = lista

        if self.value == node.value:
            new_lista.append("Encontrado")
            self.caminho = new_lista
        else:
            if self.right is not None and self.value < node.value:
                new_lista.append("Direita -> ")
                self.right.find_node(node, new_lista)

            elif self.left is not None and self.value > node.value:
                new_lista.append("Esquerda  -> ")
                self.left.find_node(node, new_lista)

            else:
                new_lista = []
                new_lista.append("Node não encontrado")
                self.caminho = new_lista

    def remover(self, node, matriz):
        if self.value == node.value:
            self.value = None
            self.right = None
            self.left = None

        elif self.right is not None and self.right.value == node.value:
            node_aux = self.right
            self.right = None
            node_aux.fix_remove(matriz)

        elif self.left is not None and self.left.value == node.value:
            node_aux = self.right
            self.left = None
            node_aux.fix_remove(matriz)

        elif self.right is not None and self.value < node.value:
            self.right.remover(node, matriz)

        elif self.left is not None and self.value > node.value:
            self.left.remover(node, matriz)

    def fix_remove(self, matriz):
        if self.right is not None:
            matriz.add(self.right)
            self.right.fix_remove(matriz)

        if self.left is not None:
            matriz.add(self.left)
            self.left.fix_remove(matriz)

