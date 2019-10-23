public class Funcionario extends Pessoa{
	private String cargo;
	private double salario;

	public Funcionario(String nome, String cpf, String dataNasc, String logradouro, String numero, String bairro, String cidade, String cidade, String UF, String cargo, double salario){
		super(nome, cpf, dataNasc, logradouro, numero, bairro, cidade,cidade, UF);
		this.cargo = cargo;
		this.salario = salario;
	}

	public String getCargo(){
		return this.cargo;
	}

	public double getSalario(){
		return this.salario;
	}
}
