public class Retangulo{
	private double length;
	private double width;

	public void setLength(double length){
		if(length > 0.0 && length < 20.0){
			System.out.println("O comprimento é maior que 0 e menor que 20");			
		}else if(length > 0.0){
			System.out.println("O comprimento é maior que 0");				
		}else if(length < 20.0){
			System.out.println("O comprimento é menor que 20"); 
		}
		this.length = length;
	}
	public double getLenght(){
		return this.length;
	}
	

	public void setWidth(double width){
		if(width > 0.0 && width < 20.0){
			System.out.println("A largura é maior que 0 e menor que 20");			
		}else if(width > 0.0){
			System.out.println("A largura é maior que 0");				
		}else if(width < 20.0){
			System.out.println("A largura é menor que 20"); 
		}	
		this.width = width;
	}
	public double getWidth(){
		return this.width;
	}

	
	public double perimetro(){
		System.out.println("O perimetro vale:");
		return ((this.length + this.width) * 2);
	}	
	public double area(){
		System.out.println("A area vale:");
		return (this.length * this.width);
	}	

}
	
