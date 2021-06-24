function [vertCubo, facesCubo] = calculaVertCubo()
  %A - CUBO
  p1 = [0 0 0];                   % ponto inicial
  uni = 1.5;                        % unidades to tamanho do cubo
  meio = uni/2;                   % metada da unidade

  %montando os pontos do cubo
  vertCuboOriginal = [ p1(1)-meio   p1(2)-meio   p1(3) 	    1;
                       p1(1)-meio   p1(2)+meio   p1(3) 		  1;
                       p1(1)+meio   p1(2)+meio   p1(3) 		  1;
                       p1(1)+meio   p1(2)-meio   p1(3) 		  1;
                       p1(1)-meio   p1(2)-meio   p1(3)+uni 	1;
                       p1(1)-meio   p1(2)+meio   p1(3)+uni 	1;
                       p1(1)+meio   p1(2)+meio   p1(3)+uni 	1;
                       p1(1)+meio   p1(2)-meio   p1(3)+uni 	1;]';
 
  %Matriz de transformação
  mtR = [   1  0  0  -5;
            0  1  0  4;
            0  0  1  -6];  

  vertCubo = mtR*vertCuboOriginal;
  facesCubo = [1 2 3 4; 2 6 7 3; 4 3 7 8; 1 5 8 4; 1 2 6 5; 5 6 7 8]; % pontos das 6 faces do cubo
  
  patch('Faces',facesCubo,'Vertices',vertCubo','FaceColor','b');
  
  %PLOTA OS DETALHES
  xlabel ("x");					        % configura o nome da vetor X
  ylabel ("y");					        % configura o nome da vetor Y
  zlabel ("z");					        % configura o nome da vetor Z
  %axis([-0.75, 0.75, -0.75, 0.75, 0, 1.6]);
  grid();							          % inicia a plotagem com as linhas de grade
  view (15, 30);				        % determina o angulo inicial de visão da plotagem
  print -djpg q1cubo.jpg;		    % salva o  como jpg
  hold off; 
endfunction