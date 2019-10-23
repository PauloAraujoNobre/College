public class CarroDeConcessionaria extends Carro{
	private double valor;
	
	public CarroDeConcessionaria(String modelo, String marca, String ano, Pessoa proprietario, String chassi, double valor){
		super(modelo, marca, ano, proprietario, chassi);
		this.valor = valor;
	}
	
	public double getValor(){
		return this.valor;
	}
}

