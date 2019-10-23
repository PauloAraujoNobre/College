public class Empresa{
	private String razao;
	private String nome;
	private String logradouro;
	private String numero;
	private String bairro;
	private String cidade;
	private String UF;
	
	public Empresa(String nome, String razao, String logradouro, String numero, String bairro, String cidade, String UF){
		this.nome = nome;
		this.razao = razao;
		this.logradouro = logradouro;
		this.numero = numero;
		this.bairro = bairro;
		this.cidade = cidade;
		this.UF = UF;
	}
	
	public String getNome(){
		return this.nome;
	}	
	
	public String getRazao(){
		return this.razao;
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
