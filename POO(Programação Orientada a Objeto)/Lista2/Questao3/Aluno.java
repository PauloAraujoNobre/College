public class Aluno extends Pessoa{
	private String matricula;
	private String instituicao;

	public void setMatricula(String matricula){
		this.matricula = matricula;
	}
	public String getMatricula(){
		return this.matricula;
	}
	
	public void setInstituicao(String instituicao){
		this.instituicao = instituicao;
	}
	public String getInstituicao(){
		return this.instituicao;
	}
}
