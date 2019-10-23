class main{
	public static void main(String[] args){
		//Pessoa
		Aluno a1 = new Aluno("Paulo", "11122233344", "14/10/1999", "Cantor Carlos Augusto", "105", "Antonio Bezerra", "Fortaleza", "Ceara");

		System.out.println("Nome: " + a1.getNome());
		System.out.println("CPF: " + a1.getCpf());
		System.out.println("Data de Nascimento: " + a1.getDataNasc());
		System.out.println("Logradouro: " + a1.getLogradouro());
		System.out.println("Numero: " + a1.getNumero());
		System.out.println("Bairro: " + a1.getBairro());
		System.out.println("Cidade: " + a1.getCidade());
		System.out.println("UF: " + a1.getUF());
		System.out.println("");
		
		//Aluno
		a1.setMatricula("20181015020381");
		a1.setInstituicao("IFCE");

		System.out.println("Matricula: " + a1.getMatricula());
		System.out.println("Instituição: " + a1.getInstituicao());				
		System.out.println("");

		//Funcionario
		Funcionario f1 = new Funcionario("Paulo", "11122233344", "14/10/1999", "Cantor Carlos Augusto", "105", "Antonio Bezerra", "Fortaleza", "Ceara", "Gerente", 1600);

		System.out.println("Cargo: " + f1.getCargo());
		System.out.println("Salário: " + f1.getSalario());
		System.out.println("");		
	
		//Carro
		Carro c1 = new Carro("Lymozini", "CarroTop", "2019", a1, "Chassi");

		System.out.println("Modelo: " + c1.getModelo());
		System.out.println("Marca: " + c1.getMarca());
		System.out.println("Ano: " + c1.getAno());
		System.out.println("Proprietario: " + c1.getProprietario());
		System.out.println("Chassi: " + c1.getChassi());
		System.out.println("");

		c1.acelerar(50);
		c1.freiar(10);
		c1.abastecer(20);
		System.out.println("");
	
		//Concessionaria
		Concessionaria c2 = new Concessionaria("Fiat", "Venda de carros", "Bezerra", "616", "Pici", "Fortaleza", "Ceara");

		System.out.println("Nome de fantasia: " + c2.getNome());
		System.out.println("Razão Social: " + c2.getRazao());
		System.out.println("Logradouro: " + c2.getLogradouro());
		System.out.println("Numero: " + c2.getNumero());
		System.out.println("Bairro: " + c2.getBairro());
		System.out.println("Cidade: " + c2.getCidade());
		System.out.println("UF: " + c2.getUF());
		System.out.println("");
		
		//CarroDeConcessionaria
		Carro c3 = new Carro("Toro", "CarroPilca", "2020", a1, "Chassi", "2000");
	
		System.out.println("Modelo: " + c3.getModelo());
		System.out.println("Marca: " + c3.getMarca());
		System.out.println("Ano: " + c3.getAno());
		System.out.println("Proprietario: " + c3.getProprietario());
		System.out.println("Chassi: " + c3.getChassi());
		System.out.println("Valor de venda: " + c3.getValor());		
		System.out.println("");
		
		//Empresa
		Empresa e1 = new Empresa("BigBom", "Vendas", "Travessa São Vicente", "115", "Antonio Bezerra", "Fortaleza", "Ceara");

		System.out.println("Nome de fantasia: " + e1.getNome());
		System.out.println("Razão Social: " + e1.getRazao());
		System.out.println("Logradouro: " + e1.getLogradouro());
		System.out.println("Numero: " + e1.getNumero());
		System.out.println("Bairro: " + e1.getBairro());
		System.out.println("Cidade: " + e1.getCidade());
		System.out.println("UF: " + e1.getUF());
		System.out.println("");
		

		//VendedorDeConcessionaria
		VendedorDeConcessionaria v1 = new VendedorDeConcessionaria("Paulo", "11122233344", "14/10/1999", "Cantor Carlos Augusto", "105", "Antonio Bezerra", "Fortaleza", "Ceara", "Gerente", 1600, 0);

		System.out.println("Comissao atual: " + v1.getComissao());
		System.out.println("");

		v1.vender(c3);
		System.out.println("Comissao atual: " + v1.getComissao());
		System.out.println("");
				
	}	
}
