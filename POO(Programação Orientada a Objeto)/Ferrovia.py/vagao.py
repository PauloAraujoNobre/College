class Vagao:
    def __init__(self, numeroDeSerie, tipo, capacidadeDeCarga, comprimentoEntreTesteiras, comprimentoDosEngates):
        self.numeroDeSerie = numeroDeSerie
        self.tipo = tipo
        self.capacidadeDeCargaAtual = capacidadeDeCarga
        self.capacidadeDeCargaLimite = capacidadeDeCarga
        self.comprimentoEntreTesteiras = comprimentoEntreTesteiras
        self.comprimentoDosEngates = comprimentoDosEngates

    def carregar(self, valor):
        if(valor > self.capacidadeDeCargaAtual):
            print('O vagão não suporta esse valor!')
            print('Procedimento não sucedido')
            print('capacidade Atual: %d'.format(self.capacidadeDeCargaAtual))
            print('capacidade Limite: %d'.format(self.capacidadeDeCargaLimite))
        else:
            self.capacidadeDeCargaAtual -= valor
            print('Procedimento sucedido')

    def descarregar(self, valor):
        if((self.capacidadeDeCargaAtual + valor) > self.capacidadeDeCargaLimite):
            print('O vagã não possuia essa quantidade de carga!')
            print('Procedimento sucedido')
            print('capacidade Atual: %d'.format(self.capacidadeDeCargaAtual))
            print('capacidade Limite: %d'.format(self.capacidadeDeCargaLimite))
        else:
            self.capacidadeDeCargaAtual += valor
            print('Procedimento sucedido')
            print('capacidade Atual: %d'.format(self.capacidadeDeCargaAtual))
            print('capacidade Limite: %d'.format(self.capacidadeDeCargaLimite))

    def descarregar(self):
        self.capacidadeDeCargaAtual = self.capacidadeDeCargaLimite
        print('Procedimento sucedido')
        print('capacidade Atual: %d'.format(self.capacidadeDeCargaAtual))
        print('capacidade Limite: %d'.format(self.capacidadeDeCargaLimite))
