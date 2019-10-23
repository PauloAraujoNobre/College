public class Cartao{
	
	private String nomeTitular;
	private String numero;
	private int codigoSeguranca;
	private double limiteTotal;
	private double limiteAtual;
	
	public void setNomeTitular(String nomeTitular){
		this.nomeTitular = nomeTitular;
	}
	public String getNomeTitular(){
		return nomeTitular;
	}
	
	public void setNumero(String numero){
		this.numero = numero;
	}
	public String getNumero(){
		return numero;
	}	
	
	public void setCodigoSeguranca(int codigoSeguranca){
		this.codigoSeguranca = codigoSeguranca;
	}
	public int getCodigoSeguranca(){
		return codigoSeguranca;
	}
	
	public void setLimiteTotal(double limiteTotal){
		this.limiteTotal = limiteTotal;
		this.limiteAtual = this.limiteTotal;
	}
	public double getLimiteTotal(){
		return limiteTotal;
	}
	
	public double getLimiteAtual(){
		return limiteAtual;
	}
	
	public void realizaCompra(double valor){
		if(valor > this.limiteAtual){
			System.out.println("Limite excedido");
		}else{
			limiteAtual -= valor;
			System.out.println("Seu limite atual é: R$ " + this.limiteAtual + "\n");
		}
	}
	
	public void realizaPagamento(double valor){
		double troco = (this.limiteAtual + valor) - this.limiteTotal;
		if((this.limiteAtual + valor) > this.limiteTotal){
			this.limiteAtual = this.limiteTotal;
			System.out.println("Seu limite atual excede o limite máximo! \nSeu troco: " + troco);
		}else{
			this.limiteAtual += valor;
		}
		System.out.println("Pagamento realizado com sucesso!\n");
	}
	
	public void aumentaLimite(double valor){
		limiteTotal += valor;
		System.out.println("Seu novo limite máximo é: R$ " + this.limiteTotal + "\n");
	}
	
	public void realizaPagamento(){
		this.limiteAtual = this.limiteTotal;
	}	
	public String toString(){
		String str = "";
		str = str + "*--------------------------------------*\n";
		str = str + "Nome do titular: " + this.nomeTitular + "\n";
		str=  str + "Numero do cartão: " + this.numero + "\n";
		str = str + "Codigo de segurança: " + this.codigoSeguranca + "\n";
		str = str + "Limite: R$ " + this.limiteTotal + "\n";
		str = str + "*--------------------------------------*\n";
		
		return str;
	}
	
}


import java.util.Scanner;
import static java.lang.System.out;

public class UsandoCartao{
	public static void main(String[] args){
		
		Cartao c1 = new Cartao();
		Scanner input = new Scanner(System.in);
		
		out.println("Insira o nome do titular: ");
		String nome1 = input.nextLine();
		
		out.println("Insira o numero do cartão : ");
		String num1 = input.nextLine();
		
		out.println("Insira o código de segurança: ");
		int cod1 = input.nextInt();
		
		out.println("Insira o limite total: ");
		double limTotal1 = input.nextDouble();
		
		c1.setNomeTitular(nome1);
		c1.setNumero(num1);
		c1.setCodigoSeguranca(cod1);
		c1.setLimiteTotal(limTotal1);
		
		out.println(c1);
		
		out.println("*----------------------------------------------*");
		out.println("Escolha a operação desejada:");
		out.println("1- Compra\n2- Paga limite do cartão\n3- Aumenta o limite máximo do cartão");
		out.println("Digite \"S\" para sair");
		out.println("*----------------------------------------------*");
		
		input.nextLine();
		char op = input.next().charAt(0);
		while(op != 'S'){
			
			switch(op){
				case '1':
					out.println("Digite o valor do produto");
					double valorA = input.nextDouble(); 
					c1.realizaCompra(valorA);
					break;
				case '2':
					out.println("Seu limite máximo atual é: R$ " + c1.getLimiteTotal());
					out.println("Seu limite atual é: R$ " + c1.getLimiteAtual());
					out.println("Insira o valor de pagamento desejado");
					double valorB = input.nextDouble();
					c1.realizaPagamento(valorB);
					break;
					
				case '3':
					out.println("Seu limite máximo atual é: R$ " + c1.getLimiteTotal());
					out.println("Insira o valor para aumentar o limite máximo");
					double valorC = input.nextDouble();
					c1.aumentaLimite(valorC);
					break;
				
				default:
					out.println("Opção não reconhecida");
					break;
			}
			
			out.println("Escolha outra opção ou digite \"Sair\" para sair");
		
			op = input.next().charAt(0);
			
		}
	}
}
