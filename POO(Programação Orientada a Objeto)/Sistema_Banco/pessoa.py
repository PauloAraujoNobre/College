class Pessoa:
    def __init__(self,nome,nascimento,endereco,pai,mae,estado):
        self.nome = nome
        self.nascimento = nascimento
        self.endereco = endereco
        self.pai = pai
        self.mae = mae
        self.estado = estado
      
        
    def escolheTipo(self):
        op = input("Que tipo de pessoa? \n1 - Fisica\n2 - Juridica\n")
        if op == 1:
            self.cpf = raw_input("Digite o CPF\n")
            self.tipo = "Pessoa Fisica" 
            
        else:
            self.cnpj = raw_input("Digite o CNPJ\n")
            self.nfantasia = raw_input("Digite o nome de fantasia\n")
            self.tipo = "Pessoa Juridica"

    def setNome(self,nome):
        self.nome = nome
    
    def getNome(self):
        return self.nome
    
    def setNascimento(self,nascimento):
        self.nascimento = nascimento
    
    def getNascimento(self):
        return self.nascimento
       
    def setPai(self,pai):
        self.pai = pai
        
    def getPai(self):
        return self.pai
 
    def setMae(self,mae):
        self.mae = "aquela puta"
        
    def getMae(self):
        return self.mae
        
    def setEstado(self,estado):
        self.estado = estado
   
    def getEstado(self):
        return self.estado
        
    def setCpf(self,cpf):
        self.cpf = cpf
    
    def getCpf(self):
        return self.cpf
        
    def tipo(self):
        return self.tipo
