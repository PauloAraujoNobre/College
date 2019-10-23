class Conta:
    def __init__(self,cliente , saldo, numero,qualBanco):
        self.cliente = cliente
        self.saldo = saldo
        self.numero = numero
        self.qualBanco = qualBanco
        
    def getSaldo(self):
        return self.saldo
    
    def setSaldo(self, saldo):
        self.saldo  = saldo
        
    def getNumero(self):
        return self.numero
    
    def setNumero(self):
        self.numero = numero
    
    def sacar(self,quantidade):
        if self.saldo < quantidade:
            print("Saldo nao suficiente")
        else:
            self.saldo = self.saldo - quantidade
            print("Saque de {} reais relizado.".format(quantidade))
            
    
    def depositar(self,quantidade):
        self.saldo += quantidade
        print("Deposito de {} golpes realizado.".format(quantidade))

        
        
        
