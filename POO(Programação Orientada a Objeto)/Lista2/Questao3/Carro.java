public class Carro{
	private String modelo;
	private String marca;
	private String ano;
	private Pessoa proprietario;
	private String chassi;
	private double velocidade = 0;	
	private double tank = 100;

	public Carro(String modelo, String marca, String ano, Pessoa proprietario, String chassi){
		this.modelo = modelo;
		this.marca = marca;
		this.ano = ano;
		this.proprietario = proprietario;
		this.chassi = chassi;
	}

	public String getModelo(){
		return this.modelo;
	}

	public String getMarca(){
		return this.marca;
	}

	public String getAno(){
		return this.ano;
	}

	public Pessoa getProprietario(){
		return this.proprietario;
	}
	
	public String getChassi(){
		return this.chassi;
	}


	public void acelerar(double valor){
		System.out.println("O carro estava andando a " + this.velocidade + "km/h");
		this.velocidade += valor;
		System.out.println("Velocidade atual: " + this.velocidade);
	}
	public void freiar(double valor){
		System.out.println("O carro estava andando a " + valor + "km/h");
		this.velocidade -= valor;
		if(this.velocidade < 0){
			this.velocidade = 0;
		}
		System.out.println("Velocidade atual: " + this.velocidade);
	}
	public void abastecer(double valor){
		System.out.println("O tank tinha " + this.tank + " Litros");
		this.tank += valor;
		System.out.println("O tank tem agora " + this.tank + " Litros");
	}
}
