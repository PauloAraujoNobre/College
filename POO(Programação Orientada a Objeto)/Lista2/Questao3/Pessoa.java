public class Pessoa{
	private String nome;
	private String cpf;
	private String dataNasc;
	private String logradouro;
	private String numero;
	private String bairro;
	private String cidade;
	private String UF;

	public Pessoa(String nome, String cpf, String dataNasc, String logradouro, String numero, String bairro, String cidade, String cidade, String UF){
		this.nome = nome;
		this.cpf = cpf;
		this.dataNasc = dataNasc;
		this.logradouro = logradouro;
		this.numero = numero;
		this.bairro = bairro;
		this.cidade = cidade;
		this.UF = UF;
	}


	public String getNome(){
		return this.nome;
	}

	public String getCpf(){
		return this.cpf;
	}

	public String getDataNasc(){
		return this.dataNasc;
	}

	public String getLogradouro(){
		return this.logradouro;
	}

	public String getNumero(){
		return this.numero;
	}

	public String getBairro(){
		return this.bairro;
	}

	public String getCidade(){
		return this.cidade;
	}

	public String getUF(){
		return this.UF;
	}
}
