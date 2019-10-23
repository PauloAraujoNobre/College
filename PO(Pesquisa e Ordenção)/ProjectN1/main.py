from tree import Node
import os

global tree

def clear():
    space = "\n"
    print(20 * space)


def menu():
    print("===================================================")
    print("1. Criar árvore")
    print("2. Adicionar node")
    print("3. Remover node")
    print("4. Encontrar node")
    print("5. Printar árvore")
    print("6. Sair")
    print("===================================================")
    op = int(input())
    clear()
    return op

def cria_arvore(tree):
    if tree is not None:
        print("A árvore ja foi criada")
    else:
        inicial_value = int(input("Valor inicial parar a árvore: "))
        return Node(inicial_value)

def add_node(tree, node):
    lis_node = node
    num_node = int(input("Quantidade de elementos a adicionar: "))
    for i in range(num_node):
        value = int(input("Digite os valores: "))
        lis_node.append(Node(value))
        tree.add(Node(value))

    return lis_node

def remove_node(tree, node):
    list_node = node
    value = int(input("Valor do node a ser removido: "))
    for i in range(len(list_node)):
        if list_node[i].value == value:
            tree.remover(list_node[i], tree)
            list_node = fix_tree(list_node, list_node[i])
    return list_node

def fix_tree(list_node, node):
    tam = len(list_node)
    new_list_node = list_node
    for i in range(tam):
        if new_list_node[i].value == node.value:
            while(i < tam - 1):
                new_list_node[i] = new_list_node[i+1]
                i = i + 1
    return new_list_node

def encontra_node(node):
    list_node = node
    value = int(input("Valor do node a ser procurado: "))
    for i in range(len(list_node)):
        if list_node[i].value == value:
            print(list_node[i].caminho)

if __name__ == '__main__':

    tree = None
    node = []
    op = True
    clear()
    while(op != 6):
        op = menu()

        if op == 1:
            tree = cria_arvore(tree)

        if op == 2:
            node = add_node(tree, node)

        if op == 3:
            node = remove_node(tree, node)

        if op == 4:
            node = encontra_node(node)

        if op == 5:
            tree.print_tree()





